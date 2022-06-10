#ifndef PELICULAS_H_INCLUDE
#define PELICULAS_H_INCLUDE

#include "Videos.h"

class Peliculas : public Videos {
private:
public:
  Peliculas();
  Peliculas(std::string,std::string,std::string,std::string,double calificacion);
  /*double mostrarCalificacion();
  double calificarVideo();*/
};



#endif // PELICULAS_H_INCLUDE
