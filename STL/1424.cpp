#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){

  int tamanho, consultas, k, v, index, n;

  while(cin >> tamanho >> consultas){

    map<int, vector<int>> tabela;

    for(int i = 0; i < tamanho; i++){
      cin >> n;
      tabela[n].push_back(i+1);
    }

    for(int i = 0; i < consultas; i++){
      cin >> k >> v;
      bool verificar = false;
      for(int i = 0; i < tabela[v].size(); i++){
        if(i+1 == k){
          verificar = true;
          cout << tabela[v][i] << endl;
        }
      }
      if(verificar == false){
        cout << 0 << endl;
      }
    }
  }
}