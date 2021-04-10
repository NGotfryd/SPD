#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<iomanip>		
#include<algorithm>

int main()
{
	std::string fileName;
	std::fstream file;
	int n;

	std::cout << "Nazwa pliku: ";
	std::cin >> fileName;

	file.open(fileName, std::ios::in);
	if(file.good() == true)
	{
		file >> n;
		int *r = new int[n];
		int *p = new int[n];

		for(int i = 0; i < n; i++)
		{	
			file >> r[i];
			file >> p[i];
		}
		file.close();

		for(int i = 0; i < n; i++)
		{
			for(int j = 1; j < n; j++)
			{
				if(r[j - 1] > r[j])
				{
					std::swap(r[j - 1], r[j]);
					std::swap(p[j - 1], p[j]);
				}
			}
		}

		int *C = new int[n];
		C[0] = 0;
		for(int i = 1; i < n; i++)
		{
			C[i] = std::max(r[i], C[i - 1]) + p[i];
		}
		std::cout << "Cmax = " << C[n - 1] << std::endl;
		
		delete[] r;
		delete[] p;
		delete[] C;
		return 0;
	}
	else
	{
		std::cout  << "Blad /n";
		return -1;
	}
}
