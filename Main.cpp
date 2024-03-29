
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include "Experiment.h"
#include "DinExperiment.h"
#include "DinArrExperiment.h"

using namespace std;

/*C++-функция конвертирования из формата 2 в формат 1. Обратить внимание, что во 2-м формате кроме наличия «лишних» тэгов
имеет место другой порядок и формат данных.
На вход:
1)	имя или идентификатор открытого на чтение исходного файла «gpx»;
2)	имя или идентификатор открытого на запись итогового файла «csv».

*C++ - функция считывания из файла «csv» во внешние непрерывные буферы и переменные следующих данных :
1)	долгота и широта(Longitude, Latitude) – тип double, массив;
2)	время в секундах относительно 1 - го указанного в файле – тип int(int32), массив;
3)	дата и время начала */

double char_double(const char *S) //перевод из char в double
{
	size_t i;
	int k = 1;
	double r = 0, p = 1;
	for (i = 0; i < strlen(S); i++)
	{
		if (S[i] == '.' || (S[i] >= '0' && S[i] <= '9')) 
		{
			if (k < 0) { p = p * 10; }
			if (S[i] == '.')
			{
				k = -k;
			}
			else
			{
				r = r * 10 + (S[i] - '0');
			}  
		}
		else { 	break;	}
	}
	return r / p;
}
int char_int(const char* S) //перевод из char в int
{
	size_t i;
	int r = 0;
	for (i = 0; i < strlen(S); i++)
	{
		if (S[i] >= '0' && S[i] <= '9')
		{
			r = r * 10 + (S[i] - '0');
		}
		else { return r; }
	}

	return r;
}

double Number(string *str, int m) //функция вынимания данных
{
	string Str = *str;
	double Num;
	char str1[9];
	for (int j = 0; j < 9; j++, m++)
	{
		str1[j] = Str[m];
	}
	Num = char_double(str1);
	return Num;
}

int Year(string *str, int m) //функция вытягивания даты из файла
{
	string Str = *str;
	int Time;
	char Year[4];
	for (int i = 0; i < 4; i++, m++)
	{
		Year[i] = Str[m];
	}
	Time = char_int(Year);
	return Time;
}
int Month(string *str, int m) //функция вытягивания даты из файла
{
	int n = m + 5;
 	string Str = *str;
	int Time;
	char Month[2];
	for (int i = 0; i < 2; i++, n++)
	{
		Month[i] = Str[n];
	}
	Time = char_int(Month);
	return Time;
}
int Day (string *str, int m) //функция вытягивания даты из файла
{
	int n = m + 8;
	string Str = *str;
	int Time;
	char Day[2];
	for (int i = 0; i < 2; i++, n++)
	{
		Day[i] = Str[n];
	}
	Time = char_int(Day);
	return Time;
}
int Hour(string *str, int m) //функция вытягивания даты из файла
{
	int n = m + 11;
	string Str = *str;
	int Time;
	char Hour[2];
	for (int i = 0; i < 2; i++, n++)
	{
		Hour[i] = Str[n];
	}
	Time = char_int(Hour);
	return Time;
}
int Min(string *str, int m) //функция вытягивания даты из файла
{
	int n = m + 14;
	string Str = *str;
	int Time;
	char Min[2];
	for (int i = 0; i < 2; i++, n++)
	{
		Min[i] = Str[n];
	}
	Time = char_int(Min);
	return Time;
}
int Sec(string *str, int m) //функция вытягивания даты из файла
{
	int n = m + 17;
	string Str = *str;
	int Time;
	char Sec[2];
	for (int i = 0; i < 2; i++, n++)
	{
		Sec[i] = Str[n];
	}
	Time = char_int(Sec);
	return Time;
}


int main()
{
	setlocale(LC_ALL, "ru");
	Experiment Point;
	string file1 = "2018-09-20_11-34-46.gpx";
	string file = "MyFile.txt";
	string str;
	ifstream File1;
	File1.open(file1);
	if (!File1.is_open()) //проверка на открытие файла
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{
		cout << "Файл открыт." << endl;
		int k = 0, m = 0;
		while (!File1.eof())
		{	
			getline(File1, str);
			cout << "Cчитали строку" << endl;
			cout << str << endl;
			int SizeLat = str.find("lat=") + 5, SizeLon = str.find("lon=") + 5, SizeTime = str.find("<time>") + 6;
			if (str.find("lat=") != -1)
			{
				Point.SetLatitude(Number(&str, SizeLat));
			}
			if (str.find("lon=") != -1)
			{
				Point.SetLongitude(Number(&str, SizeLon));

			}
			if (str.find("<time>") != -1)
			{	cout << "Проверка на время" << endl;

			cout << Year(&str, SizeTime) << " " << Month(&str, SizeTime) / 10 << Month(&str, SizeTime) % 10 << " " << Day(&str, SizeTime) / 10 << Day(&str, SizeTime) % 10 << endl;
			cout << Hour(&str, SizeTime) / 10 << Hour(&str, SizeTime) % 10 << ":" << Min(&str, SizeTime) / 10 << Min(&str, SizeTime) % 10 << ":" << Sec(&str, SizeTime) / 10 << Sec(&str, SizeTime) % 10 << endl;
			}
			//cout << Point << endl;
		}
	}
	Time S(1, 1, 1, 1, 1, 1);
	cout << "Проверка Time" << S;
	
	
	/*fstream File;
	File.open(file, fstream::in | fstream::out | fstream::app);
	if (!File.is_open()) //проверка на открытие файла
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else 
	{	cout << "Файл открыт." << endl; 
	int value;
	cout << "Введите 1 для записи данных в файл\n";
	cout << "введите 2 для вывода всех данных на экран\n";
	cin >> value;
		if (value == 1)
		{			
			File.write((char*)&Point_in, sizeof(Point_in));//функция write записывает данные в файл
		}
		if (value == 2)
		{
			Experiment Point_out;
			while (File.read((char*)&Point_out, sizeof(Point_out)))//функция read возращает true если удалось считать данные
			{
				Point_out.Print();
			}
		}
	}
	File.close();*/


	//проверка работы класса//
	const int size = 5;
	double a[size]{ 1, 2, 3, 4, 1 };
	int e[size]{ 4, 2, 1, 5, 3 };
	double d[size]{ 1, 2, 3, 4, 2 };
	double *b = new double[6];
	for (int i = 0; i < 6; i++)
	{
		b[i] = i;
	}
	int *c = new int[7];
	for (int i = 0; i < 7; i++)
	{
		c[i] = rand() / 10;
	}
		
	//A.Print();
	
	delete[] b;
	delete[] c;
    return 0;
}

