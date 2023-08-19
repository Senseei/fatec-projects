#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


int len(int n);
int convert(int numToConvert, int base);
int convertFromString(char numToConvert[], int base);
void toUppercase(char str[]);

int main(void) {
    printf("From binary: %d\n", convert(101, 2));
    printf("From hexadecimal: %d\n", convertFromString("AF", 16));
}

int convert(int numToConvert, int base) {
    int sum = 0;

    for (int i = 0, length = len(numToConvert); i < length; i++) {
        int digit = numToConvert % 10;
        numToConvert /= 10;
        sum += digit * pow(base, i);
    }
    return sum;
}

int convertFromString(char numToConvert[], int base) {
    char num[strlen(numToConvert) + 1];
    strcpy(num, numToConvert);

    int sum = 0;

    for (int i = 0, length = strlen(num); i < length; i++) {
        int digit = num[length - i - 1];
        if (isalpha(digit)) {
            int toDecimal = 10 + digit - 'A';
            sum += toDecimal * pow(base, i);
        }
        else if (isdigit(digit)) {
            int toDecimal = digit - '0';
            sum += toDecimal * pow(base, i);
        }
    }
    return sum;
}

int len(int n) {
    int count = 0;

    if (n == 0)
        return 1;

    while (n != 0) {
        n /= 10;
        count++;
    }

    return count;
}

void toUppercase(char str[]) {
    for (int i = 0; str[i]; i++)
        str[i] = toupper(str[i]);
}