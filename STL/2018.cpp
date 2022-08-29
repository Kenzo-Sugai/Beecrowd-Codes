#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct medalhas{
  int ouro;
  int prata;
  int bronze;
};

struct placar{
  string pais;
  medalhas m;
};

bool compare(placar A, placar B){
  if(A.m.ouro == B.m.ouro){
    if(A.m.prata == B.m.prata){
      if(A.m.bronze == B.m.bronze){
        return A.pais < B.pais;
      }
      else{
        return A.m.bronze > B.m.bronze;
      }
    }
    else{
      return A.m.prata > B.m.prata;
    }
  }
  else{
    return A.m.ouro > B.m.ouro;
  }

}

map<string, medalhas> pais;
map<string, medalhas>::iterator it;
vector<placar> resultado;
int t {0};
string modalidade, p;

int main(){

  while(getline(cin, modalidade)){
    // t++;
    // if(t == 6){
    //   break;
    // }
    if(cin.peek() == '\n'){
      cin.ignore();
    }
    for(int i = 0; i < 3; i++){
      getline(cin, p);
      if(cin.peek() == '\n'){
        cin.ignore();
      }
      if(pais.find(p) == pais.end()){
        pais[p] = {0, 0, 0};
      }
      switch(i){
        case 0: pais[p].ouro++; break;
        case 1: pais[p].prata++; break;
        case 2: pais[p].bronze++; break;
      }
    }
    if(cin.peek() == '\n'){
      cin.ignore();
    }
  }
  for(it = pais.begin(); it != pais.end(); ++it){
    resultado.push_back({it->first, it->second});
  }
  sort(resultado.begin(), resultado.end(), compare);
  cout << "Quadro de Medalhas" << endl;
  for(int i = 0; i < resultado.size(); i++){
    cout << resultado[i].pais << " " 
    << resultado[i].m.ouro << " " 
    << resultado[i].m.prata << " " 
    << resultado[i].m.bronze << endl;
  }
}