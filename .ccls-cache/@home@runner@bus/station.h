#ifndef STATION_H
#define STATION_H

#include <string>

struct station{
  std::string name, line;

  bool operator==(const station &other) const ;
  bool operator<(const station &other) const ;
};

#endif // STATION_H ~ //