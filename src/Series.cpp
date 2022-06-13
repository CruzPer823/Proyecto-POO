#include "Series.h"

Series::Series():Videos(){}

Series::Series(std::string id,
  std::string nombre, std::string genero, std::string temporadas):Videos(id, nombre,
 genero){
  this -> temporadas = temporadas;
}

std::string Series::getGen(){
  return genero;
}

std::string Series::getNombre(){
  return nombre;
}
