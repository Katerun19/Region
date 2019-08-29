#pragma once
#include <iostream>


using namespace std;
//КЛАСС В ДИНАМИЧЕСКОЙ ПАМЯТИ

class DinExperiment
{
private:
	double *_pLongitude;
	double *_pLatitude;
	int *_pTime;
	int Id;//индекс счетчика
	static int Count;//счетчик объектов
public:
	
	
	
	DinExperiment() //конструктор по умолчанию.
	{
		_pLongitude = new double;
		*_pLongitude = 0;
		_pLatitude = new double;
		*_pLatitude = 0;
		_pTime = new int;
		*_pTime = 0;
		cout << "Вызвалсы конструктор по умолчанию для динамического объекта" << this << endl;
		Count++;
		Id = Count;
	}
	DinExperiment(double Longitude, double Latitude, int Time) //конструктор с параметрами.
	{
		_pLongitude = new double;
		*_pLongitude = Longitude;
		_pLatitude = new double;
		*_pLatitude = Latitude;
		_pTime = new int;
		*_pTime = Time;
		cout << "Вызвалсы конструктор c параметрами для динамического объекта" << this << endl;
		Count++;
		Id = Count;
	}

	DinExperiment(const DinExperiment &other) //конструктор копирования
	{
		this->_pLongitude = new double;//выделение адреса
		*_pLongitude = *other._pLongitude;//заполнение ячейки памяти по данному адресу нужной информацией
		this->_pLatitude = new double;
		*_pLatitude = *other._pLatitude;
		this->_pTime = new int;
		*_pTime = *other._pTime;
		cout << "Вызвалсы конструктор КОПИРОВАНИЯ для динамического объекта" << this << endl;
		Count++;
		Id = Count;
	}
	~DinExperiment()//деструктор
	{
		delete _pLongitude;
		delete _pLatitude;
		delete _pTime;
		cout << "Вызвалсы деструктор для динамического объекта" << this << endl;
	}


	DinExperiment &operator = (const DinExperiment &other);//переопределение оператора присваивания.
	bool operator == (const DinExperiment &other);//переопределение оператора ==.
	bool operator != (const DinExperiment &other);//переопределение оператора !=.
	

	
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
