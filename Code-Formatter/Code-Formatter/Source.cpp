#include <fstream>
#include "Editor.h"

char c;
edit file;




int main() {

	std::ifstream source;
	std::ofstream output;

	source.open("test_one_line.cpp");
	output.open("output.cpp");
	
	file._create_config();
	bool _brace;
	
	char last='\0';
	int end = 0;
	while (!source.eof() && end<1) {
		while (source.get(c)) {
			while (c == '\t' || c == '\n')		/*skips all new lines and tabulations*/
				source.get(c);

			if (c != '#') {
				output << c;
			}
			switch (c) {
			case 40: {		/*	(	*/
				file._bracket();
				break;
			}
			case 41: {		/*	)	*/
				file._bracket_end(output);
				break;
			}
			case 123: {		/*	{	*/
				_brace = 0;
			}
			case 125: {		/*	}	*/
				if (!file._quotation_return() && !file._comment_return()) {
					if (c == '}')
						_brace = 1;
					source.get(c);
					while (c == 32 || c == 10 || c == 9) {
						source.get(c);
					}

					if ((c >= 48 && c <= 57) || c == '\"' || c == '\'') {	/*check if there are numbers or quotation marks inside*/
						if (c == '\"' || c == '\'')
							file._quotation();
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
					if (_brace == 1)	/*	for }	*/
						file._brace_end(output);
					else
						file._brace(output);	/*	for {	*/
				}
				break;
			}
			case 59: {		/*	;	*/
				if (!file._quotation_return() && !file._comment_return())
					file._enter(output);
				break;
			}
			case 42: {	/*	end of comment	*/
				source.get(c);
				if (c == '/') {
					output << '/' << std::endl;
					file._comment();
					file._tab(output);
				}
				else
					source.seekg(-1, source.cur);
				break;
			}
			case 47: {	/*	/	*/
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
				break;
			}
			case 35: {
				source.get(c);
				if ((c != 32 || c != 10 || c != 9) && (!file._quotation_return()) && !file._comment_return()) {
					source.seekg(-1, source.cur);
					source.get(c);
					
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
			case 69:
			case 101: {
				if (!file._quotation_return() && !file._comment_return()) {
					char *problem = "else";
					bool ans = 0;
					for (int i = 1; i < 4; i++) {
						source.get(c);

						if (c == ';' || c == '{' || c == '}' || c == '(' || c == ')' || c == '\\' || c == '*') {
							source.seekg(-1, source.cur);
							ans = 0;
							break;
						}
						output << c;
						if (c == problem[i]) {
							ans = 1;
							continue;
						}
						else {
							ans = 0;
							break;
						}
					}
					if (ans == 1) {
						output << std::endl << "\t";
					}
				}
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