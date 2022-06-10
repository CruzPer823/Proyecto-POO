#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include <string>

class Videos {
  protected:
    std::string id, nombre, duracion, genero;
    double calificacion;
  public:
  Videos();
  Videos(std::string,std::string,std::string,std::string,double calificacion);
  /*virtual double mostrarCalificacion();
  virtual double calificarVideo();*/
  std::string getNombre();
  double getCalif();

};

#endif // VIDEO_H_INCLUDED
