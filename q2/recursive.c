#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char inputString[100];
char searchChar;

int length;
char smallest;
char output;
int a = 0;

char smallest_character ();

int main(int argc, char *argv[])
{
char temp;
char output = ' ';
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
				inputString[count] = temp;
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

length = count;

output = smallest_character();
printf("The smallest character is '%c'.\n", output);

fclose(input);

return 0;
}


char smallest_character () { 
if (smallest == NULL || inputString[a] < smallest) {
	smallest = inputString[a];
}

if (inputString[a] > searchChar) {
	if (output == NULL || inputString[a] < output) {
		output = inputString[a];
	}
}	


if (a < length - 1) {
	a++;
}
else if (output == NULL) {
	output = smallest;
	return output;
}
else {
	return output;
}


smallest_character();

return output;
}
