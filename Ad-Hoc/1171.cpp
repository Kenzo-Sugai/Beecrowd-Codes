#include <iostream>
#include <map>

using namespace std;

int main(){
  map<int, int> num;
  int n, c;
  cin >> c;
  while(c--){
    cin >> n;
    if(num.find(n) == num.end()){
      num[n] = 1;
    }
    else{
      num[n]++;
    }
  }
  for(auto &x: num){
    cout << x.first << " aparece " << x.second << " vez(es)" << endl;
  }
}