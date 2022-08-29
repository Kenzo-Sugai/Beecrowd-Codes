#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M;
  string linha;
  vector<vector<char>> mapa;
  cin >> N >> M;
  mapa.resize(N+1);
  for(int i = 0; i < N; i++){
    cin >> linha;
    for(int j = 0; j < M; j++){
      mapa[i].push_back(linha[j]);
    }
  }
  int contador = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(mapa[i][j] == '#'){
        if(i-1 >= 0 && mapa[i-1][j] == '#' && i+1 < N && mapa[i+1][j] == '#' && j-1 >= 0 && mapa[i][j-1] == '#' && j+1 < M && mapa[i][j+1] == '#'){
          contador = contador;
        }
        else{
          contador++;
        }
      }
    }
  }
  cout << contador << endl;
}