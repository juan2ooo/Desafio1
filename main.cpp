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
int* estructuraX(short *K, short tam){
    short fila = K[0], colm = K[1];
    //int *p = nullptr;
    int *x = new int[tam-1];
    //int x[tam-1];
    x[0] =  encontrarImparCercano(encontrarMayor(K[0], K[1])); //el tamaño inicial lo determina la poscicon de k
    short rotacion[tam-2];
    int **m1 = estructuraM(x[0]);
    int **m2 = estructuraM(x[0]);

    short vueltas = 0;
    short j = 1;
    for(short i = 2; i <= tam ; i++){
        if(K[i] == 0){
            short aumentoDeM = 1;
            while(true){
                //short a =m1[fila][colm] , b= m2[fila][colm];

                while(m1[fila][colm] != m2[fila][colm] and vueltas != 3){
                    rotar(m1);
                    vueltas++;
                }
                //cout << "vueltas de 1: " << vueltas;


                if(vueltas == 3){
                    liberarm(m1);
                    m1 = estructuraM( x[0]+2*aumentoDeM); //aumentar la m
                    aumentoDeM++;
                    //cout << "numero de vueltas para abrir la cerradura " << vueltas;
                    vueltas = 0;
                    continue;
                }else{
                    //vueltas = 0;
                    x[i-2] = x[0]+2*(aumentoDeM-1);
                    cout << "numero de vueltas de " << j <<": " << vueltas << endl;
                    j++;
                    vueltas = 0;
                    //aumentoDeM = 1;
                    break;
                }
            }

        }else{

            if(K[i] == 1){
                short aumentoDeM = 1;
                while(true){
                    short a =m1[fila][colm] , b= m2[fila][colm];

                    while(m1[fila][colm] <= m2[fila][colm] and vueltas != 3){
                        rotar(m1);
                        vueltas++;
                    }
                    //cout << "vueltas de 1: " << vueltas;


                    if(vueltas == 3){
                        liberarm(m1);
                        m1 = estructuraM( x[0]+2*aumentoDeM); //aumentar la m
                        aumentoDeM++;
                        //cout << "numero de vueltas para abrir la cerradura " << vueltas;
                        vueltas = 0;
                        continue;
                    }else{
                        //vueltas = 0;
                        x[i-2] = x[0]+2*(aumentoDeM-1);
                        cout << "numero de vueltas de " << j <<": " << vueltas << endl;
                        j++;
                        vueltas = 0;
                        //aumentoDeM = 1;
                        break;
                    }
                }
            }else{
                short aumentoDeM = 1;
                while(true){
                    //short a =m1[fila][colm] , b= m2[fila][colm];

                    while(m1[fila][colm] < m2[fila][colm] and vueltas != 3){
                        rotar(m1);
                        vueltas++;
                    }
                    //cout << "vueltas de 1: " << vueltas;


                    if(vueltas == 3){
                        liberarm(m1);
                        m1 = estructuraM( x[0]+2*aumentoDeM); //aumentar la m
                        aumentoDeM++;
                        //cout << "numero de vueltas para abrir la cerradura " << vueltas;
                        vueltas = 0;
                        continue;
                    }else{
                        //vueltas = 0;
                        x[i-2] = x[0]+2*(aumentoDeM-1);
                        cout << "numero de vueltas de " << j <<": " << vueltas << endl;
                        j++;
                        vueltas = 0;
                        //aumentoDeM = 1;
                        break;
                    }
                }
            }

        }
    }
    return x;
}




int encontrarMayor(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

short contarElementos(short *arr) {
    short contador = 0;

    // Recorre el arreglo hasta encontrar el valor de finalización (-99)
    while (*arr != -99) {
        contador++;
        arr++; // Mueve el puntero al siguiente elemento
    }

    return contador;
}

short encontrarImparCercano(short numero) {
    // Si el número es impar, simplemente sumamos 2
    if (numero % 2 != 0)
        return numero + 2;
    // Si el número es par, sumamos 1
    else
        return numero + 1;
}
