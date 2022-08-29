#include <iostream>
#include <vector>

using namespace std;

int main(){
  int P, L, C;
  cin >> P >> L >> C;
  vector<string> palavras;
  string Matrix[L][C];
  string p;

  for(int i = 0; i < P; i++){
    cin >> p;
    palavras.push_back(p);
  }
  string linha;
  for(int i = 0; i < L; i++){
    cin >> linha;
    for(int j = 0; j < C; j++){
      Matrix[i][j] = linha[j];
    }
  }
  cout << endl;
  int t = 0, aux;
  for(int i = 0; i < L; i++){
    aux = t;
    for(int j = C-1; t >= 0; j--){
      //cout << t << " " << j << endl;
      cout << Matrix[t][j];
      t--;
    }
    t = aux + 1;   
    cout << endl;
  }
  t = C-1;
  for(int i = 0; i < C; i++){
    aux = t;
    for(int j = C-2; t > 0; j--){
      //cout << t << " " << j << endl;
      cout << Matrix[t][j];
      t--;
    }
    t = aux - 1;   
    cout << endl;
  }
}