#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cont {
  int soma = 0;
  int i;
};

vector<int> M;
int T, V, n;

vector<vector<bool>> check;

bool compare(int a, int b){ return a > b; }

int main(){

  cin >> T >> V;
  check.resize(V);
  for(int i = 0; i < V; i++){
    check[i].resize(T+1, false);
    scanf("%d", &n);
    if(n == T){
      cout << "S" << endl;
      return 0;
    }
    if(n < T){
      M.push_back(n);
    }
  }

  sort(M.begin(), M.end(), compare);

  queue<cont> Q;
  Q.push({0, 0});
  while(!Q.empty()){
    cont u = Q.front();
    //cout << u.soma << endl;
    Q.pop();
    if(u.soma == T){
      cout << "S" << endl;
      return 0;
    }
    if(u.i < M.size() && u.soma < T && !check[u.i][u.soma]){
      check[u.i][u.soma] = true;
      Q.push({u.soma + M[u.i], u.i+1});
      Q.push({u.soma, u.i+1});
    }
  }
  cout << "N" << endl;

}
