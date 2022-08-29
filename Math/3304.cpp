#include <iostream>
#include <string>

using namespace std;

bool luck(string N){
  bool verify = false;
  for(int i = 0; i < N.size(); i++){
    if(N[i] == '4' || N[i] == '7'){
    }
    else{
      verify = true;
      break;
    }
  }
  return verify;
}

int main(){

  string S;
  while(cin >> S){
    bool verify = false;
    bool V = luck(S);
    if(V == true){
      int s = stoi(S);
      for(int i = 4; i < s; i++){
        string t = string(i, 1);
        bool V = luck(t);
        if(V == true){
          if(s%i == 0){
            verify = true;
            break;
          }
        }
      }
      if(verify == true){
        cout << "quase sortudo" << endl;
      }
      else{
        cout << "azarado" << endl;
      }
    }
    else{
      cout << "sortudo" << endl;
    }
  }
}