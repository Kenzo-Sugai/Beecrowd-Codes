#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define BRANCO 0
#define CINZA 1
#define PRETO 2

using namespace std;

int V, tempo;
bool verify = false;
vector<int> cor;
vector<int> p;
vector<int> d;
vector<int> f;
vector<vector<int>> G;

void DFS_Visit(int u){
  //cout << "u: " << u << endl;
  //cout << "G[u].size(): " << G[u].size() << endl;
  if(u != 0 && d[u] != 0){
    for(int k = 0; k < d[u]; k++){
      cout << "  ";
    }
    if(p[u] != -1){
      verify = false;
      cout << p[u] << "-" << u << " pathR(G," << u << ")" << endl;
    }
  }
	cor[u] = CINZA;
	tempo = tempo+1;
	for(int i = 0; i < G[u].size(); i++){
		if(cor[G[u][i]] == BRANCO){
			p[G[u][i]] = u;
      d[G[u][i]] = d[u] +1;
			DFS_Visit(G[u][i]);
		}
    //cout << "u: " << u << " G[u][i]: " << G[u][i] << " corp[u]: " << corp[u] << endl;
    else if(cor[G[u][i]] == PRETO || cor[G[u][i]] == CINZA){
      verify = false;
      for(int k = 0; k <= d[u]; k++){
        cout << "  ";
      }
      cout << u << "-" << G[u][i] << endl;
    }
	}
	cor[u] = PRETO;
	f[u] = tempo;
	tempo++;
}

void DFS(int ini, int V){
	cor.resize(V+1);
  d.resize(V+1);
  p.resize(V+1);
  f.resize(V+1);
	for(int i = 0; i < G[i].size(); i++){
		cor[i] = BRANCO;
		d[i] = -1;
		p[i] = -1;
	}
  d[ini] = 0;
	for(int i = 0; i < V; i++){
    //cout << "cor[i]: " << cor[i] << endl;
    if(cor[i] == BRANCO){
      if((i != 0 || G[i].size() == 0) && verify == false){
        cout << endl;
        verify = true;
      }
      DFS_Visit(i);
    }
    if(cor[i] == CINZA){
      cor[i] = PRETO;
    }
  }
  cor.clear();
  d.clear();
  p.clear();
}

int main(){
  int T, V, A, a1, a2, c = 1;
  cin >> T; 
  for(int k = 0; k < T; k++){
    cin >> V >> A;
    G.resize(V+1);
    while(A--){
      cin >> a1 >> a2;
      G[a1].push_back(a2);
    }
    for(int i = 0; i < G.size(); i++){
      sort(G[i].begin(), G[i].end());
    }
    cout << "Caso " << c << ":" << endl;
    c++;
    DFS(0, V);
    if(k != T-1){
      cout << endl;
    }
    G.clear();
  }
}
