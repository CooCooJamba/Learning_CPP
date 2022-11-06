#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdio.h>
using namespace std;
struct Session {
	int key;
	char name[30];
	char film[30];
	char date[30];
	char time[30];
	char cost[30];
};
void createSessionFile() {
	srand(time(0));
	cout << "Укажите имя исходного файла." << endl;
	string path;
	cin >> path;
	fstream file(path, ios::app | ios::in | ios::out);
	cout << "Сколько записей будет в файле?" << endl;
	int n;
	cin >> n;
	char names[10][30] = { "Логос", "Планета", "Звезда", "Афиша", "Зритель", "Экран", "Океан", "Линза", "Аврора", "Мечта" };
	char films[10][30] = { "Шрек", "Аватар", "Стартрек", "Оно", "Челюсти", "Веном", "Тролли", "Аквамен", "Варкрафт", "Дюна" };
	char dates[10][11] = { "21.05.2022", "22.05.2022", "23.05.2022", "24.05.2022", "25.05.2022", "26.05.2022", "27.05.2022", "28.05.2022", "29.05.2022", "30.05.2022" };
	char times[10][6] = { "10:30", "09:00", "19:00", "15:30", "12:30", "09:00", "21:00", "16:00", "09:00", "07:30" };
	char costs[10][10] = { "500", "600", "700", "550", "650", "750", "400", "450", "350", "300" };
	for (size_t i = 0; i < n; i++) {
		if (i != 0) {
			file << endl;
		}
		file << i + 1 << endl;
		file << names[rand() % 10] << endl;
		file << films[rand() % 10] << endl;
		file << dates[rand() % 10] << endl;
		file << times[rand() % 10] << endl;
		file << costs[rand() % 10];
	}
	cout << "Файл создан." << endl;
	file.close();
	cout << "Файл закрыт." << endl;
};
void createBinaryFile() {
	cout << "Введите путь к исходному файлу." << endl;
	string path;
	cin >> path;
	ifstream ifile(path);
	cout << "Введите название бинарного файла." << endl;
	string path_b;
	cin >> path_b;
	ofstream ofile(path_b, ios::in | ios::out | ios::trunc | ios::binary);
	if (ifile.is_open()) {
		cout << "Файл открыт." << endl;
		Session session;
		while (!ifile.eof()) {
			ifile >> session.key;
			ifile >> session.name;
			ifile >> session.film;
			ifile >> session.date;
			ifile >> session.time;
			ifile >> session.cost;
			ofile.write((char*)&session, sizeof(Session));
		}
	}
	else {
		cout << "Не удалось открыть файл." << endl;
		cout << "Попробуйте ещё раз." << endl;
		createBinaryFile();
	}
	cout << "Операция прошла успешно." << endl;
	ifile.close();
	ofile.close();
	cout << "Файл закрыт." << endl;
};
void readBinaryFile() {
	cout << "Введите путь к файлу для чтения." << endl;
	string path;
	cin >> path;
	ifstream file;
	file.open(path, ios::out | ios::binary);
	if (file.is_open()) {
		cout << "Файл открыт." << endl;
		cout << "Данные файла:" << endl;
		Session session;
		file.read((char*)&session, sizeof(Session));
		while (!file.eof()) {
			cout << session.key << endl;
			cout << session.name << endl;
			cout << session.film << endl;
			cout << session.date << endl;
			cout << session.time << endl;
			cout << session.cost << endl;
			file.read((char*)&session, sizeof(Session));
		}
	}
	else {
		cout << "Не удалось открыть файл." << endl;
		cout << "Попробуйте ещё раз." << endl;
		readBinaryFile();
	}
	cout << "Операция прошла успешно." << endl;
	file.close();
	cout << "Файл закрыт." << endl;
};
void removeEntry(int key) {
	cout << "Введите путь к файлу сеансов." << endl;
	string path;
	cin >> path;
	fstream file(path, ios::out | ios::in | ios::binary);
	Session session;
	int t = sizeof(session);
	file.seekg(-t, ios::end);
	file.read((char*)&session, sizeof(Session));
	int tp = --key * sizeof(session);
	file.seekp(tp, ios::beg);
	file.write((char*)&session, sizeof(Session));
	file.close();
	cout << "Файл закрыт." << endl;
};
void insertEntry() {
	cout << "Введите путь к файлу сеансов, в который нужно добавить запись." << endl;
	string path;
	cin >> path;
	fstream file(path, ios::out | ios::in | ios::binary);
	Session session;
	int t = sizeof(session);
	file.seekg(-t, ios::end);
	file.read((char*)&session, sizeof(Session));
	session.key++;
	cout << "Введите название кинотеатра." << endl;
	cin >> session.name;
	cout << "Введите название фильма." << endl;
	cin >> session.film;
	cout << "Введите дату сеанса." << endl;
	cin >> session.date;
	cout << "Введите время сеанса." << endl;
	cin >> session.time;
	cout << "Введите стоимость билета." << endl;
	cin >> session.cost;
	file.write((char*)&session, sizeof(Session));
	file.close();
	cout << "Файл закрыт." << endl;
};
void readEntry(Session& s, int key) {
	cout << "Введите путь к файлу сеансов." << endl;
	string path;
	cin >> path;
	fstream file(path, ios::out | ios::in | ios::binary);
	file.seekg(key * sizeof(s), ios::beg);
	file.read((char*)&s, sizeof(Session));
	cout << s.key << endl;
	cout << s.name << endl;
	cout << s.film << endl;
	cout << s.date << endl;
	cout << s.time << endl;
	cout << s.cost << endl;
	file.close();
	cout << "Файл закрыт." << endl;
};
int findEntry(int key) {
	cout << "Введите путь к файлу сеансов." << endl;
	string path;
	cin >> path;
	fstream file(path, ios::out | ios::in | ios::binary);
	Session s;
	key--;
	file.seekg(key * sizeof(s), ios::beg);
	file.read((char*)&s, sizeof(Session));
	file.close();
	cout << "Файл закрыт." << endl;
	return s.key;
};
void testBinF() {
	//создание обычного файла
	//createSessionFile();
	//создание бинарного файла
	createBinaryFile();
	//чтение бинарного файла
	readBinaryFile();
	//удаление записи из бинарного файла
	//removeEntry(2);
	//readBinaryFile();
	//добавление записи в бинарный файл
	//insertEntry();
	//readBinaryFile();
	//поиск записи в бинарном файле
	//Session session;
	//readEntry(session, 3);
};