#include <iostream>
#include <fstream>
#include "Editor.h"

char c;

int main() {

	std::ifstream source;
	std::ofstream output;

	source.open("test.cpp");
	output.open("output.cpp");
	
	edit file;
	int end = 0;
	while (!source.eof() && end<1) {
		while (source.get(c)) {
			while (c == '\t' || c == '\n')
				source.get(c);
			//if (c != '{' && c != '}' )
				output << c;
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
						//output << c;
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
						//output << c;
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
					file._enter(output);
					break;
				}
			}
		}
		end++;
	}

	source.close();
	output.close();
	
	return 0;
}

// edycja przy komentarzach
// edycja przy znakach ++ itp
// edycja przy for, while itp
// wstawia tyle tab i ent ile powinno byæ wszystkie kolejne pomija