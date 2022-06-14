#include "Episodios.h"

Episodios :: Episodios(){
}

Episodios :: Episodios(std::string id, std::string id_episodio, std::string nombre
  , std::string duracion,
   double calificacion, int temporada):Series(id, nombre){
  this -> id_episodio = id_episodio;
  this -> temporada = temporada;
  this -> calificacion = calificacion;
  this->duracion=duracion;
}

std::string Episodios::getGen(){
  return 0;
}

std::string Episodios::getNombre(){
  return nombre;
}

double Episodios:: getCalif(){
  return calificacion;
}

std::string Episodios:: getID(){

  return id;
}

void Episodios::mostrarDatos(){
  std::cout<<"\nTitulo: "<<nombre<<
  "\nTemporada: "<<temporada<<
  "\nDuracion: "<<duracion<<
  "\nCalificacion: "<<calificacion<<"\n";
}