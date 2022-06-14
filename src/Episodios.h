#ifndef EPISODIOS_H_INCLUDE
#define EPISODIOS_H_INCLUDE

#include "Series.h"
#include "Videos.h"

class Episodios : public Series {
private:
  std::string id_episodio;
  double calificacion;
  int temporada;
public:
  Episodios();
  Episodios(std::string, std::string, std::string, std::string, double, int);
  Episodios(double);
  std::string getNombre();
  std::string getGen();
  double getCalif();
  std::string getID();
  void mostrarDatos();
   void operator+(double val){
    this-> calificacion=((calificacion*50)+val)/51;
  }
};


#endif
