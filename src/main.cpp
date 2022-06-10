#include <iostream>
#include <sstream>
#include <fstream>
#include "Videos.cpp"
#define NOMBRE_ARCHIVO "Peliculas.csv"

using namespace std;


int main(){
  ifstream archivo(NOMBRE_ARCHIVO);
  string linea;
  char delimitador = ',';
  getline(archivo, linea);
  string ID,NOMBRE,DURACION,GENERO,CALIFICACION;
  int calificacion;
  while (getline(archivo,linea)){
    stringstream stream(linea);

    getline(stream,ID,delimitador);
    getline(stream,NOMBRE,delimitador);
    getline(stream,DURACION,delimitador);
    getline(stream,GENERO,delimitador);
    getline(stream,CALIFICACION,delimitador);

    calificacion = stoi(CALIFICACION);
  }
  if (calificacion > 4){
    Videos video1(ID,NOMBRE,DURACION,GENERO,calificacion);
    cout<<video1.getNombre()<<endl;
  }

  archivo.close();
  return 0;
}
