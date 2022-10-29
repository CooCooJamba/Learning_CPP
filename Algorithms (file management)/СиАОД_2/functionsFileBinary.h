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
	char date[11];
	char time[30];
	char cost[30];
};
void readSessionFile() {
	cout << "������� ���� � ����� ��� ������." << endl;
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
		readSessionFile();
	}
	cout << "�������� ������ �������." << endl;
	file.close();
	cout << "���� ������." << endl;
}
void createBinaryFile() {
	cout << "������� ���� � ��������� �����." << endl;
	string path;
	cin >> path;
	ifstream ifile(path);
	cout << "������� �������� ��������� �����." << endl;
	string path_b;
	cin >> path_b;
	ofstream ofile(path_b, ios::in | ios::out | ios::trunc | ios::binary);
	if (ifile.is_open()) {
		cout << "���� ������." << endl;
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
		cout << "�� ������� ������� ����." << endl;
		cout << "���������� ��� ���." << endl;
		createBinaryFile();
	}
	cout << "�������� ������ �������." << endl;
	ifile.close();
	ofile.close();
	cout << "���� ������." << endl;
}
void readBinaryFile() {
	cout << "������� ���� � ����� ��� ������." << endl;
	string path;
	cin >> path;
	ifstream file;
	file.open(path, ios::out | ios::binary);
	if (file.is_open()) {
		cout << "���� ������." << endl;
		cout << "������ �����:" << endl;
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
		cout << "�� ������� ������� ����." << endl;
		cout << "���������� ��� ���." << endl;
		readBinaryFile();
	}
	cout << "�������� ������ �������." << endl;
	file.close();
	cout << "���� ������." << endl;
}
void increaseCost() {
	Session temp;
	cout << "������� ���� � ����� ��� ���������� ��������� ������." << endl;
	cin >> temp.date;
	cin >> temp.time;
	cout << "������� ����� ��������� ������." << endl;
	cin >> temp.cost;
	cout << "������� ���� � ����� �������." << endl;
	string path;
	cin >> path;
	fstream file(path, ios::out | ios::in | ios::binary);
	ofstream ofile("temp.txt", ios::trunc | ios::out | ios::in | ios::binary);
	Session session;
	file.read((char*)&session, sizeof(Session));
	while (!file.eof()) {
		if (session.date[0] == temp.date[0] &&
			session.date[1] == temp.date[1] &&
			session.date[3] == temp.date[3] &&
			session.date[4] == temp.date[4] &&
			session.date[6] == temp.date[6] &&
			session.date[7] == temp.date[7] &&
			session.date[8] == temp.date[8] &&
			session.date[9] == temp.date[9] &&
			session.time[0] == temp.time[0] &&
			session.time[1] == temp.time[1] &&
			session.time[3] == temp.time[3] &&
			session.time[4] == temp.time[4]) {
			session.cost[0] = temp.cost[0];
			session.cost[1] = temp.cost[1];
			session.cost[2] = temp.cost[2];
			session.cost[3] = temp.cost[3];
		}
		ofile.write((char*)&session, sizeof(Session));
		file.read((char*)&session, sizeof(Session));
	}
	file.close();
	ofile.close();
	remove(path.c_str());
	rename("C:/Users/vlads/source/repos/�����_2/�����_2/temp.txt", path.c_str());
}
void createPoster() {
	Session temp;
	cout << "������� ���� ��� ������������ �����." << endl;
	cin >> temp.date;
	cout << "������� ���� � ����� �������." << endl;
	string path;
	cin >> path;
	ifstream file(path, ios::out | ios::binary);
	cout << "������� �������� ����� ��� ����� �����." << endl;
	string path_b;
	cin >> path_b;
	ofstream ofile(path_b, ios::trunc | ios::out | ios::in | ios::binary);
	Session session;
	file.read((char*)&session, sizeof(Session));
	while (!file.eof()) {
		if (session.date[0] == temp.date[0] &&
			session.date[1] == temp.date[1] &&
			session.date[3] == temp.date[3] &&
			session.date[4] == temp.date[4] &&
			session.date[6] == temp.date[6] &&
			session.date[7] == temp.date[7] &&
			session.date[8] == temp.date[8] &&
			session.date[9] == temp.date[9]) {
			ofile.write((char*)&session, sizeof(Session));
		}
		file.read((char*)&session, sizeof(Session));
	}
	file.close();
	ofile.close();
}
void deleteEntry() {
	Session temp;
	cout << "������� ����� ������, ������� ������ �������." << endl;
	cin >> temp.key;
	cout << "������� ���� � ����� �������." << endl;
	string path;
	cin >> path;
	fstream file(path, ios::out | ios::in | ios::binary);
	fstream ofile("temp.txt", ios::trunc | ios::in | ios::out | ios::binary);
	Session session;
	file.read((char*)&session, sizeof(Session));
	while (!file.eof()) {
		if (session.key == temp.key) {
			file.read((char*)&session, sizeof(Session));
		}
		else {
			ofile.write((char*)&session, sizeof(Session));
			file.read((char*)&session, sizeof(Session));
		}
	}
	file.close();
	ofile.close();
	remove(path.c_str());
	rename("C:/Users/vlads/source/repos/�����_2/�����_2/temp.txt", path.c_str());
	cout << "���� ������." << endl;
}
void fileWriteAccess() {
	cout << "������� �������� ��������� ����� ��� ��������� ��� ������." << endl;
	string path;
	cin >> path;
	fstream file(path, ios::in | ios::out | ios::binary);
	if (file.is_open()) {
		cout << "���� ������." << endl;
		cout << "������� ����� ������, ������� ������ ��������, � ����� ��������." << endl;
		int index;
		cin >> index;
		Session session;
		file.seekg(sizeof(Session) * (index - 1), ios::beg);
		session.key = index;
		cin >> session.name;
		cin >> session.film;
		cin >> session.date;
		cin >> session.time;
		cin >> session.cost;
		file.write((char*)&session, sizeof(Session));
	}
	else {
		cout << "�� ������� ������� ����." << endl;
		cout << "���������� ��� ���." << endl;
		fileWriteAccess();
	}
	cout << "�������� ������ �������." << endl;
	file.close();
	cout << "���� ������." << endl;
}