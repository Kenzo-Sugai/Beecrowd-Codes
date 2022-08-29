#include <iostream>
#include <vector>

using namespace std;

struct piece{
  int front;
  int back;
};

int main(){
  int N, p1, p2;
  bool check;
  while(cin >> N){
    vector<piece> G;
    piece masterPiece;
    for(int i = 0; i < N; i++){
      cin >> p1 >> p2;
      check = false;
      if(i == 0){
        masterPiece = {p1, p2};
        check = true;
      }
      else{
        if(masterPiece.front == p1){
          masterPiece.back = p2;
          check = true;
        }
        else if(masterPiece.front == p2){
          masterPiece.back = p1;
          check = true;
        }
        else if(masterPiece.back == p1){
          masterPiece.front = p2;
          check = true;
        }
        else if(masterPiece.back == p2){
          masterPiece.front = p1;
          check = true;
        }
      }
      if(check == false){
        G.push_back({p1, p2});
      }
    }
    for(int i = 0; i < G.size(); i++){
      if(masterPiece.front == G[i].back){
          masterPiece.back = G[i].front;
          G.erase(G.begin()+i);
          i = 0;
        }
        else if(masterPiece.front == G[i].front){
          masterPiece.back = G[i].back;
          G.erase(G.begin()+i);
          i = 0;
        }
        else if(masterPiece.back == G[i].back){
          masterPiece.front = G[i].front;
          G.erase(G.begin()+i);
          i = 0;
        }
        else if(masterPiece.back == G[i].front){
          masterPiece.front = G[i].back;
          G.erase(G.begin()+i);
          i = 0;
        }
    }
    if(G.size() > 0){
      cout << "nao" << endl;
    }
    else{
      cout << "sim" << endl;
    }
  }
}