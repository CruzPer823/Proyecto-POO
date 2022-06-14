#include "Series.h"

Series::Series():Videos(){}

Series::Series(std::string id, std::string nombre, std::string genero,int temporadas):
Videos(id, nombre, genero ){
  this -> temporadas = temporadas;
}

Series::Series(std::string id, std::string nombre):Videos(id, nombre){
}

std::string Series::getGen(){
  return genero;
}

std::string Series::getNombre(){
  return nombre;
}

double Series:: getCalif(){
  return 0;
}

std::string Series:: getID(){
  return id;
}

void Series::mostrarDatos(){
  std::cout<< "\nSerie: "<<nombre<<"\n"
  "Temporadas: "<<temporadas<<
  "\nGenero: "<<genero<<"\n";
}