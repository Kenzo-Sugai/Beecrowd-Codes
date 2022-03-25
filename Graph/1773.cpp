#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define BRANCO 0 // não passou
#define CINZA 1 // possibilidade de passar
#define PRETO 2 // ja passou
#define CHAVE 3 // pode passar

using namespace std;

int main() {
  int V, A, a, b, k;
  while(cin >> V >> A){
    bool verify = false;
    vector<vector <int> > G;
    vector<vector <int> > chaves;

    G.resize(V+1);
    chaves.resize(V+1);

    for(int i = 0; i < A; i++){
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    for(int j = 2; j < V+1; j++){
      // j = chave | k = sala
      cin >> k;
      chaves[k].push_back(j);
    }
    /*
    for(int i=1;i<=V;i++){
      cout<<i<<" -";
      for(int u = 0;u<G[i].size();u++){
          cout<<" "<<G[i][u];
      }
      cout<<endl;

    }

    for(int i=1;i<=V;i++){
      cout<<i<<" -";
      for(int u = 0;u<chaves[i].size();u++){
          cout<<" "<<chaves[i][u];
      }
      cout<<endl;

    }
    */
    queue<int> Q;
    vector<int> cor(V+1, 0);
    Q.push(1);
    cor[1] = CINZA;
    while(!Q.empty()){
      int u = Q.front();
      //cout << "u: " << u << endl;
      cor[u] = PRETO;
      Q.pop();
      for(int i = 0; i < G[u].size(); i++){
        if(cor[G[u][i]] == CHAVE){
          Q.push(G[u][i]);
        }
        if(cor[G[u][i]] != PRETO && cor[G[u][i]] != CHAVE){
          cor[G[u][i]] = CINZA;
        }
      }
      //cout << "cor[" << 2 << "] = " << cor[2] << endl;
      for(int i = 0; i < chaves[u].size(); i++){
        if(cor[chaves[u][i]] == CINZA){
          Q.push(chaves[u][i]);
        }
        else{
          cor[chaves[u][i]] = CHAVE;
        }
      }
    }
    for(int i = 1; i < cor.size(); i++){
      //cout << "cor[" << i << "] = " << cor[i] << endl;
      if(cor[i] != PRETO){
        verify = true;
        cout << "nao" << endl;
        break;
      }
    }
    if(verify == false){
      cout << "sim" << endl;
    }
  }
} 
