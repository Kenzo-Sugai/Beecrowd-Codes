#include <iostream>
#include <algorithm>

using namespace std;

struct churras{
  string carne;
  int valor;
};

bool sorted(churras A, churras B){
  return A.valor < B.valor;
}

int main(){
  int N, V;
  string C;
  while(cin >> N){
    churras carnes[N];
    for(int i = 0; i < N; i++){
      cin >> C >> V;
      carnes[i] = {C, V};
    }
    sort(carnes, carnes + N, sorted);
    
    for(int i = 0; i < N; i++){
      if(i != N-1)
        cout << carnes[i].carne << " ";
      else
        cout << carnes[i].carne;
    }
    cout << endl;
  }
}