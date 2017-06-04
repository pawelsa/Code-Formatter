#include <iostream>
#include <fstream>
#include "Editor.h"

char c;
edit file;


int main() {

	std::ifstream source;
	std::ofstream output;

	source.open("test.cpp");
	output.open("output.cpp");

	char last='\0';
	int end = 0;
	while (!source.eof() && end<1) {
		while (source.get(c)) {
			while (c == '\t' || c == '\n')
				source.get(c);

			if (c != '#') {
				output << c;
				std::cout << c;
			}
			switch (c) {
			case 40: {
				file._bracket();
				break;
			}
			case 41: {
				file._bracket_end(output);
				break;
			}
			case 123: {
				source.get(c);
				while (c == 32 || c == 10 || c == 9) {
					source.get(c);
				}

				if (c >= 48 && c <= 57) {
					output << c;
					file._brace_add();
					break;
				}
				if (c == ';') {
					output << ";";
				}
				else {
					source.seekg(-1, source.cur);
				}
				file._brace(output);
				break;
			}
			case 125: {
				source.get(c);
				while (c == 32 || c == 10 || c == 9) {
					source.get(c);
				}

				if (c >= 48 && c <= 57) {
					output << c;
					file._brace_add();
					break;
				}
				if (c == ';') {
					output << ";";
				}
				else {
					source.seekg(-1, source.cur);
				}
				file._brace_end(output);
				break;
			}
			case 59: {
				if(!file._quotation_return())
					file._enter(output);
				break;
			}
			case 42: {
				source.get(c);
				if (c == '/') {
					output << '/' << std::endl;
					file._tab(output);
				}
				else
					source.seekg(-1, source.cur);
				break;
			}
			case 47: {
				source.get(c);
				if (c == '*') {
					output << "*";
					file._comment();
				}
				else
					source.seekg(-1, source.cur);
				break;

			}
			case 39:
			case 34: {
				file._quotation();
				std::cout << file._quotation_return();
				break;
			}
			case 35: {
				source.get(c);
				if ((c != 32 || c != 10 || c != 9) && (file._quotation_return() == 0)) {
					source.seekg(-1, source.cur);
					source.get(c);
					
					std::cout << file._quotation_return();
					output << std::endl << "#" << c;
				}
				else if (file._quotation_return() == 1) {
					source.seekg(-1, source.cur);
					source.get(c);
					if (c == 34 || c == 39)
						file._quotation();
					output << "#" << c;
				}
				else
					source.seekg(-1, source.cur);
				break;

			}
			}
			last = c;
		}
		end++;
	}

	source.close();
	output.close();

	return 0;
}