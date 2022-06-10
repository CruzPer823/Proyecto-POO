#include "Series.h"

Series::Series():Videos(){}

Series::Series(std::string id,std::string idCapitulo,std::string temporada,
  std::string nombreCapitulo,
  std::string nombre,std::string duracion,
  std::string genero, double calificacion):Videos(id, nombre,
  duracion, genero, calificacion){
  this -> nombreCapitulo = nombreCapitulo;
  this -> temporada = temporada;
  this -> idCapitulo = idCapitulo;
}

std::string Series::getGen(){
  return genero;
}

std::string Series::getNombre(){
  return nombre;
}
