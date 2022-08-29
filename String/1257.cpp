#include <iostream>

using namespace std;

int main(){

  int casos, entradas;
  string elemento;

  cin >> casos;

  while(casos--){
    cin >> entradas;
    int soma {0};
    for(int i = 0; i < entradas; i++){
      cin >> elemento;
      for(int pos = 0; pos < elemento.size(); pos++){
        soma += (int)elemento[pos]-65 + i + pos;
      }
    }
    cout << soma << endl;
  }
}