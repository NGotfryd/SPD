#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;


struct zadanie
{
	int nr;
	int r;
	int p;
	int q;
};


struct Nqueue
{
	bool operator() (zadanie a, zadanie b)
	{
		return a.r >b.r;
	}
};

struct Qqueue
{
	bool operator()(zadanie a, zadanie b)
	{
		return a.r < b.r;
	}
};



ostream& operator << (ostream out, zadanie& zadanie)
{
	cout << zadanie.nr << ": " << zadanie.r << " " << zadanie.p << " " << zadanie.q << endl;
};


int main(int argc, char **argv)
{
	string fileName;
	fstream file;
	zadanie zad;
	int n;
	int t = 0;

	priority_queue <zadanie, vector<zadanie>, Nqueue> N;
	priority_queue <zadanie, vector<zadanie>, Gqueue> G;



	fileName = argv[1];
	file.open(fileName, ios::in);
	if(file.good() == true)
	{
		file >> n;
		int *C = new int [n];

		int buf;
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
	cout << n << endl;
	for(int i = 0; i < N.size(); i++)
	{
		cout << N[i];
	}

	return 0;
}


















