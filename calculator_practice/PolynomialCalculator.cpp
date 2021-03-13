#include "PolynomialCalculator.h"
using namespace std;


struct polynom {
	double* a;
	int d; //������� ����������

	void setDegree(int n)
	{
		d = n;
		a = new double[n + 1];
	}

	double getA(int index)
	{
		if (index > d)
			return 0;

		return a[index];
	}

	~polynom() {
		delete[]a;
	}
};


void enter_poly(polynom& p1);
void enter_poly(polynom& p1, polynom& p2);
void print_poly(polynom& p1);


void Menu_polynomial_calculator()
{
	bool quite = 0;
	while (!quite)
	{
		system("cls");
		cout << "\t\t\t����������� �����������:" << endl;
		cout << "1)������� ����������� � �������" << endl;
		cout << "2)�������� �����������" << endl;
		cout << "3)��������� �����������" << endl;
		cout << "4)��������� �����������" << endl;
		cout << "5)��������� ����������� �� �����" << endl;
		cout << "6)���������� ����������� �� ����������" << endl;
		cout << "0)�����" << endl;
		cout << "�������� ����� �������: ";
		unsigned short a;

		cin >> a;
		system("cls");

		switch (a)
		{
		case 1:
			cout << "\t\t������� ����������� � �������" << endl << endl;
			div_poly();
			system("pause");
			break;
		case 2:
			cout << "\t\t�������� �����������" << endl << endl;
			sum_poly();
			system("pause");
			break;
		case 3:
			cout << "\t\t��������� �����������" << endl << endl;
			minus_poly();
			system("pause");
			break;
		case 4:
			cout << "\t\t��������� �����������" << endl << endl;
			multi_poly();
			system("pause");
			break;
		case 5:
			cout << "\t\t��������� ����������� �� �����" << endl << endl;
			multi_num_poly();
			system("pause");
			break;
		case 6:
			cout << "\t\t���������� ����������� �� ����������" << endl << endl;
			deriv_poly();
			system("pause");
			break;
		case 0:
			quite = true;
			break;
	
		}
	}

}



void div_poly() {
	polynom p1, p2, result;

	
	enter_poly(p1, p2);

	if (p1.a[p1.d] == 0)
	{
		cout << "������� ���� ���������� �������� �� ����� ���� 0" << endl;
		return;
	}

	if (p2.a[p2.d] == 0)
	{
		cout << "������� ���� ���������� �������� �� ����� ���� 0"<<endl;
		return;
	}


	result.setDegree(p1.d - p2.d);

	if (result.d <= 0)
	{
		cout << "���������� ���������� �������";
		return;
	}

	for (int i = 0; i < result.d; i++) {
		result.a[i] = 0;
	}

	for (int i = p1.d; i >= 0; i--) {
		if (p1.a[i] == 0) continue;

		double temp = p1.a[i] / p2.a[p2.d];

		int t = i - p2.d;
		if (t < 0) break;

		result.a[t] = temp;

		for (int j = 0; j <= p2.d; j++) {
			p1.a[t + j] -= temp * p2.a[j];
		}

		cout << endl << "���������:" << endl;
		print_poly(result);
		cout << endl << "�������:" << endl;
		print_poly(p1);
	}

	cout << endl << "���������:" <<endl;
	print_poly(result);
	cout << endl << "�������:"<<endl;
	print_poly(p1);


}


void sum_poly()
{
	polynom p1, p2, result;

	enter_poly(p1, p2);

	result.setDegree(p1.d > p2.d ? p1.d : p2.d);

	for (int i = 0; i <= result.d; i++)
	{
		result.a[i] = p1.getA(i) + p2.getA(i);
	}

	cout << endl << "���������: " << endl;

	print_poly(result);
}


void minus_poly()
{
	polynom p1, p2, result;

	enter_poly(p1, p2);

	result.setDegree(p1.d > p2.d ? p1.d : p2.d);

	for (int i = 0; i <= result.d; i++)
	{
		result.a[i] = p1.getA(i) - p2.getA(i);
	}

	cout << endl << "���������: " << endl;

	print_poly(result);
}


void multi_poly()
{
	polynom p1, p2, result;

	enter_poly(p1, p2);

	result.setDegree( p1.d + p2.d);

	for (int i = 0; i <= result.d; i++)
	{
		result.a[i] = 0;
	}

	for (int i = 0; i <= p2.d; i++)
	{
		for (int j = 0; j <= p1.d; j++)
		{
			result.a[i + j] += p1.a[j] * p2.a[i];
		}
	}

	cout << endl << "���������: " << endl;

	print_poly(result);
}


void multi_num_poly()
{
	polynom p1, result;

	enter_poly(p1);

	result.setDegree(p1.d);

	int n;

	cout << "������� �����, �� ������� ���������� ���������: ";
	cin >> n;

	for (int i = 0; i <= p1.d; i++)
	{
			result.a[i] = p1.a[i] * n;
	}

	cout << endl << "���������: " << endl;

	print_poly(result);
}


void deriv_poly() {
	polynom p1, result;

	enter_poly(p1);

	result.setDegree(p1.d-1);

	
	for (int i = 0; i <= result.d; i++)
	{
		result.a[i] = p1.a[i+1] * (i+1);
	}

	cout << endl << "���������: " << endl;

	print_poly(result);
}

void print_poly(polynom& p)
{
	cout << endl << p.a[0];
	if (p.getA(1))
	{
		if (p.a[1] >= 0)
			cout << " + ";
		else
			cout << " - ";
		cout << abs(p.a[1]) << "x";
	}

	for (int i = 2; i <= p.d; i++)
	{
		if (p.a[i] == 0) continue;

			if (p.a[i] >= 0)
				cout << " + ";
			else
				cout << " - ";

		cout << abs(p.a[i]) << "x^" << i;
	}

	cout << endl;
}


void enter_poly(polynom &p1)
{
	int n;

	while (1)
	{
		cout << "������� ������� ����������: ";
		cin >> n;
		if (n <= 0)
		{
			cout << endl << " �������� ���������� ������ ���� ������ 0" << endl << endl;
		}
		else break;
	}

	p1.setDegree(n);


	cout << endl << "������� ������� � ������� ����������� �������!"<<endl;

	for (int i = 0; i <= n; i++)
	{
		cout << "a*x^" << i << "  a= ";
		cin >> p1.a[i];
	}
	cout << endl;
	
}


void enter_poly(polynom& p1, polynom& p2)
{
	cout << "������ ���������" << endl;
	enter_poly(p1);
	cout << "������ ���������" << endl;
	enter_poly(p2);
}