#ifndef EPISODIOS_H_INCLUDE
#define EPISODIOS_H_INCLUDE

#include "Series.h"

class Episodios : public Series {
private:
  std::string id,id_episodio,nombre,duracion;
  double calificacion;
  int temporada;
public:
  Episodios();
  Episodios(std::string, std::string, std::string, std::string, double, int);
  std::string getNombre();
  std::string getGen();
  double getCalif();
  std::string getID();
};


#endif
