#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	//������� 1.1.1
	/*unsigned int x = 0x460C;
	cout << "�������� ���������� x:" << endl;
	cout << "x = " << hex << x << endl;
	cout << "���������� �������� �������� ���� � ����������� ������� �� ���� ��� (~0 << 5):" << endl;
	cout << hex << (~0 << 5) << endl;
	cout << "���������� �������� �������� ��������� � ����������� ������� �� ���� ��� (~(~0 << 5) << 7):" << endl;
	cout << hex << (~(~0 << 5) << 7) << endl;
	cout << "���������� �������� ���������� ��� ���������� x � ��������� (~(~0 << 5) << 7):" << endl;
	cout << hex << (x | (~(~0 << 5) << 7));*/
	//������� 1.1.2
	/*unsigned int x;
	unsigned int maska = 0;
	cout << "������������ ����������� ��� ������� �����" << endl;
	cout << "��������� ��� �������� �����: maska | (1 << 4) | (1 << 6) | (1 << 10)" << endl;
	maska = maska | (1 << 4) | (1 << 6) | (1 << 10);
	cout << "maska: " << hex << maska << endl;
	cin >> hex >> x;
	cout << "�������� ���������� x:" << endl;
	cout << "x = " << hex << x << endl;
	cout << "��������� ��������� (x & ~maska):" << endl;
	cout << hex << (x & ~maska);*/
	//������� 1.1.3
	/*unsigned int x;
	cin >> hex >> x;
	cout << "�������� x: " << hex << x << endl;
	cout << "��������� ��������� ��������� x �� 32: (x << 5)" << endl;
	cout << hex << (x << 5);*/
	//������� 1.1.4
	/*unsigned int x;
	cin >> hex >> x;
	cout << "�������� x: " << hex << x << endl;
	cout << "��������� ��������� ������� x �� 32: (x >> 5)" << endl;
	cout << hex << (x >> 5);*/
	//������� 1.1.5
	/*unsigned int x, n;
	cin >> hex >> x >> dec >> n;
	cout << "�������� x: " << hex << x << endl;
	cout << "�������� n: " << dec << n << endl;
	cout << "��������� ��������� �������� �������, �������� ��������� �� n - 1 ������ ~(1 << (n - 1)):" << endl;
	cout << hex << ~(1 << (n - 1)) << endl;
	cout << "��������� ��������� ���������� � ���������� x � ��������� ~(1 << (n - 1)):" << endl;
	cout << hex << (x & ~(1 << (n - 1)));*/
	//������� 1.2
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
	cout << endl << "����������" << endl;
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