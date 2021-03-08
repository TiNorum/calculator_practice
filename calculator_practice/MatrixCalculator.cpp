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
	}

}

void matrixEnter(int (&matrixes)[10][10], int &matrixColumnSize, int &matrixLineSize, bool isMatrixSquare = false) {
	if (isMatrixSquare) {
		do {
			cout << endl << "Введите размер матрицы: ";
			cin >> matrixColumnSize;
			if (matrixColumnSize < 1) {
				cout << endl << "Размер не может быть меньше 1" << endl;
			}
		} while (matrixColumnSize < 1);

		for (int i = 0; i < matrixColumnSize; i++) {
			for (int j = 0; j < matrixColumnSize; j++) {
				matrixes[i][j] = 0;
			}
		}
	}
	else {
		do {
			cout << endl << "Введите количество столбцов матрицы: ";
			cin >> matrixColumnSize;
			if (matrixColumnSize < 1) {
				cout << endl << "Количество столбцов не может быть меньше 1" << endl;
			}
		} while (matrixColumnSize < 1);

		do {
			cout << endl << "Введите количество строк матрицы: ";
			cin >> matrixLineSize;
			if (matrixLineSize < 1) {
				cout << endl << "Количество столбцов не может быть меньше 1" << endl;
			}
		} while (matrixLineSize < 1);


		for (int i = 0; i < matrixColumnSize; i++) {
			for (int j = 0; j < matrixLineSize; j++) {
				matrixes[i][j] = 0;
			}
		}
	}
}

void matrixEnter(float(&matrixes)[10][10], int& matrixColumnSize, int& matrixLineSize, bool isMatrixSquare = false) {
	if (isMatrixSquare) {
		do {
			cout << endl << "Введите размер матрицы: ";
			cin >> matrixColumnSize;
			if (matrixColumnSize < 1) {
				cout << endl << "Размер не может быть меньше 1" << endl;
			}
		} while (matrixColumnSize < 1);

		for (int i = 0; i < matrixColumnSize; i++) {
			for (int j = 0; j < matrixColumnSize; j++) {
				matrixes[i][j] = 0;
			}
		}
	}
	else {
		do {
			cout << endl << "Введите количество столбцов матрицы: ";
			cin >> matrixColumnSize;
			if (matrixColumnSize < 1) {
				cout << endl << "Количество столбцов не может быть меньше 1" << endl;
			}
		} while (matrixColumnSize < 1);

		do {
			cout << endl << "Введите количество строк матрицы: ";
			cin >> matrixLineSize;
			if (matrixLineSize < 1) {
				cout << endl << "Количество столбцов не может быть меньше 1" << endl;
			}
		} while (matrixLineSize < 1);


		for (int i = 0; i < matrixColumnSize; i++) {
			for (int j = 0; j < matrixLineSize; j++) {
				matrixes[i][j] = 0;
			}
		}
	}
}

void matrixPrint(int matrix[10][10], int matrixColumnSize, int matrixLineSize) {
	cout << endl << "Итоговая матрица" << endl;
	for (int i = 0; i < matrixColumnSize; i++) {
		cout << endl;
		for (int j = 0; j < matrixLineSize; j++) {
			cout << matrix[i][j] << " ";
		}
	}
	cout << endl;

	system("pause");
}

void addition_matrix()
{
	int matrix[10][10];
	int matrixColumnSize, matrixLineSize, entryTempo;

	matrixEnter(matrix, matrixColumnSize, matrixLineSize);

	for (int s = 0; s < 2; s++) {
		cout << endl << "Введите матрицу" << endl;
		for (int i = 0; i < matrixColumnSize; i++) {
			for (int j = 0; j < matrixLineSize; j++) {
				cin >> matrix[i][j];
			}
		}
	}

	matrixPrint(matrix, matrixColumnSize, matrixLineSize);

	system("pause");
}

void subtraction_matrix()
{
	int matrix[10][10];
	int matrixColumnSize, matrixLineSize, entryTempo;

	matrixEnter(matrix, matrixColumnSize, matrixLineSize);

	for (int s = 0; s < 2; s++) {
		cout << endl << "Введите матрицу" << endl;
		for (int i = 0; i < matrixColumnSize; i++) {
			for (int j = 0; j < matrixLineSize; j++) {
				cin >> entryTempo;
				if (s == 0) {
					matrix[i][j] += entryTempo;
				}
				else {
					matrix[i][j] -= entryTempo;
				}
			}
		}
	}

	matrixPrint(matrix, matrixColumnSize, matrixLineSize);

}

void multiplication_matrix()
{
	int matrixes[3][10][10];
	int matrixColumnSize[3], matrixLineSize[3];

	do {
		matrixEnter(matrixes[0], matrixColumnSize[0], matrixLineSize[0]);
		matrixEnter(matrixes[1], matrixColumnSize[1], matrixLineSize[1]);
	} while (matrixColumnSize[0] != matrixLineSize[1]);
	

	for (int s = 0; s < 2; s++) {
		cout << endl << "Введите матрицу" << endl;
		for (int i = 0; i < matrixColumnSize[s]; i++) {
			for (int j = 0; j < matrixLineSize[s]; j++) {
				cin >> matrixes[s][i][j];
			}
		}
	}

	for (int i = 0; i < matrixColumnSize[0]; i++) {
		for (int j = 0; j < matrixLineSize[1]; j++) {
			matrixes[2][i][j] = 0;
			for (int k = 0; k < matrixLineSize[0]; k++) {
				matrixes[2][i][j] += matrixes[0][i][k] * matrixes[1][k][j];
			}
		}
	}

	matrixPrint(matrixes[2], matrixColumnSize[0], matrixLineSize[1]);

}

void multiplication_by_number()
{
	int matrix[10][10];
	int matrixColumnSize, matrixLineSize, number;

	cout << endl << "Введите число: ";
	cin >> number;

	matrixEnter(matrix, matrixColumnSize, matrixLineSize);

	cout << endl << "Введите матрицу" << endl;
	for (int k = 0; k < matrixColumnSize; k++) {
		for (int j = 0; j < matrixLineSize; j++) {
			cin >> matrix[k][j];
			matrix[k][j] *= number;
		}
	}

	matrixPrint(matrix, matrixColumnSize, matrixLineSize);

}

void multiplication_with_number()
{
}

void subtraction_with_number()
{
}

void matrix_transpose()
{
	int matrix[2][10][10];
	int matrixColumnSize, matrixLineSize;

	matrixEnter(matrix[0], matrixColumnSize, matrixLineSize);

	cout << endl << "Введите матрицу" << endl;
	for (int k = 0; k < matrixColumnSize; k++) {
		for (int j = 0; j < matrixLineSize; j++) {
			cin >> matrix[0][k][j];
			matrix[1][j][k] = matrix[0][k][j];
		}
	}

	matrixPrint(matrix[1], matrixColumnSize, matrixLineSize);
}

void inverse_matrix()
{
	float matrix[10][10];
	int matrixSize;

	matrixEnter(matrix, matrixSize, matrixSize, true);

	cout << endl << "Введите матрицу" << endl;
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cin >> matrix[i][j];
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

	system("pause");
}

void determinant()
{
	int matrix[10][10];
	int matrixSize;

	matrixEnter(matrix, matrixSize, matrixSize, true);

	cout << endl << "Введите матрицу" << endl;
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cin >> matrix[i][j];
		}
	}

	int p = 0, determinant = 0;
	for (int i = 0; i < matrixSize - 1; i++)
	{
		int t = 1;
		while (matrix[i][i] == 0)
		{
			for (int j = 0; j < matrixSize; j++)
			{
				matrix[i][j] = determinant;
				matrix[i][j] = matrix[i + t][j];
				matrix[i + t][j] = determinant;
			}
			p++;
			t++;
		}

		for (int k = i + 1; k < matrixSize; k++)
		{
			determinant = matrix[k][i] / matrix[i][i];
			for (int j = 0; j < matrixSize; j++)
				matrix[k][j] -= matrix[i][j] * determinant;
		}
	}

	determinant = pow(-1, p);

	for (int i = 0; i < matrixSize; i++) {
		determinant *= matrix[i][i];
	}

	cout << "Определитель равен: " << determinant;

	cout << endl;

	system("pause");
}
