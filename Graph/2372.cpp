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

vector<vector<Vertice>> G; // lista de adjacencia

vector<int> dist; // distancia
vector<bool> cor; // cor
vector<int> pai; // pai

bool comparar(const int A, const int B){
  return dist[A] < dist[B];
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
  int X, Y, M, N, maior = 0, m, menor = 10000, soma = 0, maiortotal;
  cin >> N >> M;
  G.resize(N+1);
  double p;
  for(int i = 0; i < M; i++){
    cin >> X >> Y >> p;
    G[X].push_back(Vertice(Y, p));
    G[Y].push_back(Vertice(X, p));
  }
  for(int i = 0; i < N; i++){
    dijkstra(i);
    maior = 0;
    for(int j = 0; j < N; j++){
      if(j != i){
        m = dist[j];
        soma += m;
      }
      if(m > maior){
        maior = m;
      }
    }
    cor.clear();
    dist.clear();
    pai.clear();
    if(soma < menor){
      menor = soma;
      maiortotal = maior;
    }
  }
  cout << maiortotal << endl;
}