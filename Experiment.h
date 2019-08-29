#pragma once
#include <iostream>
#include <string>
#include "Time.h"

using namespace std;
//����� � ����������� ������

class Experiment
{
private:
	double Latitude;
	double Longitude;
	int Time;
public:
	Experiment() //����������� �� ���������.
	{
		Latitude = Longitude = Time = 0;
	}
	Experiment(double Longitude, double Latitude, int Time) //����������� � �����������.
	{	this->Latitude = Latitude;
		this->Longitude = Longitude;
		this->Time = Time;
	}

	~Experiment()//����������
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
