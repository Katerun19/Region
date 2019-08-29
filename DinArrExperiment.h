#pragma once
#include <iostream>


using namespace std;
//КЛАСС В ДИНАМИЧЕСКОЙ ПАМЯТИ C МАССИВОМ

class DinArrExperiment
{
private:
	double *_pLongitude;
	double *_pLatitude;
	int *_pTime;
	int Size;
public:
 	DinArrExperiment() //конструктор по умолчанию создает массив из 1 элемента
	{
		this->Size = 1;
		this->_pLongitude = new double[Size];
		*_pLongitude = 0;
		this->_pLatitude = new double[Size];
		*_pLatitude = 0;
		this->_pTime = new int[Size];
		*_pTime = 0;
		cout << "Вызвалсы конструктор по умолчанию для динамического МАССИВА" << this << endl;
	}

	DinArrExperiment(int size) //конструктор c заданным размером массива.
	{
		this->Size = size;
		this->_pLongitude = new double[Size];
		for (int i = 0; i < Size; i++)
		{
			_pLongitude[i] = 0;
		}
		this->_pLatitude = new double[Size];
		for (int i = 0; i < Size; i++)
		{
			_pLatitude[i] = 0;
		}
		this->_pTime = new int[Size];
		for (int i = 0; i < Size; i++)
		{
			_pTime[i] = 0;
		}
		cout << "Вызвалсы конструктор с заданным размером для динамического МАССИВА " << this << endl;
	}

	DinArrExperiment(const double *other_Longitude, const double *other_Latitude, const int *other_Time, const int size) //конструктор с параметрами.
	{
		this->Size = size;
		this->_pLongitude = new double[Size];
		for (int i = 0; i < Size; i++)
		{
			this->_pLongitude[i] = other_Longitude[i];
		}
		this->_pLatitude = new double[Size];
		for (int i = 0; i < Size; i++)
		{
			this->_pLatitude[i] = other_Latitude[i];
		}
		this->_pTime = new int[Size];
		for (int i = 0; i < Size; i++)
		{
			this->_pTime[i] = other_Time[i];
		}
		cout << "Вызвалсы конструктор с параметрами для динамического МАССИВА" << this << endl;
	}

	DinArrExperiment(const DinArrExperiment &other)//конструктор копирования
	{
		this->Size = other.Size;
		if (this->_pLongitude != nullptr)
		{
			delete[] this->_pLongitude;
		}
		this->_pLongitude = new double[Size];
		for (int i = 0; i < Size; i++)
		{
			this->_pLongitude[i] = other._pLongitude[i];
		}

		if (this->_pLatitude != nullptr)
		{
			delete[] this->_pLatitude;
		}
		this->_pLatitude = new double[Size];
		for (int i = 0; i < Size; i++)
		{
			this->_pLatitude[i] = other._pLatitude[i];
		}
		if (this->_pTime != nullptr)
		{
			delete[] this->_pTime;
		}
		this->_pTime = new int[Size];
		for (int i = 0; i < Size; i++)
		{
			this->_pTime[i] = other._pTime[i];
		}
		cout << "Вызван конструктор копирования  " << this << endl;
	}



	~DinArrExperiment()//деструктор
	{
		delete[] this->_pLongitude;
		delete[] this->_pLatitude;
		delete[] this->_pTime;
		cout << "Вызвался деструктор  для динамического МАССИВА" << this << endl;
	}

	

	double GetLongitude();
	double GetLatitude();
	int GetTime();
	
	void SetLongitude(double *Longitude);
	void SetLatitude(double *Latitude);
	void SetTime(int *Time);


	DinArrExperiment &operator = (const DinArrExperiment &other);

	bool operator == (const DinArrExperiment &other);
	//bool operator != (const DinArrExperiment &other);
	int &operator [] (int index);
	 


	void Push_back(double Longitude, double Latitude, int Time);//добавление элемента в конец массива
	void Pop_back(double Longitude, double Latitude, int Time);//добавление элемента в начало массива
	void Sort();//сортировка массива по возрастанию
	void Search(int Time);//поиск по времени до конца массива
	void Search(int Time_Start, int Time_Finish);//поиск по времени до конца массива
	void Print();
	
};