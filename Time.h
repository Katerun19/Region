#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time
{
private:
	int _Year;
	int _Month;
	int _Day;
	int _Hour;
	int _Min;
	int _Sec;

public:
	Time()//конструктор по умолчанию
	{
		_Year = _Month = _Day = _Hour = _Min = _Sec = 0;
	}
	Time(int Year, int Month, int Day, int Hour, int Min, int Sec)
	{
		this->_Year = Year;
		this->_Month = Month;
		this->_Day = Day;
		this->_Hour = Hour;
		this->_Min = Min;
		this->_Sec = Sec;
	}

	int HourGet();
	int MinGet();
	int SecGet();
	int DayGet();
	int MonthGet();
	int YearGet();

	void DaySet(int);
	void MonthSet(int);
	void YearSet(int);
	void HourSet(int);
	void MinSet(int);
	void SecSet(int);
	

	void DateSet(int Day, int Month, int Year);

	void DateRead();
	void TimeRead();
	void TimePrint();

	bool operator == (const Time &other);
	Time operator = (const Time &other);
	friend ostream & operator << (ostream& os, Time& a);
	//friend istream & operator >> (istream& is, Time& b);
};

ostream & operator << (ostream& os, Time& a);
//istream & operator >> (istream& is, Time& b);
int TimeHourSec(Time &a);
Time TimeSecHour(int a);