#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  string arv;
  int total, T;
  string b;
  cin >> T;
  while(T--){
    map<string, int> A;
    vector<string> db;
    map<string, int>::iterator itr;
    total = 0;
    cin >> b;
    while(getline(cin, arv)){
    itr = A.find(arv);
    // if(arv == "00"){
    //   break;
    // }
    if (itr == A.end()){
      db.push_back(arv);
    }
    A[arv]++;
    total++;
    }
    sort(db.begin(), db.end());
    for(int i = 0; i < db.size(); i++){
      if(i == 0){
        for(int j = 1 ; j < db[0].size(); j++){
          cout << db[0][j];
        }
      }
      else{
        cout << db[i];
      }
      printf(" %.4lf\n", (double)(A[db[i]]*100)/total);
    }
  }
}