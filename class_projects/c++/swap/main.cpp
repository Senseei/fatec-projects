#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	int a=0, b=0;
	cout << "Troca dois numeros de posição\n";
	cout << "Insira um numero: ";
	cin >> a;
	cout << "Insira outro numero: ";
	cin >> b;
	
	cout << "Seus numeros: " << a << " e " << b << "\n";
	
	int temp = a;
	a = b;
	b = temp;
	
	cout << "Trocados: " << a << " e " << b << "\n";
	
	return 0;
}
