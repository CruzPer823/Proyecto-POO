#include "Peliculas.h"

Peliculas::Peliculas():Videos(){}

Peliculas::Peliculas(std::string id,std::string nombre,std::string duracion,
  std::string genero, double calificacion):Videos(id, nombre, duracion, genero,calificacion){}
