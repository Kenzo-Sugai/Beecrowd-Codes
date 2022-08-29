#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Matrix{
  public:
    vector<vector<int>> G;
    int x0;
    int y0;
    Matrix(vector<vector<int>> G, int x0, int y0){
      this->G = G;
      this->x0 = x0;
      this->y0 = y0;
    };
};

int main(){
  int X, Y;
  vector<vector<int>> G;
  G.resize(3);
  string line;
  for(int i = 0; i < 3; i++){
    cin >> line;
    for(int j = 0; j < 3; j++){
      int n = int(line[j] - 48);
      if(n == 0){
        X = i;
        Y = j;
      }
      G[i].push_back(n);
    }
  }

  queue<Matrix> Q;
  Q.push(Matrix(G, X, Y));
  while(!Q.empty()){
    Matrix u = Q.front();
    Q.pop();

    if(u.x0-1 >= 0){
      u.G[u.]
      Q.push(Matrix())
    }
  }

}