#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int X, Y, l = 0, c = 0, npush, ctr = 0, pos = 0;
  string n;
  
  vector < vector <int> > G;

  G.resize(1024*1024);

  cin >> Y >> X;

  for(int i = 0; i < Y; i++){
    cin >> n;
    //cout << "LINHA: " << n << endl;
    for(int j = 0; j < n.size(); j++){
      npush = int(n[j]);
      //cout << "Recebido " << npush << " na posição " << i << " " << j << endl;
      G[i].push_back(npush);
    }
  }

  queue<int> Q;
  queue<int> L;
  queue<int> C;

  vector< vector<int> > cor(1024*1024);
  for(int a = 0; a < Y; a++){
    for(int b = 0; b < X; b++){
      cor[a].push_back(false);
    }
  }
  
  for(int l = 0; l < Y; l++){
    for(int c = 0; c < X; c++){
      //cout << "G: " << G[l][c] << " l: " << l << " c: " << c << endl;
      if(cor[l][c] == false && G[l][c] == 46){
        //cout << "--- NEW ENTRY ---" << endl;
        Q.push(G[l][c]);
        L.push(l);
        C.push(c);
        cor[l][c] = true;
        while(!Q.empty()){
          int u = Q.front();
          int l = L.front();
          int c = C.front();
          //cout << "u: " << u << endl;
          //cout << "l: " << l << endl;
          //cout << "c: " << c << endl;
          Q.pop();
          C.pop();
          L.pop();
          if(l-1 >= 0 && l-1 < Y && c >= 0 && c < X && G[l-1][c] == 46 && cor[l-1][c] == false){
            //cout << "entrou" << endl;
            cor[l-1][c] = true;
            Q.push(G[l-1][c]);
            L.push(l-1);
            C.push(c);
          }
          if(l+1 >= 0 && l+1 < Y && c >= 0 && c < X && G[l+1][c] == 46 && cor[l+1][c] == false){
            cor[l+1][c] = true;
            Q.push(G[l+1][c]);
            L.push(l+1);
            C.push(c);
          }
          if(l >= 0 && l < Y && c-1 >= 0 && c-1 < X && G[l][c-1] == 46 && cor[l][c-1] == false){
            //cout << "entrou" << endl;
            cor[l][c-1] = true;
            Q.push(G[l][c-1]);
            L.push(l);
            C.push(c-1);
          }
          if(l >= 0 && l < Y && c+1 >= 0 && c+1 < X && G[l][c+1] == 46 && cor[l][c+1] == false){
            cor[l][c+1] = true;
            Q.push(G[l][c+1]);
            L.push(l);
            C.push(c+1);
          }
        }
        ctr++;
        //cout << "contador = " << ctr << endl;
      }
    }
  }
  cout << ctr << endl;
} 
