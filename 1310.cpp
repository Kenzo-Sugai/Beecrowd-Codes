#include <iostream>
#include <vector>

using namespace std;

int main(){

  int dias, ingresso, lucro, valor, maior, sum;

  while(cin >> dias){
    maior = 0;
    cin >> ingresso;
    vector<int> lucroPorDia;
    for(int i = 0; i < dias; i++){
      cin >> valor;
      lucroPorDia.push_back(valor);
    }

    for(int size = 1; size <= lucroPorDia.size(); size++){

      for(int i = 0; i < lucroPorDia.size(); i++){
        sum = 0;
        for(int j = 0; j < size; j++){
          if(size + i > lucroPorDia.size()){
            break;
          }
          if(i+j < lucroPorDia.size()){
            //cout << lucroPorDia[j+i] <<  " ";
            sum += lucroPorDia[j+i];
          }
        }
        lucro = sum - (size * ingresso);
        if(maior < lucro){
          maior = lucro;
        }
      }
    }
    cout << maior << endl;
  } 
}
