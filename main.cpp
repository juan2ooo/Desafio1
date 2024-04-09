//#include <iostream>
//using namespace std;

int** estructuraM(short tamano);
void imprimem (int** m);
void liberarm(int** m);
int*** estructuraX(short tamano);
short calcularLongitud(const short* ptr);
void invertirPrimera(int *m, short tamano);
void invertir(int *m, short tamano);
void invertirNumerosM(int **m);
void calcularTraspuesta(int **matriz);
void rotar(int **m);
int main()
{
    int **prueba = estructuraM(5);
    rotar(prueba);
    imprimem(prueba);
    liberarm(prueba);

    return 0;
}
