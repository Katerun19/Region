#pragma once
#include <iostream>


using namespace std;
//����� � ������������ ������

class DinExperiment
{
private:
	double *_pLongitude;
	double *_pLatitude;
	int *_pTime;
	int Id;//������ ��������
	static int Count;//������� ��������
public:
	
	
	
	DinExperiment() //����������� �� ���������.
	{
		_pLongitude = new double;
		*_pLongitude = 0;
		_pLatitude = new double;
		*_pLatitude = 0;
		_pTime = new int;
		*_pTime = 0;
		cout << "�������� ����������� �� ��������� ��� ������������� �������" << this << endl;
		Count++;
		Id = Count;
	}
	DinExperiment(double Longitude, double Latitude, int Time) //����������� � �����������.
	{
		_pLongitude = new double;
		*_pLongitude = Longitude;
		_pLatitude = new double;
		*_pLatitude = Latitude;
		_pTime = new int;
		*_pTime = Time;
		cout << "�������� ����������� c ����������� ��� ������������� �������" << this << endl;
		Count++;
		Id = Count;
	}

	DinExperiment(const DinExperiment &other) //����������� �����������
	{
		this->_pLongitude = new double;//��������� ������
		*_pLongitude = *other._pLongitude;//���������� ������ ������ �� ������� ������ ������ �����������
		this->_pLatitude = new double;
		*_pLatitude = *other._pLatitude;
		this->_pTime = new int;
		*_pTime = *other._pTime;
		cout << "�������� ����������� ����������� ��� ������������� �������" << this << endl;
		Count++;
		Id = Count;
	}
	~DinExperiment()//����������
	{
		delete _pLongitude;
		delete _pLatitude;
		delete _pTime;
		cout << "�������� ���������� ��� ������������� �������" << this << endl;
	}


	DinExperiment &operator = (const DinExperiment &other);//��������������� ��������� ������������.
	bool operator == (const DinExperiment &other);//��������������� ��������� ==.
	bool operator != (const DinExperiment &other);//��������������� ��������� !=.
	

	
	double GetLongitude();
	
	double GetLatitude();
	
	int GetTime();

	int GetId();

	static int GetCount();
	
	void SetLongitude(double Longitude);
	
	void SetLatitude(double Latitude);
	
	void SetTime(int Time);
	
	void Print();
};
