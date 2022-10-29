#include "application.h"
application::application() {};
cl_base* application::way(string name, cl_base* obj_temp) {
	string name_temp;
	if (name[0] == '/') {
		name.erase(0, 1);
	}
	while (name[0] != '\0') {
		name_temp += name[0];
		name.erase(0, 1);
		if (name[0] == '/' || name[0] == '\0') {
			obj_temp = find(name_temp, obj_temp);
			if (obj_temp == nullptr) {
				return obj_temp;
			}
			name.erase(0, 1);
			name_temp = "";
		}
	}
	return obj_temp;
}
void application::build_tree() {
	setlocale(LC_ALL, "ru");
	string name1, name2;
	int classnum;
	cl_base* temp_head = this;
	while (true) {
		cin >> name1;
		cl_base* temp_head = this;
		if (name1 == "endtree") { break; }
		else if (name1 == "/") { name1 = "root"; }
		else { temp_head = way(name1, temp_head); };
		if (temp_head == nullptr) {
			cout << "The head object " << name1 << " is not found\n";
			cout << "Object tree" << "\n";
			cout << this->get_name();
			show_tree();
			exit(0);
		}
		cin >> name2 >> classnum;
		switch (classnum) {
		case 2: temp_head->add_child(new cl_2(name2, temp_head, classnum)); break;
		case 3: temp_head->add_child(new cl_3(name2, temp_head, classnum)); break;
		case 4: temp_head->add_child(new cl_4(name2, temp_head, classnum)); break;
		case 5: temp_head->add_child(new cl_5(name2, temp_head, classnum)); break;
		case 6: temp_head->add_child(new cl_6(name2, temp_head, classnum)); break;
		default: temp_head->add_child(new cl_1(name2, temp_head)); break;
		}
	}
}
string application::commands() {
	string name1, name2, text, command, result = "";
	cl_base* temp_head = this;
	while (true) {
		cin >> command;
		if (command == "END") {
			if (result == "") { return ""; };
			return result;
		}
		else if (command == "SET_CONDITION") {
			int readiness;
			cin >> name1 >> readiness;
			cl_base* ptr = way(name1, this);
			if (!ptr) { result += "\nObject " + name1 + " not found"; continue; };
			set_condition(ptr, readiness);
			continue;
		}
		else if (command == "EMIT") {
			cin >> name1 >> text;
			cl_base* ptr = way(name1, this);
			if (!ptr) { result += "\nObject " + name1 + " not found"; continue; }
			else if (ptr->get_readiness() != 0) { result = emit(ptr, text, result); continue; };
		}
		else if (command == "SET_CONNECT") {
			cin >> name1 >> name2;
			cl_base* from = way(name1, this);
			cl_base* to = way(name2, this);
			if (!from) { result += "\nObject " + name1 + " not found"; continue; }
			else if (!to) { result += "\nHandler object " + name2 + " not found"; continue; };
			set_connect(from, to);
			continue;
		}
		else if (command == "DELETE_CONNECT") {
			cin >> name1 >> name2;
			cl_base* from = way(name1, this);
			cl_base* to = way(name2, this);
			if (!from) { result += "\nObject " + name1 + " not found"; continue; }
			else if (!to) { result += "\nHandler object " + name2 + " not found"; continue; };
			delete_connect(from, to);
			continue;
		}
	}
}
void application::set_connections() {
	while (true) {
		string from, to;
		cin >> from;
		if (from == "end_of_connections") { break; }
		else if (from == "/") { from = this->get_name(); };
		cin >> to;
		set_connect(way(from, this), way(to, this));
	}
}
int application::exec_app() {
	//string result = commands();
	cout << "Object tree" << "\n";
	cout << this->get_name();
	show_tree();
	cl_base* ptr = way("/object_s2/object_s4", this);
	cout << "\n" << get_way(ptr) << endl;
	//cout << result;
	return 0;
}