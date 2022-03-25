#include <iostream>
#include <set>
#include <vector>
#include <stdio.h>


using namespace std;

int main() {
  int N, min, max, num, start, end, value = 0;
  multiset<int> lotes;
  multiset<int>::iterator itr;
  vector<int> aee;
  while(cin >> N){

    for(int i = 0; i < N; i++){
      cin >> min >> max;
      for(int j = min; j <= max; j++){
        lotes.insert(j);
      }
    }
    cin >> num;
    for(itr=lotes.begin(); itr!=lotes.end(); ++itr){
      aee.push_back(*itr);
    }
    for(int k = 0; k < aee.size(); k++){
      if(aee[k] == num && value == 0){
        start = k;
        value = 1;
      }
      if(aee[k] == num && value == 1){
        end = k;
      }
    }
    if(value == 0){
      printf("%d not found\n", num);
    }
    else{
      printf("%d found from %d to %d\n", num, start, end);
    }
    aee.clear();
    lotes.clear();
    value = 0;
  }
} 
