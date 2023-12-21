#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

void part1();
void part2();

int main() {
    part1();
	part2();
    return 0;
}

void part1() {
	int line = 1;
	int line_sum = 0;
	char str[256];
	FILE* file;
	file = fopen("input.txt", "r");

	while (fgets(str, sizeof(str), file)) {
		int c = 0;
		int curr_i = 0;
		char curr_num[3];
		int green = 0;
		int blue = 0;
		int red = 0;

		if (line < 10) {
			c += 8;
		} else if (line < 100) {
			c += 9;
		} else {
			c += 10;
		}
		
		while (c < strlen(str)) {
			while (isdigit(str[c])) {
				curr_num[curr_i] = str[c];
				c++;
				curr_i++;
			}
			
			c += 1;
			
			switch (str[c]) {
				case 'r':
					red += atoi(curr_num);
					c += 3;
					break;

				case 'g':
					green += atoi(curr_num);
					c += 5;
					break;

				case 'b':
					blue += atoi(curr_num);
					c += 4;
					break;
			}

			curr_i = 0;			
			memset(curr_num, ' ', 3);
			
			if (str[c] == ';') {
				if (red <= 12 && green <= 13 && blue <= 14) {
					c += 2;
					red = 0;
					green = 0;
					blue = 0;
				} else break;	
			} else if (str[c] == ',') {
				c += 2;
			} else {
				if (red <= 12 && green <= 13 && blue <= 14) {
					line_sum += line;
				}
				break;
			}	
		}
		
		printf("Game %d: %d red, %d green, %d blue;\n", line, red, green, blue);
		line++;
	}

	fclose(file);

	printf("Part 1: %d\n\n", line_sum);
}

int max(int a, int b) {return a > b ? a : b;}

void part2() {
	int line = 1;
	int power_sum = 0;
	char str[256];
	FILE* file;
	file = fopen("input.txt", "r");

	while (fgets(str, sizeof(str), file)) {
		int c = 0;
		int curr_i = 0;
		char curr_num[3];
		int green = 0;
		int blue = 0;
		int red = 0;

		if (line < 10) {
			c += 8;
		} else if (line < 100) {
			c += 9;
		} else {
			c += 10;
		}
		
		while (c < strlen(str)) {
			while (isdigit(str[c])) {
				curr_num[curr_i] = str[c];
				c++;
				curr_i++;
			}
			
			c += 1;
			
			switch (str[c]) {
				case 'r':
					red = max(atoi(curr_num), red);
					c += 3;
					break;

				case 'g':
					green = max(atoi(curr_num), green);
					c += 5;
					break;

				case 'b':
					blue = max(atoi(curr_num), blue);
					c += 4;
					break;
			}

			curr_i = 0;			
			memset(curr_num, ' ', 3);
			
			if (str[c] == ',' || str[c] == ';') {
				c += 2;
			}
		}
		
		power_sum += red * green * blue;
		printf("Game %d: %d red, %d green, %d blue;\n", line, red, green, blue);
		line++;
	}

	fclose(file);

	printf("Part 2: %d\n", power_sum);
}