#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdio.h>
using namespace std;
void createFile() {
	cout << "Введите путь к файлу." << endl;
	string path;
	cin >> path;
	ofstream file;
	file.open(path, fstream::app | fstream::in | fstream::out);
	if (file.is_open()) {
		cout << "Файл создан." << endl;
		cout << "Сколько значений внести в файл?" << endl;
		int n;
		cin >> n;
		int value;
		for (size_t i = 0; i < n; i++) {
			cout << "Введите число." << endl;
			cin >> value;
			file << value << " ";
			if (i % 4 == 3) {
				file << endl;
			}
		}
	}
	else {
		cout << "Не удалось открыть файл." << endl;
		cout << "Попробуйте ещё раз." << endl;
		createFile();
	}
	if (file.good()) {
		cout << "Операция прошла успешно." << endl;
	}
	file.close();
	cout << "Файл закрыт." << endl;
}
void readFile() {
	cout << "Введите путь к файлу." << endl;
	string path;
	cin >> path;
	ifstream file;
	file.open(path);
	if (file.is_open()) {
		cout << "Файл открыт." << endl;
		cout << "Данные файла:" << endl;
		string str;
		while (getline(file, str)) {
			cout << str << endl;
		}
	}
	else {
		cout << "Не удалось открыть файл." << endl;
		cout << "Попробуйте ещё раз." << endl;
		readFile();
	}
	cout << "Операция прошла успешно." << endl;
	file.close();
	cout << "Файл закрыт." << endl;
}
void addValueFile() {
	cout << "Введите путь к файлу." << endl;
	string path;
	cin >> path;
	ofstream file;
	file.open(path, fstream::app);
	if (file.is_open()) {
		cout << "Файл открыт." << endl;
		cout << "Сколько значений внести в файл?" << endl;
		int n;
		cin >> n;
		int value;
		for (size_t i = 0; i < n; i++) {
			cout << "Введите число." << endl;
			cin >> value;
			file << value << " ";
			if (i % 4 == 3) {
				file << endl;
			}
		}
	}
	else {
		cout << "Не удалось открыть файл." << endl;
		cout << "Попробуйте ещё раз." << endl;
		addValueFile();
	}
	if (file.good()) {
		cout << "Операция прошла успешно." << endl;
	}
	file.close();
	cout << "Файл закрыт." << endl;
}
string findValueFile(int index) {
	cout << "Введите путь к файлу." << endl;
	string path;
	cin >> path;
	ifstream file;
	file.open(path);
	if (file.is_open()) {
		cout << "Файл открыт." << endl;
		string value;
		int i = 0;
		while (!file.eof()) {
			i++;
			value = "не";
			file >> value;
			if (index == i) {
				cout << "Операция прошла успешно." << endl;
				file.close();
				cout << "Файл закрыт." << endl;
				return value;
			}
		}
		cout << "Операция прошла успешно." << endl;
		file.close();
		cout << "Файл закрыт." << endl;
		return value;
	}
	else {
		cout << "Не удалось открыть файл." << endl;
		cout << "Попробуйте ещё раз." << endl;
		findValueFile(index);
	}
}
int countValuesFile() {
	cout << "Введите путь к файлу." << endl;
	string path;
	cin >> path;
	ifstream file;
	file.open(path);
	if (file.is_open()) {
		cout << "Файл открыт." << endl;
		int i = 0;
		string str;
		while (!file.eof()) {
			file >> str;
			i++;
		}
		cout << "Операция прошла успешно." << endl;
		file.close();
		cout << "Файл закрыт." << endl;
		return (i - 1);
	}
	else {
		cout << "Не удалось открыть файл." << endl;
		cout << "Попробуйте ещё раз." << endl;
		countValuesFile();
	}
}
bool deleteValueFile(int index) {
	cout << "Введите путь к файлу." << endl;
	string path;
	cin >> path;
	ifstream file_old;
	ofstream file_new;
	file_old.open(path);
	file_new.open("temp.txt");
	if (file_old.is_open()) {
		cout << "Файл открыт." << endl;
		int i = 0;
		string value;
		if (index == 0) {
			if (file_new.good()) {
				cout << "Операция прошла успешно." << endl;
			}
			file_old.close();
			file_new.close();
			cout << "Файл закрыт." << endl;
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
			rename("C:/Users/vlads/source/repos/СиАОД_2/СиАОД_2/temp.txt", path.c_str());
			if (file_new.good()) {
				cout << "Операция прошла успешно." << endl;
			}
			cout << "Файл закрыт." << endl;
			return false;
		}
		file_old.close();
		file_new.close();
		remove(path.c_str());
		rename("C:/Users/vlads/source/repos/СиАОД_2/СиАОД_2/temp.txt", path.c_str());
	}
	else {
		cout << "Не удалось открыть файл." << endl;
		cout << "Попробуйте ещё раз." << endl;
		deleteValueFile(index);
	}
	if (file_new.good()) {
		cout << "Операция прошла успешно." << endl;
	}
	cout << "Файл закрыт." << endl;
	return true;
}