#include <stdio.h>
#include <stdlib.h>

char valToHexLetter(int v) {
	switch (v) {
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
	}

}

void decimalToBase(int n, int base) { //base=2 converts to binary, base=8 to octal, base=16 to hexadecimal
	printf("Transfering number %d from decimal to base %d \n", n, base);	
	char bNum[1000];
	int i = 0;
	if (base == 2 || base == 8 || base == 16) {
		while (n > 0) {
			if (base == 16 && n%base > 9) {
				bNum[i++] = valToHexLetter(n%base);
			} else {
				bNum[i++] = n % base + '0';
			}
			n = n / base;
		}
		for (int j = 0; j < i/2; j++) { //reverse the order of letters
			char temp = bNum[j];
			bNum[j] = bNum[i - j - 1];
			bNum[i - j - 1] = temp;
		}
		bNum[i] = '\0';
		printf("%s \n", bNum);
	}
}

int hexLetterToVal(char c) {
	switch(c) {
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
	}
}

void baseToDecimal(char* num, int len, int base) { //base=2 converts from binary, base=8 from octal, base=16 from hexadecimal, each character in n contain one allowed digits
	printf("Transfering number %s from base %d to decimal \n", num, base);	
	int m = 0;
	int degree = 1;
	int i = len - 1;
	int dig = 0;
	while (i >= 0) {
		if (base == 16 && num[i] > 'A') {
			dig = hexLetterToVal(num[i--]);
		} else {
			dig = num[i--] - '0';
		}
		m += dig * degree; //last digit of current number is multiplied with degree of it's position; we move to the left
		degree *= base; // degree = base^current position from right, we move to the next position towards left
	}
	printf("%d \n", m);
}

int main() {
	//Binary values start with 0b
	int x = 0b1011; //binary value 1011, ie. decimal 11 (1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 1 * 2^0)
	printf("Decimal value of 0b1011 is %d \n", x); // would print decimal 11
	decimalToBase(11, 2); // prints number 11 as binary number
	baseToDecimal("1011", 4, 2);

	//Octal values start with 0
	int y = 014; // octal value 14, ie. decimal 12 (1 * 8^1 + 4 * 8^0)
	printf("Decimal is %d and octal is %o and hexadecimal is %x \n", y, y, y);
	decimalToBase(12, 8);
	baseToDecimal("014", 3, 8);

	//Hexadecimal values start with 0x
	int z = 0xA6; // hexadecimal value A6, ie. decimal 166 (10 * 16^1 + 6 * 16^0);
	printf("Decimal is %d and hexadecimal is %x and octal is %o \n", z, z, z);
	decimalToBase(166, 16);
	baseToDecimal("A6", 2, 16);

	printf("~140 as char is '%c' (115th character in ASCII table) and as integer is %d and as unsigned integer is %u, 140 & 25 is %d, 140 | 25 is %d, 140 ^ 25 is %d, 140 >> 2 is %d, 140 << 3 is % d", ~140, ~140, ~140, 140 & 25, 140 | 25, 140 ^ 25, 140 >> 2, 140 << 3); // explanations are in Lab 4 slides
}
