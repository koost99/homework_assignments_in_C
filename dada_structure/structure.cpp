#include <iostream>
using namespace std;

/*======================================*/
void translate(int a) {
	int acc;
	int sc=1;
	acc = (a % 2) * sc;
	sc *= 10;
	a = a / 2;
	if (a > 0)
	{
		translate(a);
	}
	cout << acc;
}
void translatestart() {
	cout << "функция перевода числа из десятичной системы в двоичную.\n";
	cout << "Введите число: ";
	int a;
	cin >> a;
	translate(a);
	cout << "\n";
}
/*======================================*/
void degree(int a, int b, int acc) {
	if (b>0)
	{
		acc = acc*a;
		b -= 1;
		degree(a,b, acc);
	}
	else {
		cout << acc << endl;
	}
}
/*======================================*/
void degree1(int a, int b, int acc) {
	if (b>0)
	{
		if (b % 2 == 0)
		{
			acc *= acc;
			b %= 2;
			degree1(a, b, acc);
		}
		else {
			acc *= a;
			b -= 1;
			degree1(a, b, acc);
		}
	}
	else {
		cout << acc << endl;
	}
}

/*======================================*/
void degreestart(int num) {
	switch (num)
	{
	case(1): 
		{int a, b, acc = 1;
		cin >> a >> b;
		degree(a, b, acc);
		break;
		}
	case(2): 
		{int a, b, acc = 1;
		cin >> a >> b;
		acc = a;
		degree1(a, b, acc);
		break;
		}
	default:break;
	}
}
/*======================================*/
void chessking() {

}
/*======================================*/
int main()
{
    setlocale(LC_ALL, "Ru");
	int sw = 0;
	cout << "В данной программе реализовано четыре функции. для проверки конкретной введите номер задаия цифрой\n";
	cout << "\n";
		while (sw != -1) {
			cout << "Введите номер задания: ";
			cin >> sw;
			switch (sw)
			{
			case 1: {cout << "Задание 1\n"; translatestart();	break; }
			case 2: {cout << "Задание 2\n"; degreestart(1); break; }
			case 3: {cout << "Задание 3\n";	degreestart(2); break; }
			case 4: {cout << "Задание 4\n";	chessking(); break; }
			case 5: {cout << "Условие выхода\n"; sw = -1; break; }
			default: cout << "такого задания нет.\n"; break;
			}
		}
}

