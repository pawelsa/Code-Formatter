#include "Editor.h"

void edit::_brace(std::ofstream &output) {
	brace++;
	output << std::endl;
	
	for (int i = 0; i < (brace + tab); i++)
		output << "\t";
}
void edit::_brace_end(std::ofstream &output) {
	brace--;
	output <<std::endl;
	if (brace == 0)
		output << std::endl; 
	for (int i = 0; i < (brace + tab); i++)
		output << "\t";
}
void edit::_brace_add() {
	brace++;
}
void edit::_bracket() {
	bracket++;
}
void edit::_bracket_end(std::ofstream &output) {
	bracket--;
}
void edit::_tab(std::ofstream &output) {
	for (int i = 0; i < (brace+tab); i++)
		output << "\t";
}
void edit::_enter(std::ofstream &output) {
	if (bracket != 0)
		;
	else {
		output << std::endl;
		for (int i = 0; i < (brace + tab); i++)
			output << "\t";
	}
}
void edit::_tab_add() {
	tab++;
}
