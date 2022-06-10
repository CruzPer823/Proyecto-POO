#ifndef SERIES_H_INCLUDE
#define SERIES_H_INCLUDE

#include "Videos.h"

class Series : public Videos{
private:
  std::string nombreCapitulo, temporada, idCapitulo;
public:
  Series();
  Series(std::string,std::string,std::string,
    std::string,std::string, std::string, std::string, double);
  std::string getGen();
  std::string getNombre();
};

#endif // SERIES_H_INCLUDE
