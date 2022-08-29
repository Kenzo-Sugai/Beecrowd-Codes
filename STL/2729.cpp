#include <iostream>
#include <set>

using namespace std;

int main(){
  int N;
  string lista;
  cin >> N;

  for(int j = 0; j < N+1; j++){
    set<string> S;
    set<string>::iterator itr;
    getline(cin, lista);
    if(lista[0] != '\n'){
      string aux = "";
      for(int i = 0; i < lista.size(); i++){
        if(lista[i] != ' '){
          aux += lista[i];
        }
        else{
          S.insert(aux);
          aux = "";
        }
      }
      int i = 0;
      for(itr = S.begin(); itr != S.end(); itr++, i++){
        if(i == 0)
          cout << *itr;
        else
          cout << " " << *itr;
      }
      cout << endl;
    }
  }
}