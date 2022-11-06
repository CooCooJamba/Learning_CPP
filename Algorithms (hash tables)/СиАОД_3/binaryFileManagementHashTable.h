#pragma once
#include "hashTableManagement.h"
#include "binaryFileManagement.h"
void new_cell(hashTable& hT, int num) {
	Session s;
	readEntry(s, num);
	if (s.key) insert(hT, s.key);
	cout << "Запись из файла создана в хеш-таблице" << endl;
}
void remove_cell(hashTable& hT, int key) {
	remove(hT, key);
	removeEntry(key);
	readBinaryFile();
	cout << "Запись удалена из файла и хеш-таблицы" << endl;
}
int find_cell(hashTable& hT, int key) {
	Session s;
	int index = find(hT, key);
	if (index == -1) return -1;
	int number = findEntry(index) - 1;
	readEntry(s, number);
	cout << "Получен доступ к записи хеш-таблицы под индексом: "
		<< index << "\nПолучен доступ к записи файла под номером: "
		<< number + 1 << "\nДанные сеанса: "
		<< s.name << '\t' << s.film << '\t'
		<< s.date << '\t' << s.time
		<< '\t' << s.cost << '\n';
	return 0;
}
void testFinal() {
	hashTable hT;
	//чтение записи из файла и вставка элемента в хеш-таблицу
	cout << "Чтение записи из файла и вставка элемента в хеш-таблицу." << endl;
	new_cell(hT, 0);
	new_cell(hT, 1);
	new_cell(hT, 2);
	new_cell(hT, 3);
	new_cell(hT, 4);
	new_cell(hT, 5);
	cout << "Хеш-таблица после вставки в неё записей." << endl;
	print_table(hT);
	//удаление записи из хеш-таблицы при заданном значении ключа и соответственно из файла
	cout << "Удаление записи из хеш-таблицы при заданном значении ключа и соответственно из файла." << endl;
	remove_cell(hT, 5);
	cout << "Бинарный файл после удаления из него записи." << endl;
	readBinaryFile();
	cout << "Хеш-таблица после удаления из неё записи." << endl;
	print_table(hT);
	//нахождение записи в файле по значению ключа
	cout << "Нахождение записи в файле по значению ключа." << endl;
	find_cell(hT, 2);
	find_cell(hT, 5);
};