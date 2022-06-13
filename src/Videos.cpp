#include "Videos.h"

Videos :: Videos(){}

Videos :: Videos(std::string id,std::string nombre,std::string duracion,
  std::string genero, double calificacion){
  this -> id = id;
  this -> nombre = nombre;
  this -> duracion = duracion;
  this -> genero = genero;
  this -> calificacion = calificacion;
}

Videos :: Videos(std::string id, std::string nombre, std::string genero){
  this -> id = id;
  this -> nombre = nombre;
  this -> genero = genero;
}

Videos :: Videos(std::string id, std::string nombre){
  this -> id = id;
  this -> nombre = nombre;
}
/*double Videos ;; calificarVideo(){
  // que haga una cada para darle la oportunidad al wey del usuario y que su calificacion llene algo
}*/
