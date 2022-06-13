#ifndef EPISODIOS_H_INCLUDE
#define EPISODIOS_H_INCLUDE

#include "Series.h"

class Episodios : public Series {
private:
  std::string id_espisodio,nombre_capitulo,duracion,calificacion,temporada;
public:
  Episodios();
  Episodios(std::string);
};


#endif
