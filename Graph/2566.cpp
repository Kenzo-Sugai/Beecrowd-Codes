#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

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

vector<vector<Vertice>> G_onibus; // lista de adjacencia
vector<vector<Vertice>> G_aviao; 

vector<int> dist; // distancia
vector<bool> cor; // cor
vector<int> pai; // pai

bool comparar(const int A, const int B){
  return dist[A] > dist[B];
}

void dijkstra_aviao(int s){
  vector<int> Q; // heap

  pai.resize(G_aviao.size(), -1);
  cor.resize(G_aviao.size(), false);
  dist.resize(G_aviao.size(), INT_MAX);
  Q.push_back(s);
  dist[s] = 0;
  cor[s] = true;

  while(!Q.empty()){ // DFS/heap
    int u = Q[0];
    pop_heap(Q.begin(), Q.end(), comparar);
    Q.pop_back();

    for(int i = 0; i < G_aviao[u].size(); i++){

      if(dist[u] + G_aviao[u][i].p < dist[G_aviao[u][i].i]){
        dist[G_aviao[u][i].i] = dist[u] + G_aviao[u][i].p;
        pai[G_aviao[u][i].i] = u;
      }

      if(cor[G_aviao[u][i].i] == false){
        cor[G_aviao[u][i].i] = true;
        Q.push_back(G_aviao[u][i].i);
      }

   }
    make_heap(Q.begin(), Q.end(), comparar);
  }
}

void dijkstra_onibus(int s){
  vector<int> Q; // heap

  pai.resize(G_onibus.size(), -1);
  cor.resize(G_onibus.size(), false);
  dist.resize(G_onibus.size(), INT_MAX);
  Q.push_back(s);
  dist[s] = 0;
  cor[s] = true;

  while(!Q.empty()){ // DFS/heap
    int u = Q[0];
    pop_heap(Q.begin(), Q.end(), comparar);
    Q.pop_back();

    for(int i = 0; i < G_onibus[u].size(); i++){

      if(dist[u] + G_onibus[u][i].p < dist[G_onibus[u][i].i]){
        dist[G_onibus[u][i].i] = dist[u] + G_onibus[u][i].p;
        pai[G_onibus[u][i].i] = u;
      }

      if(cor[G_onibus[u][i].i] == false){
        cor[G_onibus[u][i].i] = true;
        Q.push_back(G_onibus[u][i].i);
      }

   }
    make_heap(Q.begin(), Q.end(), comparar);
  }
}

int main(){
  int X, Y, M, N, T;
  while(cin >> N >> M){
    G_aviao.resize(N+1);
    G_onibus.resize(N+1);
    double p;
    bool av = false, on = false;
    int aviao, onibus;
    for(int i = 0; i < M; i++){
      cin >> X >> Y >> T >> p;
      if(T == 0){
        on = true;
        G_onibus[X].push_back(Vertice(Y, p));
        G_onibus[Y].push_back(Vertice(X, p));
      }
      if(T == 1){
        av = true;
        G_aviao[X].push_back(Vertice(Y, p));
        G_aviao[Y].push_back(Vertice(X, p));
      }
    }
    if(av == true){
      dijkstra_aviao(1);
      aviao = dist[N];
      dist.clear();
      cor.clear();
      pai.clear();
    }
    if(on == true){
      dijkstra_onibus(1);
      onibus = dist[N];
      dist.clear();
      cor.clear();
      pai.clear();
    }
    if(aviao > onibus){
      cout << onibus << endl;
    }
    else{
      cout << aviao << endl;
    }
  }
}