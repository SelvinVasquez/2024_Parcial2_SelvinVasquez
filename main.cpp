#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"

using namespace std;
void crearArchivos(int cantidad);
int contarArchivos();
int contarArchivos2();


int main() {
    int opc;
    cout << "Bienvenido al Programa de Manejo de Archivos" << endl;
    do {
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Elija una opcion" << endl;
        cout << "1. Crear Archivos" << endl;
        cout << "0. Salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                cout << "Opcion seleccionada -> Crear Archivos" << endl;
                int cantidad;
                cout << "Ingrese la cantidad de archivos que desea crear" << endl;
                cin >> cantidad;
                crearArchivos(cantidad);
                break;
            case 0:
                cout << "Fin del programa" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (opc != 0);
    return 0;
}

void crearArchivos(int cantidad){
    string nombreArchivo = "documento";
    if (cantidad % 2 == 0){
        cout << "Cantidad de Archivos par" << endl;
        for (int i = 0; i < cantidad; ++i) {
            ofstream file;
            file.open("C:/Users/selvi/Desktop/Manejo de Archivos/par/" + nombreArchivo + to_string(i + 1) + ".txt");
            file.close();
        }
        cout << cantidad << " Archivos creados con Exito" << endl;
        contarArchivos();
    }else{
        cout << "Cantidad de Archivos impar" << endl;
        for (int i = 0; i < cantidad; ++i) {
            ofstream file;
            file.open("C:/Users/selvi/Desktop/Manejo de Archivos/impar/" + nombreArchivo + to_string(i + 1) + ".txt");
            file.close();
        }
        cout << cantidad << " Archivos creados con Exito" << endl;
        contarArchivos2();
    }
}

/*void agregarTexto(){
    cout << "Agregando texto..." << endl;
}*/

int contarArchivos(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadArchivos=0;
    hFind = FindFirstFile("C:/Users/selvi/Desktop/Manejo de Archivos/par/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE){
        cout << "Ruta incorrecta" << endl;
    }else{
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadArchivos=cantidadArchivos+1;
        }
    }
    return cantidadArchivos-1;
}

int contarArchivos2(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadArchivos=0;
    hFind = FindFirstFile("C:/Users/selvi/Desktop/Manejo de Archivos/impar/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE){
        cout << "Ruta incorrecta" << endl;
    }else{
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadArchivos=cantidadArchivos+1;
        }
    }
    return cantidadArchivos-1;
}