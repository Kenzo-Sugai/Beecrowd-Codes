#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cords{
  int x;
  int y;
};

vector<vector<char>> G;

int main(){

  int N, M, index_i, index_j;
  string line;

  while(cin >> N >> M){
    if(N == 0 && M == 0){
      break;
    }
    queue<cords> Q;
    G.resize(N+1);
    for(int i = 0; i < N; i++){
      cin >> line;
      for(int j = 0; j < M; j++){
        G[i].push_back(line[j]);
        if(line[j] == 'T'){
          Q.push({i, j});
        }
      }
    }

    while(!Q.empty()){
      cords u = Q.front();
      Q.pop();

      if(u.y+1 < M && G[u.x][u.y+1] == 'A'){
        G[u.x][u.y+1] = 'T';
        Q.push({u.x, u.y+1});
      }
      if(u.y-1 >= 0 && G[u.x][u.y-1] == 'A'){
        G[u.x][u.y-1] = 'T';
        Q.push({u.x, u.y-1});
      }
      if(u.x+1 < N && G[u.x+1][u.y] == 'A'){
        G[u.x+1][u.y] = 'T';
        Q.push({u.x+1, u.y});
      }
      if(u.x-1 >= 0 && G[u.x-1][u.y] == 'A'){
        G[u.x-1][u.y] = 'T';
        Q.push({u.x-1, u.y});
      }
    }

    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        cout << G[i][j];
      }
      cout << endl;
    }
    G.clear();
    cout << endl;
  }
}