#include "CombinatorialCalculator.h"
#include<iostream>

using namespace std;


void Menu_combinatorial_calculator()
{
	bool quite = 0;
	while (!quite)
	{
		system("cls");
		cout << "\t\t\t����������� ������ �������������:" << endl;
		cout << "1)���������� � �����������" << endl;
		cout << "2)���������� ��� �����������" << endl;
		cout << "3)��������� � �����������" << endl;
		cout << "4)��������� ��� �����������" << endl;
		cout << "5)������������" << endl;		
		cout << "0)�����" << endl;
		cout << "�������� ����� �������: ";
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
}

void per_without()
{
}
