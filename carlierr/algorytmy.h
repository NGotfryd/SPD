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
	int c;
};


inline istream& operator >> (istream& in, zadanie& zadanie)
{
	in >> zadanie.r >> zadanie.p >> zadanie.q;
	return in;
};


inline ostream& operator << (ostream& out, zadanie& zadanie)
{
	cout << zadanie.nr << ": " << zadanie.r << " " << zadanie.p << " " << zadanie.q << endl;
	return out;
};

class algorytmy
{
public:


    
    vector<zadanie> tabZadan;
    vector<zadanie> PI;      //permutacja zadan

    int iloscZadan;
	int CmaxS = 0;
	int CmaxSP = 0;
	int UB;


    bool WczytajDane(string fileName);
	int schrage();
	int schragePod();
	int carlier();
	int find_a();
	int find_b();
	int find_c();



};


