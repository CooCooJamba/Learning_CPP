#include "application.h"
application::application() {};
cl_base* application::way(string name, cl_base* obj_temp) {
	string name_temp;
	if (name[0] == '/' && name.length() == 1) {
		return obj_temp;
	}
	if (name[0] == '/') {
		name.erase(0, 1);
	}
	while (name[0] != '\0') {
		name_temp += name[0];
		name.erase(0, 1);
		if (name[0] == '/' || name[0] == '\0') {
			vector<cl_base*>::iterator it = obj_temp->children.begin();
			int i = 0;
			for (; it != obj_temp->children.end(); it++) {
				if (obj_temp->children[i]->get_name() == name_temp) { obj_temp = *it; break; };
				i++;
			}
			if (obj_temp != *it) { return nullptr; }
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
	while (true) {
		cin >> name1;
		cl_base* temp_head = this;
		if (name1 == "endtree") { break; }
		else { temp_head = way(name1, temp_head); };
		if (temp_head == nullptr) {
			cout << "The head object " << name1 << " is not found\n";
			cout << "Object tree\n";
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
void application::set_connections() {
	while (true) {
		string from, to;
		SIGNAL _signal;
		HANDLER _handler;
		cin >> from;
		if (from == "end_of_connections") { break; }
		cin >> to;
		if (!way(from, this)) { "\nObject " + from + " not found"; continue; };
		if (!way(to, this)) { "\nHandler object " + to + " not found"; continue; };
		_signal = find_signal(way(from, this)->get_classnum());
		_handler = find_handler(way(to, this)->get_classnum());
		way(from, this)->set_connect(_signal, way(to, this), _handler);
	}
}
void application::commands() {
	string name1, name2, text, command;
	SIGNAL _signal;
	HANDLER _handler;
	while (true) {
		cin >> command;
		if (command == "END") {
			break;
		}
		else if (command == "SET_CONDITION") {
			int readiness;
			cin >> name1 >> readiness;
			cl_base* ptr = way(name1, this);
			if (!ptr) { cout << "\nObject " + name1 + " not found"; }
			else { set_condition(ptr, readiness); };
		}
		else if (command == "EMIT") {
			cin >> name1;
			cl_base* ptr = way(name1, this);
			if (!ptr) { cout << "\nObject " + name1 + " not found"; }
			else if (ptr->get_readiness() != 0) {
				_signal = find_signal(ptr->get_classnum());
				getline(cin, text);
				ptr->emit(_signal, text);
			};
		}
		else if (command == "SET_CONNECT") {
			cin >> name1 >> name2;
			cl_base* from = way(name1, this);
			cl_base* to = way(name2, this);
			if (!from) { cout << "\nObject " + name1 + " not found"; };
			if (!to) { cout << "\nHandler object " + name2 + " not found"; };
			if (from && to) {
				_signal = find_signal(from->get_classnum());
				_handler = find_handler(to->get_classnum());
				from->set_connect(_signal, to, _handler);
			};
		}
		else if (command == "DELETE_CONNECT") {
			cin >> name1 >> name2;
			cl_base* from = way(name1, this);
			cl_base* to = way(name2, this);
			if (!from) { cout << "\nObject " + name1 + " not found"; };
			if (!to) { cout << "\nHandler object " + name2 + " not found"; };
			if (from && to) {
				_signal = find_signal(from->get_classnum());
				_handler = find_handler(to->get_classnum());
				from->delete_connect(_signal, to, _handler);
			};
		}
	}
}
int application::exec_app() {
	cout << "Object tree" << "\n";
	cout << this->get_name();
	show_tree();
	commands();
	return 0;
}