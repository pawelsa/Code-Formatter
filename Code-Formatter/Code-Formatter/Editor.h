#pragma once
#include <fstream>

class edit {
	int bracket = 0;
	int brace = 0;
	int tab = 0;

public:
	void _bracket();
	void _bracket_end(std::ofstream &output);
	void _brace(std::ofstream &output);
	void _brace_add();
	void _brace_end(std::ofstream &output);
	void _tab();
	void _enter(std::ofstream &output);
	void _comma();
};