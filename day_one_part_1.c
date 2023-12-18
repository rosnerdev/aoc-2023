#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

int main() {
	int acc = 0;
	char str[64];
	FILE* file;
	file = fopen("day_one.txt", "r");

	while (fgets(str, sizeof(str), file)) {
		char curr[2];
		
		int i;
		for (i = 0; str[i] != '\0'; i++) {
			if (isdigit(str[i])) {
				curr[0] = str[i];	
				break;
			}
		}

		i = strlen(str) - 1;

		while (!isdigit(str[i])) {
			i--;
		}
		
		curr[1] = str[i];
		
		printf("%s\n", curr);
		acc += atoi(curr);
	}

	fclose(file);

	/* this is the final answer */
	printf("\n%d\n", acc);

	return 0;
}
