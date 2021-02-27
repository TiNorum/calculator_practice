#include<iostream>
using namespace std;

void Menu_polynomial_calculator()
{
	bool quite = 0;
	while (!quite)
	{
		system("cls");
		cout << "\t\t\tКалькулятор многочленов:" << endl;
		cout << "1)Деление многочленов в столбик" << endl;
		cout << "2)Сложение многочленов" << endl;
		cout << "3)Вычитание многочленов" << endl;
		cout << "4)Умножение многочленов" << endl;
		cout << "5)Умножение многочленов на число" << endl;
		cout << "6)Вычисление производной от многочлена" << endl;
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
		case 6:
			break;
		case 0:
			quite = true;
			break;
	
		}
	}

}