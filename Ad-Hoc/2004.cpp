#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

  int N, alim, type, p;

  cin >> N;

  while(N--){
    cin >> alim;
    map<int, int> alimentos;
    vector<int> save;
    for(int i = 0; i < alim; i++){
      cin >> type >> p;
      if(!(p >= 100)){
        if(alimentos.find(type) == alimentos.end()){
          alimentos[type] = p;
          save.push_back(type);

        }
        else{
          if(alimentos[type] < p){
            alimentos[type] = p;
          }
        }
      }
    }
    int sum = 0;
    for(int i = 0; i < save.size(); i++){
      sum += alimentos[save[i]];
    }
    cout << sum << endl;
  }
}