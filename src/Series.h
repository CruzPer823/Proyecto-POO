#ifndef SERIES_H_INCLUDE
#define SERIES_H_INCLUDE

#include "Videos.h"

class Series : public Videos{
private:
  std::string id,nombre,genero;
  int temporadas;
public:
  Series();
  Series(std::string,std::string,std::string,
    std::string);
  std::string getGen();
  std::string getNombre();
};

#endif // SERIES_H_INCLUDE
