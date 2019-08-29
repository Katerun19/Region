#pragma once
#include <iostream>
#include <string>
#include "Time.h"

using namespace std;
//КЛАСС В СТАТИЧЕСКОЙ ПАМЯТИ

class Experiment
{
private:
	double Latitude;
	double Longitude;
	int Time;
public:
	Experiment() //конструктор по умолчанию.
	{
		Latitude = Longitude = Time = 0;
	}
	Experiment(double Longitude, double Latitude, int Time) //конструктор с параметрами.
	{	this->Latitude = Latitude;
		this->Longitude = Longitude;
		this->Time = Time;
	}

	~Experiment()//деструктор
	{
	
	}
	double GetLongitude();
	
	double GetLatitude();
	
	int GetTime();
	 
	string GetInfo();
	
	

	void SetLongitude(double Longitude);
	
	void SetLatitude(double Latitude);
	
	void SetTime(int Time);
	friend ostream & operator << (ostream& os, Experiment& a);
	friend istream & operator >> (istream& is, Experiment& b);
	
};
ostream & operator << (ostream& os, Experiment& a);
istream & operator >> (istream& is, Experiment& b);	
