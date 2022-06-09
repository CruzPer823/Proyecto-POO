#ifndef SERIES_H_INCLUDE
#define SERIES_H_INCLUDE

#include "Videos.h"

class Series: Videos{
private:
  int numeroCapitulo, temporada;
public:
  Series();
  Series(std::string,std::string,std::string,std::string, std::string, int, int);
  double mostrarCalificacion(std::string);
  double calificarVideo(std::string);

}

#endif // SERIES_H_INCLUDE
