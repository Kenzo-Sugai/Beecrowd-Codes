#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int reverse(int x) {
  int inv = 0;
  while (x > 0) {
    inv = 10 * inv + x % 10;
    x /= 10;
  }
  return inv;
}

int main() {
  int T, A, B;

  cin >> T;

  for(int i = 0; i < T; i++){
    cin >> A >> B;

    //cout << "-- " << A << " to " << B << " --" << endl;
    queue<int> Q;
    Q.push(A);
    vector <int> dist(100000, -1);
    vector <int> pai(100000, -1);
    vector <bool> cor(100000, false);

    dist[A] = 0;
    cor[A] = true;

    while(!Q.empty()){
      if(A == B){
        cout << 0 << endl;
        break;
      }
      int u = Q.front();
      int n = reverse(u);
      Q.pop();
      //cout << "[u: " << u << "]" << endl;
      //cout << "u+1: " << u+1 << endl;
      //cout << "n: " << n << endl;
      if(cor[u+1] == false){
        dist[u+1] = dist[u] +1;
        pai[u+1] = u;
        cor[u+1] = true;
        Q.push(u+1);
        if(u+1 == B){
          cout << dist[u+1] << endl;
          break;
        }
      }
      if(cor[n] == false){
        dist[n] = dist[u] +1;
        pai[n] = u;
        cor[n] = true;
        Q.push(n);
        if(n == B){
          cout << dist[n] << endl;
          break;
        }
      }
    }
  }
} 
