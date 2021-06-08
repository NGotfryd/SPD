#include "algorytmy.h"




int main()
{
	algorytmy test;

	test.WczytajDane("SCHRAGE2.DAT");

	// cout << test.iloscZadan << endl;
	// for(int i = 0; i < test.tabZadan.size(); i++)
	// {
	// 	cout << test.tabZadan[i];
	// }


	test.carlier();


	return 0;
}