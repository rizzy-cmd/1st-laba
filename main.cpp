#pragma once
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;


//вводим union для float
union floatbits {
	float f;
	unsigned int bits;
};
//вводим union для double
union doublebits {
	double d;
	long long unsigned int bits_d;
};


//функция вывода битов int
void printBitsInt(int a) {
	const int orderInt = sizeof(int) * 8;
	int sign = (a >> (orderInt - 1)) & 1;
	cout << "[" << sign << "]" << " ";
	for (int i = orderInt - 1; i >= 0; i--) {
		if (a & (1 << i)) {
			cout << "1";
		}
		else {
			cout << "0";
		}
		if (((orderInt - i) % 4) == 0 and (i != 0)) {
			cout << " ";
		}
	}
}

//функция вывода битов float
void printBitsFloat(float f) {
	int orderFloat = sizeof(float) * 8;
	floatbits u;
	u.f = f;
	for (int i = orderFloat - 1; i >= 0; i--) {
		if (i == orderFloat - 1) {
			cout << "[Sign]";
		}
		if (u.bits & (1 << i)) {
			cout << "1";
		}
		else {
			cout << "0";
		}
		if (i == (orderFloat - 1)) {
			cout << " [Exp]";
		}
		if (i == (orderFloat - (1 + 8))) {
			cout << " [Mant]";
		}
	}
}

//функция вывода битов double
void printBitsDouble(double d) {
	int orderDouble = sizeof(double) * 8;
	doublebits u2;
	u2.d = d;
	for (int i = orderDouble - 1; i >= 0; i--) {
		if (i == orderDouble - 1) {
			cout << "[Sign]";
		}
		if (u2.bits_d >> i & 1) {
			cout << "1";
		}
		else {
			cout << "0";
		}
		if (i == (orderDouble - 1)) {
			cout << " [Exp]";
		}
		if (i == (orderDouble - (1 + 11))) {
			cout << " [Mant]";
		}
	}
}

//функция побитового изменения числа
unsigned long long editbit() {
	string tip;
	cout << "Выберите тип числа:\nЦелое (введите cl)\nFloat (введите fl)\nDouble (введите db)" << endl;
	cin >> tip;
	cout << "Введите число:" << endl;

	if (tip == "cl") {
		int cl;
		cin >> cl;

		cout << "Было: ";
		printBitsInt(cl);
		cout << endl;

		int n;
		cout << "Введите индекс битa:" << endl;
		cin >> n;

		string deistv;
		cout << "Выберите действие:\nУстановить (уст) \nСбросить (сбр) \nИнвертировать (инв)" << endl;
		cin >> deistv;

		int result = cl;
		if (deistv == "уст") result = cl | (1ULL << n);
		else if (deistv == "сбр") result = cl & ~(1ULL << n);
		else if (deistv == "инв") result = cl ^ (1ULL << n);

		cout << "Стало: ";
		printBitsInt(result);
		cout << endl;

		return result;
	}

	if (tip == "fl") {
		float ft;
		cin >> ft;
		floatbits uf;
		uf.f = ft;

		cout << "Было: ";
		printBitsFloat(uf.f);
		cout << endl;

		int n;
		cout << "Введите индекс битa:" << endl;
		cin >> n;

		string deistv;
		cout << "Выберите действие:\nУстановить (уст) \nСбросить (сбр) \nИнвертировать (инв)" << endl;
		cin >> deistv;

		if (deistv == "уст") uf.bits |= (1ULL << n);
		else if (deistv == "сбр") uf.bits &= ~(1ULL << n);
		else if (deistv == "инв") uf.bits ^= (1ULL << n);

		cout << "Стало: ";
		printBitsFloat(uf.f);
		cout << endl;

		return uf.bits;
	}

	if (tip == "db") {
		double db;
		cin >> db;
		doublebits ud;
		ud.d = db;

		cout << "Было: ";
		printBitsDouble(ud.d);
		cout << endl;

		int n;
		cout << "Введите индекс битa:" << endl;
		cin >> n;

		string deistv;
		cout << "Выберите действие:\nУстановить (уст) \nСбросить (сбр) \nИнвертировать (инв)" << endl;
		cin >> deistv;

		if (deistv == "уст") ud.bits_d |= (1ULL << n);
		else if (deistv == "сбр") ud.bits_d &= ~(1ULL << n);
		else if (deistv == "инв") ud.bits_d ^= (1ULL << n);

		cout << "Стало: ";
		printBitsDouble(ud.d);
		cout << endl;

		return ud.bits_d;
	}

	return 0;
}

//индивидуальное задание: проверка чётности
long long makeEven(long long x) {
	return x & ~1LL;
}
int main()
{// 1.выводим размер разных типов данных
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "size of bool        = " << sizeof(bool) << " byte" << endl;
	cout << "size of char        = " << sizeof(char) << " byte" << endl;
	cout << "size of short int   = " << sizeof(short int) << " byte" << endl;
	cout << "size of int         = " << sizeof(int) << " byte" << endl;
	cout << "size of long int    = " << sizeof(long int) << " byte" << endl;
	cout << "size of float       = " << sizeof(float) << " byte" << endl;
	cout << "size of double      = " << sizeof(double) << " byte" << endl;
	cout << "size of long double = " << sizeof(long double) << " byte" << endl;



	// 2. выводим двоичное представление целого числа
	int a;
	cout << "Введитe целое число:" << endl;
	cin >> a;
	cout << "Биты: ";
	printBitsInt(a);
	cout << endl;


	//3.выводим двоичное представление float:

	floatbits u;
	//запрашиваем float число
	cout << "Введите число float:" << endl;
	cin >> u.f;
	cout << "u.bits = " << u.bits << endl;
	cout << "u.f = " << u.f << endl;
	cout << "Биты: ";
	printBitsFloat(u.f);
	cout << endl;

	//4 выводим двоичное представление doudle:

	doublebits u2;
	//запрашиваем double число
	cout << "Введите число double:" << endl;
	cin >> u2.d;
	cout << "u2.bits_d = " << u2.bits_d << endl;
	cout << "u2.d = " << u2.d << endl;
	cout << "Биты: ";
	printBitsDouble(u2.d);
	cout << endl;

	//5 реализовываем изменение произвольного бита в числе:
	unsigned long long Result = editbit();
	cout << "Результат: " << Result << endl;

	//индивидуальное задание: проверка чётности
	long long testNum;
	cout << "Введите целое число:" << endl;
	cin >> testNum;

	cout << "Было: " << testNum << " (";
	if (testNum & 1) cout << "нечётное";
	else cout << "чётное";
	cout << ")" << endl;

	cout << "Стало: " << makeEven(testNum) << " (чётное)" << endl;

	return 0;
}