#include "Functions.h"
#include<iostream>
using namespace std;
void Menu_functions()
{
	bool quite = false;
	while (!quite)
	{
		system("cls");
		cout << "\t\t\tРабота с функциями:" << endl;
		cout << "1)Вычисление определенного интервала на отрезке" << endl;
		cout << "2)Построение графика" << endl;
		cout << "3)Поиск корня Y=0 на отрезке" << endl;
		cout << "4)Поиск экстремумов на отрезке" << endl;
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
		case 0:
			quite = true;
			break;
		}
	}

}