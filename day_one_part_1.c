#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

int main() {
	int acc = 0;
	char str[64];
	FILE* file;
	file = fopen("day_one_part_1.txt", "r");

	while (fgets(str, sizeof(str), file)) {
		char curr[2];
		
		int i;
		for (i = 0; str[i] != '\0'; i++) {
			if (isdigit(str[i])) {
				curr[0] = str[i];	
				break;
			}
		}

		while(str[i] != '\0') {
			i++;
		}
		i -= 1;

		while (!isdigit(str[i])) {
			i--;
		}
		
		curr[1] = str[i];
		
		printf("%s\n", curr);
		acc += atoi(curr);
	}

	fclose(file);
	printf("\n%d\n", acc);

	return 0;
}