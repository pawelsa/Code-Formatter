#include <iostream>
#include <fstream>
#include "Editor.h"

char c;
edit file;

bool functions(std::ifstream &source, std::ofstream &output, char *prefix[], int to_prefix[], char last) {
	int j=0;
	int max = 0;
	if ((last == 32 || last == 10 || last == 9 || last=='\0' ) && (file._quotation_return()==0 || file._comment_return()==0)) {
		for (int i = 0; i < 8; i++) {
			for (j = 0; j < to_prefix[i]; j++, source.get(c)) {
				if (c == prefix[i][j]) {
					j > max ? max = j : max = max;
					if ((j + 1) == to_prefix[i]) {
						/*
						if (i == 8) {
							output << prefix[i] << std::endl;
							file._tab(output);
						}
						else {*/
							output << std::endl;
							file._tab(output);
							output << prefix[i];
						//}
						return false;
					}
					else{
						continue;
					}
				}
				else {
					break;
				}
				//source.seekg(-(max+1), source.cur);
					//source.get(c);
					//output << c;
					return false;
					
			}
			
		}
		
	}
	return true;
	
}

int main() {

	std::ifstream source;
	std::ofstream output;

	source.open("test.cpp");
	output.open("output.cpp");

	char *prefix[10] = { "for","while","do","if","void","switch","class","structure","else" };
	int to_prefix[9] = { 3,5,2,2,4,6,5,9,4 };

	char last='\0';
	int end = 0;
	while (!source.eof() && end<1) {
		while (source.get(c)) {
			while (c == '\t' || c == '\n')
				source.get(c);
			

			//if (functions(source, output, prefix, to_prefix, last) && c!='#') {
				output << c;
				std::cout << c;
			//}
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
			/*case 47: {
				source.get(c);
				if (c == '*') {
					output << "*";
					file._comment();
				}
				else
					source.seekg(-1, source.cur);
				break;

			}*/
			case 34: {
				file._quotation();
			}
			/*case 35: {
				source.get(c);
				if (c != 32 || c != 10 || c != 9) {
					source.seekg(-1, source.cur);
					source.get(c);
					output << std::endl << "#"<<c;
				}
				else
					source.seekg(-1, source.cur);
				break;

			}*/
			}
			last = c;
		}
		end++;
	}

	source.close();
	output.close();

	return 0;
}