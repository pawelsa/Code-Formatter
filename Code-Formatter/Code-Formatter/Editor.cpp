#include "Editor.h"

void edit::_brace(std::ofstream &output) {	/*do what user specified after opening brace*/
	brace++;
	for (int i = 0; i < (user_conf->_vertical_brace_o()); i++)
		output << std::endl;
	
	for (int i = 0; i < (brace + tab) * (user_conf->_horizontal()); i++)
		output << "\t";
}
void edit::_brace_end(std::ofstream &output) {	/*do what user specified after closing brace*/
	brace--;
	for (int i = 0; i < (user_conf->_vertical_brace_e()); i++)
		output << std::endl;
	if (brace == 0)
		output << std::endl; 
	for (int i = 0; i < (brace + tab) * (user_conf->_horizontal()); i++)
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
void edit::_tab(std::ofstream &output) {	/*places as many tabulations as user wish*/
	for (int i = 0; i < (brace+tab)*(user_conf->_horizontal()); i++)
		output << "\t";
}
void edit::_enter(std::ofstream &output) {	/*method specifying what to do after semicolon*/
	if (bracket != 0);
	else {
		for (int i = 0; i < user_conf->_vertical_after_semicolon(); i++)	/*places as many new lines as user wish*/
			output << std::endl;
		for (int i = 0; i < (brace + tab)*(user_conf->_horizontal()); i++)	/*places as many tabulations as user wish*/
			output << "\t";
	}
}
void edit::_tab_add() {
	tab++;
}
void edit::_comment() {	/*marks if comment is open/closed*/
	if (comment == 0)
		comment++;
	else
		comment--;
}
int edit::_comment_return() {
	return comment;
}
void edit::_quotation() {	/*marks if quotation is open/closed*/
	if (quotation == 0)
		quotation++;
	else
		quotation--;
}
int edit::_quotation_return() {
	return quotation;
}