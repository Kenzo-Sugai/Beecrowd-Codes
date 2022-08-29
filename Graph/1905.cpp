#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cords{
  int x;
  int y;
};

int main(){
  int T, n;
  string line;
  cin >> T;

  while(T--){
    cin >> line;
    bool verify = false;
    vector<vector<int>> G;
    vector<vector<int>> cor;
    G.resize(5);
    cor.resize(5);
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        cin >> n;
        cor[i].push_back(false);
        G[i].push_back(n);
      }
    }

    queue<cords> Q;
    Q.push({0, 0});
    cor[0][0] = true;

    while(!Q.empty()){
      cords u = Q.front();
      Q.pop();

      if(u.x+1 < 5 && G[u.x+1][u.y] == 0 && cor[u.x+1][u.y] == false){
        cor[u.x+1][u.y] = true;
        Q.push({u.x+1, u.y});
        if(u.x+1 == 4 && u.y == 4){
          verify = true;
        }
      }
      if(u.x-1 >= 0 && G[u.x-1][u.y] == 0 && cor[u.x-1][u.y] == false){
        cor[u.x-1][u.y] = true;
        Q.push({u.x-1, u.y});
        if(u.x-1 == 4 && u.y == 4){
          verify = true;
        }
      }
      if(u.y+1 < 5 && G[u.x][u.y+1] == 0 && cor[u.x][u.y+1] == false){
        cor[u.x][u.y+1] = true;
        Q.push({u.x, u.y+1});
        if(u.x == 4 && u.y+1 == 4){
          verify = true;
        }
      }
      if(u.y-1 >= 0 && G[u.x][u.y-1] == 0 && cor[u.x][u.y-1] == false){
        cor[u.x][u.y-1] = true;
        Q.push({u.x, u.y-1});
        if(u.x == 4 && u.y-1 == 4){
          verify = true;
        }
      }
    }

    if(verify == true){
      cout << "COPS" << endl;
    }
    else{
      cout << "ROBBERS" << endl;
    }
  }
}