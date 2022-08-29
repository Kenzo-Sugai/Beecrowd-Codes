#include <iostream>
#include <vector>
#include <queue>

struct pos{
  int x;
  int y;
};

using namespace std;

int main(){

  int N, M, S, X, Y, R;

  cin >> N >> M >> S;

  vector<vector<char>> G;
  vector<vector<bool>> cor;
  G.resize(N+1);
  cor.resize(N+1);
  for(int i = 0; i < N+1; i++){
    for(int j = 0; j < M+1; j++){
      G[i].push_back('.');
      cor[i].push_back(false);
    }
  }

  for(int i = 0; i < S; i++){
    cin >> X >> Y >> R;
    for(int j = X-R; j <= X+R; j++){
      for(int k = Y-R; k <= Y+R; k++){
        if(j < 0 || k < 0 || j > N || k > M){
          break;
        } 
        if((abs(j-X) + abs(k-Y)) <= R){
          G[j][k] = 'X';
          cor[j][k] = true;
        }
      }
    }
  }
  
  for(int i = 0; i < N+1; i++){
    for(int j = 0; j < M+1; j++){
      cout << G[i][j];
    }
    cout << endl;
  }
  
  bool verify = false;
  queue<pos> Q;
  cor[0][0] = true;
  Q.push({0, 0});
  while(!Q.empty()){
    int ux = Q.front().x;
    int uy = Q.front().y;
    //cout << "x: " << ux << " " << "y: " << uy << endl;
    Q.pop();
    for(int i = uy-1; i <= uy+1; i++){
      for(int j = ux-1; j <= ux+1; j++){
        if(j >= 0 && j <= M && i >= 0 && i <= N && cor[i][j] == false && G[i][j] == '.'){
          cor[i][j] = true;
          Q.push({j, i});
          if(i == N && j == M){
            verify = true;
            //cout << "ACHOU" << endl;
          }
        }
      }
    }
  }
  if(verify == true){
    cout << "S" << endl;
  }
  else{
    cout << "N" << endl;
  }
}