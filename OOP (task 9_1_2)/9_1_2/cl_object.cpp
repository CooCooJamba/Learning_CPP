#include "cl_object.h"
cl_object::cl_object(string value, string pattern) {
	map<char, string> bits = {
		{'0', "0000"},
		{'1', "0001"},
		{'2', "0010"},
		{'3', "0011"},
		{'4', "0100"},
		{'5', "0101"},
		{'6', "0110"},
		{'7', "0111"},
		{'8', "1000"},
		{'9', "1001"},
		{'A', "1010"},
		{'B', "1011"},
		{'C', "1100"},
		{'D', "1101"},
		{'E', "1110"},
		{'F', "1111"}
	};
	this->value = bitset<8>(bits[value[0]] + bits[value[1]]);
	this->pattern = bitset<8>(bits[pattern[0]] + bits[pattern[1]]);
}
string cl_object::get_result() {
	string result;
	map<string, string> bits = {
	{"0000", "0"},
	{"0001", "1"},
	{"0010", "2"},
	{"0011", "3"},
	{"0100", "4"},
	{"0101", "5"},
	{"0110", "6"},
	{"0111", "7"},
	{"1000", "8"},
	{"1001", "9"},
	{"1010", "A"},
	{"1011", "B"},
	{"1100", "C"},
	{"1101", "D"},
	{"1110", "E"},
	{"1111", "F"}
	};
	result = bits[value.to_string().substr(0, 4)] + bits[value.to_string().substr(4, 4)];
	return result;
}
cl_object& cl_object::operator|(cl_object& obj) {
	bitset<8>
		value_this = this->value,
		pattern_this = this->pattern,
		value_other = obj.value,
		pattern_other = obj.pattern;
	for (int i = 0; i < 8; ++i)
		if (pattern_this[i] && pattern_other[i])
			value_this[i] = pattern_this[i] | value_other[i];
	this->value = (bitset<8>(value_this));
	return *this;
}
cl_object& cl_object::operator&(cl_object& obj) {
	bitset<8>
		value_this = this->value,
		pattern_this = this->pattern,
		value_other = obj.value,
		pattern_other = obj.pattern;
	for (int i = 0; i < 8; ++i)
		if (pattern_this[i] && pattern_other[i])
			value_this[i] = value_this[i] & value_other[i];
	this->value = (bitset<8>(value_this));
	return *this;
}