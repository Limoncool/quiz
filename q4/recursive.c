#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int A[100];
char temp;
int n = 0;
int minus = 0;
int length;
int max_beginning_here = 0;
int max_ending_here = 0;
int max_pointer = 0;
int max_so_far = 0;
int a = 0;
int b;
int on = 0;
int aa = 0;

int MaxSubArray ();


int main(int argc, char *argv[]) 
{
FILE *input;
input = fopen (argv[1], "r");
if (input == NULL) {
	printf("FILE NOT FOUND!!");
	exit(1);
}

while (fscanf (input, "%c", &temp) != EOF) {
	if (temp == '-') {
		minus = 1;
	}
	else if (temp != '[' && temp != ']' && temp != ',') {
		switch (minus) {
			case 0:
				A[a] = (int) (temp - '0');
				break;
			case 1:
				A[a] = (int) -(temp - '0');
				minus = 0;
				break;
			default:
				break;
		}		
		a++;
	}
}

length = a;
a = 0;
MaxSubArray();

printf ("The maximum contiguous subarray of input is [");
for (b = max_beginning_here;b <= max_ending_here;b++) {
	printf ("%d", A[b]);
	if (b < max_ending_here) {
		printf (",");
	}
}
printf ("],\nwhich has the maximum sum = %d\n", max_so_far);

fclose(input);
return 0;
}


int MaxSubArray () {
max_pointer += A[a];
if (max_pointer < 0) {
	max_pointer = 0;
}
	
if (on == 0 && max_pointer > 0) {
	max_beginning_here = a;		
	on = 1;
}

if (max_so_far < max_pointer) {
	max_so_far = max_pointer;
	max_ending_here = a;
}


if (a < length - 1) {
	a++;
}
else {
	return 0;
}


MaxSubArray();

return 0;
}


