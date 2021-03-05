#include "CombinatorialCalculator.h"
#include<iostream>

using namespace std;


void Menu_combinatorial_calculator()
{
	bool quite = 0;
	while (!quite)
	{
		system("cls");
		cout << "\t\t\tКалькулятор формул комбинаторики:" << endl;
		cout << "1)Размещение с повторением" << endl;
		cout << "2)Размещение без повторением" << endl;
		cout << "3)Сочитание с повторением" << endl;
		cout << "4)Сочитание без повторением" << endl;
		cout << "5)Перестановки" << endl;		
		cout << "0)Выход" << endl;
		cout << "Выберите номер задания: ";
		unsigned short a;

		cin >> a;
		switch (a)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			quite = true;
			break;
		}
	}
}

void razm_with()
{
}

void razm_without()
{
}

void soch_with()
{
}

void soch_without()
{
}

void per_with()
{
	фыввфыыфв
}

void per_without()
{
}
