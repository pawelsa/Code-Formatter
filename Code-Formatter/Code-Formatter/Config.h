#pragma once

class config {
	int horizontal;
	int vertical_after_semicolon;
	int vertical_brace_o;
	int vertical_brace_e;
	bool brace_next_line;
public:
	config();
	int _horizontal();
	int _vertical_after_semicolon();
	int _vertical_brace_o();
	int _vertical_brace_e();
};
