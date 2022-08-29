#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

// struct
struct position{
  int x;
  int y;
  int w;
};

// classe vertice
class Vertice {
  public:
    char p;
    int i;

    // contrutores
    Vertice(){};

    Vertice(int i, char p){
      this->p = p;
      this->i = i;
    }
};

vector<vector<Vertice>> G; // lista de adjacencia

vector<int> dist; // distancia
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

    if(G[u]){

    }
    if(Lab[][]){

    }
    if(){

    }
    if(){

    }
    make_heap(Q.begin(), Q.end(), comparar);
  }
}

int main(){
  int X, Y, M, N;
  string line;
  cin >> N >> M;
  G.resize(N+1);
  double p;
  for(int i = 0; i < N; i++){
   cin >> line;
   for(int j = 0; j < M; j++){
     if(line[j] == 'H'){
       X = i;
       Y = j;
     }
     G[i].push_back(Vertice(j, line[j]));
   } 
  }
  dijkstra(G[X][Y].i);
  for(int i = 0; i < N; i++){
    cout << dist[i] << endl;
  }
}