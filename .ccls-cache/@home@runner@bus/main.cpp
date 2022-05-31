#include <bits/stdc++.h>
#include <cctype>

#include "routeedits.h"

using namespace std;

Route bus;

int main(){
  int choice;
  
  cout << endl << "=============" << endl << endl;

  mainMenu:
  cout << "1. Search route\n";
  cout << "2. Edit Routes/Station\n";

  cout << "0. Exit\n";
  cout << "Choice: ";
  cin >> choice;

  cout << "\n===========\n\n";

  switch(choice)
  {
    case 0:
    {
      cout << "Exiting...\n";
      break;  
    }
    
    case 1:
    {
      station src, dest;

      cout << "Enter start station name: ";
      cin >> src.name;
      cout << "Enter start station line: ";
      cin >> src.line;

      cout << "\nEnter destination station name: ";
      cin >> dest.name;
      cout << "Enter destination station line: ";
      cin >> dest.line;

      cout << "\nFrom: " << src.name << "/" << src.line << endl;
      cout << "To  : " << dest.name << "/" << dest.line << endl << endl;

      bus.dijkstra(src, dest);

      cout << endl << "\n===========\n\n";
      
      goto mainMenu;
    }
    
    case 2:
    {
      routeEdits(bus);

      goto mainMenu;
    }
    
    default:
    {
      cout << "No menu with your choice!\n";
      cout << "\n===========\n\n";
      goto mainMenu;
    }
  }

  //bus.debug();

  return 0;
}
