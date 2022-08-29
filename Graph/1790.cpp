#include <iostream>
#include <vector>

using namespace std;

int main(){

  int N, M, A, B;

  while(cin >> N >> M){
    vector<vector<int>> G;
    G.resize(N+1);
    for(int i = 0; i < M; i++){
      cin >> A >> B;
      G[A].push_back(B);
      G[B].push_back(A);
    }

    for(int i = 0; i < G.size(); i++){
      cout << i << ": ";
      for(int u = 0; G[i].size(); u++){
        cout << G[i][u] << " ";
      }
      cout << endl;
    }
  }
}