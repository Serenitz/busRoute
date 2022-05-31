#include <bits/stdc++.h>>

#include "routeedits.h"

using namespace std;

void routeEdits(Route bus)
{
  int choice;

  pickChoice:
  
  cout << "1. Add Station\n";
  cout << "2. Add Stops to a Station\n";
  cout << "3. List All Stations and Stops\n";

  cout << "0. Back to main menu\n";

  cout << "Pick menu: ";
  cin >> choice;

  cout << "\n===========\n\n";

  switch(choice){
    case 0:
    {
      bus.save();
      cout << "Back to main menu\n";
      break;  
    }
    
    case 1:
    { 
      station x;
      
      cout << "Enter station name: ";
      cin >> x.name;
      cout << "Enter station line: ";
      cin >> x.line;
    
      cout << endl;
    
      bus.addStation(x);
      cout << "\n===========\n\n";
      goto pickChoice; 
    }
    
    case 2:
    {
      int choice2;

      pickChoice2:
      cout << "1. Insert in between stations\n";
      cout << "2. Insert at the beginning\n";
      cout << "3. Insert at the end\n";

      cout << "Pick menu: ";
      cin >> choice2;

      cout << "\n===========\n\n";

      switch(choice2){
        case 1:
        {
          station x, y, z;
          int w1, w2;
          bool twoWay;
          char ans;

          cout << "Enter station name: ";
          cin >> x.name;
          cout << "Enter station line: ";
          cin >> x.line;
    
          cout << endl << "Editing " << x.name << "/" << x.line << endl << endl;
          
          cout << "Enter prev station name: ";
          cin >> y.name;
          cout << "Enter prev station line: ";
          cin >> y.line;
          cout << "Enter prev station dist: ";
          cin >> w1;
    
          cout << endl << "Connecting " << y.name << "/" << y.line << " with dist " << w1 << " as prev station" << endl << endl;

          do
          {
            cout << "Make two way?(Y/N) ";
            cin >> ans;
            ans = tolower(ans);
          }while (ans != 'y' && ans != 'n');
        
          if(ans == 'y')
          {
            twoWay = 1;
            cout << "Connected two way!" << endl << endl;
            bus.addEdge(y, x, w1, twoWay);
          }else if(ans == 'n')
          {
            twoWay = 0;
            cout << "Connected one way!" << endl << endl;
            bus.addEdge(y, x, w1, twoWay);
          }

          cout << "Enter next station name: ";
          cin >> z.name;
          cout << "Enter next station line: ";
          cin >> z.line;
          cout << "Enter next station dist: ";
          cin >> w2;
    
          cout << endl << "Connecting " << z.name << "/" << z.line << " with dist " << w2 << " as next station" << endl << endl;

          do
          {
            cout << "Make two way?(Y/N) ";
            cin >> ans;
            ans = tolower(ans);
          }while (ans != 'y' && ans != 'n');
        
          if(ans == 'y')
          {
            twoWay = 1;
            cout << "Connected two way!" << endl << endl;
            bus.addEdge(x, z, w2, twoWay);
          }else if(ans == 'n')
          {
            twoWay = 0;
            cout << "Connected one way!" << endl << endl;
            bus.addEdge(x, z, w2, twoWay);
          }
          
          bus.delEdge(y, z, true);
          break;
        }
        
        case 2:
        {
          station x, y;
          int w;
          bool twoWay;
          char ans;
          
          cout << "Enter station name: ";
          cin >> x.name;
          cout << "Enter station line: ";
          cin >> x.line;
    
          cout << endl << "Editing " << x.name << "/" << x.line << endl << endl;
          
          cout << "Enter next station name: ";
          cin >> y.name;
          cout << "Enter next station line: ";
          cin >> y.line;
          cout << "Enter next station dist: ";
          cin >> w;
    
          cout << endl << "Connecting " << y.name << "/" << y.line << " with dist " << w << " as next station" << endl << endl;

          do
          {
            cout << "Make two way?(Y/N) ";
            cin >> ans;
            ans = tolower(ans);
          }while (ans != 'y' && ans != 'n');
        
          if(ans == 'y')
          {
            twoWay = 1;
            cout << "Connected two way!" << endl << endl;
            bus.addEdge(x, y, w, twoWay);
          }else if(ans == 'n')
          {
            twoWay = 0;
            cout << "Connected one way!" << endl << endl;
            bus.addEdge(x, y, w, twoWay);
          }

          break;
        }

        case 3:
        {
          station x, y;
          int w;
          bool twoWay;
          char ans;
          
          cout << "Enter station name: ";
          cin >> x.name;
          cout << "Enter station line: ";
          cin >> x.line;
    
          cout << endl << "Editing " << x.name << "/" << x.line << endl << endl;
          
          cout << "Enter prev station name: ";
          cin >> y.name;
          cout << "Enter prev station line: ";
          cin >> y.line;
          cout << "Enter prev station dist: ";
          cin >> w;
    
          cout << endl << "Connecting " << y.name << "/" << y.line << " with dist " << w << " as prev station" << endl << endl;

          do
          {
            cout << "Make two way?(Y/N) ";
            cin >> ans;
            ans = tolower(ans);
          }while (ans != 'y' && ans != 'n');
        
          if(ans == 'y')
          {
            twoWay = 1;
            cout << "Connected two way!" << endl << endl;
            bus.addEdge(y, x, w, twoWay);
          }else if(ans == 'n')
          {
            twoWay = 0;
            cout << "Connected one way!" << endl << endl;
            bus.addEdge(y, x, w, twoWay);
          }

          break;
        }  

        default:
        {
          cout << "No menu with your choice!\n";
          goto pickChoice2;
        }
      }

      cout << "\n===========\n\n";
      goto pickChoice;
      }

    case 3:
    {
      bus.printRoutes();
      cout << "===========\n\n";

      goto pickChoice;
    }
    
    default:
    {
      cout << "No menu with your choice!\n";
      cout << "\n===========\n\n";
      goto pickChoice;
    }
      
  }
}