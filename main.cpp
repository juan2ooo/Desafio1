#include <iostream>
using namespace std;

int** estructuraM(short tamano);
void imprimem (int** m);
void liberarm(int** m);
int*** estructuraX(short tamano);
short calcularLongitud(const short* ptr);
int main()
{

    return 0;
}

int** estructuraM(short tamano){
    int **m = new int*[tamano];
    int cont = 1;
    bool primeraVez = true;
    int *fila = nullptr;
    short centro = (tamano/2);

    for(int i = 0; i < tamano; i++){ // desde 1 porque la priemra estructura la asigno yo, entonces quiero que el ciclo se ejecute una vez menos
        if(i == 0){
            fila = new int[tamano+1];
            fila[0] = tamano;
            //primeraVez = false;
        }else{
            fila = new int[tamano];
        }



        for(int j = 0; j < tamano; j++){ //llenar los renglones

            if(not(i == centro and j == centro)){ //mientras no sea el centro
                if(i == 0){
                    fila[j+1] = cont;
                }else{
                    fila[j] = cont;
                }
                cont++;
            }else{
                fila[j] = -1;
            }



        }
        m[i] = fila;
    }
    return m;
}

void imprimem(int** m){
    short tam = m[0][0];

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if(i == 0){
                int a = (m[i][j+1]);
                cout << a;
            }else{
                int a = (m[i][j]);
                cout << a;
            }
        }
        cout << endl;

    }
}

void liberarm(int** m){
    short tam = m[0][0];
    for (int i = 0; i < tam; i++) {
        delete[] m[i];
    }
    delete[] m;
}



short calcularLongitud(const short* ptr) {
    short longitud = 0;

    // Contar elementos hasta encontrar el final del array (suponemos que el final es un valor especial, como -1)
    while (*ptr != -1) {
        ++longitud;
        ++ptr;
    }

    return longitud;
}
