#pragma once
#include<iostream>
using namespace std;




class Date
{
public:
	//��ȡÿ���¶�Ӧ������
	int GetMonthDay(int year, int month) const;
	//��ʼ��
	Date(int year = 0, int month = 1, int day = 1);
	//��������
	Date(const Date& d);

	bool operator<(const Date& d) const;

	bool operator==(const Date& d) const;

	Date& operator=(const Date& d);

	//����
	bool operator<=(const Date& d);

	bool operator>(const Date& d);

	bool operator>=(const Date& d);

	bool operator!=(const Date& d);

	Date operator+(int day) const;

	Date& operator+=(int day);

	Date operator-(int day) const;

	Date& operator-=(int day);
	//ǰ��++
	Date& operator++();
	//����++
	Date operator++(int);
	//ǰ��--
	Date& operator--();
	//����--
	Date operator--(int);

	int operator-(const Date& d) const;

	void Print();

private:
	int _year;
	int _month;
	int _day;
};