#include <iostream>
#include <vector>
#include <string>

using namespace std;

string derivada(string n){
  string aux1 = "", aux2 = "";
  bool x = false;
  for(int i = 0; i < n.size(); i++){
    if(n[i] != 'x' && x == false){
      aux1 += n[i];
    }
    else if(n[i] != 'x' && x == true){
      aux2 += n[i];
    }
    else{
      x = true;
    }
  }
  int a1 = stoi(aux1)*stoi(aux2), a2 = stoi(aux2)-1;
  if(a2 == 1)
    return to_string(a1)+'x';
  else if(a2 == 0)
    return to_string(a1);
  else   
    return to_string(a1)+'x'+to_string(a2);
}

int main(){
  int der;
  string func, oper;
  while(cin >> der){

    vector<string> function;

    for(int i = 0; i < der; i++){
      cin >> func;
      func = derivada(func);
      function.push_back(func);
      if(i != der-1){
        cin >> oper;
        function.push_back(oper);
      }
    }
    for(int i = 0; i < function.size(); i++){
      cout << function[i];
      if(i != function.size()-1)
        cout << " ";
    }
    cout << endl;
  }
}