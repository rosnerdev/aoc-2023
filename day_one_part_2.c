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
		char nums[24];
		char curr[2];
		int j = 0;
		
		int i;
		for (i = 0; i < strlen(str); i++) {
			switch (tolower(str[i])) {
				case 'o':
					switch (tolower(str[i+1])) {
						case 'n':
							switch (tolower(str[i+2])) {
								case 'e':
									nums[j] = '1';
									j++;
									break;
							}
							break;
					}
					break;

				case 't':
					switch (tolower(str[i+1])) {
						case 'w':
							switch (tolower(str[i+2])) {
								case 'o':
									nums[j] = '2';
									j++;
									break;
							}
							break;
						case 'h':
							switch (tolower(str[i+2])) {
								case 'r':
									switch (tolower(str[i+3])) {
										case 'e':
											switch (tolower(str[i+4])) {
												case 'e':
													nums[j] = '3';
													j++;
													break;
											}
											break;
									}
									break;
							}
							break;
					}
					break;

				case 'f':
					switch (tolower(str[i+1])) {
						case 'o':
							switch (tolower(str[i+2])) {
								case 'u':
									switch (tolower(str[i+3])) {
										case 'r':
											nums[j] = '4';
											j++;
											break;
									}
									break;
							}
							break;
						case 'i':
							switch (tolower(str[i+2])) {
								case 'v':
									switch (tolower(str[i+3])) {
										case 'e':
											nums[j] = '5';
											j++;
											break;
									}
									break;
							}
							break;
					}
					break;

				case 's':
					switch (tolower(str[i+1])) {
						case 'i':
							switch (tolower(str[i+2])) {
								case 'x':
									nums[j] = '6';
									j++;
									break;
							}
							break;
						case 'e':
							switch (tolower(str[i+2])) {
								case 'v':
									switch (tolower(str[i+3])) {
										case 'e':
											switch (tolower(str[i+4])) {
												case 'n':
													nums[j] = '7';
													j++;
													break;
											}
											break;
									}
									break;
							}
							break;
					}
					break;

				case 'e':
					switch (tolower(str[i+1])) {
						case 'i':
							switch (tolower(str[i+2])) {
								case 'g':
									switch (tolower(str[i+3])) {
										case 'h':
											switch (tolower(str[i+4])) {
												case 't':
													nums[j] = '8';
													j++;
													break;
											}
											break;
									}
									break;
							}
							break;
					}
					break;

				case 'n':
					switch (tolower(str[i+1])) {
						case 'i':
							switch (tolower(str[i+2])) {
								case 'n':
									switch (tolower(str[i+3])) {
										case 'e':
											nums[j] = '9';
											j++;
											break;
									}
									break;
							}
							break;
					}
					break;
				
				default:
					if (isdigit(str[i]) && str[i] != '0') {
						nums[j] = str[i];
						j++;
					}
			}
		}
		
		curr[0] = nums[0];
		curr[1] = nums[j-1];
		
		printf("%s\n", curr);
		acc += atoi(curr);
	}

	fclose(file);
	printf("\n%d\n", acc);

	return 0;
}
