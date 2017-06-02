#include <iostream>
#include <fstream>
#include "Editor.h"

char c;

bool functions(std::ifstream &source, std::ofstream &output,char *prefix[],int to_prefix[]){
	for (int i = 0; i < 7; i++) {
		int j, inside=0;
		for (j = 0; j < to_prefix[i]; j++, source.get(c)) {
			if (c == prefix[i][j]) {
				inside++;
				if ((j + 1) == to_prefix[i]) {
					output << std::endl << prefix[i];
					std::cout << std::endl << prefix[i];
					source.seekg((j-1), source.cur);
					return false;
				}
			}
			else {
				if (inside != 0) {
					source.seekg(-(inside-1), source.cur);
					//output << c;
					//std::cout << c;
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

	edit file;
	int end = 0;
	while (!source.eof() && end<1) {
		while (source.get(c)) {
			while (c == '\t' || c == '\n')
				source.get(c);
			
			//if (c != 100 && c != 99 && c != 102 && c != 105 && c != 115 && c != 119 && c != 118 && c != 67 && c != 68 && c != 70 && c != 73 && c != 83 && c != 86 && c != 87)
			if (functions(source, output, prefix, to_prefix)) {
				output << c;
				std::cout << c;
			}
			switch (c) {
				/*case 100:
				case 99:
				case 102:
				case 105:
				case 115:
				case 119:
				case 118:
				case 67:
				case 68:
				case 70:
				case 73:
				case 83:
				case 86:
				case 87: {
					for (int i = 0; i < 7; i++) {
						int j;
						for (j = 0; j < to_prefix[i]; j++, source.get(c)) {
							if (c == prefix[i][j]) {
								if ((j + 1) == to_prefix[i]) {
									output << std::endl << prefix[i];
									source.seekg(j, source.cur);
									break;
								}
							}
							else {
								
								break;
							}
						}
						source.seekg(-j, source.cur);
					}
					break;
				}*/
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
				case 42: {
					source.get(c);
					if (c == '/')
						output << '/' << std::endl;
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

/*{
for (int i = 0; i < 7; i++) {
	int j;
	for (j = 0; j < to_prefix[i]; j++, source.get(c)) {
		if (c == prefix[i][j]) {
			if ((j + 1) == to_prefix[i]) {
				output << std::endl << prefix[i];
				source.seekg(j, source.cur);
				break;
			}
		}
		else {

			break;
		}
	}
	source.seekg(-j, source.cur);
}
break;
	*/