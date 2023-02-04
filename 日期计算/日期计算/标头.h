#pragma once
#include<iostream>
using namespace std;




class Date
{
public:
	//获取每个月对应的天数
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}

		return monthDays[month];
	}

	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month >= 0 && month <= 12
			&& day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
		}
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		else
			return false;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	Date& operator=(const Date& d)
	{
		if (*this != d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}


	//复用
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		//ret._day += day;

		//while (ret._day > GetMonthDay(ret._year, ret._month))
		//{
		//	ret._day -= GetMonthDay(ret._year, ret._month);
		//	ret._month++;
		//	if (ret._month >= 13)
		//	{
		//		ret._year++;
		//		ret._month = 1;
		//	}	
		//}

		return ret;
	}

	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}

		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month >= 13)
			{
				_year++;
				_month = 1;
			}
		}

		return *this;
	}

	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		//ret._day -= day;

		//while (ret._day <= 0)
		//{
		//	ret._month--;
		//	if (ret._month <= 0)
		//	{
		//		ret._year--;
		//		ret._month = 12;
		//	}
		//	ret._day += GetMonthDay(ret._year, ret._month);
		//}

		return ret;
	}

	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}

		_day -= day;
		while (_day <= 0)
		{
			_month--;
			if (_month <= 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}

		return *this;
	}

	//前置++
	Date& operator++()
	{
		*this += 1;

		return *this;
	}

	//后置++
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;

		return ret;
	}

	//前置--
	Date& operator--()
	{
		*this -= 1;

		return *this;
	}

	//后置--
	Date& operator--(int)
	{
		Date ret(*this);
		*this -= 1;

		return ret;
	}

	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		if (max < min)
		{
			max = d;
			min = *this;
		}

		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}

		if (max == *this)
			return n;

		return max == *this ? n : -n;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};