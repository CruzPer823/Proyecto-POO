#include "Series.h"

Series::Series():Videos(){}

Series::Series(std::string id,std::string nombre,std::string duracion,
  std::string genero, int numeroCapitulo, int temporada):Videos(id, nombre,
  duracion, genero){
  this -> numeroCapitulo = numeroCapitulo;
  this -> temporada = temporada;
}
