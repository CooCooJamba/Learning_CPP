#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdio.h>
using namespace std;
void createFile() {
	cout << "������� ���� � �����." << endl;
	string path;
	cin >> path;
	ofstream file;
	file.open(path, fstream::app | fstream::in | fstream::out);
	if (file.is_open()) {
		cout << "���� ������." << endl;
		cout << "������� �������� ������ � ����?" << endl;
		int n;
		cin >> n;
		int value;
		for (size_t i = 0; i < n; i++) {
			cout << "������� �����." << endl;
			cin >> value;
			file << value << " ";
			if (i % 4 == 3) {
				file << endl;
			}
		}
	}
	else {
		cout << "�� ������� ������� ����." << endl;
		cout << "���������� ��� ���." << endl;
		createFile();
	}
	if (file.good()) {
		cout << "�������� ������ �������." << endl;
	}
	file.close();
	cout << "���� ������." << endl;
}
void readFile() {
	cout << "������� ���� � �����." << endl;
	string path;
	cin >> path;
	ifstream file;
	file.open(path);
	if (file.is_open()) {
		cout << "���� ������." << endl;
		cout << "������ �����:" << endl;
		string str;
		while (getline(file, str)) {
			cout << str << endl;
		}
	}
	else {
		cout << "�� ������� ������� ����." << endl;
		cout << "���������� ��� ���." << endl;
		readFile();
	}
	cout << "�������� ������ �������." << endl;
	file.close();
	cout << "���� ������." << endl;
}
void addValueFile() {
	cout << "������� ���� � �����." << endl;
	string path;
	cin >> path;
	ofstream file;
	file.open(path, fstream::app);
	if (file.is_open()) {
		cout << "���� ������." << endl;
		cout << "������� �������� ������ � ����?" << endl;
		int n;
		cin >> n;
		int value;
		for (size_t i = 0; i < n; i++) {
			cout << "������� �����." << endl;
			cin >> value;
			file << value << " ";
			if (i % 4 == 3) {
				file << endl;
			}
		}
	}
	else {
		cout << "�� ������� ������� ����." << endl;
		cout << "���������� ��� ���." << endl;
		addValueFile();
	}
	if (file.good()) {
		cout << "�������� ������ �������." << endl;
	}
	file.close();
	cout << "���� ������." << endl;
}
string findValueFile(int index) {
	cout << "������� ���� � �����." << endl;
	string path;
	cin >> path;
	ifstream file;
	file.open(path);
	if (file.is_open()) {
		cout << "���� ������." << endl;
		string value;
		int i = 0;
		while (!file.eof()) {
			i++;
			value = "��";
			file >> value;
			if (index == i) {
				cout << "�������� ������ �������." << endl;
				file.close();
				cout << "���� ������." << endl;
				return value;
			}
		}
		cout << "�������� ������ �������." << endl;
		file.close();
		cout << "���� ������." << endl;
		return value;
	}
	else {
		cout << "�� ������� ������� ����." << endl;
		cout << "���������� ��� ���." << endl;
		findValueFile(index);
	}
}
int countValuesFile() {
	cout << "������� ���� � �����." << endl;
	string path;
	cin >> path;
	ifstream file;
	file.open(path);
	if (file.is_open()) {
		cout << "���� ������." << endl;
		int i = 0;
		string str;
		while (!file.eof()) {
			file >> str;
			i++;
		}
		cout << "�������� ������ �������." << endl;
		file.close();
		cout << "���� ������." << endl;
		return (i - 1);
	}
	else {
		cout << "�� ������� ������� ����." << endl;
		cout << "���������� ��� ���." << endl;
		countValuesFile();
	}
}
bool deleteValueFile(int index) {
	cout << "������� ���� � �����." << endl;
	string path;
	cin >> path;
	ifstream file_old;
	ofstream file_new;
	file_old.open(path);
	file_new.open("temp.txt");
	if (file_old.is_open()) {
		cout << "���� ������." << endl;
		int i = 0;
		string value;
		if (index == 0) {
			if (file_new.good()) {
				cout << "�������� ������ �������." << endl;
			}
			file_old.close();
			file_new.close();
			cout << "���� ������." << endl;
			return false;
		}
		while (!file_old.eof()) {
			i++;
			value = "";
			file_old >> value;
			if (index != i) {
				file_new << value << " ";
				if (i % 4 == 0) {
					file_new << endl;
				}
			}
		}
		if (index > (i - 1)) {
			file_old.close();
			file_new.close();
			remove(path.c_str());
			rename("C:/Users/vlads/source/repos/�����_2/�����_2/temp.txt", path.c_str());
			if (file_new.good()) {
				cout << "�������� ������ �������." << endl;
			}
			cout << "���� ������." << endl;
			return false;
		}
		file_old.close();
		file_new.close();
		remove(path.c_str());
		rename("C:/Users/vlads/source/repos/�����_2/�����_2/temp.txt", path.c_str());
	}
	else {
		cout << "�� ������� ������� ����." << endl;
		cout << "���������� ��� ���." << endl;
		deleteValueFile(index);
	}
	if (file_new.good()) {
		cout << "�������� ������ �������." << endl;
	}
	cout << "���� ������." << endl;
	return true;
}