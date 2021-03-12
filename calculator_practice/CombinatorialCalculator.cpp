#include "CombinatorialCalculator.h"

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
	cout << "�����: " << pow(n, m)<<endl;
}


void razm_without()
{
	unsigned int n, m;
	enter_date(n, m);
	cout << "�����: " << (fact(n)) / (fact(n - m))<<endl;
}


void soch_with()
{
	unsigned int n, m;
	enter_date(n, m);
	
	cout << "�����: " << (fact(n + m - 1)) / (fact(m) * fact(n - 1)) <<endl;
}


void soch_without()
{
	unsigned int n, m;
	enter_date(n, m);
	cout << "�����: " << (fact(n)) / (fact(m) * (fact(n - m)))<<endl;
}


void perest()
{
	unsigned int n;

	do {
		cout << " ������� n > 0:";
		cin >> n;
	} while (n <= 0);

	cout << "�����: " << fact(n)<<endl;
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
	cout << "������� n � m (n>m)\n n=";
	cin >> n;
	cout << "m=";
	cin >> m;

	do{
		cout << "\t������." << endl << "������� �������� ������ (n>0,m>0,n>m)" << endl;
		cout << "������� n: ";
		cin >> n;
		cout << "������� m: ";
		cin >> m;
	} while (n <= 0 || m <= 0 || m >= n);
}