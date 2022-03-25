#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

int main(){
  int idas, compras, amount, quant;
  float value, total = 0;
  string name, type;
  map<string, float> produto;

  cin >> idas;
  for(int i = 0; i < idas; i++){
    cin >> compras;
    for(int j = 0; j < compras; j++){
      cin >> name >> value;
      produto.emplace(name, value);
    }
    cin >> amount;
    for(int j = 0; j < amount; j++){
      cin >> type >> quant;
      total = quant*produto[type] + total;
    }
    printf("R$ %.2f\n", total);
    total = 0;
    produto.clear();
  }
}
