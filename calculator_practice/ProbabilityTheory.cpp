#include  "ProbabilityTheory.h"
#include <iostream>
using namespace std;

void Menu_probability__theory()
{
	bool quite = 0;
	while (!quite)
	{
		system("cls");
		cout << "\t\tТерория вероятности и мат. статистика:" << endl;
		cout << "1)Вероятность m/n" << endl;
		cout << "2)Дисперсия для дискретного распределения величин" << endl;
		cout << "3)Мат.ожидание для дискретного распределения величин" << endl;
		cout << "4)Выход" << endl;
		cout << "Выберите номер задания: ";
		unsigned short a;

		cin >> a;
		switch (a)
		{
		case 1:
			Probability();
			break;

		case 2:
			Variance();
			break;

		case 3:
			Mat_waiting();
			break;
		case 0: 
			quite = true;
			break;
		}
	}

}

void Probability()
{
}

void Variance()
{
}

void Mat_waiting()
{
}
