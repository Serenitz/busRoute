#ifndef ROUTECLASS_H
#define ROUTECLASS_H

#include <map>
#include <vector>
#include <bits/stdc++.h>

#include "station.h"
//#include "weights.h"

typedef std::pair<station, int> stationPair;

struct maxInt
{
  int value = INT_MAX;
};

class compare
{
public:
  bool operator()(std::pair<int, int> a, std::pair<int, int> b);
};

class Route
{
protected:
  std::map<station, std::vector<stationPair>> busRoute;
  std::map<station, std::vector<stationPair>>::iterator it_busRoute;

public:
  

  Route();
  void save();
  int countStation();
  void printPath(std::map<station,station> parent, station dest);
  void dijkstra(station src, station dest);
  void addStation(station s);
  void addEdge(station s, station adj, int weight, bool twoWay);
  void delEdge(station s, station adj, bool twoWay);
  void printRoutes();
  //void debug();
};

#endif // ROUTECLASS_H ~ //