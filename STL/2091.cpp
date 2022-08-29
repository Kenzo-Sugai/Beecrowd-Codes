#include <iostream>
#include <map>

using namespace std;
map<int, int> lista;
map<int, int>::iterator it;
int N, n;
int main(){
  while(cin >> N){
    if(N == 0)
      break;
    for(int i = 0; i < N; i++){

      cin >> n;
      it = lista.find(n);
      if(it != lista.end())
        lista.erase(n);
      else
        lista.emplace(n, 1);

    }
    for(it = lista.begin(); it != lista.end(); ++it){
      cout << it->first << endl;
    }
  lista.clear();
  }
}