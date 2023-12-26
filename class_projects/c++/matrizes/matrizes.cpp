#include <iostream>

void exercicio1(int linhas, int colunas);
void exercicio2(int linhas, int colunas);
void exercicio3(int linhas, int colunas);
void exercicio4(int linhas, int colunas);
void exercicio5(int linhas, int colunas);
void exercicio6(int linhas, int colunas);
void exercicio7(int alunos, int meses);
void exercicio8(int linhas, int colunas);

int fatorial(int n);

using namespace std;

int main() {
    exercicio1(0, 0);
    exercicio2(0, 0);
    exercicio3(0, 0);
    exercicio4(0, 0);
    exercicio5(0, 0);
    exercicio6(0, 0);
    exercicio7(0, 0);
    exercicio8(3, 3);
}

void exercicio1(int linhas, int colunas) {
    int matrizA[linhas][colunas];

    cout << "Solicita numeros para o usuario para preencher uma matriz, em seguida mostra a matriz\n";

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "Digite um numero: ";
            cin >> matrizA[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "[ " << matrizA[i][j] << " ]";
        }
        cout << "\n";
    }

    cout << "------------------------\n";
}

void exercicio2(int linhas, int colunas) {
    int matrizA[linhas][colunas], matrizB[linhas][colunas];

    cout << "Solicita numeros para o usuario para preencher uma matriz, em seguida cria uma matriz transposta e mostra as duas\n";

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "Digite um numero: ";
            cin >> matrizA[i][j];
            matrizB[j][i] = matrizA[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "[ " << matrizA[i][j] << " ]";
        }
        cout << "\n";
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "[ " << matrizB[i][j] << " ]";
        }
        cout << "\n";
    }

    cout << "------------------------\n";
}

void exercicio3(int linhas, int colunas) {
    int matrizA[linhas][colunas], diagonal[linhas];

    cout << "Solicita numeros pro usuario para armazenar em uma matriz, em seguida pega a diagonal principal da matriz e armazena num vetor\n";
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "Digite um numero: ";
            cin >> matrizA[i][j];
        }
    }

    for (int i = 0; i < linhas; i++) {
        diagonal[i] = matrizA[i][i];
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "[ " << matrizA[i][j] << " ]";
        }
        cout << "\n";
    }

    cout << "Diagonal principal: ";
    for (int i = 0; i < linhas; i++) {
        cout << diagonal[i] << ", ";
    }
    cout << "\n";

    cout << "------------------------\n";
}

void exercicio4(int linhas, int colunas) {
    int matrizA[linhas][colunas], diagonal[linhas];

    cout << "Solicita numeros pro usuario para armazenar em uma matriz, em seguida pega a diagonal secundaria da matriz e armazena num vetor\n";    

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "Digite um numero: ";
            cin >> matrizA[i][j];
        }
    }

    for (int i = 0; i < linhas; i++) {
        diagonal[i] = matrizA[i][colunas - i - 1];
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "[ " << matrizA[i][j] << " ]";
        }
        cout << "\n";
    }

    cout << "Diagonal secundaria: ";
    for (int i = 0; i < linhas; i++) {
        cout << diagonal[i] << ", ";
    }
    cout << "\n";

    cout << "------------------------\n";
}

void exercicio5(int linhas, int colunas) {
    int matrizA[linhas][colunas], fatoriais[linhas][colunas];

    cout << "Solicita numeros pro usuario para preencher uma matriz, em seguida prenche outra matriz com o fatorial de cada numero da primeira matriz\n";

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            do {
                cout << "Digite um numero maior que 1: ";
                cin >> matrizA[i][j];
            }
            while (matrizA[i][j] < 1);
            fatoriais[i][j] = fatorial(matrizA[i][j]);
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "[ " << matrizA[i][j] << " ]";
        }
        cout << "\n";
    }

    cout << "Fatoriais:\n";

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "[ " << fatoriais[i][j] << " ]";
        }
        cout << "\n";
    }

    cout << "------------------------\n";
}

void exercicio6(int linhas, int colunas) {
    int vetorA[colunas], tabuada[linhas][colunas];

    cout << "Solicita pro usuario digitar valores de 1 a 10, depois insere em um vetor e por ultimo calcula a tabuada de cada elemento para inserir numa matriz\n";

    for (int i = 0; i < linhas; i++) {

        do {
            cout << "Digite um numero de um à dez: ";
            cin >> vetorA[i];
        }
        while(vetorA[i] < 1 || vetorA[i] > 10);

        for (int j = 0; j < colunas; j++) {
            tabuada[i][j] = vetorA[i] * (j + 1);
        }
    }

    for (int i = 0; i < linhas; i++) {
        cout << "Tabuada elemento " << i << ": " << vetorA[i] << "\n";
        for (int j = 0; j < colunas; j++) {
            cout << "    " << vetorA[i] << " x " << j + 1 << " = " << tabuada[i][j] << "\n";
        }
    }

    cout << "------------------------\n";
}

void exercicio7(int alunos, int meses) {
    int faltas[alunos][meses], media_faltas[alunos];

    cout << "Solicita para o usuario as faltas de todos os alunos durante os meses citados para armazenar na matriz, em seguida calcula a media de faltas de cada aluno e insere no vetor\n";

    for (int i = 0; i < alunos; i++) {
        int media = 0;

        cout << "Aluno " << i + 1 << ":\n";
        for (int j = 0; j < meses; j++) {
            do {
                cout << "Mes " << j + 1 << ": ";
                cin >> faltas[i][j];
            }
            while(faltas[i][j] < 0 || faltas[i][j] > 20 );
            media += faltas[i][j];
        }
        media_faltas[i] = media / meses;
    }

    cout << "\n";

    for (int i = 0; i < alunos; i++) {
        cout << "Aluno " << i + 1 << ":\n    ";
        for (int j = 0; j < meses; j++) {
            cout << faltas[i][j] << ", ";
        }
        cout << "\n";
        cout << "    Média: " << media_faltas[i] << "\n";
    }

    cout << "------------------------\n";
}

void exercicio8(int linhas, int colunas) {
    int matrizA[linhas][colunas], matrizB[linhas][colunas], matrizC[linhas][colunas];

    cout << "Preencher duas matrizes com valores, depois soma as duas matrizes numa terceira matriz\n";

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "Digite um numero para guardar na matriz A: ";
            cin >> matrizA[i][j];
            cout << "Digite um numero para guardar na matriz B: ";
            cin >> matrizB[i][j];

            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "[ " << matrizA[i][j] << " ]";
        }
        
        if (i == linhas / 2) {
            cout << "  +  ";
        }
        else {
            cout << "     ";
        }

        for (int j = 0; j < colunas; j++) {
            cout << "[ " << matrizB[i][j] << " ]";
        }

        if (i == linhas / 2) {
            cout << "  =  ";
        }
        else {
            cout << "     ";
        }

        for (int j = 0; j < colunas; j++) {
            cout << "[ " << matrizC[i][j] << " ]";
        }
        
        cout << "\n";
    }
    cout << "\n";
}

int fatorial(int n) {
    if (n == 2)
        return 2;
    return n * fatorial(n - 1);
}