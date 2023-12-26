#include <iostream>

using namespace std;

void exercicio1(int);
void exercicio2();
void exercicio5();
void exercicio6();
void exercicio7();
void exercicio8();
void exercicio9();

int get_positive_int(string);

int main() {

}

void exercicio1(int div) {
    cout << "Pede um numero pro usuario e mostra sua divisão por 2\n";
    int n = get_positive_int("Insira um numero inteiro positivo: ");
    cout << n / div << "\n";

    cout << "-----------------------\n";
}

void exercicio2() {
    cout << "Pede dois numeros ao usuario. Mostra a soma dos dois\n";
    int n1 = get_positive_int("Insira um numero inteiro positivo: ");
    int n2 = get_positive_int("Insira outro numero inteiro positivo: ");

    cout << "A soma é: " << n1 + n2 << "\n";

    cout << "-----------------------\n";
}

void exercicio5() {
    cout << "Pede um numero ao usuario, faz a somatoria de todos os numeros ate o informado\n";

    int n = get_positive_int("Insira um numero inteiro positivo: ");
    int soma;

    for (int i = n-1; i > 0; i--)
        soma += i;

    cout << "A somatoria é: " << soma << "\n";

    cout << "-----------------------\n";
}

void exercicio6() {
    cout << "Solicita dois numeros ao usuario, para calcular a potencia\n";

    int base = get_positive_int("Insira um numero para a base: ");
    int expoente = get_positive_int("Insira um numero para o expoente: ");
    if (expoente == 0) {
        cout << "A potencia de " << base << " elevado à " << expoente << " é: " << 1 << "\n"; 
        return;
    }

    int potencia = base;
    for (int i = 0; i < expoente; i++)
        potencia *= base;

    cout << "A potencia de " << base << " elevado à " << expoente << " é: " << potencia << "\n";

    cout << "-----------------------\n";
}

void exercicio7() {
    cout << "Solicita um numero ao usuario, em seguida mostra se o numero é par ou não\n";
    int n = get_positive_int("Insira um numero: ");
    if (n % 2 == 0)
        cout << n << " é par\n";
    else
        cout << n << " não é par\n";

    cout << "-----------------------\n";
}

void exercicio8() {
    cout << "Solicita dois numeros para o coloca-los em ordem crescente e decrescente\n";
    int n1 = 0, n2 = 0;
    
    cout << "Insira um numero: ";
    cin >> n1;
    cout << "Insira outro numero: ";
    cin >> n2;

    if (n1 == n2)
        cout << "Os numeros são iguais.\n";
    else if (n1 > n2) {
        cout << "Crescente: " << n2 << ", " << n1 << "\n";
        cout << "Decrescente: " << n1 << ", " << n2 << "\n";
    }
    else {
        cout << "Crescente: " << n1 << ", " << n2 << "\n";
        cout << "Decrescente: " << n2 << ", " << n1 << "\n";
    }

    cout << "-----------------------\n";
}

void exercicio9() {

}

int get_positive_int(string prompt) {
    int n;
    do {
        cout << prompt;
        cin >> n;
    }
    while(n < 0);

    return n;
}