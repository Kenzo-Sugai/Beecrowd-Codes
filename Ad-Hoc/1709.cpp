#include <iostream>
#include <vector>

using namespace std;

int main(){

  int P;
  cin >> P;
  vector<int> baralho;
  vector<int> baralho_original;
  for(int i = 1; i <= P; i++){
    baralho.push_back(i);
  }
  for(int j = 0; j < baralho.size(); j++){
    cout << baralho[j] << " ";
  }
  cout << endl;
  baralho_original = baralho;
  for(int cnt = 1; true; cnt++){
    vector<int> P1;
    vector<int> P2;
    int i = 0;
    for(; i < P/2; i++){
      P1.push_back(baralho[i]);
      //cout << baralho[i] << " ";
    }
    //cout << endl;
    for(; i < P; i++){
      //cout << baralho[i] << " ";
      P2.push_back(baralho[i]);
    }
    //cout << endl;
    baralho.clear();
    for(int j = 0; j < baralho_original.size()/2; j++){
      baralho.push_back(P2[j]);
      baralho.push_back(P1[j]);
    }
    for(int j = 0; j < baralho.size(); j++){
      cout << baralho[j] << " ";
    }
    cout << endl;
    if(baralho_original[0] == baralho[0]){
      cout << cnt << endl;
      return 0;
    }
  }
}