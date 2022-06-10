#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include <string>

class Videos {
  protected:
    std::string id, nombre, duracion, genero;
  public:
  Videos();
  Videos(std::string,std::string,std::string,std::string);
  /*virtual double mostrarCalificacion();
  virtual double calificarVideo();*/
  std::string getNombre();
};

#endif // VIDEO_H_INCLUDED
