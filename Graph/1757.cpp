#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <math.h>

using namespace std;

struct Ponto{
  int x;
  int y;
  double w;
};

// classe vertice
class Vertice {
  public:
    double p;
    int i;

    // contrutores
    Vertice(){};

    Vertice(int i, double p){
      this->p = p;
      this->i = i;
    }
};

vector<vector<Vertice>> G; // lista de adjacencia
vector<Ponto> pontos;

vector<double> dist; // distancia
vector<bool> cor; // cor
vector<int> pai; // pai

bool comparar(const int A, const int B){
  return dist[A] > dist[B];
}

void dijkstra(int s){
  vector<int> Q; // heap

  pai.resize(G.size(), -1);
  cor.resize(G.size(), false);
  dist.resize(G.size(), INT_MAX);
  Q.push_back(s);
  dist[s] = 0;
  cor[s] = true;

  while(!Q.empty()){ // DFS/heap
    int u = Q[0];
    pop_heap(Q.begin(), Q.end(), comparar);
    Q.pop_back();

    for(int i = 0; i < G[u].size(); i++){

      if(dist[u] + G[u][i].p < dist[G[u][i].i]){
        dist[G[u][i].i] = dist[u] + G[u][i].p;
        pai[G[u][i].i] = u;
      }

      if(cor[G[u][i].i] == false){
        cor[G[u][i].i] = true;
        Q.push_back(G[u][i].i);
      }

   }
    make_heap(Q.begin(), Q.end(), comparar);
  }
}

int main(){
  int X, Y, M, N, C;
  while(true){
    cin >> N;
    if(N == 0){
      break;
    }
    G.resize(N+1);
    double p;
    for(int i = 0; i < N; i++){
      cin >> X >> Y >> p;
      pontos.push_back({X, Y, p});
    }
    for(int i = 0; i < pontos.size(); i++){
      for(int j = 0; j < pontos.size(); j++){
        double w = sqrt(pow(pontos[i].x - pontos[j].x, 2)+pow(pontos[i].y - pontos[j].y, 2));
        if(w <= pontos[i].w){
          G[i].push_back(Vertice(j, w));
        }
      }
    }

    /*
    for(int i = 0; i < N; i++){
      cout << i << " - ";
      for(int j = 0; j < G[i].size(); j++){
        cout << G[i][j].i << " ";
      }
      cout << endl;
    }
    */

    cin >> C;
    while(C--){
      cin >> X >> Y;
      X--;
      Y--;
      dijkstra(X);
      if(dist[Y] == INT_MAX){
        cout << -1 << endl;
      }
      else{
        cout << int(dist[Y]) << endl;
      }
      cor.clear();
      dist.clear();
    }
    cor.clear();
    dist.clear();
    pai.clear();
    G.clear();
    pontos.clear();
  }
}