#include "CombinatorialCalculator.h"

using namespace std;


void Menu_combinatorial_calculator()
{
	bool quite = 0;

	while (!quite)
	{
		system("cls");
		cout << "\t\t\tКалькулятор формул комбинаторики:" << endl;
		cout << "1)Размещение с повторением" << endl;
		cout << "2)Размещение без повторением" << endl;
		cout << "3)Сочитание с повторением" << endl;
		cout << "4)Сочитание без повторением" << endl;
		cout << "5)Перестановки" << endl;		
		cout << "0)Выход" << endl;
		cout << "Выберите номер задания: ";
		unsigned short a;

		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
			razm_with();
			system("pause");
			break;
		case 2:
			razm_without();
			system("pause");
			break;
		case 3:
			soch_with();
			system("pause");
			break;
		case 4:
			soch_without();
			system("pause");
			break;
		case 5:
			perest();
			system("pause");
			break;
		case 0:
			quite = true;
			break;
		}
	}
}


void razm_with()
{
	unsigned int n, m;
	enter_date(n, m);
	cout << "Ответ: " << pow(n, m)<<endl;
}


void razm_without()
{
	unsigned int n, m;
	enter_date(n, m);
	cout << "Ответ: " << (fact(n)) / (fact(n - m))<<endl;
}


void soch_with()
{
	unsigned int n, m;
	enter_date(n, m);
	
	cout << "Ответ: " << (fact(n + m - 1)) / (fact(m) * fact(n - 1)) <<endl;
}


void soch_without()
{
	unsigned int n, m;
	enter_date(n, m);
	cout << "Ответ: " << (fact(n)) / (fact(m) * (fact(n - m)))<<endl;
}


void perest()
{
	unsigned int n;

	do {
		cout << " Введите n > 0:";
		cin >> n;
	} while (n <= 0);

	cout << "Ответ: " << fact(n)<<endl;
}


unsigned long long int fact(unsigned long long int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}


void enter_date(unsigned int &n, unsigned int &m)
{
	cout << "Введите n и m (n>m)\n n=";
	cin >> n;
	cout << "m=";
	cin >> m;

	do{
		cout << "\tОшибка." << endl << "Введите значения заново (n>0,m>0,n>m)" << endl;
		cout << "Введите n: ";
		cin >> n;
		cout << "Введите m: ";
		cin >> m;
	} while (n <= 0 || m <= 0 || m >= n);
}