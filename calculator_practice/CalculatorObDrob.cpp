#include "CalculatorObDrob.h"
#include<iostream>

using namespace std;

void Menu_calculator_ob_drob()
{
	bool quite = false;
	while (!quite)
	{
		system("cls");
		cout << "\t\t\t����������� ������������ ������:" << endl;
		cout << "1)�������� ������" << endl;
		cout << "2)��������� ������" << endl;
		cout << "3)��������� ������" << endl;
		cout << "4)������� ������" << endl;
		cout << "5)��������� ������" << endl;
		cout << "6)���������� ������" << endl;
		cout << "7)������������� � ���� ���������� �����" << endl;
		cout << "0)�����" << endl;
		cout << "�������� ����� �������: ";
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
