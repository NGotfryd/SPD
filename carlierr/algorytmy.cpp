#include "algorytmy.h"

bool algorytmy::WczytajDane(string fileName)
{
    fstream file;

    file.open(fileName, std::ios::in);
	if(file.good() == true)
	{
		file >> iloscZadan;	
		for(int i = 0; i < iloscZadan; i++)
		{
			tabZadan.push_back(zadanie());
			PI.push_back(zadanie());
			file >> tabZadan[i];
			PI[i] = tabZadan[i];
			tabZadan[i].nr = i+1;
			PI[i].nr = i+1;
		}	
        file.close();
        return true;

	}	
	else
	{
		file.close();
		cout << "Blad wczytywania pliku" << endl;
        return false;
	}
}

int algorytmy::schrage()
{
  	int t = 0;
	int k = 0;
	vector<zadanie> N;
	vector<zadanie> G;
	zadanie e;

	
	for(int i = 0; i < tabZadan.size(); i++) N.push_back(tabZadan[i]);

	for(int i = 0; i < N.size(); i++)
	{
		for(int j = 1; j < N.size(); j++)
		{
			if(N[j -1].r < N[j].r)
			{
				swap(N[j-1], N[j]);
			}
		}
	}



	// for(int i = 0; i < N.size(); i++)
	// 	{
	// 		cout << N[i];
	// 	}



	while(!N.empty() || !G.empty())

	{
		while(!N.empty() && N.back().r <= t)
		{	
			e = N.back();
			G.push_back(e);
			N.pop_back();		
		}
		
		if(G.empty())
		{
			t = N.back().r;
		}
		else
		{
			
			for(int i = 0; i < G.size(); i++)
			{
				for(int j = 1; j < G.size(); j++)
				{
					if(G[j -1].q > G[j].q)
					{
						swap(G[j-1], G[j]);
					}
				}
			}

			
			e = G.back();
			G.pop_back();
			this->PI[k] = e;
			t = t + e.p;
			this->PI[k].c = t;
			CmaxS = max(CmaxS, t + e.q);		
			k++;
		}
	}
	//cout << CmaxS << endl; 
	return CmaxS;
}


int algorytmy::schragePod()
{
	int t = 0;
	vector<zadanie> N;
	vector<zadanie> G;
	zadanie e;
	zadanie l;

	for(int i = 0; i < tabZadan.size(); i++) N.push_back(tabZadan[i]);

	for(int i = 0; i < N.size(); i++)
	{
		for(int j = 1; j < N.size(); j++)
		{
			if(N[j -1].r < N[j].r)
			{
				swap(N[j-1], N[j]);
			}
		}
	}

	while(!N.empty() || !G.empty())

	{
		while(!N.empty() && N.back().r <= t)
		{	
			e = N.back();
			G.push_back(e);
			N.pop_back();

	
			if(e.q > l.q)
			{
				l.p = t - e.r;
				t = e.r;
				if(l.p > 0)
				{
					G.push_back(l);
				}

			}
		
		}
		

		if(G.empty())
		{
			t = N.back().r;
		}
		else
		{
			
			for(int i = 0; i < G.size(); i++)
			{
				for(int j = 1; j < G.size(); j++)
				{
					if(G[j -1].q > G[j].q)
					{
						swap(G[j-1], G[j]);
					}
				}
			}


			e = G.back();
			G.pop_back();
			l = e;
			t = t + e.p;
			CmaxSP = max(CmaxSP, t + e.q);		
		}
	}
//	cout << CmaxSP << endl; 
	return CmaxSP;
}


int algorytmy::carlier()
{
	int U=0;
	int LB = 0;
	int a =0, b=0, c=-1;
	int rprim, pprim, qprim;
	int r_c = 0;
	int nr_c = 0;
	int q_c = 0;
	
	int tmp_r = 0;
	int tmp_num = 0;
	int tmp_q = 0;
	int tmp_q_num = 0;

	U = schrage();
	if(U < UB)
	{
		UB = U;
	}

	b = find_b();
	a = find_a();
	c = find_c();

	cout << a << " " << b << " " << c << "  a, b i c wyniki" << endl;

	if(c == -1) return UB;

	cout << UB << " = UB, do 207 dziala  " << endl;

	for(int i = c-1; i <= b; i++)
	{
		rprim = min(rprim, PI[i].r);
		pprim += PI[i].p;
		qprim = min(qprim, PI[i].q);
	}

	
	 tmp_r = PI[c].r;
	 tmp_num = PI[c].nr;
	 
	PI[c].r = max(PI[c].r, rprim+pprim);

	LB = schragePod();	

	cout << "LB = " << LB << endl;
	
	if(LB < UB)
	{
		carlier();
	}

	r_c = PI[c].r;
	nr_c = PI[c].nr;
	PI[c].r = max(PI[c].r, rprim + pprim);



	cout << "225 jest git jeszcze" << LB << " = LB"<< endl;



	cout << "230 dziala" << endl;

	for(int i = 0; i < tabZadan.size(); i++)
	{
		if(PI[i].nr == nr_c)	
		{
		PI[i].r = r_c;
		}
	}

	PI[c].q = max(PI[c].q, qprim + pprim);

	LB = schragePod();
	if(LB <= UB)
	{
		carlier();
	}

		for(int i=0; i<PI.size(); i++)	
	{
		if(PI[i].nr == nr_c)	
		{
		PI[i].q = q_c;
		}
	}

	cout << UB << endl;
	return UB;
}


int algorytmy::find_b()
{
	for(int i = iloscZadan; i > 0; i--)
	{
		if(this->CmaxS == (this->PI[i].c + this->PI[i].q))	
		{
		return i;
		}
	}
	return -1;
}

int algorytmy::find_a()
{
	int sum;
	int b = this->find_b();

	for(int i=0; i < b; i++)	
	{
	sum = 0;
	for(int j=i; j<=b; j++)	sum +=PI[j].p;
	if(this->CmaxS == (PI[i].r + sum + PI[b].q))	
		{
			return i;
		}
	}	
	return -1;
}

int algorytmy::find_c()
{
	int c = -1;
	int a = this->find_a();
	int b = this->find_b();
	for(int i=b; i>=a; i--)	
	{
		if(PI[i].q < PI[b].q)	
		{
			c = i;
			break;
		}
	}
	return c;
}