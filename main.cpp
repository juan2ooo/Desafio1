#include <iostream>
using namespace std;

// funciones del modulo de estructura m
int** estructuraM(short tamano);
void imprimem (int** m);
void liberarm(int** m);
void trasponer(int **matriz);
void rotar(int **m);
short encontrarImparCercano(short numero);


short calcularLongitud(const short* ptr);
void invertirPrimera(int *m, short tamano);
void invertir(int *m, short tamano);
void invertirNumerosM(int **m);



// funciones del modulo de cerraduras X
int* estructuraX(short *K, short tam);
int encontrarMayor(int num1, int num2);
short contarElementos(short *arr);


int main()
{
    short *k = new short[3]{3, 4, 1};


    int *x = estructuraX(k,3);
    cout << endl << x[0] <<endl;
    cout << x[1] <<endl;
    //cout << x[2];
    delete[] x;
    delete [] k;
    return 0;
}

