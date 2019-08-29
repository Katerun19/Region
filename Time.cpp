#include <iostream>
#include <vector>
#include "Time.h"

using namespace std;
//Get функции

int Time::HourGet() {
	return _Hour;
}

int Time::MinGet() {
	return _Min;
}

int Time::SecGet() {
	return _Sec;
}

int Time::DayGet() {
	return _Day;
}

int Time::MonthGet() {
	return _Month;
}

int Time::YearGet()
{
	return _Year;
}

//Set функции

void Time::HourSet(int Hour) 
{
	this->_Hour = Hour;
}

void Time::MinSet(int Min) {
	this->_Min = Min;
}

void Time::SecSet(int Sec) {
	this->_Sec = Sec;
}

void Time::DaySet(int Day) {
	this->_Day = Day;
}

void Time::MonthSet(int Month) {
	this->_Month = Month;
}

void Time::YearSet(int Year) {
	this->_Year = Year;
}



void Time::TimePrint() 
{	
	cout << DayGet() << "/" << MonthGet() << "/" << YearGet() << endl;
	cout << HourGet() / 10 << HourGet() % 10 << ":" << MinGet() / 10 << MinGet() % 10 << ":" << SecGet() / 10 << SecGet() % 10 << endl;
}

bool Time::operator == (const Time & other)
{
	return this->_Year == other._Year && this->_Month == other._Month && this->_Day == other._Day && this->_Hour == other._Hour && this->_Min == other._Min && this->_Sec == other._Sec;
}

void Time::TimeRead() {
	cout << "Vvedite Time (Hour:Min:Sec)";
	cin >> _Hour >> _Min >> _Sec;
}


Time TimeSecHour(int a) //функция перевода секунд в часы.
{
	Time b;
	int hour, min, sec;
	hour = a / 3600 % 24;
	min = a % 3600 / 60;
	sec = a % 3600 % 60;
	while (hour > 24) { hour = hour - 24; }
	b.HourSet(hour);
	b.MinSet(min);
	b.SecSet(sec);
	return b;
}

Time Time::operator = (const Time & other)
{
	this->_Year = other._Year;
	this->_Month = other._Month;
	this->_Day = other._Day;
	this->_Hour = other._Hour;
	this->_Min = other._Min;
	this->_Sec = other._Sec;
	return *this;
}

ostream & operator << (ostream& os, Time& a)
{
	os << a._Year << "/" << a._Month / 10 << a._Month % 10 << "/" << a._Day / 10 << a._Day % 10 << " " << a._Hour / 10 << a._Hour % 10 << ":" << a._Min / 10 << a._Min % 10 << ":" << a._Sec / 10 << a._Sec % 10 << endl;
	return os;
}
/*istream & operator >> (istream& is, Time& b)
{
	is >> this YearSet >> b.MonthSet() >> b.DayGet()>> b.HourGet() >> b.MinGet() >> b.SecGet();
}*/

int TimeHourSec(Time &a)// функция перевода часов в секунды
{
	return a.HourGet() * 3600 + a.MinGet() * 60 + a.SecGet();
}


void Time::DateSet(int Day, int Month, int Year)
{
	bool GodVisokosn;
	if (Year % 4 != 0 || Year % 100 == 0 && Year % 400 != 0) { GodVisokosn = 0; }
	else { GodVisokosn = 1; }
	if (Year >= 731)
	{
		if (Month >= 1 && Month <= 12)
		{
			if (Month == 2 && GodVisokosn == 1)
			{
				if (Day >= 1 && Day <= 29)
				{
					this->_Day = Day;
					this->_Month = Month;
					this->_Year = Year;
				}
			}
			if (Month == 2 && GodVisokosn == 0)
			{
				if (Day >= 1 && Day <= 28)
				{
					this->_Day = Day;
					this->_Month = Month;
					this->_Year = Year;
				}
			}
			if (Month != 2 && Month == 4 || Month == 6 || Month == 9 || Month == 11)
			{
				if (Day >= 1 && Day <= 30)
				{
					this->_Day = Day;
					this->_Month = Month;
					this->_Year = Year;
				}
			}
			if (Month != 2 && Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
			{
				if (Day >= 1 && Day <= 31)
				{
					this->_Day = Day;
					this->_Month = Month;
					this->_Year = Year;
				}
			}
		}
	}
}

void Time::DateRead()
{
	int Day, Month, Year;
	cout << "Vvedite Datu (Day/Mounth/Year)";
	cin >> Day >> Month >> Year;
	bool GodVisokosn;
	if (Year % 4 != 0 || Year % 100 == 0 && Year % 400 != 0) { GodVisokosn = 0; }
	else { GodVisokosn = 1; }
	if (Year >= 731)
	{
		if (Month >= 1 && Month <= 12)
		{
			if (Month == 2 && GodVisokosn == 1)
			{
				if (Day >= 1 && Day <= 29)
				{
					this->_Day = Day;
					this->_Month = Month;
					this->_Year = Year;
				}
			}
			if (Month == 2 && GodVisokosn == 0)
			{
				if (Day >= 1 && Day <= 28)
				{
					this->_Day = Day;
					this->_Month = Month;
					this->_Year = Year;
				}
			}
			if (Month != 2 && Month == 4 || Month == 6 || Month == 9 || Month == 11)
			{
				if (Day >= 1 && Day <= 30)
				{
					this->_Day = Day;
					this->_Month = Month;
					this->_Year = Year;
				}
			}
			if (Month != 2 && Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
			{
				if (Day >= 1 && Day <= 31)
				{
					this->_Day = Day;
					this->_Month = Month;
					this->_Year = Year;
				}
			}
		}
	}
}