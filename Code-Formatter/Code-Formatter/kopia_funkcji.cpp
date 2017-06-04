bool functions(std::ifstream &source, std::ofstream &output, char *prefix[], int to_prefix[], char last) {
	int j=0;
	int max = 0;
	if ((last == 32 || last == 10 || last == 9 || last=='\0' || last=='e') && (file._quotation_return()==0 || file._comment_return()==0)) {
		for (int i = 0; i < 9; i++) {
			for (j = 0; j < to_prefix[i]; j++, source.get(c)) {
				if (c == prefix[i][j]) {
					j > max ? max = j : max = max;
					if ((j + 1) == to_prefix[i]) {

						if (i == 8) {
							output << prefix[i] << std::endl;
							file._tab(output);
						}
						else {
							output << std::endl;
							file._tab(output);
							output << prefix[i];
						}
						return false;
					}
					else
						continue;
				}
				else {
					break;
				}
				source.seekg(-(max+1), source.cur);
					source.get(c);
					output << c;
					return false;
					
			}
			
		}
		
	}
	return true;
	
}