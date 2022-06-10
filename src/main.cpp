#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include "Videos.cpp"
#include "Series.cpp"
#include "Peliculas.cpp"


using namespace std;

bool isNumber(const string& str){
  return str.find_first_not_of(".0123456789") == string::npos &&
  str.front() != '.' && str.back() != '.';
}

int main(){
  Videos* arr[100];
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
      #define VIDEOS "Videos.csv"
      ifstream archivo(VIDEOS);
      string linea;
      char delimitador = ',';
      getline(archivo, linea);
      string ID,NOMBRE,DURACION,GENERO,CALIFICACION;
      double calificacion;
      int c;
      c=0;
      while (getline(archivo,linea)){
        stringstream stream(linea);

        getline(stream,ID,delimitador);
        getline(stream,NOMBRE,delimitador);
        getline(stream,DURACION,delimitador);
        getline(stream,GENERO,delimitador);
        getline(stream,CALIFICACION,delimitador);

        calificacion = stod(CALIFICACION);
        arr[c] = new Videos(ID,NOMBRE,DURACION,GENERO,calificacion);
        c+=1;
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
            cout<<"Ingrese una cantidad válidad entre 0 y 5"<<endl;
            cin>>usuarioCalif;
          }
          usuarioCalifInt=stod(usuarioCalif);
          while (usuarioCalifInt > 5){
            cout << "Ingrese una cantidad válida entre 0 y 5"<<endl;
            cin >> usuarioCalifInt;
          }
          for (int i=0; i < c; i++){
            if ( arr[i]->getCalif() > usuarioCalifInt){
              cout<<arr[i]->getNombre()<<endl;
            }
          }

    }

        archivo.close();

    }
    else if (opcion == "2"){
      #define SERIES "Series.csv"
      ifstream archivo(SERIES);
      string linea;
      char delimitador = ',';
      getline(archivo, linea);
      string ID,ID_EPISODIO,TEMPORADA,NOMBRE_CAPITULO, NOMBRE,DURACION,GENERO,CALIFICACION;
      double calificacion;
      int c;
      c=0;
      while (getline(archivo,linea)){
        stringstream stream(linea);

        getline(stream,ID,delimitador);
        getline(stream,ID_EPISODIO,delimitador);
        getline(stream,TEMPORADA,delimitador);
        getline(stream,NOMBRE_CAPITULO,delimitador);
        getline(stream,NOMBRE,delimitador);
        getline(stream,DURACION,delimitador);
        getline(stream,GENERO,delimitador);
        getline(stream,CALIFICACION,delimitador);

        calificacion = stod(CALIFICACION);
cout<<calificacion<<endl;
        arr[c] = new Series(ID,ID_EPISODIO,TEMPORADA,NOMBRE_CAPITULO,NOMBRE,DURACION,GENERO,calificacion);
        c+=1;
      }
    }
    else if (opcion == "3"){
      #define PELICULAS "Peliculas.csv"
      ifstream archivo(PELICULAS);
      string linea;
      char delimitador = ',';
      getline(archivo, linea);
      string ID,NOMBRE,DURACION,GENERO,CALIFICACION;
      double calificacion;
      int c;
      c=0;
      while (getline(archivo,linea)){
        stringstream stream(linea);

        getline(stream,ID,delimitador);
        getline(stream,NOMBRE,delimitador);
        getline(stream,DURACION,delimitador);
        getline(stream,GENERO,delimitador);
        getline(stream,CALIFICACION,delimitador);

        calificacion = stod(CALIFICACION);
cout<<calificacion<<endl;
        arr[c] = new Peliculas(ID,NOMBRE,DURACION,GENERO,calificacion);
        c+=1;
      }
    }

  return 0;
}
