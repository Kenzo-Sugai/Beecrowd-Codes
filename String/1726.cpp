#include <iostream>
#include <vector>

using namespace std;

vector<string> num;
// ({ABC}+{CDE})*{CEZ}

vector<string> parenteses(string express){
  vector<string> ret;
  string aux {""};
  bool sequence = false;
  for(int i = 0; i < express.size(); i++){
    if(express[i] == ')'){
      sequence = false;
    }
    if(sequence == true){
      aux += express[i];
    }
    if(express[i] == '('){
      sequence = true;
    }

  }
}

vector<string> parsing(string express){
  vector<string> ret;
  string aux {""};
  bool sequence = false;
  for(int i = 0; i < express.size(); i++){
    if(express[i] == '+' || express[i] == '-' || express[i] == '*'){
      aux += express[i];
      ret.push_back(aux);
      aux = "";
    }
    if(express[i] == '}'){
      sequence = false;
      ret.push_back(aux);
      aux = "";
    }
    if(sequence == true){
      aux += express[i];
    }
    if(express[i] == '{'){
      sequence = true;
    }
  }
  return ret;
}

int main(){
  string expressao;
  while(cin >> expressao){
    num = parsing(expressao);

    for(int i = 0; i < num.size(); i++){
      cout << num[i] << endl;
    }
  }

}