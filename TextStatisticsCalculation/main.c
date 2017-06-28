#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main()
{
	int k, numLines = 0, Nbrackets1 = 0, Nbrackets2 = 0, Cbrackets1 = 0, Cbrackets2 = 0;
	float commNum1 = 0, commNum2 = 0, tabs = 0, spaces = 0;
	char str[10000];
	char ch, file_name[75];
	FILE *fp;
	char writtenText[2000];
	printf("Enter the name of file you wish to see with extension .c\n");
	gets(file_name);
	fp = fopen(file_name, "a");  // reads the file

	printf("Enter a sentence:\n");
	gets(writtenText);
	fprintf(fp, "%s", writtenText);
	fclose(fp);
	fp = fopen(file_name, "r");
	printf("The contents of %s file are :\n\n", file_name);
	int i = 0;
	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
		str[i] = ch;
		i++;
	}
	int fsize = i;

	for (k = 0; k < fsize; k++) {
		if (str[k] == '(')
			Nbrackets1++;
	}
	for (k = 0; k < fsize; k++) {
		if (str[k] == ')')
			Nbrackets2++;
	}
	for (k = 0; k < fsize; k++) {
		if (str[k] == '{')
			Cbrackets1++;
	}
	for (k = 0; k < fsize; k++) {
		if (str[k] == '}')
			Cbrackets2++;
	}
	for (k = 0; k < fsize; k++) {
		if (str[k] == '\t')
			tabs++;
	}
	for (k = 0; k < fsize; k++) {
		if (str[k] == ' ')
			spaces++;
	}
	for (k = 0; k < fsize; k++) {
		if (str[k] == '\n') {
			numLines++;
		}
	}
	for (k = 0; k < fsize - 1; k++) {
		if (str[k] == '/' && str[k + 1] == '*') {
			k += 2;
			while (str[k] != '*' && str[k + 1] != '/') {
				commNum1++; /* */
				if (str[k] == ' ') {
					commNum1--;
				}
				k++;
				//			printf("commNum1 = %d\n",commNum1);					//just to test if my calculations are correct
			}
		}
	}
	commNum1 -= 2;
	for (k = 0; k < fsize - 1; k++) {
		if (str[k] == '/' && str[k + 1] == '/') {
			k += 2;
			while (str[k + 2] != '\n' && k < fsize) {
				commNum2++;
				if (str[k] == ' ') {
					commNum2--;
				}
				k++;
				//				printf("commNum2 = %d\n",commNum2);					//just to test if my calculations are correct
			}
		}
	}
	commNum2 += 2;
	float commAVG = (commNum1 + commNum2) / fsize * 100;;
	float avgTAS = (tabs + spaces) / 2;
	int choice2;
	printf("\n\nChoose an option:\n1.Print the number of () brackets\n");
	printf("2.Print the number of{} brackets\n");
	printf("3.Print the AVG number of spaces and tabulations compared to the number of lines\n");
	printf("4.Print the percentage of comments compared to the whole text\n");
	printf("5.Print all\nYour option: ");
	scanf_s("%d", &choice2);
	if (choice2 == 1) {
		printf("\nOccurence of character ( : %d", Nbrackets1);
		printf("\nOccurence of character ) : %d", Nbrackets2);
	}
	if (choice2 == 2) {
		printf("\nOccurence of character {  : %d ", Cbrackets1);
		printf("\nOccurence of character } : %d ", Cbrackets2);
	}
	if (choice2 == 3) {
		printf("\nAverage number of spaces and tabulations compared to the number of lines: %f compared to %d", avgTAS, numLines);
	}
	if (choice2 == 4) {
		printf("\nPercentage of comment text in the file: %f%%", commAVG);
	}
	if (choice2 == 5) {
		printf("\n\nOccurence of character ( : %d", Nbrackets1);
		printf("\nOccurence of character ) : %d", Nbrackets2);
		printf("\nOccurence of character {  : %d ", Cbrackets1);
		printf("\nOccurence of character } : %d ", Cbrackets2);
		printf("\nAverage number of spaces and tabulations compared to the number of lines: %f compared to %d", avgTAS, numLines);
		printf("\nPercentage of comment text in the file: %f%%", commAVG);
	}
	_getche();
	fclose(fp);
	return 0;
}