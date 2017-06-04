


bool functions(std::ifstream &source, std::ofstream &output, char *prefix[], int to_prefix[]) {
	int j;
	for (int i = 0; i < 8; i++) {

		for (j = 0; j < to_prefix[i]; j++, source.get(c)) {
			if (c == prefix[i][j]) {
				if ((j + 1) == to_prefix[i]) {/*
											  if (i == 8)
											  output << prefix[i] << std::endl;
											  else {*/
					output << std::endl;
					file._tab(output);
					output << prefix[i];
					source.seekg((j - 2), source.cur);
					//	}
					return false;
				}

			}
			
		}
		else
			continue;
		//else {
		if (j != 0) {
			source.seekg(-(j)-1, source.cur);
			source.get(c);
		}
		return true;
		//}
	}
	source.seekg(-j, source.cur);

	return true;
}