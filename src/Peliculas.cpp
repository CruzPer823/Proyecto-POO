#include "Peliculas.h"

Peliculas::Peliculas():Videos(){}

Peliculas::Peliculas(std::string id,std::string nombre,std::string duracion,
  std::string genero, double calificacion):Videos(id, nombre, duracion, genero,calificacion){}

std::string Peliculas :: getNombre(){
  return nombre;
}

std::string Peliculas :: getGen(){
  return genero;
}

double Peliculas :: getCalif(){
  return calificacion;
}
