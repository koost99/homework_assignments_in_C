#include <iostream>

using namespace std;

int massive[2][2][2], *ptr; // массив 3х3х3 и ссылка на него


extern int a; // переменные инициализированны в файле Source.cpp
extern int b;
extern int c;
extern int d;

int e; // переменная оппала по случайности, но показывает, что локальная ф-ция ее перекрывает.


int main() {

	float e = (a*(b+(c/ static_cast<float>(d)))); // "Кастомагия по сишному и по плюсному"

	cout << e << endl;
	e = (a * (b + (c / d)));

	cout << e << endl;
	e = (a * (b + (c / float(d))));

	cout << e << endl;

	/*==========================================*/

	e = (c <= 21) ? 21 - c : (c - 21) * 2; // магия присваивания тернарным (по моему так он называется) оператором.
	cout << e << endl;

	/*==========================================*/

	massive[1][1][1] = 100;				// целочисленный массив и адресация к нему (Гарри Поттер и ...)
	ptr = &massive[0][0][0];
	cout << ptr << ' ' << &massive[0][0][0] << endl;
	cout << *(ptr + 7) << ' ' << massive[1][1][1] << endl;

	*(ptr + 7) = 70;
		
	cout << ptr + 7 << ' ' << &massive[1][1][1] << endl;
	cout << *(ptr+7) << ' ' << massive[1][1][1] << endl;
	
	

	return 0;
}
