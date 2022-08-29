#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct lista{
  int a;
  int b;
};

int main(){

  int N, X, Y, maior;

  while(cin >> N){
    maior = 0;
    vector<lista> l;
    vector<vector<int>> G;
    for(int i = 0; i < N; i++){
      cin >> X >> Y;
      Y++;
      l.push_back({X, Y});
      if(Y > maior){
        maior = Y;
      }
    }
    G.resize(maior+1);
    for(int i = 0; i < N; i++){
      G[l[i].a].push_back(l[i].b);
    }

  queue<int> Q;
  Q.push(1);
  vector<bool> cor(maior+1, false);
  vector<int> d(maior+1, 0);
  d[0] = 1;

  while(!Q.empty()){
    int u = Q.front();
    cout << u << endl;
    Q.pop();

    for(int i = 0; i < G[u].size(); i++){
      if(!cor[G[u][i]]){
        d[G[u][i]] = d[u] + 1;
        cor[G[u][i]] = true;
        Q.push(G[u][i]);
        if(G[u][i] == maior){
          break;
        }
      }
    }
  }
  //cout << maior << endl;
  cout << d[maior] << endl;
  }
}