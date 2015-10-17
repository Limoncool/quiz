#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MaxSubArray (int[], int);

int main(int argc, char *argv[]) 
{
int Atemp[100];
char temp;
int n = 0;
int a = 0;
int minus = 0;

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
	else if (temp != '[' && temp != ']' && temp != ',' && temp != '\n') {
		switch (minus) {
			case 0:
				Atemp[a] = (int) (temp - '0');
				break;
			case 1:
				Atemp[a] = (int) -(temp - '0');
				minus = 0;
				break;
			default:
				break;
		}		
		a++;
	}
}

int A[a];
int aco;
for (aco = 0;aco < a;aco++) {
	A[aco] = Atemp[aco];
}
MaxSubArray(A,n);

fclose(input);
return 0;
}


int MaxSubArray (int A[], int n) {
int length = sizeof(A);
int max_beginning_here = 0;
int max_ending_here = 0;
int max_pointer = 0;
int max_so_far = 0;
int a,b;
int on = 0;

for (a = 0;a < length;a++) {
	max_pointer += A[a];
	if (max_pointer < 0) {
		max_pointer = 0;
		on = 0;
	}
	
	if (on == 0 && max_pointer > 0) {
		max_beginning_here = a;		
		on = 1;
	}

	if (max_so_far < max_pointer) {
		max_so_far = max_pointer;
		max_ending_here = a;
	}
}

printf ("The maximum contiguous subarray of input is [");
for (b = max_beginning_here;b <= max_ending_here;b++) {
	printf ("%d", A[b]);
	if (b < max_ending_here) {
		printf (",");
	}
}
printf ("],\nwhich has the maximum sum = %d\n", max_so_far);

return 0;
}


