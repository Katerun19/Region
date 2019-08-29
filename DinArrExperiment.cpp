#include <iostream>
#include "DinArrExperiment.h"
using namespace std;


//КЛАСС В ДИНАМИЧЕСКОЙ ПАМЯТИ C МАССИВОМ

double DinArrExperiment::GetLongitude()
{
	return *_pLongitude;
}
double DinArrExperiment::GetLatitude()
{
	return *_pLatitude;
}
int DinArrExperiment::GetTime()
{
	return *_pTime;
}

void DinArrExperiment::SetLongitude(double *Longitude)
{
	if (this->_pLongitude != nullptr)
	{
		delete[] this->_pLongitude;
	}
	this->_pLongitude = new double[Size];
	for (int i = 0; i < Size; i++)
	{
	this->_pLongitude[i] = Longitude[i];
	}
}
void DinArrExperiment::SetLatitude(double *Latitude)
{
	if (this->_pLatitude != nullptr)
	{
		delete[] this->_pLatitude;
	}
	this->_pLatitude = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		this->_pLatitude[i] = Latitude[i];
	}
}
void DinArrExperiment::SetTime(int *Time)
{
	if (this->_pTime != nullptr)
	{
		delete[] this->_pTime;
	}
	this->_pTime = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		this->_pTime[i] = Time[i];
	}
}

DinArrExperiment &DinArrExperiment::operator = (const DinArrExperiment &other)
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
	cout << "Вызван оператор присваивания" << endl;
	return *this;
	
}

bool DinArrExperiment::operator == (const DinArrExperiment & other)
{
	int j = 0;
	if (this->Size == other.Size) 
	{
		for (int i = 0; i < Size; i++)
		{
			if (this->_pLongitude[i] == other._pLongitude[i] && this->_pLatitude[i] == other._pLatitude[i]) 
			{
				j++;
			}	
		}
		
	}
	if (this->Size == j) { return true; }
	else { return false; }
	
}

//пока не работает
//bool DinArrExperiment::operator != (const DinArrExperiment & other)//перегрузка оператора не равенства
//{
//	int j = 0;
//	if (this->Size != other.Size) { return true; }
//	else if (this->Size == other.Size)
//	{
//		for (int i = 0; i < Size; i++)
//		{
//			if (this->_pLongitude[i] != other._pLongitude[i] || this->_pLatitude[i] != other._pLatitude[i])
//			{
//			 return true;
//			}
//		}
//		for (int i = 0; i < Size; i++)
//		{
//			if (this->_pLongitude[i] == other._pLongitude[i] && this->_pLatitude[i] == other._pLatitude[i])
//			{
//				j++;
//			}
//		}
//		if (this->Size == j) { return false; }
//	}
//	
//}


int &DinArrExperiment::operator [] (int index)//пока не работает (перегрузка оператора [])
{
	return index;
	//return _pLongitude[index];
}

void DinArrExperiment::Push_back(double Longitude, double Latitude, int Time) //добавить элемен в конец массив
{
	double *NewLongitude = new double[this->Size + 1];
	double *NewLatitude = new double[this->Size + 1];
	int *NewTime = new int[this->Size + 1];
	for (int i = 0; i < this->Size; i++)
	{
		NewLongitude[i] = this->_pLongitude[i];
		NewLatitude[i] = this->_pLatitude[i];
		NewTime[i] = this->_pTime[i];
	}
	NewLongitude[this->Size] = Longitude;
	NewLatitude[this->Size] = Latitude;
	NewTime[this->Size] = Time;
	this->Size = this->Size + 1;
	delete[] this->_pLongitude;//очистка памяти от первоначального массива
	delete[] this->_pLatitude;
	delete[] this->_pTime;
	this->_pLongitude = NewLongitude;
	this->_pLatitude = NewLatitude;
	this->_pTime = NewTime;
}

void DinArrExperiment::Pop_back(double Longitude, double Latitude, int Time) //добавить элемент в начало массив
{
	double *NewLongitude = new double[this->Size + 1];
	double *NewLatitude = new double[this->Size + 1];
	int *NewTime = new int[this->Size + 1];
	for (int i = 1; i < this->Size + 1; i++)
	{
		NewLongitude[i] = this->_pLongitude[i - 1];
		NewLatitude[i] = this->_pLatitude[i - 1];
		NewTime[i] = this->_pTime[i - 1];
	}
	NewLongitude[0] = Longitude;
	NewLatitude[0] = Latitude;
	NewTime[0] = Time;
	this->Size = this->Size + 1;
	delete[] this->_pLongitude;
	delete[] this->_pLatitude;
	delete[] this->_pTime;
	this->_pLongitude = NewLongitude;
	this->_pLatitude = NewLatitude;
	this->_pTime = NewTime;
}

void DinArrExperiment::Sort()// сортировка массива по возрастанию для времени.//поставить защиту время не повторяется и идет через 1 секунду
{
	for (int j = 0; j < this->Size; j++)//j – начиная с какого номера ищем наименьший
	{ 
		int Min = j; //номер минимального элемента
		for (int i = j; i < this->Size; i++)
		{
			if (this->_pTime[Min] > this->_pTime[i])
			{
				Min = i;
			}
		}
		int tempTime = this->_pTime[j];//меняем местами наименьший элемент с j элементом. Привязка к широте и долготе по времени.
		this->_pTime[j] = this->_pTime[Min];
		this->_pTime[Min] = tempTime;
		double tempLongitude = this->_pLongitude[j];
		this->_pLongitude[j] = this->_pLongitude[Min];
		this->_pLongitude[Min] = tempLongitude;
		double tempLatitude = this->_pLatitude[j];
		this->_pLatitude[j] = this->_pLatitude[Min];
		this->_pLatitude[Min] = tempLatitude;
	}	
}

void DinArrExperiment::Search(int Time)//поиск по времени от заданного значения до конца
{
	for (int i = 0; i < this->Size; i++)
	{
		if (this->_pTime[i] == Time)
		{
			cout << "Широта\n";
			for (int j = i; j < this->Size; j++)
			{
				std::cout << this->_pLongitude[j] << " ";
			}
			cout << endl << "Долгата\n";
			for (int j = i; j < this->Size; j++)
			{
				std::cout << this->_pLatitude[j] << " ";
			}
			std::cout << endl;
			break;
		}
		else { cout << "Error" << endl; break; }
	}
	
}

void DinArrExperiment::Search(int Time_Start, int Time_Finish)//поиск по времени от заданного момента до заданного момента
{
	if (Time_Start <= Time_Finish)
	{
		cout << "Широта\n";
		for (int i = 0; i < this->Size; i++)
		{
			if (this->_pTime[i] >= Time_Start && this->_pTime[i] <= Time_Finish)
			{
				std::cout << this->_pLongitude[i] << " ";
			}
		}
		cout << endl << "Долгoта\n";
		for (int i = 0; i < this->Size; i++)
		{
			if (this->_pTime[i] >= Time_Start && this->_pTime[i] <= Time_Finish)
			{
				std::cout << this->_pLatitude[i] << " ";
			}
		}
		cout << endl;
	}
	else { cout << "Error" << endl; }
}

void DinArrExperiment::Print()//вызов на консоль
{
	if (Size != 0)
	{
		cout << "Широта\n";
		for (int i = 0; i < Size; i++)
		{
			cout << _pLongitude[i] << " ";
		}
		cout << endl << "Долгота\n";
		for (int i = 0; i < Size; i++)
		{
			cout << _pLatitude[i] << " ";
		}
		cout << endl << "Время\n";
		for (int i = 0; i < Size; i++)
		{
			cout << _pTime[i] << " ";
		}
		cout << endl;
	}
	else 
	{
		cout << "Широта\n";
		cout << *_pLongitude << " ";
		cout << endl << "Долгота\n";
		cout << *_pLatitude << " ";
		cout << endl << "Время\n";
		cout << *_pTime << " ";
		cout << endl;
	}
} 
