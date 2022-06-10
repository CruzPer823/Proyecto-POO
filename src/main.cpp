#include <iostream>
#include <sstream>
#include <fstream>
#include "Videos.cpp"
#define NOMBRE_ARCHIVO "Peliculas.csv"

using namespace std;


int main(){
  int opcion,opcion2;
  cout<<"BIENVENIDO AL MENU DE VIDEOS"<<"\n"<<
  "1-. Desplegar por calificación o género"<<"\n"<<
  "2-. Desplegar por serie y calificación"<<"\n"<<
  "3-. Desplegar por por películas y calificación"<<"\n"<<
  "Escoja una opción: "<< endl;
  cin>>opcion;
  if (opcion == 1){
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
    cout << "Le gustaría desplegar por género o por calificación"<<"\n"<<
    "1-. Por género" << "\n" << "2-. Por calificación"<<"\n"<<
    "Ingresa la opción: "<<endl;
    cin >> opcion2;
    if (opcion2==2){
      double usuarioCalif;
      cout << "Ingrese la calificacion que desea buscar: "<<endl;
      cin >> usuarioCalif;
      if (calificacion > usuarioCalif){
        Videos video1(ID,NOMBRE,DURACION,GENERO,calificacion);
        cout<<video1.getNombre()<<endl;
      }
}
      archivo.close();

  }
  return 0;
}
