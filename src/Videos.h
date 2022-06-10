#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include <string>

class Videos {
  protected:
    std::string id, nombre, duracion, genero;
    int calificacion;
  public:
  Videos();
  Videos(std::string,std::string,std::string,std::string,int calificacion);
  /*virtual double mostrarCalificacion();
  virtual double calificarVideo();*/
  std::string getNombre();
  float getCalif();

};

#endif // VIDEO_H_INCLUDED
