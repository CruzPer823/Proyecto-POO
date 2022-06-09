#include "Peliculas.h"

Peliculas::Peliculas():Videos(){}

Peliculas::Peliculas(std::string id,std::string nombre,std::string duracion,
  std::string genero):Videos(id, nombre, duracion, genero){}

  
