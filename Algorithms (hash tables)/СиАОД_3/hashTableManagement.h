#pragma once 
#include <iostream> 
using namespace std;
struct cell {
	int key = 0;
	bool flag = false;
	bool isEmpty() { return  key == 0; };
};
struct hashTable {
	int max_size = 10;
	int size = 0;
	cell* cells = new cell[max_size];
};
int hash_func(int key, int max_size) {
	return key % max_size;
}
void reHash(hashTable& hT) {
	hT.max_size = hT.max_size * 2;
	cell* new_cells = new cell[hT.max_size];
	for (int i = 0; i < hT.max_size / 2; ++i) {
		if (!hT.cells[i].isEmpty()) {
			int newindex = hash_func(hT.cells[i].key, hT.max_size);
			new_cells[newindex] = hT.cells[i];
		}
	}
	delete[] hT.cells;
	hT.cells = new_cells;
}
void insert(hashTable& hT, int key) {
	cell cell;
	cell.key = key;
	hT.size++;
	int index = hash_func(key, hT.max_size);
	if (hT.size / hT.max_size > 0.75) {
		reHash(hT);
		insert(hT, cell.key);
	}
	else {
		while (!hT.cells[index].isEmpty()) {
			index++;
		}
		hT.cells[index] = cell;
	}
}
int find(hashTable& hT, int key) {
	int index = hash_func(key, hT.max_size);
	while (!hT.cells[index].isEmpty() || hT.cells[index].flag) {
		if (hT.cells[index].key == key) return index;
		index++;
	}
	return -1;
}
void remove(hashTable& hT, int key) {
	int index = hash_func(key, hT.max_size);
	while (hT.cells[index].key != key) {
		index++;
	}
	hT.cells[index].key = 0;
	hT.cells[index].flag = true;
}
void print_table(hashTable& hT) {
	for (int i = 0; i < hT.max_size; ++i) {
		cout << i << ": " << hT.cells[i].key
			<< "    \tэлемент удалён: "
			<< hT.cells[i].flag << endl;
	}
}
void testHeshT() {
	//создание хеш-таблицы
	hashTable hT;
	//вставка ключа без коллизии
	cout << "Вставка ключа без коллизии." << endl;
	insert(hT, 12);
	insert(hT, 13);
	insert(hT, 14);
	insert(hT, 11);
	insert(hT, 10);
	cout << "Хеш-таблица после добавления в неё записей." << endl;
	print_table(hT);
	//вставка ключа и разрешение коллизии
	cout << "Вставка ключа и разрешение коллизии." << endl;
	insert(hT, 22);
	cout << "Хеш-таблица после добавления в неё записи." << endl;
	print_table(hT);
	//вставка ключа с последующим рехешированием
	cout << "Вставка ключа с последующим рехешированием." << endl;
	insert(hT, 15);
	insert(hT, 16);
	insert(hT, 17);
	insert(hT, 18);
	insert(hT, 19);
	cout << "Хеш-таблица после добавления в неё записей." << endl;
	print_table(hT);
	//удаление ключа из хеш-таблицы
	cout << "Удаление ключа из хеш-таблицы." << endl;
	remove(hT, 19);
	remove(hT, 10);
	cout << "Хеш-таблица после удаления из неё записей." << endl;
	print_table(hT);
	//поиск ключа в хеш-таблице
	cout << "Поиск ключа в хеш-таблице." << endl;
	cout << "Элемент поиска:\t" << find(hT, 15) << endl;
	//поиск ключа в таблице после удаленного ключа
	cout << "Элемент поиска:\t" << find(hT, 19) << endl;
};