#include "Config.h"
#include <fstream>
#include <cstdlib>

config::config(){		/*Opens config file, and read all preferences specified by user*/
	std::ifstream source;

	source.open("config.txt");

	char d;
	char c[4][4];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++, c[i][j] = 0);

		int i = 0, j = 0;
	while (!source.eof()) {
		source.get(d);
		if (source.eof())
			break;
		if (d == '\n') {
			i++;
			j = 0;
			continue;
		}
		else {
			c[i][j] = d;
			j++;
		}

	}

	
	horizontal = atoi(c[0]);
	vertical_after_semicolon = atoi(c[1]);
	vertical_brace_o = atoi(c[2]);
	vertical_brace_e = atoi(c[3]);

	source.close();
}
int config::_horizontal() {
	return horizontal;
}
int config::_vertical_after_semicolon() {
	return vertical_after_semicolon;
}
int config::_vertical_brace_o() {
	return vertical_brace_o;
}
int config::_vertical_brace_e() {
	return vertical_brace_e;
}