#include<iostream>
#include"list.h"
using namespace My_List;


typedef struct Date
{
	int _year = 0;
	int _month = 1;
	int _day = 0;
}Date;

int main()
{
	list<Date> l1;
	l1.push_back(Date());
	l1.push_back(Date());
	l1.push_back(Date());



	list<Date>::iterator it = l1.begin();
	l1.erase(it);
	it = l1.begin();
	while (it != l1.end())
	{
		std::cout << it->_year;
		//"it->" = _node->date�ĵ�ַ
		//"_node->date�ĵ�ַ"->_year
		//it->->_year,�������Ż�������һ��->
		
		it++;
	}


	return 0;
}