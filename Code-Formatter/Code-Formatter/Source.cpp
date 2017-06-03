#include <iostream>
#include <fstream>
#include "Editor.h"

char c;
edit file;

bool functions(std::ifstream &source, std::ofstream &output,char *prefix[],int to_prefix[]){
	for (int i = 0; i < 7; i++) {
		int j;
		for (j = 0; j < to_prefix[i]; j++, source.get(c)) {
			if (c == prefix[i][j]) {
				if ((j + 1) == to_prefix[i]) {
					output << std::endl;
					file._tab(output);
					output << prefix[i];
					source.seekg((j-2), source.cur);
					return false;
				}
			}
			else {
				if (j != 0) {
					source.seekg(-(j)-1, source.cur);
					source.get(c);
				}
				return true;
			}
		}
		source.seekg(-j, source.cur);
	}
	return true;
}

int main() {

	std::ifstream source;
	std::ofstream output;

	source.open("test.cpp");
	output.open("output.cpp");
	
	char *prefix[10] = { "for","while","do","if","void","switch","class","structure" };
	int to_prefix[8] = { 3,5,2,2,4,6,5,9 };

	int end = 0;
	while (!source.eof() && end<1) {
		while (source.get(c)) {
			while (c == '\t' || c == '\n')
				source.get(c);
			
			if (functions(source, output, prefix, to_prefix)) {
				output << c;
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
				case 42: {
					source.get(c);
					if (c == '/') {
						output << '/' << std::endl;
						file._tab(output);
					}
					else
						source.seekg(-1,source.cur);
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
