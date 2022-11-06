#pragma once
#include "hashTableManagement.h"
#include "binaryFileManagement.h"
void new_cell(hashTable& hT, int num) {
	Session s;
	readEntry(s, num);
	if (s.key) insert(hT, s.key);
	cout << "������ �� ����� ������� � ���-�������" << endl;
}
void remove_cell(hashTable& hT, int key) {
	remove(hT, key);
	removeEntry(key);
	readBinaryFile();
	cout << "������ ������� �� ����� � ���-�������" << endl;
}
int find_cell(hashTable& hT, int key) {
	Session s;
	int index = find(hT, key);
	if (index == -1) return -1;
	int number = findEntry(index) - 1;
	readEntry(s, number);
	cout << "������� ������ � ������ ���-������� ��� ��������: "
		<< index << "\n������� ������ � ������ ����� ��� �������: "
		<< number + 1 << "\n������ ������: "
		<< s.name << '\t' << s.film << '\t'
		<< s.date << '\t' << s.time
		<< '\t' << s.cost << '\n';
	return 0;
}
void testFinal() {
	hashTable hT;
	//������ ������ �� ����� � ������� �������� � ���-�������
	cout << "������ ������ �� ����� � ������� �������� � ���-�������." << endl;
	new_cell(hT, 0);
	new_cell(hT, 1);
	new_cell(hT, 2);
	new_cell(hT, 3);
	new_cell(hT, 4);
	new_cell(hT, 5);
	cout << "���-������� ����� ������� � �� �������." << endl;
	print_table(hT);
	//�������� ������ �� ���-������� ��� �������� �������� ����� � �������������� �� �����
	cout << "�������� ������ �� ���-������� ��� �������� �������� ����� � �������������� �� �����." << endl;
	remove_cell(hT, 5);
	cout << "�������� ���� ����� �������� �� ���� ������." << endl;
	readBinaryFile();
	cout << "���-������� ����� �������� �� �� ������." << endl;
	print_table(hT);
	//���������� ������ � ����� �� �������� �����
	cout << "���������� ������ � ����� �� �������� �����." << endl;
	find_cell(hT, 2);
	find_cell(hT, 5);
};