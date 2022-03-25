#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int main() {
  int N, V, A, vertex1, vertex2, t = 1, count = 0;
  string v1, v2;
  //cout << "Números de casos: " << endl;
  cin >> N;

  while(N--){
    vector < vector <int> > G;
    //cout << "Digite o número de vértices e arestas: " << endl;
    cin >> V >> A;
    G.resize(130);
    vector<bool> cor(V+97, false);

    for(int j = 0; j < A; j++){
      //cout << "Valor v1 e v2 - A: " << j+1 << endl;
      cin >> v1 >> v2;
      vertex1 = int(v1[0]);
      vertex2 = int(v2[0]);

      G[vertex1].push_back(vertex2);
      G[vertex2].push_back(vertex1);
    }

    /*
    for(int i = 97 ; i < V+97; i++){
      cout << string(1, i) << " -";
      for(int u = 0; u < G[i].size(); u++){
          cout << " " << string(1, G[i][u]);
      }
      cout << endl;
    }
    */

    cout << "Case #" << t << ":" << endl;
    t++;
    int p = 0;
    for(int j = 97; j < V+97; j++){
      p++;
      set<int> sorted;
      set<int>::iterator itr;
      if(cor[j] == false){
        queue<int> Q;
        Q.push(j);

        vector<int> d(V+97, 0);
        vector<int> p(V+97, 0);

        d[j] = 0;
        cor[j] = true;
        while(!Q.empty()){
          int u = Q.front();
          sorted.insert(u);
          Q.pop();
          for(int i = 0; i < G[u].size(); i++){
            if(!cor[G[u][i]]){
              d[G[u][i]] = d[u] +1;
              p[G[u][i]] = u;
              cor[G[u][i]] = true;
              Q.push(G[u][i]);
            }
          }
        }
        count++;
        for(itr = sorted.begin(); itr != sorted.end(); itr++){
          cout << string(1, *itr) << ",";
        }
        cout << endl;
      }
    }
    cout << count <<" connected components" << endl;
    count = 0;
    cor.clear();
    G.clear();
    cout << endl;
  }
} 
