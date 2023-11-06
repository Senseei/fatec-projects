#include <iostream>
#include <string>

using namespace std;

void println(string s);
int getPositiveInteger(string prompt);

void printNumbers(int min, int max);
void printOddNumbers(int min, int max);
void printEvenNumbers(int min, int max);
void readNumbersInParemeter(int min, int max, int numbers);
void getStudentsGrade(int students);
void printNumbersByRest(int min, int max, int dividing, int rest);
int getFatorialOf(int number);
string decimalToBinary(int decimal);
bool isPrime(int n);
void fibonacci();

int main() {

    println("\nPrints numbers between 0 and 100");
    printNumbers(0, 100);

    println("\nPrints odd numbers between 0 and 100");
    printOddNumbers(0, 100);

    println("\nPrints even numbers between 10 and 100");
    printEvenNumbers(10, 100);

    println("\nRead 10 numbers, and check if each one is or not between 10 and 20");
    readNumbersInParemeter(10, 20, 2);

    println("\nGet 3 student's grades to calculate their average of n students");
    getStudentsGrade(2);

    println("\nPrints every number divided by 11 with rest 5 between 1000 and 1999");
    printNumbersByRest(10, 121, 11, 5);

    println("\nPrints the fatorial of some number");
    cout << getFatorialOf(getPositiveInteger("Insert a positive number to get the fatorial: "));

    println("\nConverts decimal to binary: ");
    cout << decimalToBinary(getPositiveInteger("Insert a decimal number to convert: "));

    println("\nCheck if a given number is prime");
    cout << isPrime(getPositiveInteger("Digite um numero pra testar se e primo: "));

    println("\nPrints fibonacci sequence");
    fibonacci();

    return 0;
}

void println(string s) {
    cout << s << "\n";
}

int getPositiveInteger(string prompt) {
    int n;
    do {
        cout << prompt;
        cin >> n;
    }
    while (n <= 0);
    return n;
}

void printNumbers(int min, int max) {
    while (min <= max) {
        cout << min;
        if (min < max)
            cout << ", ";
        min++;
    }
    cout << "\n";
}

void printOddNumbers(int min, int max) {
    if (min % 2 == 0)
        min++;

    while (min <= max) {
        cout << min;
        if (min < max - 1)
            cout << ", ";
        min += 2;
    }
    cout << "\n";
}

void printEvenNumbers(int min, int max) {
    int sum = 0;
    if (min % 2 != 0)
        min++;

    while (min <= max) {
        cout << min;
        if (min < max - 1)
            cout << ", ";
        sum += min;
        min += 2;
    }
    cout << "\n";
}

void readNumbersInParemeter(int min, int max, int numbers) {
    int cont = 0, in = 0, out = 0;
    while (cont < numbers) {
        int n;
        cout << "Digite um numero: ";
        cin >> n;
        if (n < min || n > max)
            out++;
        else
            in++;
        cont++;
    }
    cout << "Numbers between " << min << " and " << max << ":\n";
    cout << "in: " << in << "\n";
    cout << "out: " << out << "\n";
}

void getStudentsGrade(int students) {
    int cont = 0;
    float mediag = 0;
    while (cont < students) {
        float grade1 = 0, grade2 = 0, grade3 = 0, media = 0;

        cout << "Digite 3 notas para aluno " << cont << "\n";
        cin >> grade1;
        cin >> grade2;
        cin >> grade3;

        media = (grade1 * 2 + grade2 * 4 + grade3 * 3) / 9;
        cout << "A media do aluno " << cont << " e: " << media;

        if (media >= 6)
            cout << " - Aprovado\n";
        else
            cout << " - Reprovado\n";

        mediag += media;
        cont++;
    }
    
    if (students > 0) {
        mediag /= students;
        cout << "A media geral da sala e: " << mediag << "\n";
    }
}

void printNumbersByRest(int min, int max, int dividing, int rest) {
    if (min % dividing > rest)
        min += dividing - min % dividing + rest;
    else if (min % dividing < rest)
        min += rest - min % dividing;

    while (min <= max) {
        cout << min;
        if (min < max - dividing)
            cout << ", ";

        min += dividing;
    }
    cout << "\n";
}

int getFatorialOf(int number) {
    if (number == 1)
        return 1;

    return number * getFatorialOf(number - 1);
}

string decimalToBinary(int decimal) {
    string binary = "";

    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    if (binary.length() == 0)
        binary += "0";
    
    return binary;
}

bool isPrime(int n) {
    if (n <= 1)
        return false;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void fibonacci() {
    int n, cont = 0;
    do {
        n = getPositiveInteger("Insert a positive number: ");
    }
    while (n <= 2);

    int a = 0, b = 0;
    while (cont < n) {
        if (cont == 0 || cont == 1) {
            cout << 1;
            a = 1, b = 1;
        }
        else {
            int next = a + b;
            cout << next;
            a = b;
            b = next;
        }
        cont++;

        if (cont < n)
            cout << ", ";
    }
}

