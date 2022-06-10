#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Videos.cpp"
#define NOMBRE_ARCHIVO "Peliculas.csv"

using namespace std;

bool isNumber(const string& str){
  return str.find_first_not_of(".0123456789") == string::npos &&
  str.front() != '.' && str.back() != '.';
}

int main(){
  string opcion,opcion2;
  int opcion1;
  cout<<"BIENVENIDO AL MENU DE VIDEOS"<<"\n"<<
  "1-. Desplegar por calificación o género"<<"\n"<<
  "2-. Desplegar por serie y calificación"<<"\n"<<
  "3-. Desplegar por por películas y calificación"<<"\n"<<
  "Escoja una opción: "<< endl;
  cin>>opcion;
  while (isNumber(opcion) == false){
    cout << "Ingrse una opción válida"<<endl;
    cin>>opcion;
  }
  opcion1 = stoi(opcion);
  while (opcion1 > 3){
    cout<<"Ingrese una opción válida" << endl;
    cin>>opcion;
    opcion1 = stoi(opcion);
  }
    if (opcion == "1"){
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
      while (isNumber(opcion2) == false){
        cout << "Ingrse una opción válida"<<endl;
        cin>>opcion2;
      }
      opcion1 = stoi(opcion2);
      while (opcion1 > 2){
        cout<<"Ingrese una opción válida" << endl;
        cin>>opcion2;
        opcion1 = stoi(opcion);
      }
        if(opcion2 == "1"){
          cout << "xd" << endl;
        }
        else if (opcion2=="2"){
          string usuarioCalif;
          double usuarioCalifInt;
          cout << "Ingrese la calificacion que desea buscar: "<<endl;
          cin >> usuarioCalif;

          while (isNumber(usuarioCalif)==false){
            cout<<"Ingrese una cantidad válidad entre 0 y 10"<<endl;
            cin>>usuarioCalif;
          }
          usuarioCalifInt=stoi(usuarioCalif);
          while (usuarioCalifInt > 10){
            cout << "Ingrese una cantidad válida entre 0 y 10"<<endl;
            cin >> usuarioCalifInt;
          }
          if (calificacion > usuarioCalifInt){
            Videos video1(ID,NOMBRE,DURACION,GENERO,calificacion);
            cout<<video1.getNombre()<<endl;
          }
    }

        archivo.close();

    }
    else if (opcion == "2"){
      cout<<"Xd"<<endl;
    }
    else if (opcion == "3"){
      cout<<"Xd"<<endl;
    }

  return 0;
}
