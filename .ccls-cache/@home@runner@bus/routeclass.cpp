#include <fstream>

#include "routeclass.h"

using namespace std;

bool compare::operator() (pair<int, int> a, pair<int, int> b){
	return a.second > b.second;
};

Route::Route()
{
  station s, adj;
  std::vector<stationPair> adjWeight;
  string dist; //, time;
  int weight;

  ifstream file("dummy-data.txt");

  if (file.is_open())
  {
    while (std::getline(file, s.name, '-') && std::getline(file, s.line, '#'))
    {
      cout << s.name << "-" << s.line << "#";

      while (std::getline(file, adj.name, ',') && std::getline(file, adj.line, ',') && std::getline(file, dist, ';'))
      {
        if(dist == "end") break;

        weight = stoi(dist);
        //weight.travelTime = stoi(time);

        adjWeight.push_back(make_pair(adj, weight));

        cout << adj.name << "," << adj.line << "," << dist << ";";
      }

      string temp;

      std::getline(file, temp, '\n');

      busRoute.emplace(std::pair<station, std::vector<stationPair>>(s,adjWeight));
      //cout << endl;

      adjWeight.clear();

      cout << endl;
    }
  }

  file.close();
}

void Route::save()
{
  std::vector<stationPair>::iterator it_pair;
  
  ofstream file("dummy-data.txt");

  if(file.is_open())
  {
    for(it_busRoute = busRoute.begin(); it_busRoute != busRoute.end(); it_busRoute++)
    {
      file << it_busRoute->first.name << "-" << it_busRoute->first.line << "#";
  
      for(it_pair = it_busRoute->second.begin(); it_pair != it_busRoute->second.end(); it_pair++)
        {
          file << it_pair->first.name << "," << it_pair->first.line << "," << it_pair->second << ";" ;
        }
      
      file << "0,0,end;" << endl;
    }
  }

  file.close();
}

int Route::countStation()
{
  int count = 0;

  for(it_busRoute = busRoute.begin(); it_busRoute != busRoute.end(); ++it_busRoute){
    count++;
  }

  return count;
}

void Route::printPath(std::map<station,station> parent, station dest)
{
  // Base Case : If j is source
    if (parent[dest].name.empty() && parent[dest].line.empty()){
      cout << dest.name << "/" << dest.line;
      return;
    }
        
    printPath(parent, parent[dest]);
    cout << " -> " << dest.name << "/" << dest.line;
}

void Route::dijkstra(station src, station dest)
{
  priority_queue<stationPair,vector <stationPair>,greater<stationPair> > pq;
  
  std::map<station,maxInt> dist; // from src
  // std::map<station,bool> sptSet; 
  //   // sptSet[i] will true if vertex i is included / in
  // 	// shortest path tree or shortest distance from src to i
  // 	// is finalized
  std::map<station,station> parent; // to store shortest path tree

  dist[src].value = 0;
  pq.push(make_pair(src, 0));

  // foo/red - bar/red 5 - baz/red 3 - baz/blue 0

  while(!pq.empty())
  {
    station u = pq.top().first;
    pq.pop();
    if(u == dest && pq.empty()) break;

    std::vector<stationPair>::iterator it_pair;
    for(it_pair = busRoute[u].begin(); it_pair != busRoute[u].end(); it_pair++)
    {
      station v = it_pair->first;
      int weight = it_pair->second;

      if(dist[v].value > dist[u].value + weight)
      {
        parent[v] = u;
        dist[v].value = dist[u].value + weight;
				pq.push(make_pair(v, dist[v].value));
      }
    }
    
    if(u.name != dest.name && u.line != dest.line && pq.empty())
      goto noRoute;
  }

  printPath(parent, dest);

  noRoute:
  cout << "No route available from " << src.name << "/" << src.line << " to "  << dest.name << "/" << dest.line << "!";
}

void Route::addStation(station s)
{
  busRoute[s] = {};
};
  
void Route::addEdge(station s, station adj, int weight, bool twoWay)
{
  std::vector<stationPair> temp;
  temp = busRoute[s];
  temp.push_back(make_pair(adj,weight));  
  busRoute[s] = temp;

  temp.empty();

  if(twoWay)
  {
    std::vector<stationPair> temp;
    temp = busRoute[adj];
    temp.push_back(make_pair(s,weight));  
    busRoute[adj] = temp;
  }
}

void Route::delEdge(station s, station adj, bool twoWay)
{
  int w;
  std::vector<stationPair> temp;
  temp = busRoute[s];

  for(auto& it : temp){
        if(it.first == adj){
            w = it.second;
        }
    }

  temp.erase(std::find(temp.begin(),temp.end(),make_pair(adj,w)));
  busRoute[s] = temp;

  temp.empty();

  if(twoWay)
  {
    temp = busRoute[adj];
    
    for(auto& it : temp){
          if(it.first == s){
              w = it.second;
          }
      }
  
    temp.erase(std::find(temp.begin(),temp.end(),make_pair(s,w)));
    busRoute[adj] = temp;
  }
}

void Route::printRoutes()
{
  std::vector<stationPair>::iterator it_pair;
  
  for(it_busRoute = busRoute.begin(); it_busRoute != busRoute.end(); it_busRoute++)
  {
    cout << it_busRoute->first.name << "-" << it_busRoute->first.line << "#";

    for(it_pair = it_busRoute->second.begin(); it_pair != it_busRoute->second.end(); it_pair++)
    {
      cout << it_pair->first.name << "," << it_pair->first.line << "," << it_pair->second << ";" ;
    }

    cout << endl;
  }

  cout << endl;
}
//void loading(){
//  cout << "Load!" << endl;
//}

// void route::debug()
// {
//   std::vector<std::pair<station, weights>>::iterator it_pair;
  
//   for(it_busRoute = busRoute.begin(); it_busRoute != busRoute.end(); it_busRoute++)
//   {
//     cout << it_busRoute->first.name << "-" << it_busRoute->first.line << "#";

//     for(it_pair = it_busRoute->second.begin(); it_pair != it_busRoute->second.end(); it_pair++)
//       {
//         cout << it_pair->first.name << "," << it_pair->first.line << "," << it_pair->second.km << "," << it_pair->second.travelTime << ";";
//       }
//   }
// }