#include "CalculatorObDrob.h"
#include<iostream>

using namespace std;

void Menu_calculator_ob_drob()
{
	bool quite = false;
	while (!quite)
	{
		system("cls");
		cout << "\t\t\tКалькулятор обыкновенных дробей:" << endl;
		cout << "1)Сложение дробей" << endl;
		cout << "2)Вычитание дробей" << endl;
		cout << "3)Умножение дробей" << endl;
		cout << "4)Деление дробей" << endl;
		cout << "5)Сравнение дробей" << endl;
		cout << "6)Сокращение дробей" << endl;
		cout << "7)Представление в виде десятичной дроби" << endl;
		cout << "0)Выход" << endl;
		cout << "\nВыберите номер задания: ";
		unsigned short a;

		cin >> a;
		switch (a)
		{
		case 1:
			Addition_of_fractions();
			break;

		case 2:
			Subtraction_of_fractions();
			break;

		case 3:
			Multiplication_of_fractions();
			break;

		case 4:
			Dividing_fractions();
			break;

		case 5:
			Comparing_fractions();
			break;

		case 6:
			Reduction_of_fractions();
			break;

		case 7:
			Decimal_representation();
			break;
		case 0:
			quite = true;
			break;

		}
	}

}

void Addition_of_fractions()
{
}

void Subtraction_of_fractions()
{
}

void Multiplication_of_fractions()
{
}

void Dividing_fractions()
{
}

void Comparing_fractions()
{
}

void Reduction_of_fractions()
{
}

void Decimal_representation()
{
}
