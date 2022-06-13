#ifndef SERIES_H_INCLUDE
#define SERIES_H_INCLUDE

#include "Videos.h"

class Series : public Videos{
private:
  int temporadas;
public:
  Series();
  Series(std::string,std::string,std::string,int);
  Series(std::string, std::string);
  std::string getGen();
  std::string getNombre();
  std::string getID();
  double getCalif();
};

#endif // SERIES_H_INCLUDE
