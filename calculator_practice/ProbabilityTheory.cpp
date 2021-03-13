#include  "ProbabilityTheory.h"
#include <iostream>
using namespace std;


void Menu_probability_theory()
{
	bool quite = 0;
	while (!quite)
	{
		system("cls");
		cout << "\t\tТерория вероятности и мат. статистика:" << endl;
		cout << "1)Вероятность наступления единичного события" << endl;
		cout << "2)Вероятность наступления множественного события" << endl;
		cout << "3)Дисперсия для дискретного распределения величин" << endl;
		cout << "4)Мат.ожидание для дискретного распределения величин" << endl;
		cout << "0)Выход" << endl;
		cout << "Выберите номер задания: ";
		unsigned short a;

		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
			prob_1();
			system("pause");
			break;
		case 2:
			prob_2();
			system("pause");
			break;

		case 3:
			Variance();
			system("pause");
			break;

		case 4:
			Mat_waiting();
			system("pause");
			break;
		case 0: 
			quite = true;
			break;
		}
	}

}

void prob_1()
{
	int n, m;

	cout << "\t\tВероятность наступления единичного события" << endl << endl;

	while (1) {
		
		cout << "Количество возможных исходов: ";
		cin >> n;
		cout << "Количество наступивших событий: ";
		cin >> m;
		if (n < 0 || m < 0 || n < m)
		{
			system("cls");
			cout << "\t\tВероятность наступления единичного события" << endl<<endl;
			cout << "Количество наступивших событий всегда меньше, чем число возможных исходов." << endl<<endl;
			
		}
		else break;
	} 

	cout << "Вероятность наступившего события P(A): " << (double)m / n<<endl;
	cout << "Вероятность ненаступившего события P(A'): " << 1 - (double)m / n << endl<<endl;
}

void prob_2()
{
	int n, A,B;

	cout << "\t\tВероятность наступления множественного события" << endl << endl;

	while (1) {
		
		cout << "Количество возможных исходов: ";
		cin >> n;
		cout << "Количество наступивших событий A: ";
		cin >> A;
		cout << "Количество наступивших событий B: ";
		cin >> B;

		if (n < 0 || A < 0 || n < A || B < 0 || n < B)
		{
			system("cls");
			cout << "\t\tВероятность наступления множественного события" << endl << endl;
			cout << "Количество наступивших событий всегда меньше, чем число возможных исходов." << endl << endl;
		}
		else break;
	}

	cout << endl;
	cout << "Вероятность наступившего события P(A): " << (double)A / n << endl;
	cout << "Вероятность наступившего события P(B): " << (double)B / n << endl;
	cout << "Вероятность того, что оба события происходят: " << ((double)A / n) * ((double)B / n) << endl;
	cout << "Вероятность того, что любой из случае возникает: " << (double)B / n + (double)A / n - ((double)A/n) * ((double)B / n) << endl<<endl;
}

void Variance()
{
	double* P;
	double* X;
	int N = 0;

	while (1)
	{
		cout << "\t\tДисперсия для дискретного распределения величин" << endl<<endl;
		cout << "Введите количество величин: ";
		cin >> N;

		if (N <= 0)
		{
			system("cls");
			cout << "\t\tДисперсия для дискретного распределения величин" << endl << endl;
			cout << "Количество величин должно быть больше 0" << endl << endl;
		}
		else break;
	}
	
	P = new double[N];
	X = new double[N];

	cout << endl << "Введите значения X:" << endl;

	for (int i = 0; i < N; i++) {
		cout << "Введите X[" << i + 1 << "]: ";
		cin >> X[i];
	}

	cout << endl << "Введите значения P:" << endl;

	while (1)
	{
		double p =0;

		for (int i = 0; i < N; i++) {
			cout << "Введите P[" << i + 1 << "]: ";
			cin >> P[i];
			p+=P[i];
		}

		if (p != 1)
		{
			cout << endl << "Суммарная вероятность должна быть равна 1!" << endl << endl;
		}
		else
			break;
	}
	

	double MX2 = 0;
	double MX = 0;

	for (int i = 0; i < N; i++) {
		MX2 += X[i] * X[i] * P[i];
	}

	for (int i = 0; i < N; i++) {
		MX += X[i] * P[i];
	}
	
	cout << "D = " << MX2 - MX* MX<<endl << endl;

	delete[] P;
	delete[] X;
}

void Mat_waiting()
{
	double* P;
	double* X;
	int N = 0;

	while (1)
	{
		cout << "\t\tМат.ожидание для дискретного распределения величин" << endl << endl;
		cout << "Введите количество величин: ";
		cin >> N;

		if (N <= 0)
		{
			system("cls");
			cout << "\t\tМат.ожидание для дискретного распределения величин" << endl << endl;
			cout << "Количество величин должно быть больше 0" << endl << endl;
		}
		else break;
	}

	P = new double[N];
	X = new double[N];

	cout << endl << "Введите значения X:" << endl;

	for (int i = 0; i < N; i++) {
		cout << "Введите X[" << i + 1 << "]: ";
		cin >> X[i];
	}

	cout << endl << "Введите значения P:" << endl;

	for (int i = 0; i < N; i++) {
		cout << "Введите P[" << i + 1 << "]: ";
		cin >> P[i];
		if (P[i] <= 0 || P[i] > 1)
		{
			cout << "P принимает значения (0;1]" << endl;
			i--;
		}
	}


	double M = 0;

	for (int i = 0; i < N; i++) {
		M += X[i] * P[i];
	}
	
	cout <<endl << "М[x]=" << M<<endl<<endl;

	delete[] P;
	delete[] X;
}
