#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include <string>

class Videos {
  Protected:
    std::string id, nombre, duracion, genero;
    std::string datos[10000]
  Public:
  Videos();
  Videos(std::string,std::string,std::string,std::string, std::string);
  virtual double mostrarCalificacion(std::string datos);
  virtual double calificarVideo(std::string datos);

};

#endif // VIDEO_H_INCLUDED
