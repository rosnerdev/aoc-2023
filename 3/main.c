#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

char (*get_mat(const char*))[140];
int (*get_coords(char (*mat)[140]))[2];
int get_gears(char (*mat)[140]);

void part1();
void part2();

int main() {
    part1();
    part2();
    return 0;
}

void part2() {
    double sum = 0;
    double ratio = 1;
    int found = 0;
    char curr_num[10];
    int num_i = 0;
    int track = 0;
    int (*nums)[4] = calloc(1, sizeof(int[4]));
    char (*mat)[140] = get_mat("input.txt");
    int (*coords)[2] = get_coords(mat);
    int gears_num = get_gears(mat);

    int i, j;
    for (i = 0; i < 140; i++) {
        for (j = 0; j < 140; j++) {
            if (isdigit(mat[i][j]) && j != 139) {
                curr_num[num_i] = mat[i][j];
                num_i++;
            } else {
                if (isdigit(mat[i][j]) && j == 139) {
                    curr_num[num_i] = mat[i][j];
                    j++;
                }

                nums = realloc(nums, sizeof(int[4]) * (track + 1));
                nums[track][0] = j - strlen(curr_num);
                nums[track][1] = j;
                nums[track][2] = atoi(curr_num);
                nums[track][3] = i;
                track++;
                num_i = 0;
                memset(curr_num, '\0', sizeof(curr_num));
            }
        }
    }

    for (i = 0; i < gears_num; i++) {
        for (j = 0; j < track + 1; j++) {
            int x;
            for (x = nums[j][0]; x < nums[j][1]; x++) {
                if ((coords[i][0] == x - 1 || coords[i][0] == x || coords[i][0] == x + 1) && (coords[i][1] == nums[j][3] - 1 || coords[i][1] == nums[j][3] || coords[i][1] == nums[j][3] + 1)) {
                    found++;
                    ratio *= nums[j][2];
                    break;
                }
            }
        }

        if (found == 2) {
            sum += ratio;
        }
        found = 0;
        ratio = 1;
    }

    free(nums);

    printf("Part 2: %.f\n", sum);
}

int get_gears(char (*mat)[140]) {
    int gears = 0;
    int i, j;
    for (i = 0; i < 140; i++) {
        for (j = 0; j < 140; j++) {
            if (mat[i][j] == '*') {
                gears++;
            }
        }
    }

    return gears;
}

int (*get_coords(char (*mat)[140]))[2] {
    int (*coords)[2] = calloc(1, sizeof(int[2]));
    int track = 0;
    int i, j;

    if (coords == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }

    for (i = 0; i < 140; i++) {
        for (j = 0; j < 140; j++) {
            if (mat[i][j] == '*') {
                coords = realloc(coords, sizeof(int[2]) * (track + 1));
                coords[track][0] = j;
                coords[track][1] = i;
                track++;
            }
        }
    }

    return coords;
}

char (*get_mat(const char* filename))[140] {
    char (*mat)[140] = calloc(140, sizeof(char[140]));
    char c;
    int i = 0, j = 0;
    FILE* file;
    file = fopen(filename, "r");

    while ((c = getc(file)) != EOF) {
        if (c != '\n') {
            mat[i][j] = c;
            j++;
        } else {
            i += 1;
            j = 0;
        }
    }

    fclose(file);

    return mat;
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
            if (isdigit(mat[i][j]) && j != 139) {
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