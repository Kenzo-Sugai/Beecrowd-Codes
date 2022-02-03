#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {

  // Sumário:
  // T = Número de casos
  // X = Número vértices
  // A = Número de arestas
  // N-linhas = (n1 - n2) = Vértices que se ligam por arestas

  int T, X, A, start, cont = 0;

  cin >> T;

  while(T--){
    cin >> start;
    cin >> X >> A;
    vector<vector<int>> G;
    set<int> arestas;
    set<int>::iterator itr;
    G.resize(X);
    for(int i = 0; i < A; i++){
      int n1, n2;
      cin >> n1 >> n2;
      G[n1].push_back(n2);
      G[n2].push_back(n1);
    }

    for(int i=0;i<X;i++){
      set<int> arestas;
      set<int>::iterator itr;
      //cout<<i<<" - ";
      for(int u = 0;u<G[i].size();u++){
          arestas.insert(G[i][u]);
      }
      for(itr = arestas.begin(); itr != arestas.end(); ++itr){
        //cout << *itr << " ";
        cont++;
      }
      //cout<<endl;
    }

    cout << cont << endl;
    cont = 0;
  }
}
