(;tc(fo) != EOF; i++) {/*count words*/fseek(f, -1, SEEK_CUR);if (getc(f) == '\n')size++;}words = (char**)malloc((size) * sizeof(char*));fseek(f, 0, SEEK_SET);for (int i = 0; getc(f) != EOF; i++) {/*add to structure from file*/words[i] = (char*)malloc