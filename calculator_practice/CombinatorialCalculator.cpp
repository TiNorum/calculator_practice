#include "CombinatorialCalculator.h"
#include<iostream>

using namespace std;
long long int fact(long long int N)
{
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

int soch_without(int n, int m) {
    int C = 0;
    C = (fact(n)) / (fact(m) * (fact(n - m)));
    return C;
}
int soch_with(int n, int m) {
    long long int C = 0;
    C = (fact(n + m - 1)) / (fact(m) * fact(n - 1));

    return C;
}
int razm_without(int n, int m) {
    long long int A = 0;
    A = (fact(n)) / (fact(n - m));
    return A;
}
long long int razm_with(int n, int m) {
    long long int A = 0;

    A = pow(n, m);
    return A;
}
int perest(int n) {
    int P = 0;
    P = fact(n);
    return P;
}

void Menu_combinatorial_calculator()
{

        setlocale(LC_ALL, "ru");
        int n = 0, m = 0, v;
        cout << "Введите n и m (n>m)\n n=";
        cin >> n;
        cout << "m=";
        cin >> m;
        while (n <= 0 || m <= 0 || m > n) {
            cout << "Ошибка. Введите значения заново (n>0,m>0,n>m)\nn=";
            cin >> n;
            cout << "m=";
            cin >> m;
        }
        cout << "Выберите задание:\n 0- выход.\n 1- сочетание без повторений.\n 2- сочетание с повторениями.\n 3-размещение без повторений.\n 4-размещение с повторениями.\n 5-перестановки\n";
        do {
            cin >> v;
            while (v < 0 || v>5) {
                cout << "Введите номер от 1 до 5 или 0, чтобы выйти \n";
                cin >> v;
            }
            switch (v) {
            case 1: cout << "Ответ: " << soch_without(n, m) << endl; break;
            case 2: cout << "Ответ: " << soch_with(n, m) << endl; break;
            case 3: cout << "Ответ: " << razm_without(n, m) << endl; break;
            case 4: cout << "Ответ: " << razm_with(n, m) << endl; break;
            case 5: cout << "Ответ: " << perest(n) << endl; break;
            }
        } while (v != 0);

  
    }




