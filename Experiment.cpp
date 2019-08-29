#include <iostream>
#include "Experiment.h"
using namespace std;


double Experiment::GetLongitude()
	{
		return this->Longitude;
	}
double Experiment::GetLatitude()
	{
		return this->Latitude;
	}
int Experiment::GetTime()
	{
		return this->Time;
	}

string Experiment::GetInfo()
{
	return "Данные" + to_string(Latitude) + " " + to_string(Longitude) + " " + to_string(Time);
}

ostream & operator << (ostream& os, Experiment& a)
{
	os << a.Latitude << " " << a.Longitude << " " << a.Time;
	return os;
}

istream & operator >> (istream& is, Experiment& a)
{
	is >> a.Latitude >> a.Longitude >> a.Time ;	
	return is;
}

void Experiment::SetLongitude(double Longitude)
	{
		this->Longitude = Longitude;
	}
void  Experiment::SetLatitude(double Latitude)
	{
		this->Latitude = Latitude;
	}
void Experiment::SetTime(int Time)
	{
		this->Time = Time;
	}


