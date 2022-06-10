#include "Videos.h"

Videos :: Videos(){}

Videos :: Videos(std::string id,std::string nombre,std::string duracion,std::string genero){
  this -> id = id;
  this -> nombre = nombre;
  this -> duracion = duracion;
  this -> genero = genero;
}

/*double Videos :: mostrarCalificacion(){ //el string datos pienso que sea le vector del txt, pero no c como se mete
  //que haga una cagada para mostrar la calificacion de los videos xd

}*/

/*double Videos ;; calificarVideo(){
  // que haga una cada para darle la oportunidad al wey del usuario y que su calificacion llene algo
}*/

std::string Videos:: getNombre(){
  return nombre;
}
