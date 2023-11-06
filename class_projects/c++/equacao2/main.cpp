#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int a = 0, b = 0, c = 0, delta = 0;

    cout << "Digite 3 valores inteiros para o calculo de uma equação do segundo grau.";
    cout << "Valor de A: ";
    cin >> a;

    cout << "Valor de B: ";
    cin >> b;

    cout << "Valor de C: ";
    cin >> c;

    delta = b*b - 4 * a * c;

    if (delta < 0) {
        cout << "Não tem raizes reais";
        return 0;
    }
    
    int x1 = (-b + sqrt(delta)) / (2 * a);
    int x2 = (-b - sqrt(delta)) / (2 * a);

    if (delta == 0) {
        cout << "Existe uma raiz real: " << x1;
    }
    else {
        cout << "Existem duas raizes reais: \n" << "x1 = " << x1 << "\nx2 = " << x2;
    }
    
    return 0;
}