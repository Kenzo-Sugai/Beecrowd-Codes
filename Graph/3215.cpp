#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
  int P, A, X, Y, v;
  cin >> P >> A;
  int valores[P];
  for(int i = 0; i < P; i++){
    cin >> v;
    valores[i] = v; 
  }
  vector<vector<int>> G;
  G.resize(P+1);
  for(int i = 0; i < A; i++){
    cin >> X >> Y;
    G[X].push_back(Y);
    G[Y].push_back(X);
  }

  vector<bool> cor(P+1, false);
  bool verify = false;
  for(int i = 0; i < P; i++){
    int soma = 0;
    if(!cor[i]){
      queue<int> Q;
      Q.push(i);
      while(!Q.empty()){
        int u = Q.front();
        //cout << "v: " << valores[u] << endl;
        soma += valores[u];
        valores[u] = 0;
        //cout << "s: " << soma << endl;
        cor[u] = true;
        Q.pop();
        for(int j = 0; j < G[u].size(); j++){
          if(!cor[G[u][j]]){
            Q.push(G[u][j]);
          }
        }
      }
      if(soma != 0){
        cout << "IMPOSSIBLE" << endl;
        verify = true;
        break;
      }
    }
  }
  if(verify == false){
    cout << "POSSIBLE" << endl;
  }
}