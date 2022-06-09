#ifndef PELICULAS_H_INCLUDE
#define PELICULAS_H_INCLUDE

#include "Videos.h"

class Peliculas : Videos {
private:
public:
  Peliculas();
  Peliculas(std::string,std::string,std::string,std::string, std::string);
  double mostrarCalificacion();
  double calificarVideo();
}



#endif // PELICULAS_H_INCLUDE
