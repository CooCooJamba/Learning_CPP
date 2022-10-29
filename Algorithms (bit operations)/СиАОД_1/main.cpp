#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	//Задание 1.1.1
	/*unsigned int x = 0x460C;
	cout << "Значение переменной x:" << endl;
	cout << "x = " << hex << x << endl;
	cout << "Выполнение операции инверсии нуля с последующим сдвигом на пять бит (~0 << 5):" << endl;
	cout << hex << (~0 << 5) << endl;
	cout << "Выполнение операции инверсии выражения с последующим сдвигом на семь бит (~(~0 << 5) << 7):" << endl;
	cout << hex << (~(~0 << 5) << 7) << endl;
	cout << "Выполнение операции побитового ИЛИ переменной x и выражения (~(~0 << 5) << 7):" << endl;
	cout << hex << (x | (~(~0 << 5) << 7));*/
	//Задание 1.1.2
	/*unsigned int x;
	unsigned int maska = 0;
	cout << "Формирование необходимой для задания маски" << endl;
	cout << "Выражение для создания маски: maska | (1 << 4) | (1 << 6) | (1 << 10)" << endl;
	maska = maska | (1 << 4) | (1 << 6) | (1 << 10);
	cout << "maska: " << hex << maska << endl;
	cin >> hex >> x;
	cout << "Значение переменной x:" << endl;
	cout << "x = " << hex << x << endl;
	cout << "Результат выражения (x & ~maska):" << endl;
	cout << hex << (x & ~maska);*/
	//Задание 1.1.3
	/*unsigned int x;
	cin >> hex >> x;
	cout << "Значение x: " << hex << x << endl;
	cout << "Результат выражения умножения x на 32: (x << 5)" << endl;
	cout << hex << (x << 5);*/
	//Задание 1.1.4
	/*unsigned int x;
	cin >> hex >> x;
	cout << "Значение x: " << hex << x << endl;
	cout << "Результат выражения деления x на 32: (x >> 5)" << endl;
	cout << hex << (x >> 5);*/
	//Задание 1.1.5
	/*unsigned int x, n;
	cin >> hex >> x >> dec >> n;
	cout << "Значение x: " << hex << x << endl;
	cout << "Значение n: " << dec << n << endl;
	cout << "Результат выражения инверсии единицы, побитово сдвинутой на n - 1 разряд ~(1 << (n - 1)):" << endl;
	cout << hex << ~(1 << (n - 1)) << endl;
	cout << "Результат выражения побитового И переменной x и выражения ~(1 << (n - 1)):" << endl;
	cout << hex << (x & ~(1 << (n - 1)));*/
	//Задание 1.2
	/*srand(time(0));
	setlocale(LC_ALL, "ru");
	const int n = 1024;
	int arr[n];
	for (int i = n - 1; i >= 0; i--) {
		arr[i] = n - 1 - i;
	}
	arr[0] = 0;
	arr[127] = 0;
	arr[255] = 0;
	arr[511] = 0;
	arr[1023] = 0;
	for (size_t i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	unsigned int bit[n / 32];
	for (size_t i = 0; i < size(bit); i++) {
		bit[i] = 0x0;
	}
	unsigned int maska = 0x80000000;
	for (size_t i = 0; i < n; i++) {
		bit[arr[i] >> 5] = bit[arr[i] >> 5] | (maska >> arr[i] ^ 32);
	}
	cout << endl << "Сортировка" << endl;
	for (size_t i = 0; i < size(bit); i++) {
		for (size_t j = 0; j < 32; j++) {
			if ((bit[i] & (maska >> j)) != 0) {
				arr[j + 32 * i] = j + 32 * i;
			}
			else {
				arr[j + 32 * i] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}*/
	return 0;
}