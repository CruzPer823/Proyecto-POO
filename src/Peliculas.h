#ifndef PELICULAS_H_INCLUDE
#define PELICULAS_H_INCLUDE

#include "Videos.h"

class Peliculas : public Videos {
public:
  Peliculas();
  Peliculas(std::string,std::string,std::string,std::string,double calificacion);
  /*double mostrarCalificacion();
  double calificarVideo();*/
  std::string getNombre();
  std::string getGen();
  double getCalif();
  std::string getID();
};



#endif // PELICULAS_H_INCLUDE
