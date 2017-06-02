#include "Editor.h"

void edit::_brace(std::ofstream &output) {
	brace++;
	output << "{" << std::endl;
	tab++;
	for (int i = 0; i < tab; i++)
		output << "\t";
}
void edit::_brace_end(std::ofstream &output) {
	brace--;
	output <<std::endl;
	if (brace == 0)
		output << std::endl;
	tab--;
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
void edit::_tab() {
	tab++;
}
void edit::_enter(std::ofstream &output) {
	if (bracket == 0)
		output << std::endl;
	for (int i = 0; i < tab; i++)
		output << "\t";
}
void edit::_comma() {

}
