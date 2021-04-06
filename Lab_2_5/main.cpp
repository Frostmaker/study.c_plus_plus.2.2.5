#include <iostream>
#include "bignum.h"

using namespace std;

int main()
{
	// Конструктор по умолчанию
	BigInt bn1;
	cout << bn1 << "\n\n";
	
	// Конструктор по числу
	BigInt bn2(98765);
	cout << bn2 << '\n';
	BigInt bn3(-12345);
	cout << bn3 << "\n\n";

	// Конструктор по строке
	BigInt bn4("220304");
	cout << bn4 << '\n';
	BigInt bn5("-123754234536");
	cout << bn5 << "\n\n";

	// Конструктор копирования
	BigInt bn6(bn2);
	cout << bn6 << '\n';
	BigInt bn7(bn3);
	cout << bn7 << "\n\n";

	// Доступ к длине и знаку
	cout << bn4.length() << '\n';
	cout << bn4.mark() << '\n';
	cout << bn5.length() << '\n';
	cout << bn5.mark() << "\n\n";

	// Индексирование
	cout << bn4[1] << bn4[2] << '\n';
	cout << bn4 << '\n';
	bn4[1] = 5;
	cout << bn4 << '\n';
	const BigInt bn8(bn4);
	cout << bn8[1] << bn8[2] << "\n\n";
	
	// Операция ввода
	//BigInt bn9;
	//cin >> bn9;
	//cout << bn9 << "\n\n";

	// Оператор присваивания
	BigInt bn10 = bn8;
	cout << bn10 << "\n\n";

	// Операторы сравнения
	cout << bn10 << " == " << bn8 << " ?  -  " << (bn10 == bn8) << '\n';
	cout << bn1 << " == " << bn2 << " ?  -  " << (bn1 == bn2) << '\n';
	cout << bn10 << " != " << bn8 << " ?  -  " << (bn10 != bn8) << '\n';
	cout << bn1 << " != " << bn2 << " ?  -  " << (bn1 != bn2) << "\n\n";

	cout << bn10 << " > " << bn8 << " ?  -  " << (bn10 > bn8) << '\n';
	cout << bn10 << " > " << bn5 << " ?  -  " << (bn10 > bn5) << '\n';
	cout << bn5 << " > " << bn10 << " ?  -  " << (bn5 > bn10) << "\n\n";

	cout << bn10 << " < " << bn8 << " ?  -  " << (bn10 < bn8) << '\n';
	cout << bn10 << " < " << bn5 << " ?  -  " << (bn10 < bn5) << '\n';
	cout << bn5 << " < " << bn10 << " ?  -  " << (bn5 < bn10) << "\n\n";
	
	cout << bn10 << " >= " << bn8 << " ?  -  " << (bn10 >= bn8) << '\n';
	cout << bn10 << " >= " << bn5 << " ?  -  " << (bn10 >= bn5) << '\n';
	cout << bn5 << " >= " << bn10 << " ?  -  " << (bn5 >= bn10) << "\n\n";

	cout << bn10 << " <= " << bn8 << " ?  -  " << (bn10 <= bn8) << '\n';
	cout << bn10 << " <= " << bn5 << " ?  -  " << (bn10 <= bn5) << '\n';
	cout << bn5 << " <= " << bn10 << " ?  -  " << (bn5 <= bn10) << "\n\n";


	// Приведение к типу int
	int res = static_cast<int>(bn2);
	cout << "BigInt -> int: " << res << '\n';
	res = static_cast<int>(bn3);
	cout << "BigInt -> int: " << res << "\n\n";


	string s = static_cast<string>(bn2);
	cout << "BigInt -> string: " << s << '\n';
	s = static_cast<string>(bn3);
	cout << "BigInt -> string: " << s << "\n\n";

	// Арифметика
	BigInt bn12(100);
	BigInt bn13(-25);
	BigInt bn14;

	bn14 = (bn12 + bn13);
	cout << bn12 << " + " << bn13 << " = " << bn14 << '\n';
	cout << bn14 << " + " << bn13 << " = ";
	bn14 += bn13;
	cout << bn14 << "\n\n";
	cout << "(-)" << bn14 << " = ";
	cout << (-bn14) << "\n\n";

	BigInt bn15(bn12 - bn13);
	cout << bn12 << " - " << bn13 << " = " << bn15 << '\n';
	cout << bn15 << " - " << bn14 << " = ";
	bn15 -= bn14;
	cout << bn15 << '\n';

	BigInt bn16("3");
	cout << bn15 << " * " << bn16 << " = ";
	bn15 = bn15 * bn16;
	cout << bn15 << '\n';
	cout << bn15 << " * " << bn16 << " = ";
	bn15 *= bn16;
	cout << bn15 << "\n\n";

	cout << bn15 << " / " << bn16 << " = ";
	bn15 = bn15 / bn16;
	cout << bn15 << '\n';
	cout << bn15 << " / " << bn16 << " = ";
	bn15 /= bn16;
	cout << bn15 << "\n\n";

	cout << bn15 << " % " << bn16 << " = ";
	bn15 %= bn16;
	cout << bn15 << '\n';
	cout << bn15 << " % " << bn16 << " = ";
	bn15 = bn15 % bn16;
	cout << bn15 << "\n\n";

	// Простота
	BigInt bn19("19");
	BigInt bn18("18");
	cout << bn18 << " is prime? - " << bn18.is_prime() << '\n';
	cout << bn19 << " is prime? - " << bn19.is_prime() << "\n\n";

	// НОД
	BigInt bn17(10080);
	BigInt bn20("2646");
	cout << "GCD of " << bn17 << " and " << bn20 << " is " << gcd(bn17, bn20) << "\n\n";

	// 100!
	BigInt answ(1);

	for (int i(2); i < 100; ++i) {
		BigInt temp(i);
		answ *= temp;
	}

	cout << "100! = " << answ << "\n\n";
	return EXIT_SUCCESS;
}