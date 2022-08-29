#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
  int N;
  string line;

  cin >> N;

  vector<vector<int>> G;

  G.resize(N);

  for(int i = 0; i < N; i++){
    cin >> line;
    for(int j = 0; j < N; j++){
      if(line[j] == 'S' && i != j){
        //cout << "i: " << i << " j: " << j << endl;
        G[i].push_back(j);
        G[j].push_back(i);
      }
    }
  }
  int casas = 0, ptotal = 0;
  vector<int> pessoas;
  queue<int> Q;
  vector<bool> cor(N, false);
  for(int i = 0; i < N; i++){
    if(!cor[i]){
      casas++;
      int p = 0;
      Q.push(i);
      cor[i] = true;
      while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        //cout << "u: " << u << endl;
        p++;
        for(int i = 0; i < G[u].size(); i++){
          if(!cor[G[u][i]]){
            cor[G[u][i]] = true;
            Q.push(G[u][i]);
          }
        }
      }
      ptotal += p;
      pessoas.push_back(p);
    }
  }
  if(ptotal != N || casas == 1){
    cout << -1 << endl;
  }
  else{
    sort(pessoas.begin(), pessoas.end());
    cout << casas << endl;
    cout << pessoas[pessoas.size()-1];
    for(int i = pessoas.size()-2; i >= 0; i--){
      cout << " " << pessoas[i];
    }
    cout << endl;
  }
}