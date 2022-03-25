#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

int main() {

  int N, M, a, b, E;

  while(scanf("%d %d", &N, &M) != EOF){
    vector < vector <int> > G;

    G.resize(N+1);

    for(int i = 0; i < M; i++){
      scanf("%d %d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }

    cin >> E;

    queue<int> Q;

    Q.push(E);
    vector<int> t;
    vector<bool> cor(N+1, false);
    cor[E] = true;
    while(!Q.empty()){
      int u = Q.front();
      t.push_back(u);
      Q.pop();
      for(int i = 0; i < G[u].size(); i++){
        if(!cor[G[u][i]]){
          cor[G[u][i]] = true;
          Q.push(G[u][i]);
        }
      }
    }
    printf("%d\n", t.size());
  }
} 
