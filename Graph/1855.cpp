#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
  vector< vector<int> > G;
  int x, y, npush, t = 0, k = 0, m;
  bool confirm = false;
  string n;
  cin >> x >> y;
  G.resize(x*y*x);
  //cout <<endl << "--- DEBUG ---" << endl;
  for(int i = 0; i < y; i++){
    cin >> n;
    for(int j = 0; j < x; j++){
      npush = int(n[j]);
      G[i].push_back(npush);
      //cout << "Adicionado " << n[j] << " (" << npush << ") " << "na posição: " << i << " - " << j << endl;
    }
  }

  queue<int> Q;
  vector< vector<int> > cor(x*y*x);
  for(int a = 0; a < y; a++){
    for(int b = 0; b < x; b++){
      cor[a].push_back(false);
    }
  }
  Q.push(G[0][0]);
  while(!Q.empty()){
    int u = Q.front();
    //cout << "u: " << u << endl;
    Q.pop();
    if(cor[t][k] == false){
      if(k >= x || t < 0 || t >= y || k < 0){
        cout << "!" << endl;
        break;
        //confirm = true;
        break;
      }
      if(u == 42){
        cout << "*" << endl;
        break;
      }
      if(u == 62){
        for(int g = 0; g < x; g++){
          cor[t][k] = true;
          k++;
          if(k >= x || k < 0|| t >= y || t < 0){
            cout << "!" << endl;
            break;
            //confirm = true;
            continue;
          }
          m = G[t][k];
          //cout << m << "t: " << t << " k: " << k << endl;
          if(m != 46){
            Q.push(m);
            break;
          }
        }
      }
      if(u == 60){
        for(int g = 0; g < x; g++){
          cor[t][k] = true;
          k--;
          if(k >= x || k < 0|| t >= y || t < 0){
            cout << "!" << endl;
            break;
            //confirm = true;
            continue;
          }
          m = G[t][k];
          if(m != 46){
            Q.push(m);
            break;
          }
        }
      }
      if(u == 94){
        for(int g = 0; g < y; g++){
          cor[t][k] = true;
          t--;
          if(k >= x || k < 0|| t >= y || t < 0){
            cout << "!" << endl;
            break;
            //confirm = true;
            continue;
          }
          m = G[t][k];
          if(m != 46){
            Q.push(m);
            break;
          }
        }
      }
      if(u == 118){
        for(int g = 0; g < y; g++){
          //cout <<"ANTES: "<< t << " " <<  k << endl;
          //cout << m << " t: " << t << " k: " << k << endl;
          cor[t][k] = true;
          t++;
          //cout <<"DEPOIS: "<< t << " " <<  k << endl;
          if(k >= x || k < 0 || t >= y || t < 0){
            cout << "!" << endl;
            break;
            //confirm = true;
            continue;
          }
          m = G[t][k];
          //cout << m << " t: " << t << " k: " << k << endl;
          //cout << m << endl;
          if(m != 46){
            Q.push(m);
            break;
          }
        }
      }
      if(confirm == true){
        //cout << "confirm true" << endl;
        cout << "!" << endl;
        break;
      }
    }
    else{
      //cout << "color true" << endl;
      cout << "!" << endl;
      break;
    }
  }
} 
