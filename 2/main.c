#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

void part1();

int main() {
    part1();
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

			if (c >= strlen(str)) break;

			if (str[c] == 'r') {
				red += atoi(curr_num);
				c += 3;
			}	
			else if (str[c] == 'g') {
				green += atoi(curr_num);
				c += 5;
			}				
			else if (str[c] == 'b') {
				blue += atoi(curr_num);
				c += 4;
			}

			curr_i = 0;			
			curr_num[0] = ' ';
			curr_num[1] = ' ';
			curr_num[2] = ' ';
			
			if (str[c] == ';') {
				if (red <= 12 && green <= 13 && blue <= 14) {
					c += 2;
					red = 0;
					green = 0;
					blue = 0;
				}  else {
					break;
				}			
			} else if (str[c] == ',') {
				c += 2;
			} else {
				if (red <= 12 && green <= 13 && blue <= 14) {
					line_sum += line;
					printf("Added!\n");
				}
				break;
			}	
		}
		
		printf("Game %d: %d red, %d green, %d blue;\n", line, red, green, blue);
		line++;
	}

	fclose(file);

	printf("Part 1: %d\n", line_sum);
}
