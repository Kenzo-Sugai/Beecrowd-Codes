#include <iostream>
#include <map>

using namespace std;

int main(){

  int size, evt, size_car, size_total, cash {0};
  string placa;
  char type;

  while(cin >> size >> evt){
    map<string, int> car;
    size_total = 0;
    cash = 0;
    for(int i = 0; i < evt; i++){
      cin >> type;
      switch(type){
        case 'C':
          cin >> placa >> size_car;
          car[placa] = size_car;
          if(size_car + size_total <= size){
            size_total += size_car;
            cash += 10;
          }
          break;
        case 'S':
          cin >> placa;
          size_total -= car[placa];
          break;
      }
    }
    cout << cash << endl; 
  }
}