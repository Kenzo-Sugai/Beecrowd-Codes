#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(void){

  int V, A, ida = 0, volta = 0, ctr = 0;

  map<string, int> vertex;
  map<string, int>::iterator itr;
  vector < vector <int> > G;

  G.resize(4000);

  cin >> V >> A;

  for(int i = 0; i < A; i++){
    string v1, v2;
    cin >> v1;
    if(v1 == "Entrada"){
      v1 = ">";
    }
    if(v1 == "Saida"){
      v1 = "<";
    }

    itr = vertex.find(v1);
    if(itr != vertex.end()){
      //cout << "Vértice " << v1 << " já existente com o valor " << vertex[v1] << endl;
    }
    else{
      //cout << "Colocando " << v1 << " com o valor " << ctr << endl;
      vertex.emplace(v1, ctr);
      ctr++;
    }

    cin >> v2;
    if(v2 == "Entrada"){
      v2 = ">";
    }
    if(v2 == "Saida"){
      v2 = "<";
    }

    itr = vertex.find(v2);
    if(itr != vertex.end()){
      //cout << "Vértice " << v2 << " já existente com o valor " << vertex[v2] << endl;
    }
    else{
      //cout << "Colocando " << v2 << " com o valor " << ctr << endl;
      vertex.emplace(v2, ctr);
      ctr++;
    }

    G[vertex[v1]].push_back(vertex[v2]);
    G[vertex[v2]].push_back(vertex[v1]);

  }

  queue<int> Q;
  Q.push(vertex[">"]);

  vector<int> dist(4000, -1);
  vector<int> pai(4000, -1);
  vector<bool> cor(4000, false);

  dist[vertex[">"]] = 0;
  cor[vertex[">"]] = true;

  while(!Q.empty()){
    int u = Q.front();
    //cout << u << endl;
    //cout << "G[u] - " << G[u].size() << endl;
    Q.pop();
    for(int i = 0; i < G[u].size(); i++){
      //cout << "G UI" << G[u][i] << endl;
      if(!cor[G[u][i]]){
        dist[G[u][i]] = dist[u] + 1;
        pai[G[u][i]] = u;
        cor[G[u][i]] = true;
        Q.push(G[u][i]);
      }
    }
  }
  
  ida = dist[vertex["*"]];

  queue<int> Q2;
  Q.push(vertex["*"]);

  vector<int> d(4000, -1);
  vector<int> p(4000, -1);
  vector<bool> c(4000, false);

  d[vertex["*"]] = 0;
  c[vertex["*"]] = true;

  while(!Q.empty()){
    int u = Q.front();
    //cout << u << endl;
    //cout << "G[u] - " << G[u].size() << endl;
    Q.pop();
    for(int i = 0; i < G[u].size(); i++){
      //cout << "G UI" << G[u][i] << endl;
      if(!c[G[u][i]]){
        d[G[u][i]] = d[u] + 1;
        p[G[u][i]] = u;
        c[G[u][i]] = true;
        Q.push(G[u][i]);
      }
    }
  }
  
  volta = d[vertex["<"]];

  cout << ida+volta << endl;
}
