#include "CalculatorObDrob.h"
#include <iostream>

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
	int plusChislitel1 = 0, plusChislitel2 = 0, plusZnamenatel1 = 0, plusZnamenatel2 = 0;
	int chislitel, znamenatel; // - ����������, ������� ��� ���������� ��� �������� 

	do {
		cout << "������� ��������� ������ ����� �� ��������� [-100;100] : " << endl;
		cin >> plusChislitel1;
	} while (plusChislitel1 > 100 || plusChislitel1 < -100);
	do {
		cout << "������� ����������� ��� ������ ����� �� ��������� [-100;100] �������� 0: " << endl;
		cin >> plusZnamenatel1;
	} while (plusZnamenatel1 == 0);
	do {
		cout << "������� ��������� ������ ����� �� ��������� [-100;100]: " << endl;
		cin >> plusChislitel2;
	} while (plusChislitel2 > 100 || plusChislitel2 < -100);
	do {
		cout << "������� ����������� ������ ����� �� ��������� [-100;100] �������� 0: " << endl;
		cin >> plusZnamenatel2;
	} while (plusZnamenatel2 == 0);

	znamenatel = plusZnamenatel1 * plusZnamenatel2;
	chislitel = plusChislitel1 * plusZnamenatel2 + plusChislitel2 * plusZnamenatel1;

	if (chislitel < znamenatel)
	{
		cout << plusChislitel1 << " " << plusChislitel2 << " " << chislitel << endl;
		cout << "�" << " + " << "�" << " = " << "��" << endl;
		cout << plusZnamenatel1 << " " << plusZnamenatel2 << " " << znamenatel << endl;
	}
	else
	{
		if (chislitel == znamenatel)
		{
			cout << plusChislitel1 << " " << plusChislitel2 << " " << endl;
			cout << "�" << " + " << "�" << "= 1" << endl;
			cout << plusZnamenatel1 << " " << plusZnamenatel2 << " " << endl;
		}
		else
		{
			int integer = 0;
			integer = chislitel / znamenatel;

			cout << plusChislitel1 << " " << plusChislitel2 << " " << chislitel - integer * znamenatel << endl;
			cout << "�" << " + " << "�" << " = " << integer << "��" << endl;
			cout << plusZnamenatel1 << " " << plusZnamenatel2 << " " << znamenatel << endl;
		}

	}
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
