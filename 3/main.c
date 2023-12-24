#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

void part1();
/*void part2();*/

int main() {
    part1();
    /*part2();*/
    return 0;
}

int special(char x) {
	return x != '.' && !isdigit(x) ? 1 : 0;
}

int adj(int num, int row, int start, int end, char mat[140][140]) {
	int i;
	for (i = start; i < end; i++) {
		if (row == 0) {
            if (i != 0 && i != 139) {
                if (special(mat[row][i-1]) || special(mat[row+1][i-1]) || special(mat[row+1][i]) || special(mat[row+1][i+1]) || special(mat[row][i+1])) {
                    return num;
                }
            } else if (i == 0) {
                if (special(mat[row][i+1]) || special(mat[row+1][i+1]) || special(mat[row+1][i])) {
                    return num;
                }
            } else {
                if (special(mat[row][i-1]) || special(mat[row+1][i-1]) || special(mat[row+1][i])) {
                    return num;
                }
            }
        } else if (row == 139) {
            if (i != 0 && i != 139) {
                if (special(mat[row][i-1]) || special(mat[row-1][i-1]) || special(mat[row-1][i]) || special(mat[row-1][i+1]) || special(mat[row][i+1])) {
                    return num;
                }
            } else if (i == 0) {
                if (special(mat[row][i+1]) || special(mat[row-1][i+1]) || special(mat[row-1][i])) {
                    return num;
                }
            } else {
                if (special(mat[row][i-1]) || special(mat[row-1][i-1]) || special(mat[row-1][i])) {
                    return num;
                }
            }
        } else {
            if (i != 0 && i != 139) {
                if (special(mat[row][i-1]) || special(mat[row-1][i-1]) || special(mat[row-1][i]) || special(mat[row-1][i+1]) || special(mat[row][i+1]) || special(mat[row+1][i+1]) || special(mat[row+1][i]) || special(mat[row+1][i-1])) {
                    return num;
                }
            } else if (i == 0) {
                if (special(mat[row][i+1]) || special(mat[row-1][i+1]) || special(mat[row-1][i]) || special(mat[row+1][i+1]) || special(mat[row+1][i])) {
                    return num;
                }
            } else {
                if (special(mat[row][i-1]) || special(mat[row-1][i-1]) || special(mat[row-1][i]) || special(mat[row+1][i]) || special(mat[row+1][i-1])) {
                    return num;
                }
            }
        }
	}

	return 0;
}

void part1() {
    int sum = 0, num_i = 0;
    char curr_num[6];
	int i = 0, j = 0;
	char mat[140][140];
	char c;
	FILE* file;
	file = fopen("input.txt", "r");

	while ((c = getc(file)) != EOF) {
		mat[i][j] = c;
		j++;
		if (c == '\n') {
			i += 1;
			j = 0;
		}
	}
	fclose(file);
	
	for (i = 0; i < 140; i++) {
        for (j = 0; j < 140; j++) {	
            if (isdigit(mat[i][j])) {
                curr_num[num_i] = mat[i][j];
                num_i++;
            } else {
                if (isdigit(mat[i][j-1])) {
                    sum += adj(atoi(curr_num), i, j-strlen(curr_num), j, mat);
                    num_i = 0;
                    memset(curr_num, '\0', sizeof(curr_num));
                }
            }
        }
    }

    printf("Part 1: %d\n", sum);
}