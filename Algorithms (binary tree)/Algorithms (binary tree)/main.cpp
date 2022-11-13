#include <iostream>

using namespace std;

class binaryTree {
private:
	char ch;
	binaryTree* tl = nullptr;
	binaryTree* tr = nullptr;
public:
	binaryTree(string* expr, string type) {
		if (type == "original") {
			int index = lastOper(*expr);
			if (index != -1) {
				this->ch = expr->at(index);
				string left, right;
				for (int i = 0; i != index; i++) {
					left.push_back(expr->at(i));
				}
				for (int i = index + 1; i < expr->length(); i++) {
					right.push_back(expr->at(i));
				}
				this->tl = new binaryTree(&left, type);
				this->tr = new binaryTree(&right, type);
			}
			else {
				this->ch = getOper(*expr);
				this->tl = nullptr;
				this->tr = nullptr;
			}
		}
		else if (type == "prefix") {
			if (expr->at(0) >= '0' && expr->at(0) <= '9') {
				this->ch = *expr->begin();
				expr->erase(expr->begin());
			}
			else {
				this->ch = *expr->begin();
				expr->erase(expr->begin());
				this->tl = new binaryTree(expr, type);
				this->tr = new binaryTree(expr, type);
			}
		}
	}
	static int lastOper(string expr) {
		int prLvl = 0, retInd = -1, lowLvl;
		for (int i = 0; i < expr.length(); i++) {
			if (expr[i] == '(') {
				prLvl++;
			}
			else if (expr[i] == ')') {
				prLvl--;
			}
			else if (expr[i] == '+' || expr[i] == '-') {
				if (retInd == -1) {
					lowLvl = prLvl;
					retInd = i;
				}
				else {
					if (prLvl < lowLvl) {
						lowLvl = prLvl;
						retInd = i;
					}
					else if (prLvl == lowLvl) {
						retInd = i;
					}
				}
			}
			else if (expr[i] == '*' || expr[i] == '/') {
				if (retInd == -1) {
					lowLvl = prLvl;
					retInd = i;
				}
				else {
					if (prLvl < lowLvl) {
						lowLvl = prLvl;
						retInd = i;
					}
					else if (prLvl == lowLvl) {
						if (expr[retInd] != '-' && expr[retInd] != '+') {
							retInd = i;
						}
					}
				}
			}
		}
		return retInd;
	}
	static char getOper(string expr) {
		for (int i = 0; i < expr.length(); i++) {
			if (expr[i] >= '0' && expr[i] <= '9') {
				return expr[i];
			}
		}
	}
	void printTree(binaryTree* t, int level) {
		if (t) {
			printTree(t->tl, level - 1);
			for (int i = 0; i < level; i++) cout << "   ";
			cout << t->ch << endl;
			printTree(t->tr, level - 1);
		}
	}
	~binaryTree() {
		delete tl;
		delete tr;
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Выражение: ";
	string str1;
	cin >> str1;
	binaryTree t1(&str1, "original");
	cout << "Двоичное дерево:\n";
	t1.printTree(&t1, 4);
	cout << "Префиксное выражение: ";
	string str2;
	cin >> str2;
	binaryTree t2(&str2, "prefix");
	cout << "Двоичное дерево:\n";
	t2.printTree(&t2, 4);
}