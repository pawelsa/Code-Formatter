#pragma once
#include <fstream>

class edit {
	int bracket = 0;	//nawias
	int brace = 0;		//klamra
	int tab = 0;
	int comment = 0;
	int quotation = 0;
public:
	void _bracket();
	void _bracket_end(std::ofstream &output);
	void _brace(std::ofstream &output);
	void _brace_add();
	void _brace_end(std::ofstream &output);
	void _tab(std::ofstream &output);
	void _tab_add();
	void _enter(std::ofstream &output);
	void _comment();
	int _comment_return();
	void _quotation();
	int _quotation_return();
};