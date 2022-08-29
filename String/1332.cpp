#include <iostream>

using namespace std;

int main(){

  int N;
  string word;

  cin >> N;

  while(N--){

    cin >> word;

    if(word.size() > 3){
      cout << 3 << endl;
    }
    else{
      char one_word[3] = {'o', 'n', 'e'}, two_word[3] = {'t', 'w', 'o'};
      int one {0}, two {0};
      for(int i = 0; i < word.size(); i++){
        if(word[i] == one_word[i]){
          one++;
        }
        if(word[i] == two_word[i]){
          two++;
        }
      }
      if(one > two){
        cout << 1 << endl;
      }
      else{
        cout << 2 << endl;
      }
    }
  }
}