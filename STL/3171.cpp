#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>>G;

int main(){
  int N, M, A, B;
  cin >> N >> M;
  G.resize(N+1);
  for(int i = 0; i < M; i++){
    cin >> A >> B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  queue<int> Q;
  Q.push(1);
  vector<bool>cor(N+1, false);
  cor[1] = true;
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
  bool verify = false;
  for(int i = 1; i < cor.size(); i++){
    if(cor[i] == false){
      verify = true;
      break;
    }
  }
  if(verify == true){
    cout << "INCOMPLETO" << endl;
  }
  else{
    cout << "COMPLETO" << endl;
  }
}