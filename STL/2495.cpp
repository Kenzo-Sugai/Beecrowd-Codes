#include <iostream>
#include <set>

using namespace std;

int main(){
  int N, n;
  while(cin >> N){
    set<int> S;
    set<int>::iterator itr;
    for(int i = 0; i < N-1; i++){
      cin >> n;
      S.insert(n);
    }
    int i = 1;
    bool limit = false;
    for(itr = S.begin(); itr != S.end(); itr++, i++){
      if(*itr != i){
        cout << i << endl;
        limit = true;
        break;
      }
    }
    if(limit == false){
      cout << N << endl;
    }
  }
}