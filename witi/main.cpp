#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<iomanip>		
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;



struct zadanie
{
    int p;  //czas wykonania
    int d;  //wspolczynnik kary
    int w;  //zadany czas wykonania
    int nr; //numer zadania
};

istream& operator >> (istream& in, zadanie& zadanie)
{
	in >> zadanie.p >> zadanie.d >> zadanie.w;
	return in;
};


ostream& operator << (ostream& out, zadanie& zadanie)
{
	cout << zadanie.nr + 1 << ": " << zadanie.p << " " << zadanie.d << " " << zadanie.w << endl;
	return out;
};



vector<zadanie> PI; //wektor zadan
int n;  //ilosc zadan


bool wczytajDane(string filename)
{
    fstream file;
    file.open(filename, ios::in);
    if (file.good())
    {
        file >> n;
        for(int i = 0; i < n; i++)
        {
        PI.push_back(zadanie());
            file >>PI[i];
        PI[i].nr = i;
        }
        file.close();
         return true;
    }

    else
    {
        cout << "blad wczytywania pliku" << endl;
        return false;
    }
   
}

void wypiszDane()
{
    cout << n << endl;
    for(int i = 0; i <PI.size(); i++)
    {
        cout <<PI[i];
    }


}

void WiTi()
{

    int N = 1 << PI.size(); //przesuwa bity w lewo o PI.size
    int *OPT = new int[N];
    int *P = new int[N];
    OPT[0] = 0;

    vector<int> kolejka;

    for(int i = 0; i < PI.size(); i++)
    {
        kolejka.push_back(i+1);
    }


    for(int i = 1; i < N; i++)
    {
        P[i] = 0;
        

        for(int j = 0, b = 1; j < PI.size(); j++,b*=2)
        {
            if(i&b)
            P[i] += PI[j].p;

            OPT[i] = 123321;

            for(int j = 0, b = 1; j < PI.size(); j++, b*=2)
            {
                if(i&b){
               OPT[i]=min(OPT[i],OPT[i-b]+PI[j].d*max(0,P[i]-PI[j].w));
                }
            }
        }
    }

    int mini;
    int set = (1 << PI.size()) - 1;
    int tmp1;
    int tmp2;

    for(int i = PI.size(); i > 0; i--)
    {
        mini = 3000000;
        for(int k = 0, b = 1; k < PI.size(); k++, b*=2)
        {
            if(set&b)
            {
                tmp1 = mini;
                mini = min(mini, OPT[set - b] + PI[k].d * max(0, P[set] - PI[k].w));
                if(tmp1 > mini)
                {
                    tmp2 = k;
                }
            }
        }
        set = set - pow(2,tmp2);
        kolejka[i-1] = tmp2+1;
    }

    cout << "suma kar = " << OPT[N-1] << endl;
   
    delete [] P;
    delete [] OPT;
}


int main()
{

    wczytajDane("dane4.txt");
   // wypiszDane();
    WiTi();

    return 0;
}