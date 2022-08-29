#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int t;
  string pack, n;
  while(cin >> t){
    vector<string> TCP;
    while(true){
      cin >> pack;
      if(pack == "0"){
        break;
      }
      cin >> n;
      TCP.push_back(n);
    }

    sort(TCP.begin(), TCP.end());

    for(int i = 0; i < TCP.size(); i++){
      cout << "Package " << TCP[i] << endl;
    }
    cout << endl;
  }
}