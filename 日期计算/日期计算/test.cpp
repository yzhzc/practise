#include"date.h"


int main()
{
	Date d1(2023, 2, 1);
	d1.Print();

	Date d2(2023, 1, 1);
	d2.Print();

	Date d3 = d1 + -20;
	d3.Print();
	d1.Print();

	cout << d1 - d2 << endl;
	return 0;
}


