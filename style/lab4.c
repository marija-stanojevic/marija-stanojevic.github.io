#include <stdio.h>
#include <stdlib.h>

int n = 0; // have to put n=0, because most of C compliers will assign random value to n

void strLength(char str[]); // declaring function before the call
void toLowercase(char str[]);
char* isPalindrome(char* str); //returns string that says if it's palindrom or not

int main() {
    char str[50];  //* str = malloc(sizeof(char)*100) is equivalent to char str[50]; allocates 50 char spaces in memory
    fgets(str, 100, stdin); // don't need & becasue str is address of char array
    toLowercase(str); //we don't need to return char* because we call-by-reference
    printf("String %s %s \n", str, isPalindrome(str));
    exit(0);
}

void strLength(char str[]) { // we can use char str[] or char * p
    for (int i = 0; str[i] != '\0'; i++) { //move through the string until we come to '\0'
        n++; // we are updating global variable, so we don't have to return anything
    }
}

void toLowercase(char str[]) { // we can use char str[] or char * p 
    int c = 0;
    while (*(str + c) != '\0') { //is current character the one that ends the string
        if (str[c] >= 65 && str[c] <= 90) { //str[c] is equivalent to *(str + c)
            str[c] += 32; //converts uppercase into lowercase, in ASCII A is 65, a is 97    
        } 
        c++;
    }
} // return type is void, so we don't have to return anything

char* isPalindrome(char* str) { // we can use char str[] or char * p
    int c = 0;
    while (c <= n/2) { // for 5 elements would give us 2nd, so we check if 1st == 5th and 2nd == 4th element
        if (*(str + c) != *(str + n - c)) { //c and n-c position from the begining of string
            return "is not palindrom";
        }
	c++;
    }
    return "is palindrom";
}

