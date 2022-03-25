#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int O, D, K, P;

  while(true){
    bool verify = false;
    cin >> O >> D >> K;
    if(O == 0 && D == 0 && K == 0){
      break;
    }
    vector <bool> cor(100001, false);
    vector <int> dist(100001, -1);

    for(int i = 0; i < K; i++){
      cin >> P;
      cor[P] = true;
    }

    queue<int> Q;

    Q.push(O);

    cor[O] = true;
    dist[O] = 0;

    while(!Q.empty()){
      int u = Q.front();
      Q.pop();
      if(u-1 > 0 && cor[u-1] == false){
        cor[u-1] = true;
        dist[u-1] = dist[u] +1;
        Q.push(u-1);
        if(u-1 == D){
          verify = true;
          cout << dist[u-1] << endl;
          break;
        }
      }
      if(u+1 < 100001 && cor[u+1] == false){
        cor[u+1] = true;
        dist[u+1] = dist[u] +1;
        Q.push(u+1);
        if(u+1 == D){
          verify = true;
          cout << dist[u+1] << endl;
          break;
        }
      }
      if(u/2 > 0 && u % 2 == 0 && cor[u/2] == false){
        cor[u/2] = true;
        dist[u/2] = dist[u] +1;
        Q.push(u/2);
        if(u/2 == D){
          verify = true;
          cout << dist[u/2] << endl;
          break;
        }
      }
      if(u*2 < 100001 && cor[u*2] == false){
        cor[u*2] = true;
        dist[u*2] = dist[u] +1;
        Q.push(u*2);
        if(u*2 == D){
          verify = true;
          cout << dist[u*2] << endl;
          break;
        }
      }
      if(u*3 < 100001 && cor[u*3] == false){
        cor[u*3] = true;
        dist[u*3] = dist[u] +1;
        Q.push(u*3);
        if(u*3 == D){
          verify = true;
          cout << dist[u*3] << endl;
          break;
        }
      }
    }
    if(verify == false){
      cout << -1 << endl;
    }
  }
} 
