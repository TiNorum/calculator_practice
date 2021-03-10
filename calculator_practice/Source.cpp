#include <iostream>
#include "CalculatorObDrob.h"
#include "CombinatorialCalculator.h"
#include "Functions.h"
#include "MatrixCalculator.h"
#include "PolynomialCalculator.h"
#include "ProbabilityTheory.h"

using namespace std;
int  main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RU");

	bool quite = false;

	while (!quite)
	{
		system("cls");
		cout << "\t\t\t����:" << endl;
		cout << "1)��������� �����������" << endl;
		cout << "2)����������� ������������ ������" << endl;
		cout << "3)����������� ������ �������������" << endl;
		cout << "4)����������� �����������" << endl;
		cout << "5)���. ���. � ���. ����������" << endl;
		cout << "6)������ � ���������" << endl;
		cout << "0)�����" << endl;
		cout << "�������� ����� �������: ";
		unsigned short a;

		cin >> a;
		switch (a)
		{
		case 1:
			Menu_matrix_calculator();
			break;
		case 2:
			Menu_calculator_ob_drob();
			break;
		case 3:
			Menu_combinatorial_calculator();
			break;
		case 4:
			Menu_polynomial_calculator();
			break;
		case 5:
			Menu_probability__theory();
			break;
		case 6:
			Menu_functions();
			break;
		case 0:
			quite = true;
			break;
		}
	}

	return 0;
}