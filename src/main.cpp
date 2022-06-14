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
  Videos* cal[2];
  Videos* arr[100];
  Videos* arrepi[100];
  string opcion,opcion2,opcion4,opcion5,ID,NOMBRE,DURACION,GENERO,CALIFICACION,TEMPORADAS,opcion3,
  calificacionSerie,line,linea,linea2,linea3,usuarioCalifP,ID_EPISODIO,TEMPORADA;
  char delimitador = ',';
  int opcion1,c1=0,c2=1,c3=0,opcion3int,opcion5int,temporadas,temporada, e=0;
  double califint,califint2 ,calificacion, usuarioCalifpint;
  #define SERIES "Series.csv"
      ifstream archivo(SERIES);
      getline(archivo, linea);
      while (getline(archivo,linea)){
        stringstream stream(linea);

        getline(stream,ID,delimitador);
        getline(stream,NOMBRE,delimitador);
        getline(stream,GENERO,delimitador);
        getline(stream,TEMPORADAS,delimitador);

        temporadas = stoi(TEMPORADAS);

        arr[c1] = new Series(ID,NOMBRE,GENERO,temporadas);
        c2+=c1;
        c1+=1;
      }
      archivo.close();
#define PELICULAS "Peliculas.csv"
      ifstream archivo2(PELICULAS);
      getline(archivo2, linea2);
      while (getline(archivo2,linea2)){
        stringstream stream(linea2);

        getline(stream,ID,delimitador);
        getline(stream,NOMBRE,delimitador);
        getline(stream,DURACION,delimitador);
        getline(stream,GENERO,delimitador);
        getline(stream,CALIFICACION,delimitador);

        calificacion = stod(CALIFICACION);
        arr[c1] = new Peliculas(ID,NOMBRE,DURACION,GENERO,calificacion);
        c1+=1;
      }
      archivo2.close();
#define EPISODIOS "Episodios.csv"
        ifstream archivo3(EPISODIOS);
        getline(archivo3, linea3);
        while (getline(archivo3,linea3)){
          stringstream stream(linea3);

          getline(stream,ID,delimitador);
          getline(stream,ID_EPISODIO,delimitador);
          getline(stream,NOMBRE,delimitador);
          getline(stream,DURACION,delimitador);
          getline(stream,CALIFICACION,delimitador);
          getline(stream,TEMPORADA,delimitador);

          temporada = stoi(TEMPORADA);
          califint2 = stod(CALIFICACION);
          arrepi[c3] = new Episodios(ID,ID_EPISODIO,NOMBRE,DURACION,califint2,temporada);
          c3+=1;
        }
        archivo3.close();
        while(e==0){
        system("clear");
    cout<<"BIENVENIDO AL MENU DE VIDEOS"<<"\n"<<
    "1-. Desplegar por calificación o género"<<"\n"<<
    "2-. Desplegar por serie y calificación"<<"\n"<<
    "3-. Desplegar por por películas y calificación"<<"\n"<<
    "4-. Calificar un video"<<"\n"<<
    "0-. Salir"<<"\n"<<
    "Escoja una opción: "<< endl;
    cin>>opcion;
    while (isNumber(opcion) == false){
      cout << "Ingrese una opción válida"<<endl;
      cin>>opcion;
    }
    opcion1 = stoi(opcion);
    while (opcion1 > 4){
      cout<<"Ingrese una opción válida" << endl;
      cin>>opcion;
      opcion1 = stoi(opcion);
    }
  //Opción 1
      if (opcion == "1"){
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
            string generos[3];
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
              cout<<"Ingrese una cantidad válida entre 1 y 3"<<endl;
              cin>>genero;
            }
            generoint=stoi(genero);
            while (generoint > 4){
              cout << "Ingrese una cantidad válida entre 1 y 3"<<endl;
              cin>>genero;
              generoint=stoi(genero);
            }
            generoint=stoi(genero)-1;
            for (int i=0; i < c1; i++){
              if ( arr[i]->getGen() == generos[generoint]){
                arr[i]->mostrarDatos();
              }
            }
            cout<<"¿Qué desea realizar?\n1-.Volver al menú\n2-.Salir"<<endl;
            cin >> opcion4;
          while (isNumber(opcion4) == false){
            cout << "Ingrese una opción válida"<<endl;
            cin>>opcion4;
          }
          opcion1 = stoi(opcion4);
          while (opcion1 > 2){
            cout<<"Ingrese una opción válida" << endl;
            cin>>opcion4;
          }
            if(opcion1== 1){
              e=0;
            }else{
              e=1;
            }
          }
          else if (opcion2=="2"){
            string usuarioCalif;
            double usuarioCalifInt;
            cout << "Ingrese la calificacion del 1 al 10 que desea buscar: "<<endl;
            cin >> usuarioCalif;

            while (isNumber(usuarioCalif)==false){
              cout<<"Ingrese una cantidad válida entre el 1 y 10"<<endl;
              cin>>usuarioCalif;
            }
            usuarioCalifInt=stod(usuarioCalif);
            while (usuarioCalifInt > 10){
              cout << "Ingrese una cantidad válida entre 0 y 5"<<endl;
              cin >> usuarioCalifInt;
            }
            for (int i=0; i < c1; i++){
              if ( arr[i]->getCalif() >= usuarioCalifInt){
                arr[i]->mostrarDatos();
              }
            }
            for (int i=0; i < c3; i++){
              if ( arrepi[i]->getCalif() >= usuarioCalifInt){
                arrepi[i]->mostrarDatos();
              }
            }
            cout<<"¿Qué desea realizar?\n1-.Volver al menú\n2-.Salir"<<endl;
            cin >> opcion4;
          while (isNumber(opcion4) == false){
            cout << "Ingrese una opción válida"<<endl;
            cin>>opcion4;
          }
          opcion1 = stoi(opcion4);
          while (opcion1 > 2){
            cout<<"Ingrese una opción válida" << endl;
            cin>>opcion4;
          }
          opcion1 = stoi(opcion4);
            if(opcion1== 1){
              e=0;
            }else{
              e=1;
            }
      }

  //Opción 2

      }
      else if (opcion == "2"){
        cout << "Escoge una de las siguientes series: "<<endl;
        for (int i=0; i < 4; i++){
            cout<<i+1<<"-."<<arr[i]->getNombre()<<endl;
      }
        cin >> opcion3;
        while (isNumber(opcion3)==false){
              cout<<"Ingrese un valor válido"<<endl;
              cin>>opcion3;
            }
            opcion3int=stod(opcion3);
            while (opcion3int > 4){
              cout << "Ingrese una cantidad válida entre el 1 y 4"<<endl;
              cin >> opcion3int;
            }
        cout << "Ingresa una calificacion: "<<endl;
        cin>>calificacionSerie;
        while (isNumber(calificacionSerie)==false){
              cout<<"Ingrese un valor válido"<<endl;
              cin>>calificacionSerie;
            }
            califint=stod(calificacionSerie);
            while (califint > 10){
              cout << "Ingrese una cantidad válida entre el 1 y 10"<<endl;
              cin >> califint;
            }
          for (int n=0; n < c3;n++){
            if (arrepi[n]->getID() == arr[opcion3int-1]->getID() && arrepi[n]->getCalif() >= califint){
              arrepi[n]->mostrarDatos();
          }
        }
         cout<<"¿Qué desea realizar?\n1-.Volver al menú\n2-.Salir"<<endl;
            cin >> opcion4;
          while (isNumber(opcion4) == false){
            cout << "Ingrese una opción válida"<<endl;
            cin>>opcion4;
          }
          opcion1 = stoi(opcion4);
          while (opcion1 > 2){
            cout<<"Ingrese una opción válida" << endl;
            cin>>opcion1;
          }
          opcion1 = stoi(opcion4);
            if(opcion1== 1){
              e=0;
            }else{
              e=1;
            }
    }
    //Opción 3
      else if (opcion == "3"){
        cout << "Ingrese la calificación que desee buscar"<<endl;
        cin >> usuarioCalifP;
        while (isNumber(usuarioCalifP)==false){
          cout<<"Ingrese una cantidad válida entre 0 y 10"<<endl;
          cin>>usuarioCalifP;
        }
        usuarioCalifpint=stod(usuarioCalifP);
        while (usuarioCalifpint > 10){
          cout << "Ingrese una cantidad válida entre 0 y 10"<<endl;
          cin >> usuarioCalifpint;
        }
        for (int i=4; i < 11; i++){
          if ( arr[i]->getCalif() >= usuarioCalifpint){
            arr[i]->mostrarDatos();
          }
        }
        string opcion5;
         cout<<"¿Qué desea realizar?\n1-.Volver al menú\n2-.Salir"<<endl;
            cin >> opcion5;
          while (isNumber(opcion5) == false){
            cout << "Ingrese una opción válida"<<endl;
            cin>>opcion5;
          }

          opcion1 = stoi(opcion5);
          while (opcion1 > 2){
            cout<<"Ingrese una opción válida" << endl;
            cin>>opcion1;
          }
          opcion1 = stoi(opcion5);
            if(opcion1== 1){
              e=0;
            }else{
              e=1;
            }
      }
 //Opción 4
      else if(opcion=="4"){
        cout<<"***TITULOS***\n"<<endl;
        for(int i=4;i<11;i++){
          cout<<i-3<<"-."<<arr[i]->getNombre()<<endl;
        }
        for(int i=0; i<147;i++){
          cout<<i+8<<"-."<<arrepi[i]->getNombre()<<endl;
        }
        cout<<"Introduzca el título a calificar: "<<endl;
        cin >> opcion5;
        while (isNumber(opcion5)==false){
              cout<<"Ingrese un valor válido"<<endl;
              cin>>opcion5;
            }
            opcion5int=stod(opcion5);
            while (opcion5int > 154){
              cout << "Ingrese una cantidad válida entre el 1 y 151"<<endl;
              cin >> opcion5int;
            }
            cout<<"Introduzca la calificacion deseada en la escala del 1 al 10: "<<endl;
            cin >> usuarioCalifP;
        while (isNumber(usuarioCalifP)==false){
          cout<<"Ingrese una cantidad válida entre 0 y 10"<<endl;
          cin>>usuarioCalifP;
        }
        usuarioCalifpint=stod(usuarioCalifP);
        while (usuarioCalifpint > 10){
          cout << "Ingrese una cantidad válida entre 0 y 10"<<endl;
          cin >> usuarioCalifpint;
        }
        if((opcion5int)<=7){
          cout<<"\nLa antigua calificación es: "<<arr[opcion5int+3]->getCalif()<<endl;
          *arr[opcion5int+3]+usuarioCalifpint;
          cout<<"\nLa nueva calificación es: "<<arrepi[opcion5int+3]->getCalif()<<"\n"<<endl;
        }else if((opcion5int)>7){
          cout<<"\nLa antigua calificación es: "<<arrepi[opcion5int-8]->getCalif()<<endl;
          *arrepi[opcion5int-8]+usuarioCalifpint;
          cout<<"\nLa nueva calificación es: "<<arrepi[opcion5int-8]->getCalif()<<"\n"<<endl;
        }
             cout<<"¿Qué desea realizar?\n1-.Volver al menú\n2-.Salir"<<endl;
            cin >> opcion4;
          while (isNumber(opcion4) == false){
            cout << "Ingrese una opción válida"<<endl;
            cin>>opcion4;
          }
          opcion1 = stoi(opcion4);
          while (opcion1 > 2){
            cout<<"Ingrese una opción válida" << endl;
            cin>>opcion1;
          }
          opcion1 = stoi(opcion4);
            if(opcion1== 1){
              e=0;
            }else{
              e=1;
            }
      }
      else if(opcion=="0"){
        e=1;
        cout<<"Gracias por utilizar este programa."<<endl;
      }
        }
  return 0;
}
