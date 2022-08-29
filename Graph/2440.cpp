#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

  int N, M, A, B;

  cin >> N >> M;

  vector<vector<int>> G;

  G.resize(N+1);

  for(int i = 0; i < M; i++){
    cin >> A >> B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  queue<int> Q;
  vector<bool> cor(N+1, false);
  int cnt {0};
  for(int c = 1; c <= N; c++){
    if(!cor[c]){
      Q.push(c);
      cor[c] = true;
      while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int i = 0; i < G[u].size(); i++){
          if(!cor[G[u][i]]){
            cor[G[u][i]] = true;
            Q.push(G[u][i]);
          }
        }
      }
      cnt++;
    }
  }
  cout << cnt << endl;
}