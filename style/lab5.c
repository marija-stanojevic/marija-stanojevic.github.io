#include <stdio.h>

int returnLength(char arr[]);
int returnLengthPtr(char* arr);
int returnSizeof(int arr[]);
int returnSizeofPtr(int* arr);
int lengthWithSizeof(int arr[]);
int lengthWithSizeofPtr(int* arr);
void reverseArray(int arr[], int len); //equivalent as (int* arr, int len)
void printArray(int* arr, int len); //equivalent as (int arr[], int len)
void printMatrix(int n, int m, double mat[n][m]);
void changeToOne(double* mat, int n, int m); //pointer to the array of arrays of size m

int main() {
	//Pointers and arrays
	//Showing 1
	char a[10];
	char *p;
	printf("Showing 1: Size of a is %lu and size of p is %lu. Value of a is %p and value of p is %p. \n", sizeof(a), sizeof(p), a, p); //a is an array of 10 chars, so it's size is 10*1B. p is 1 pointer, so its size is 8B
	
	//Showing 3
	char b[10] = "don't";
	char *q = "don't";
	printf("Showing 3: Address of b is %p and b is %p. Address of q is %p and q is %p\n", &b, b, &q, q);
	printf("\tString in b is \"%s\" and string in q is \"%s\"\n", b, q);

	//Showing 4
	printf("Showing 4: b[2] gives '%c'. *(b+2) gives '%c'. q[2] gives '%c'. *(q + 2) gives '%c'\n", b[2], *(b+2), q[2], *(q+2)); 
	
	//Showing 5
	//a = "hello"; //uncomment to see that you'll get an error
	p = "hello";
	printf("Showing 5: We gave value to p. p is \"%s\". Assigning whole string to a gave an error.\n", p);
	
	//Showing 6
	//b++; //uncomment to see that you'll get an error
	q++;
	printf("Showing 6: b++ gives an error, but q++ has value %p\n", q);
	
	//Showing 7
	//q[0] = 'c'; //uncomment to see that you'll get an error
	b[0] = 'c';
	printf("Showing 7: q[0]='c'; gives an error. b[0] = 'c'; changes string, so b is now %s \n", b);
	
	//Showing 8
	//char c[5] = "Welcome"; //uncomment to see you'll get an error
	char *r = "Welcome";
	printf("Showing 8: char c[5] = \"Welcome\"; gives an error, but char*r=\"Welcome\"; stores %s in r\n\n", r);

	printf("Address of third element of b written as b+2 is %p and written as &b[2] is %p.\n\t Address of third element of q written as q+2 is %p and written as &q[2] is %p\n\n\n", b+2, &b[2], q+2, &q[2]);
	


	//Arrays, pointers and functions
	printf("Using returnLength function: length of b is %d and length of q is %d\n", returnLength(b), returnLength(q));
	printf("Using returnLenghtPtr function: length of b is %d and length of q is %d\n\n", returnLengthPtr(b), returnLengthPtr(q));
	//int *c = {1, 2, 3}; //gives an error because int*c defines only a pointer and there is no space to put array
	int c[5] = {4, 5, 6, 7};
	int* d = c; // d now points on array c;
	printf("Using returnSizeof function: length of c is %d and length of d is %d\n", returnSizeof(c), returnSizeof(d));
	printf("Using returnSizeofPtr function: length of c is %d and length of d is %d\n", returnSizeofPtr(c), returnSizeofPtr(d));
	printf("Using lengthWithSizeof function: length of c is %d and length of d is %d\n", lengthWithSizeof(c), lengthWithSizeof(d));
	printf("Using lenghtWithSizeofPtr function: length of c is %d and length of d is %d\n\n", lengthWithSizeofPtr(c), lengthWithSizeofPtr(d));
	printf("Only in the function where array is defined we can use sizeof(arr)/sizeof(arr[0]) to find array size. Size is: %lu. However, here we already know the size that we used\n", sizeof(c)/sizeof(c[0]));
	printf("So, make sure to send size of list as argument or to define it as symbolic constant or global variable\n\n");
	int num = 5;
	int* e = &num; // works well because we try to put address of num into e and e can store 1 address
	//int f[5] = &num; //doesn't work because we try to put address in f and f can store only array of integers
	printArray(c, 4);
	reverseArray(c, 4);
	printArray(c, 4);

	printf("Arrays are passed by reference to functions, so all the changes do in function are done in original array memory and we don't need to return changes\n");
	printf("Since functions exchange pointers to arrays, we can't return array from function. All the arrays defined in function exist only until that function doesn't finish.\n\n\n");



	//Multidimensional arrays
	int n = 2, m = 3;
	double mat[2][3] = {{1, 2, 3}, {4, 5, 6}}; // n is number of rows, m is number of columns
	printMatrix(n, m, mat);
	changeToOne((double*)mat, n, m);
	printMatrix(n, m, mat);
}


void printMatrix(int n, int m, double mat[n][m]) { //you have to give at least number of columns, ie. can write mat[][m] as well and m has to be given as parameter before mat[][m]
	printf("Matrix is: \n");  // if you do mat[n][m], n and m have to be given as parameters. Mat is pointer to 2D array, so all changes done on mat will be visible from main
	int i;				//As for array, you can't access the matrix created in some function after function is finished.
	for (i = 0; i < n; i++) {
		int j;
		for (j = 0; j < m; j++) { 
			printf("%f, ", mat[i][j]);
		}
		printf("\n");
	}
}

void changeToOne(double* mat, int n, int m) { // alternative way to pass matrix, here the address of memory of your matrix is passed
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			*(mat + i * m + j) = 1;
		}
	}
}

void printArray(int* arr, int n) {
	printf("Array is:");
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}


int returnLength(char str[]) { // this is appropriate way to find size of char array
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

int returnLengthPtr(char* str) { //as you can see this function behave the same as returnLength because both of them pass array by reference
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

int returnSizeof(int arr[]) {
	return sizeof(arr); //sizeof(arr) is not the size of arr array. sizeof(arr) returns 8, ie. size of 1 pointer
}

int returnSizeofPtr(int *arr) { //as you can see this function behave the same as returnSizeof
	return sizeof(arr);
}

int lengthWithSizeof(int arr[]) {
	return sizeof(arr) / sizeof(arr[0]); //this is not size of an array, instead it is size of pointer (8) divided by size of first element (int in this case, so 4) => 8/4 = 2
} // this is different from using sizeof(arr)/sizeof(arr[0]) in function where array is defined, because here arr is pointer to the array and not the array itself

int lengthWithSizeofPtr(int* arr) { // same as previous function
	return sizeof(arr) / sizeof(arr[0]);
}

void reverseArray(int arr[], int n) {
	int i;
	for (i = 0; i < n/2; i++) {
		int tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
}
