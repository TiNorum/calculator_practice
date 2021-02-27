#include "MatrixCalculator.h"
#include<iostream>
using namespace std;

void Menu_matrix_calculator()
{
	bool quite = false;
	while (!quite)
	{
		system("cls");
		cout << "\t\t\tМатричный калькултор:" << endl;
		cout << "1)Сложение матриц"<<endl;
		cout << "2)Вычитание матриц" << endl;
		cout << "3)Умножение матриц" << endl;
		cout << "4)Умножение матриц на число" << endl;
		cout << "5)Сложение матрицы с числом" << endl;
		cout << "6)Транспонирование матрицы" << endl; 
		cout << "7)Обратная матрица" << endl;
		cout << "8)Определитель" << endl;
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
		case 7:
			break;
		case 8:
			break;
		case 0:
			quite = true;
			break;
		}
	}

}

void addition_matrix()
{
}

void subtraction_matrix()
{
}

void multiplication_matrix()
{
}

void multiplication_by_number()
{
}

void multiplication_with_number()
{
}

void subtraction_with_number()
{
}

void matrix_transpose()
{
}

void inverse_matrix()
{
}

void determinant()
{
}
