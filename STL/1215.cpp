#include <iostream>
#include <queue>
#include <string>
#include <set>

using namespace std;

int main(){
  
  queue<string> Q;
  set<string> S;
  string word;

  while(cin >> word){
    string aux = "";
    for(int i = 0; i < word.size(); i++){
      if((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122)){
        aux += word[i];
      }
      else{
        if(aux != ""){
          for(int i = 0; i < aux.size(); i++)
            aux[i] = char(::tolower(aux[i]));
          S.insert(aux);
        }
        aux = "";
      }
    }
  } 
  for(set<string>::iterator itr = S.begin(); itr != S.end(); ++itr)
    cout << *itr << endl;
}