#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <map>

using namespace std;

struct peso{
  double w;
  string txt;
};

// classe vertice
class Vertice {
  public:
    peso p;
    int i;

    // contrutores
    Vertice(){};

    Vertice(int i, peso p){
      this->p = p;
      this->i = i;
    }
};

vector<vector<Vertice>> G; // lista de adjacencia

vector<int> dist; // distancia
vector<bool> cor; // cor
vector<int> pai; // pai
vector<vector<string>> verificarpeso;

bool comparar(const int A, const int B){
  return dist[A] > dist[B];
}

void dijkstra(int s){
  vector<int> Q; // heap

  pai.resize(G.size(), -1);
  cor.resize(G.size(), false);
  dist.resize(G.size(), INT_MAX);
  verificarpeso.resize(G.size());
  Q.push_back(s);
  dist[s] = 0;
  cor[s] = true;

  while(!Q.empty()){ // DFS/heap
    int u = Q[0];
    pop_heap(Q.begin(), Q.end(), comparar);
    Q.pop_back();

    for(int i = 0; i < G[u].size(); i++){

      if(dist[u] + G[u][i].p.w < dist[G[u][i].i] && verificarpeso[G[u][i].i][i][0] != G[u][i].p.txt[0]){
        dist[G[u][i].i] = dist[u] + G[u][i].p.w;
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
  int M, N;
  string X, Y, start, end, p;
  while(cin >> N){
    if(N == 0){
      break;
    }
    int cnt = 1;
    map<string, int> L;
    map<string, int>::iterator itr;
    M = N;
    G.resize(10000);
    cin >> start >> end;
    L[start] = cnt;
    cnt++;
    L[end] = cnt;
    cnt++;
    for(int i = 0; i < M; i++){
      cin >> X >> Y >> p;
      itr = L.find(X);
      if(itr == L.end()){
        L[X] = cnt;
        cnt++;
      }
      itr = L.find(Y);
      if(itr == L.end()){
        L[Y] = cnt;
        cnt++;
      }
      peso w;
      w.w = p.size();
      w.txt = p;
      if(i == 0){
        G[L[X]].push_back(Vertice(L[Y], w));
        G[L[Y]].push_back(Vertice(L[X], w));
        verificarpeso[G[L[X]][L[Y]].p.txt].push_back(G[L[Y]][L[Y]].p.txt);
        G[L[Y]].push_back(Vertice(L[X], w));
      }
      else{
        for(int i = 0; i < G[L[X]].size(); i++){
          cout << "a" << endl;
          if(G[L[X]][i].p.txt[0] != w.txt[0]){
            G[L[X]].push_back(Vertice(L[Y], w));
          }
        }
        for(int i = 0; i < G[L[Y]].size(); i++){
          cout << "b" << endl;
          if(G[L[Y]][i].p.txt[0] != w.txt[0]){
            G[L[Y]].push_back(Vertice(L[X], w));
          }
        }
      }
      // if(G[L[X]].size() == 0){
      //   G[L[X]].push_back(Vertice(L[Y], w));
      // }
      // else if(G[L[Y]].size() == 0){
      //   G[L[Y]].push_back(Vertice(L[X], w));
      // }
      // else{
      //   for(int i = 0; i < G[L[X]].size(); i++){
      //     cout << G[L[X]][i].i << endl;
      //   }
      // }

    }
    dijkstra(L[start]);
    if(dist[L[end]] == INT_MAX){
      cout << "impossivel" << endl;
    }
    else{
      cout << dist[L[end]] << endl;
    }
    G.clear();
    cor.clear();
    dist.clear();
    pai.clear();
    L.clear();
  }
}