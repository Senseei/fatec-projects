#include <iostream>

using namespace std;

int somaimparseformultide3(int);
int fibonacci(int, int, int);

int main() {
    int n;
    cout << "Digite um numero para somar os numeros primos e divisiveis por 3 ate esse numero: ";
    cin >> n;
    cout << somaimparseformultide3(n);

    cout << "\n------------------\n";

    int termo;
    cout << "Digite o termo fibonacci para buscar: ";
    cin >> termo;
    cout << fibonacci(1, 1, termo);
}

int somaimparseformultide3(int n) {
    if (n <= 0)
        return 0;
    if (n % 3 == 0 && !(n % 2 == 0))
        return n + somaimparseformultide3(n - 1);
    return 0 + somaimparseformultide3(n - 1);
}

int fibonacci(int ant2, int ant1, int termo) {
    if (termo <= 2)
        return ant1;
    return fibonacci(ant1, ant2 + ant1, termo - 1);
}