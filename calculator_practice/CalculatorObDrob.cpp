#include "CalculatorObDrob.h"

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
		system("cls");
		switch (a)
		{
		case 1:
			Addition_of_fractions();
			system("pause");
			break;

		case 2:
			Subtraction_of_fractions();
			system("pause");

			break;

		case 3:
			Multiplication_of_fractions();
			system("pause");

			break;

		case 4:
			Dividing_fractions();
			system("pause");

			break;

		case 5:
			Comparing_fractions();
			system("pause");

			break;

		case 6:
			Reduction_of_fractions();
			system("pause");

			break;

		case 7:
			to_Decimal();
			system("pause");

			break;
		case 0:
			quite = true;
			break;

		}
		
	}

}


void Addition_of_fractions()
{
	fraction f1, f2, result;

	enter_fraction(f1, f2);

	result.z = NOK(f1.z, f2.z);
	result.c = f1.c * result.z / f1.z + f2.c * result.z / f2.z;

	print_fraction(f1, f2, result, '+');
}


void Subtraction_of_fractions()
{
	fraction f1, f2, result;

	enter_fraction(f1, f2);


	result.z = NOK(f1.z, f2.z);
	result.c = f1.c * result.z / f1.z - f2.c * result.z / f2.z;

	print_fraction(f1, f2, result, '-');
}


void Multiplication_of_fractions()
{
	fraction f1, f2, result;

	enter_fraction(f1, f2);

	result.c = f1.c * f2.c;
	result.z = f1.z * f2.z;

	print_fraction(f1, f2, result, '*');
}


void Dividing_fractions()
{
	fraction f1, f2, result;

	enter_fraction(f1, f2);

	result.c = f1.c * f2.z;
	result.z = f1.z * f2.c;

	print_fraction(f1, f2, result, ':');
}


void Comparing_fractions()
{
	fraction f1, f2;
	int temp1, temp2;
	enter_fraction(f1, f2);

	int nok = NOK(f1.z, f2.z);

	temp1 = f1.c * nok / f1.z;
	temp2 = f2.c* nok / f2.z;

	char c = temp1 > temp2 ? '>':'<';
	print_fraction(f1, f2, c);
}


void Reduction_of_fractions()
{
	fraction f1, f2;
	enter_fraction(f1);

	int nod = NOD(f1);

	f2.c = f1.c / nod;
	f2.z = f1.z / nod;

	print_fraction(f1, f2, '=');
}


void to_Decimal()
{
	fraction f1;
	enter_fraction(f1);

	double a = (double)f1.c / f1.z;

	print_fraction(f1, a);
}


void print_fraction(fraction f1,fraction f2, fraction result, char sign)
{
	int ac1 = amount_chars(f1);
	int ac2 = amount_chars(f2);
	int ac3 = amount_chars(result);

	cout << setw(ac1) << f1.c << "   " << setw(ac2) << f2.c << "   " << setw(ac3) << result.c <<endl;

	for (int i = 0; i < ac1; i++)
		cout << '-';
	cout << " " << sign << " ";
	for (int i = 0; i < ac2; i++)
		cout << '-';
	cout << " = ";
	for (int i = 0; i < ac3; i++)
		cout << '-';
	cout << endl;

	cout << setw(ac1) << f1.z << "   " << setw(ac2) << f2.z << "   " << setw(ac3) << result.z << endl;


}


void print_fraction(fraction f1,  fraction f2, char sign)
{
	int ac1 = amount_chars(f1);
	int ac2 = amount_chars(f2);

	cout << setw(ac1) << f1.c << "   " << setw(ac2) << f2.c << endl;

	for (int i = 0; i < ac1; i++)
		cout << '-';
	cout << " " << sign << " ";
	for (int i = 0; i < ac2; i++)
		cout << '-';


	cout << endl;

	cout << setw(ac1) << f1.z << "   " << setw(ac2) << f2.z << endl;
}


void print_fraction(fraction f1, double result)
{
	int ac1 = amount_chars(f1);

	cout << setw(ac1) << f1.c << "   " << endl;

	for (int i = 0; i < ac1; i++)
		cout << '-';

	cout <<   " = " << result<<endl;

	cout << setw(ac1) << f1.z << endl;
}


void enter_fraction(fraction &f1)
{
	cout << "������� ��������� : ";
	cin >> f1.c;
	cout << "������� ����������� : ";
	cin >> f1.z;
	while (f1.z == 0)
	{
		cout << "����������� �� ����� ���� ����� 0!" << endl;
		cout << "������� ����������� : ";
		cin >> f1.z;
	}
}


void enter_fraction(fraction& f1, fraction& f2)
{
	cout << "������ �����."<<endl;
	enter_fraction(f1);
	cout << "������ �����." << endl;
	enter_fraction(f2);

}


int NOK(int denominator1, int denominator2)
{
	int i = denominator1 < denominator2 ? denominator1 : denominator2;
	for (; i <= denominator1 * denominator2; i++)
	{
		if (i % denominator1 == 0 && i % denominator2 == 0)
			return i;
	}
}


int NOD(fraction f1)
{
	int nod = 1;

	for (int i = 2; i <= f1.c && i <= f1.z; i++)
	{
		if (f1.c % i == 0 && f1.z % i == 0)
			nod = i;
	}

	return nod;
}


int amount_chars(fraction& f)
{
	int count_1, count_2, t;

	count_1 = count_2 = 0;
	t = f.c;

	while (t > 0)
	{
		t /= 10;
		count_1++;
	}

	t = f.z;
	while (t > 0)
	{
		t /= 10;
		count_2++;
	}
	
	return count_1 > count_2 ? count_1 : count_2;
}