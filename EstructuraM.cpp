#include <iostream>
using namespace std;

int** estructuraM(short tamano){
    int **m = new int*[tamano];
    int cont = 1;
    bool primeraVez = true;
    int *fila = nullptr;
    short centro = (tamano/2);

    for(int i = 0; i < tamano; i++){ // desde 1 porque la priemra estructura la asigno yo, entonces quiero que el ciclo se ejecute una vez menos
        if(i == 0){
            fila = new int[tamano+2];
            fila[0] = tamano;
            fila[tamano+1] = -99;
            //primeraVez = false;
        }else{
            fila = new int[tamano+1];
            fila[tamano] = -99;
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

void invertir(int *m, short tamano){
    short inicio = 0, final = tamano-1;
    int a = 0;

    for(int i = 0; i < tamano/2; i++){

        m[inicio] = m[inicio] + m[final];



        m[final] = m[inicio] - m[final];


        m[inicio] = m[inicio] - m[final];
        inicio ++;
        final --;
    }
}

void invertirPrimera(int *m, short tamano){
    short inicio = 1, final = tamano;
    for(int i = 0; i < tamano/2; i++){
        m[inicio] = m[inicio] + m[final];
        m[final] = m[inicio] - m[final];
        m[inicio] = m[inicio] - m[final];
        inicio ++;
        final --;
    }
}



short calcularLongitud(const short* ptr) {
    short longitud = 0;

    // Contar elementos hasta encontrar el final del array (suponemos que el final es un valor especial, como -1)
    while (*ptr != -99) {
        ++longitud;
        ++ptr;
    }

    return longitud;
}


void invertirNumerosM(int **m){
    short tamano = m[0][0];
    for(int i = 0; i < tamano; i++){
        if(!i){
            invertirPrimera(m[i],tamano);
        }else{
            invertir(m[i], tamano);
        }
    }
}

void calcularTraspuesta(int **matriz) {
    short tamano = matriz[0][0];
    for (int i = 0; i < tamano; i++) {
        for (int j = i+1; j < tamano; j++) {
            if(not i){
                int temp = matriz[i][j+1];
                matriz[i][j+1] = matriz[j][i];
                matriz[j][i] = temp;
            }else{
                int temp = matriz[i][j];
                matriz[i][j] = matriz[j][i];
                matriz[j][i] = temp;
            }

        }
    }
}
