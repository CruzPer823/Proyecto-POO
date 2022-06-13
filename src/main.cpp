#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include "Videos.cpp"
#include "Series.cpp"
#include "Peliculas.cpp"
#include "Episodios.cpp"

using namespace std;

bool isNumber(const string& str){
  return str.find_first_not_of(".0123456789") == string::npos &&
  str.front() != '.' && str.back() != '.';
}

int main(){

  Videos* arr[100];
  Videos* arrepi[100];
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
        arr[c] = new Peliculas(ID,NOMBRE,DURACION,GENERO,calificacion);
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
          string genero;
          string generos[100];
          generos[0]="Drama";
          generos[1]="Accion";
          generos[2]="Misterio";
          int generoint;
          cout << "Ingrese el género que desea buscar: "<<endl;
          for (int l=0;l<3;l++){
            cout<<l+1<<"-."<<generos[l]<<endl;
          }
          cin>>genero;
          while (isNumber(genero)==false){
            cout<<"Ingrese una cantidad válidad entre 1 y 7"<<endl;
            cin>>genero;
          }
          generoint=stoi(genero);
          while (generoint > 8){
            cout << "Ingrese una cantidad válida entre 1 y 7"<<endl;
            cin>>genero;
            generoint=stoi(genero);
          }
          generoint=stoi(genero)-1;
          for (int i=0; i < c; i++){
            if ( arr[i]->getGen() == generos[generoint]){
              cout<<arr[i]->getNombre()<<endl;
            }
          }
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
            if ( arr[i]->getCalif() >= usuarioCalifInt){
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
      string ID,NOMBRE,GENERO,TEMPORADAS;
      int c;
      string opcion3,calificacionSerie;
      int opcion3int;
      int temporadas;
      double califint;
      c=0;
      while (getline(archivo,linea)){
        stringstream stream(linea);

        getline(stream,ID,delimitador);
        getline(stream,NOMBRE,delimitador);
        getline(stream,GENERO,delimitador);
        getline(stream,TEMPORADAS,delimitador);

        temporadas = stoi(TEMPORADAS);

        arr[c] = new Series(ID,NOMBRE,GENERO,temporadas);
        c+=1;
      }
      cout << "Escoge una de las siguientes series: "<<endl;
      for (int i=0; i < c; i++){
          cout<<i+1<<"-."<<arr[i]->getNombre()<<endl;
    }
      cin >> opcion3;
      opcion3int = stoi(opcion3);
      cout << "Ingresa una calificacion: "<<endl;
      cin>>calificacionSerie;
      califint = stod(calificacionSerie);
      bool yes = true;
      while (yes == true){
        #define EPISODIOS "Episodios.csv"
        ifstream archivo(EPISODIOS);
        string linea;
        char delimitador = ',';
        getline(archivo, linea);
        string ID,ID_EPISODIO,NOMBRE,DURACION,CALIFICACION,TEMPORADA;
        int x;
        int temporada;
        double califint2;
        x=0;
        while (getline(archivo,linea)){
          stringstream stream(linea);

          getline(stream,ID,delimitador);
          getline(stream,ID_EPISODIO,delimitador);
          getline(stream,NOMBRE,delimitador);
          getline(stream,DURACION,delimitador);
          getline(stream,CALIFICACION,delimitador);
          getline(stream,TEMPORADA,delimitador);

          temporada = stoi(TEMPORADA);
          califint2 = stod(CALIFICACION);
          arrepi[x] = new Episodios(ID,ID_EPISODIO,NOMBRE,DURACION,califint2,temporada);
          x+=1;
        }
        for (int n=0; n < x;n++){
          if (arrepi[n]->getID() == arr[opcion3int]->getID() && arrepi[n]->getCalif() > califint){
            cout<<arrepi[n]->getNombre()<<endl;
        }
      }
yes = false;
      }


  }
    else if (opcion == "3"){
      #define PELICULAS "Peliculas.csv"
      ifstream archivo(PELICULAS);
      string usuarioCalifP;
      double usuarioCalifpint;
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
        arr[c] = new Peliculas(ID,NOMBRE,DURACION,GENERO,calificacion);
        c+=1;
      }
      cout << "Ingrese calificación que desee buscar"<<endl;
      cin >> usuarioCalifP;
      while (isNumber(usuarioCalifP)==false){
        cout<<"Ingrese una cantidad válidad entre 0 y 5"<<endl;
        cin>>usuarioCalifP;
      }
      usuarioCalifpint=stod(usuarioCalifP);
      while (usuarioCalifpint > 5){
        cout << "Ingrese una cantidad válida entre 0 y 5"<<endl;
        cin >> usuarioCalifpint;
      }
      for (int i=0; i < c; i++){
        if ( arr[i]->getCalif() >= usuarioCalifpint){
          cout<<arr[i]->getNombre()<<endl;
        }
      }
    }

  return 0;
}
