#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<iomanip>		
#include<algorithm>
#include<vector>

using namespace std;

struct zadanie
{
	int nr;
	int r;
	int p;
	int q;
};




ostream& operator << (ostream& out, zadanie& zadanie)
{
	cout << zadanie.nr << ": " << zadanie.r << " " << zadanie.p << " " << zadanie.q << endl;
	return out;
};


int main(int argc, char **argv)
{
	string fileName;
	fstream file;
	int n;
	int t = 0;
	int k = 0;
	vector<zadanie> N;
	vector<zadanie> G;
	zadanie e;	
	int Cmax;		
	fileName = argv[1];
	
/********WCZYTANIE DANYCH Z PLIKU************/

	file.open(fileName, std::ios::in);
	if(file.good() == true)
	{
		file >> n;
		//int *C = new int [n];		

		int buff;
		for(int i = 0; i < n; i++)
		{
			N.push_back(zadanie());
			N[i].nr = i+1;
			file >> buff;
			N[i].r = buff;
			file >> buff;
			N[i].p = buff;
			file >> buff;
			N[i].q = buff;
		}	
		
	}	





	
		file.close();
	

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



		cout << n << endl;
	for(int i = 0; i < N.size(); i++)
		{
			cout << N[i];
		}

		

/**************ALGORYTM*****************/
	while(!N.empty() || !G.empty())
//		cout << "dupa" << endl;
	{
		while(!N.empty() && N.back().r <= t)
		{	
			e = N.back();
			//N.back() = e;
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
			t = t + e.p;
			Cmax = max(Cmax, t + e.q);
			cout << Cmax << endl;

			
		}


	}
	cout << Cmax << endl; 


return 0;
}

