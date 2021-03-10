#include "MatrixCalculator.h"
#include <iostream>
#define MAX_ROW 20
#define MAX_COL 20

using namespace std;

struct Matrix {
	double array[MAX_ROW][MAX_COL]{};
	int columnsAmount = 0, rowsAmount = 0;
};

void Menu_matrix_calculator()
{
	bool quite = false;
	while (!quite)
	{
		system("cls");
		cout << "\t\t\tМатричный калькултор:" << endl;
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

void matrixEnter(Matrix& matrix, bool isMatrixSquare = false) {
	if (isMatrixSquare) {
		do {
			cout << "Введите размер матрицы: ";
			cin >> matrix.columnsAmount;
			if (matrix.columnsAmount < 1 || matrix.columnsAmount> MAX_COL) {
				cout << "Размер  может быть только от 1 до 20" << endl;
			}
		} while (matrix.columnsAmount < 1 || matrix.columnsAmount> MAX_COL);
	}
	else {
		do {
			cout << "Введите количество столбцов матрицы: " << endl;
			cin >> matrix.columnsAmount;
			if (matrix.columnsAmount < 1 || matrix.columnsAmount> MAX_COL) {
				cout << "Размер  может быть только от 1 до 20" << endl;
			}
		} while (matrix.columnsAmount < 1 || matrix.columnsAmount> MAX_COL);

		do {
			cout << "Введите количество строк матрицы: "<< endl;
			cin >> matrix.rowsAmount;
			if (matrix.rowsAmount < 1 || matrix.rowsAmount> MAX_ROW) {
				cout << "Размер  может быть только от 1 до 20" << endl;
			}
		} while (matrix.rowsAmount < 1 || matrix.rowsAmount> MAX_ROW);
	}
}

void matrixPrint(Matrix matrix) {

	cout << "\nИтоговая матрица";

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

	for (int s = 0; s < 2; s++) {
		cout << "Введите матрицу " << s + 1 << ":" << endl;
		for (int i = 0; i < matrix.rowsAmount; i++) {
			for (int j = 0; j < matrix.columnsAmount; j++) {
				cin >> entryTempo;
				if (s == 0) {
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
		cout << "\nМатрица 1:\n";
		matrixEnter(matrix[0]);

		cout << "\nМатрица 2:\n";
		matrixEnter(matrix[1]);

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

	cout << "\nВведите число: ";
	cin >> number;

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

	matrixEnter(matrix, true);

	cout << "\nВведите матрицу\n";
	for (int i = 0; i < matrix.columnsAmount; i++) {
		for (int j = 0; j < matrix.columnsAmount; j++) {
			cin >> matrix.array[i][j];
		}
	}

	/*for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < 2 * matrixSize; j++) {
			// Добавление 1 в диагональных местах
			// матрицы для создания идентичности

			if (j == (i + matrixSize)) {
				matrix[i][j] = 1;
			}
		}
	}

	// Меняем строку матрицы,
	// смена ряда начнется с последнего ряда

	float temp;

	for (int i = matrixSize - 1; i > 0; i--) {
		// Меняем местами каждый элемент двух строк
		if (matrix [i - 1] [0] <matrix [i] [0])
		for (int j = 0; j < 2 * matrixSize; j ++) {
			// Перестановка строки, если выше
			// условие выполнено.

			temp = matrix [i] [j];
			matrix [i] [j] = matrix [i - 1] [j];
			matrix [i - 1] [j] = temp;
		}

		// Прямой обмен строк с помощью указателей экономит время

		if (matrix[i - 1][0] < matrix[i][0]) {
			int temp = matrix[i][0];
			matrix[i][0] = matrix[i - 1][0];
			matrix[i - 1][0] = temp;
		}
	}

	// Замена строки на сумму самой себя и
	// константы, кратной другой строке матрицы

	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			if (j != i) {
				temp = matrix[j][i] / matrix[i][i];

				for (int k = 0; k < 2 * matrixSize; k++) {
					matrix[j][k] -= matrix[i][k] * temp;
				}
			}
		}
	}

	// Умножаем каждую строку на ненулевое целое число.
	// Делим элемент строки по диагональному элементу

	for (int i = 0; i < matrixSize; i++) {
		temp = matrix[i][i];

		for (int j = 0; j < 2 * matrixSize; j++) {
			matrix[i][j] = matrix[i][j] / temp;
		}
	}

	//Выводим результирующую обратную матрицу.

	cout << "\nОБРАТНАЯ МАТРИЦА\n";
	for (int i = 0; i < matrixSize; i++) {
		for (int j = matrixSize; j < 2 * matrixSize; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << endl;
}

void determinant()
{
	Matrix matrix;
	int matrixSize;

	matrixEnter(matrix, true);

	cout << "\nВведите матрицу\n";
	for (int i = 0; i < matrix.columnsAmount; i++) {
		for (int j = 0; j < matrix.columnsAmount; j++) {
			cin >> matrix.array[i][j];
		}
	}

	int p = 0, determinant = 0;
	for (int i = 0; i < matrix.columnsAmount - 1; i++)
	{
		int t = 1;
		while (matrix.array[i][i] == 0)
		{
			for (int j = 0; j < matrix.columnsAmount; j++)
			{
				matrix.array[i][j] = determinant;
				matrix.array[i][j] = matrix.array[i + t][j];
				matrix.array[i + t][j] = determinant;
			}
			p++;
			t++;
		}

		for (int k = i + 1; k < matrix.columnsAmount; k++)
		{
			determinant = matrix.array[k][i] / matrix.array[i][i];
			for (int j = 0; j < matrix.columnsAmount; j++)
				matrix.array[k][j] -= matrix.array[i][j] * determinant;
		}
	}

	determinant = pow(-1, p);

	for (int i = 0; i < matrix.columnsAmount; i++) {
		determinant *= matrix.array[i][i];
	}

	cout << "Определитель равен: " << determinant << endl;

}
