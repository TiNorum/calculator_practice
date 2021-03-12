#include "MatrixCalculator.h"
#include <iostream>
#define MAX_ROW 20
#define MAX_COL 20

using namespace std;

struct Matrix {
	double array[MAX_ROW][MAX_COL]{};
	int columnsAmount = 0, rowsAmount = 0, size = 0;
};

void Menu_matrix_calculator()
{
	bool quite = false;
	while (!quite)
	{
		system("cls");
		cout << "\t\t\tМатричный калькулятор:" << endl;
		cout << "1)Сложение матриц" << endl;
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
		system("cls");

		switch (a)
		{
		case 1:
			addition_matrix();
			break;
		case 2:
			subtraction_matrix();
			break;
		case 3:
			multiplication_matrix();
			break;
		case 4:
			multiplication_by_number();
			break;
		case 5:
			break;
		case 6:
			matrix_transpose();
			break;
		case 7:
			inverse_matrix();
			break;
		case 8:
			determinant();
			break;
		case 0:
			quite = true;
			break;
		}
		system("Pause");
	}
}

void matrixEnter(Matrix& matrix) {
	do {
		cout << "Введите количество столбцов матрицы: ";
		cin >> matrix.columnsAmount;
		if (matrix.columnsAmount < 1 || matrix.columnsAmount> MAX_COL) {
			cout << "\nРазмер  может быть только от 1 до 20\n";
		}
	} while (matrix.columnsAmount < 1 || matrix.columnsAmount> MAX_COL);

	do {
		cout << "Введите количество строк матрицы: ";
		cin >> matrix.rowsAmount;
		if (matrix.rowsAmount < 1 || matrix.rowsAmount> MAX_ROW) {
			cout << "\nРазмер  может быть только от 1 до 20\n";
		}
	} while (matrix.rowsAmount < 1 || matrix.rowsAmount> MAX_ROW);
}

void matrixPrint(Matrix matrix) {
	cout << "\nИтоговая матрица\n";

	for (int i = 0; i < matrix.rowsAmount; i++) {
		cout << endl;
		for (int j = 0; j < matrix.columnsAmount; j++) {
			cout << matrix.array[i][j] << " ";
		}
	}

	cout << endl;
}

void addition_matrix()
{
	Matrix matrix;
	int entryTempo;

	matrixEnter(matrix);

	for (int s = 0; s < 2; s++) {
		cout << "Введите матрицу " << s + 1 << ":" << endl;
		for (int i = 0; i < matrix.rowsAmount; i++) {
			for (int j = 0; j < matrix.columnsAmount; j++) {
				cin >> entryTempo;
				matrix.array[i][j] += entryTempo;
			}
		}
	}

	matrixPrint(matrix);
}

void subtraction_matrix()
{
	Matrix matrix;
	int entryTempo;

	matrixEnter(matrix);

	for (int n = 0; n < 2; n++) {
		cout << "Введите матрицу " << n + 1 << ":" << endl;
		for (int i = 0; i < matrix.rowsAmount; i++) {
			for (int j = 0; j < matrix.columnsAmount; j++) {
				cin >> entryTempo;
				if (n == 0) {
					matrix.array[i][j] += entryTempo;
				}
				else {
					matrix.array[i][j] -= entryTempo;
				}
			}
		}
	}

	matrixPrint(matrix);
}

void multiplication_matrix()
{
	Matrix matrix[3];

	do {
		for (int n = 0; n < 2; n++) {
			cout << "Матрица " << n+1 <<":\n";
			matrixEnter(matrix[n]);
			cout << endl;
		}

		if (matrix[0].columnsAmount != matrix[1].rowsAmount) {
			cout << "\nКоличество столбцов в первой матрице, должно совпадать с количеством строк во второй матрице\n";
		}
	} while (matrix[0].columnsAmount != matrix[1].rowsAmount);

	for (int s = 0; s < 2; s++) {
		cout << "Введите матрицу " << s + 1 << ":" << endl;
		for (int i = 0; i < matrix[s].columnsAmount; i++) {
			for (int j = 0; j < matrix[s].rowsAmount; j++) {
				cin >> matrix[s].array[i][j];
			}
		}
	}

	for (int i = 0; i < matrix[0].columnsAmount; i++) {
		for (int j = 0; j < matrix[1].rowsAmount; j++) {
			for (int k = 0; k < matrix[0].rowsAmount; k++) {
				matrix[2].array[i][j] += matrix[0].array[i][k] * matrix[1].array[k][j];
			}
		}
	}

	matrix[2].columnsAmount = matrix[0].columnsAmount;
	matrix[2].rowsAmount = matrix[1].rowsAmount;
	matrixPrint(matrix[2]);
}

void multiplication_by_number()
{
	Matrix matrix;
	double number;

	cout << "Введите число: ";
	cin >> number;
	cout << endl;

	matrixEnter(matrix);

	cout << "\nВведите матрицу\n";
	for (int k = 0; k < matrix.columnsAmount; k++) {
		for (int j = 0; j < matrix.rowsAmount; j++) {
			cin >> matrix.array[k][j];
			matrix.array[k][j] *= number;
		}
	}

	matrixPrint(matrix);
}

void matrix_transpose()
{
	Matrix matrix[2];
	int matrixColumnSize, matrixLineSize;

	matrixEnter(matrix[0]);

	cout << "\nВведите матрицу\n";
	for (int k = 0; k < matrix[0].rowsAmount; k++) {
		for (int j = 0; j < matrix[0].columnsAmount; j++) {
			cin >> matrix[0].array[k][j];
			matrix[1].array[j][k] = matrix[0].array[k][j];
		}
	}

	matrix[1].columnsAmount = matrix[0].rowsAmount;
	matrix[1].rowsAmount = matrix[0].columnsAmount;
	matrixPrint(matrix[1]);
}

void inverse_matrix()
{
	Matrix matrix;
	do {
		cout << "\nВведите размер матрицы: ";
		cin >> matrix.size;
		cout << endl;
		if (matrix.size < 1) {
			cout << "\nРазмер матрицы не может быть меньше 1\n";
		}
	} while (matrix.size < 1);

	cout << "\nВведите матрицу\n";
	for (int i = 0; i < matrix.size; i++) {
		for (int j = 0; j < matrix.size; j++) {
			cin >> matrix.array[i][j];
		}
	}

	double temp;
	double newMatrix[MAX_ROW][MAX_COL];

	for (int i = 0; i < matrix.size; i++) {
		for (int j = 0; j < matrix.size; j++)
		{
			newMatrix[i][j] = 0;
			if (i == j) {
				newMatrix[i][j] = 1;
			}				
		}
	}

	for (int k = 0; k < matrix.size; k++) {
		temp = matrix.array[k][k];

		for (int j = 0; j < matrix.size; j++)
		{
			matrix.array[k][j] /= temp;
			newMatrix[k][j] /= temp;
		}

		for (int i = k + 1; i < matrix.size; i++)
		{
			temp = matrix.array[i][k];

			for (int j = 0; j < matrix.size; j++)
			{
				matrix.array[i][j] -= matrix.array[k][j] * temp;
				newMatrix[i][j] -= newMatrix[k][j] * temp;
			}
		}
	}

	for (int k = matrix.size - 1; k > 0; k--) {
		for (int i = k - 1; i >= 0; i--)
		{
			temp = matrix.array[i][k];

			for (int j = 0; j < matrix.size; j++)
			{
				matrix.array[i][j] -= matrix.array[k][j] * temp;
				newMatrix[i][j] -= newMatrix[k][j] * temp;
			}
		}
	}

	cout << "\nОбратная матрица\n";
	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++) {
			cout << newMatrix[i][j] << "  ";
		}
		cout << endl;
	}
}

// Determinant

void matrixWithoutRowAndCol(double matrix[MAX_ROW][MAX_COL], int size, int column, double newMatrix[MAX_ROW][MAX_COL]) {
	int offsetCol = 0;
	for (int i = 0; i < size - 1; i++) {
		offsetCol = 0;
		for (int j = 0; j < size - 1; j++) {
			if (j == column) {
				offsetCol = 1;
			}
			newMatrix[i][j] = matrix[i + 1][j + offsetCol];
		}
	}
}

double matrixDet(double matrix[MAX_ROW][MAX_COL], int size) {
	double det = 0;
	int degree = 1;

	if (size == 1) {
		return matrix[0][0];
	}
	else if (size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else {
		double newMatrix[MAX_ROW][MAX_COL];
		for (int j = 0; j < size; j++) {
			matrixWithoutRowAndCol(matrix, size, j, newMatrix);

			det += degree * matrix[0][j] * matrixDet(newMatrix, size - 1);

			degree = -degree;
		}

	}

	return det;
}

void determinant()
{
	Matrix matrix;
	do {
		cout << "\nВведите размер матрицы: ";
		cin >> matrix.size;
		cout << endl;
		if (matrix.size < 1) {
			cout << "\nРазмер матрицы не может быть меньше 1\n";
		}
	} while (matrix.size < 1);

	
	cout << "\nВведите матрицу\n";
	for (int i = 0; i < matrix.size; i++) {
		for (int j = 0; j < matrix.size; j++) {
			cin >> matrix.array[i][j];
		}
	}

	cout << "Определитель равен: " << matrixDet(matrix.array, matrix.size) << endl;
}
