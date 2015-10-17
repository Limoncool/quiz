#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char smallest_character (char[], char);

int main(int argc, char *argv[])
{
char tempInput[100];
char searchChar;
char temp;
char output;
int count = 0;
int end = 0;

FILE *input;
input = fopen (argv[1], "r");
if (input == NULL) {
	printf("FILE NOT FOUND!!");
	exit(1);
}

while (fscanf (input, "%c", &temp) != EOF) {
	if (temp == ']') {
		end = 1;
	}
	else if (temp != '[' && temp != '\'' && temp != ',' && temp != ' ' && temp != '\n') {
		switch(end) {
			case 0:
				tempInput[count] = temp;
				count++;
				break;
			case 1:
				searchChar = temp;
				end = 0;
				break;
			default:
				break;
		}
	}
}

char inputString[count];
int eco;
for (eco = 0;eco < count;eco++) {
	inputString[eco] = tempInput[eco];
}

output = smallest_character(inputString, searchChar);
printf("The smallest character is '%c'.\n", output);


fclose(input);
return 0;
}


char smallest_character (char str[], char c) {
int length = strlen(str);
char smallest = NULL, result = NULL;
int a;

for (a = 0;a < length;a++) {
	if (smallest == NULL || str[a] < smallest) {
		smallest = str[a];
	}

	if (str[a] > c) {
		if (result == NULL || str[a] < result) {
			result = str[a];
		}
	}	
}

if (result == NULL) {
	result = smallest;
}

return result;
}

