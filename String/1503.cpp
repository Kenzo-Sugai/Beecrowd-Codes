#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool print_seq(vector<char> &seq){
  for(auto &x: seq){
    cout << x << " ";
  }
  cout << endl;
}

int main(){
  int n;
  string m;
  while(cin >> n){
    vector<string> msg;
    vector<char> seq;
    while(n--){
      cin >> m;
      msg.push_back(m);
    }

    sort(msg.begin(), msg.end());

    bool check = true;
    int cnt {0};
    for(int i = 0; i < msg[0].size(); i++){ // i = letra da menor frase

      if(!check) seq.clear();
      else seq.push_back(msg[0][i]);

      print_seq(seq);

      for(int j = 1; j < msg.size(); j++){ // j = indice do vector de msg
        cnt = 0;
        bool sequence = false;
        for(int k = 0; k < msg[j].size(); k++){ // k = letra de cada msg do vector

          if(msg[j][k] == seq[cnt]){
            cout << j << ": " << seq[cnt] << " -> " << k << endl;
            sequence = true;
            cnt++;
            if(cnt == seq.size()){
              break;
            }
          }
          else if(sequence == true){
            cout << "lose sequence" << endl;
            break;
          }
        }
      }
    }
  
  }
  
}