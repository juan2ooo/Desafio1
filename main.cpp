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
void imprimirHastaFin(int *puntero);



// funciones del modulo de cerraduras X
int* estructuraX(short *K, short tam);
int encontrarMayor(int num1, int num2);
short contarElementos(short *arr);


int main()
{
    short response = 0, fila, colm;

    cout << "De que longitud sera k? ";
    cin >> response;

    //short *k = new short[response];
    short k [response+2];

    cout <<endl << "Ingrese el valor de la fila: ";
    cin >> fila;
    k[0] = fila;

    cout << endl << "Ingrese el valor de la columna: ";
    cin >> colm;
    k[1] = colm;

    for(short i = 2; i < response+2; i++){
        short response1;
        cout << "Ingrese -1, 0, 1: ";
        cin >> response1;
        k[i] = response1;
    }


    cout << endl << "Para la regla K se tiene la siguiente configuracion de rotacion para las m"<<endl;
    int *x = estructuraX(k,response);
    cout << endl << "Una X para esa regla K es: " << "(";
    imprimirHastaFin(x);
    cout << ")" << endl;



    //cout << x[2];
    delete[] x;
    //delete [] k;
    return 0;
}

