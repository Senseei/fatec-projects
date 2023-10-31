#include <iostream>

using namespace std;

void initializeArray(int arr[], int length);
void printArray(int arr[], int length);
int getPositiveInt(string prompt);
int getFatorial(int n);
bool isPrime(int n);

void exercicio1(int length);
void exercicio2(int length);
void exercicio3(int length);
void exercicio4(int length);
void exercicio5(int length);
void exercicio6(int length);
void exercicio7(int length);
void exercicio8(int length);

int main() {
    exercicio1(10);
    exercicio2(20);
    exercicio3(10);
    exercicio4(5);
    exercicio5(15);
    exercicio6(5);
    exercicio7(20);
    exercicio8(10);
}

void initializeArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        arr[i] = 0;
}

void printArray(int arr[], int length) {
    if (length > 0)
        cout << "|";

    for (int i = 0; i < length; i++)
        cout << arr[i] << "|";
    cout << "\n";
}

int getPositiveInt(string prompt) {
    int n;

    do {
        cout << prompt;
        cin >> n;
    }
    while (n < 0);
    return n;
}

int getFatorial(int n) {
    if (n == 1)
        return 1;
    return n * getFatorial(n - 1);
}

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void exercicio1(int length) {
    int vetor[length];
    initializeArray(vetor, length);
    
    for (int i = 0; i < length; i++)
        vetor[i] = i + 1;
    
    cout << "--------------------------\n";

    printArray(vetor, length);

    cout << "--------------------------\n";
}

void exercicio2(int length) {
    int vetor[length], soma = 0;
    initializeArray(vetor, length);

    for (int i = 0, j = 10; i < length; i++, j+=2) {
        vetor[i] = j;
        soma += vetor[i];
    }    

    printArray(vetor, length);

    cout << "soma: " << soma << "\n";
    cout << "--------------------------\n";
}

void exercicio3(int length) {
    int vetorA[length], vetorB[length];
    initializeArray(vetorA, length);
    initializeArray(vetorB, length);

    for (int i = 0; i < length; i++) {
        vetorA[i] = i + 1;
        vetorB[i] = vetorA[i] * 2;
    }

    printArray(vetorA, length);
    printArray(vetorB, length);

    cout << "--------------------------\n";
}

void exercicio4(int length) {
    int vetor[length];
    initializeArray(vetor, length);

    for (int i = 0; i < length; i++) {
        cout << "Digite um numero: ";
        cin >> vetor[i];
    }
    cout << "\n";

    printArray(vetor, length);
    cout << "--------------------------\n";
}

void exercicio5(int length) {
    int binario[length], n, i;

    initializeArray(binario, length);
    n = getPositiveInt("Digite um numero positivo: ");

    for (i = 0; i < length && n > 0; i++, n/=2)
        binario[i] = n % 2;
    
    cout << "binario: ";
    for (int j = i - 1; j >= 0; j--)
        cout << binario[j];
    cout << "\n--------------------------\n";
}

void exercicio6(int length) {
    int vetorA[length], fatorial[length];

    initializeArray(vetorA, length);
    initializeArray(fatorial, length);

    for (int i = 0; i < length; i++) {
        cout << "Digite um numero: ";
        cin >> vetorA[i];
    }
    cout << "\n";

    for (int i = 0; i < length; i++)
        fatorial[i] = getFatorial(vetorA[i]);

    printArray(vetorA, length);
    printArray(fatorial, length);
    cout << "--------------------------\n";
}

void exercicio7(int length) {
    int fibonacci[length], termo = 0;

    initializeArray(fibonacci, length);

    termo = getPositiveInt("Digite um numero maior que 2: ");

    for (int i = 0; i < termo && i < length; i++) {
        if (i < 2)
            fibonacci[i] = 1;
        else
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    cout << "fibonacci: ";
    if (termo <= length)
        printArray(fibonacci, termo);
    else
        printArray(fibonacci, length);
    cout << "--------------------------\n";
}

void exercicio8(int length) {
    int vetorA[length], eprimo[length];

    initializeArray(vetorA, length);
    initializeArray(eprimo, length);

    for (int i = 0; i < length; i++) {
        cout << "Digite um numero: ";
        cin >> vetorA[i];
    }
    cout << "\n";

    for (int i = 0; i < length; i++) {
        if (isPrime(vetorA[i]))
            eprimo[i] = 1;
        else
            eprimo[i] = 0;
    }

    for (int i = 0; i < length; i++) 
        cout << vetorA[i] << " -> " << eprimo[i] << "\n";
    cout << "--------------------------\n";
}