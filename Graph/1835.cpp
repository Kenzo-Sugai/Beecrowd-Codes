#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stdlib.h>

using namespace std;

int main() {
  int T, M, N, X, Y, t = 1, count = 0;
  string v1, v2;
  //cout << "Números de casos: " << endl;
  cin >> T;

  while(T--){
    vector < vector <int> > G;
    //cout << "Digite o número de vértices e arestas: " << endl;
    cin >> N;
    cin >> M;
    G.resize(130);
    vector<bool> cor(N+1, false);

    for(int j = 0; j < M; j++){
      //cout << "Valor v1 e v2 - A: " << j+1 << endl;
      cin >> X >> Y;

      G[X].push_back(Y);
      G[Y].push_back(X);
    }

    /*
    for(int i = 97 ; i < V+97; i++){
      cout << string(1, i) << " -";
      for(int u = 0; u < G[i].size(); u++){
          cout << " " << string(1, G[i][u]);
      }
      cout << endl;
    }
    */

    cout << "Caso #" << t << ": ";
    t++;
    int p = 0;
    for(int j = 1; j <= N; j++){
      p++;
      if(cor[j] == false){
        queue<int> Q;
        Q.push(j);

        vector<int> d(N+1, 0);
        vector<int> p(N+1, 0);

        d[j] = 0;
        cor[j] = true;
        while(!Q.empty()){
          int u = Q.front();
          Q.pop();
          for(int i = 0; i < G[u].size(); i++){
            if(!cor[G[u][i]]){
              d[G[u][i]] = d[u] +1;
              p[G[u][i]] = u;
              cor[G[u][i]] = true;
              Q.push(G[u][i]);
            }
          }
        }
        count++;
      }
    }

    if(count == 1){
      cout << "a promessa foi cumprida" << endl;
    }
    else{
      cout << "ainda falta(m) " << count-1 << " estrada(s)" << endl;
    }
    count = 0;
    cor.clear();
    G.clear();
  }
} 
