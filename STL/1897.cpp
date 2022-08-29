#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
  int inicio, fim;
  cin >> inicio >> fim;

  int maior = 0;
  if(inicio > fim){
    maior = inicio;
  } else{
    maior = fim;
    }

  vector<bool> cor(10000, false);
  vector<int> distance(10000, -1);
  
  queue<int> Q;
  cor[inicio] = true;
  distance[inicio] = 0;
  Q.push(inicio);

  while(!Q.empty()){
    int u = Q.front();
    cout << "u: " << u << endl;
    Q.pop();
    if(u*2 <= 10000 && cor[u*2] == false){
      distance[u*2] = distance[u] +1;
      cor[u*2] = true;
      if(u*2 == fim){
        break;
      }
      Q.push(u*2);
    }
    if(u*3 <= 10000 && cor[u*3] == false){
      distance[u*3] = distance[u] +1;
      cor[u*3] = true;
      if(u*3 == fim){
        break;
      }
      Q.push(u*3);
    }
    if(cor[u/2] == false){
      distance[u/2] = distance[u] +1;
      cor[u/2] = true;
      if(u/2 == fim){
        break;
      }
      Q.push(u/2);
    }
    if(cor[u/3] == false){
      distance[u/3] = distance[u] +1;
      cor[u/3] = true;
      if(u/3 == fim){
        break;
      }
      Q.push(u/3);
    }
    if(u+7 <= 10000 && cor[u+7] == false){
      distance[u+7] = distance[u] +1;
      cor[u+7] = true;
      if(u+7 == fim){
        break;
      }
      Q.push(u+7);
    }
    if(u-7 >= 0 && cor[u-7] == false){
      distance[u-7] = distance[u] +1;
      cor[u-7] = true;
      if(u-7 == fim){
        break;
      }
      Q.push(u-7);
    }
  }
  cout << distance[fim] << endl;
}