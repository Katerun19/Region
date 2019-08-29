#include <iostream>
#include "DinExperiment.h"
using namespace std;

//����� � ������������ ������


int DinExperiment::Count = 0;//����������� ����������

double DinExperiment::GetLongitude()
{
	return *_pLongitude;
}
double DinExperiment::GetLatitude()
	{
		return *_pLatitude;
	}
int DinExperiment::GetTime()
{
	return *_pTime;
}

int DinExperiment::GetId()
{
	return Id;
}

int DinExperiment::GetCount()
{
	return Count;
}

void DinExperiment::SetLongitude(double Longitude)
{
	*_pLongitude = Longitude;
}
void DinExperiment::SetLatitude(double Latitude)
{
	*_pLatitude = Latitude;
}
void DinExperiment::SetTime(int Time)
{
	*_pTime = Time;
}

DinExperiment &DinExperiment::operator = (const DinExperiment &other)//��������������� ��������� ������������.
{
	if (this->_pLongitude != nullptr)
	{
		delete this->_pLongitude;
	}
	if (this->_pLatitude != nullptr)
	{
		delete this->_pLatitude;
	}
	if (this->_pTime != nullptr)
	{
		delete this->_pTime;
	}
	this->_pLongitude = new double;
	*_pLongitude = *other._pLongitude;//���������� ������ ������ �� ��������� ������ ������ �����������
	this->_pLatitude = new double;
	*_pLatitude = *other._pLatitude;
	this->_pTime = new int;
	*_pTime = *other._pTime;
	cout << "�������� ��������     =     ��� ������������� �������" << this << endl;
	return *this;
}

bool DinExperiment::operator == (const DinExperiment &other)
{
	return *this->_pLongitude == *other._pLongitude && *this->_pLatitude == *other._pLatitude;
}

bool DinExperiment::operator != (const DinExperiment &other)
{
	return *this->_pLongitude != *other._pLongitude && *this->_pLatitude != *other._pLatitude;
}



void DinExperiment::Print()
{
	cout << "������ = " << *_pLongitude << "\n������� = " << *_pLatitude << "\n����� = " << *_pTime << endl << endl;
}
