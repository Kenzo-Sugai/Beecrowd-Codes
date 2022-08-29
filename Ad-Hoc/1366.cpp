#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, C, V;

  while(cin >> N){
    if(!N) break;
    vector<int> var;
    int ret {0}, cnt {0};
    for(int i = 0; i < N; i++){
      cin >> C >> V;
      if(V != 1){
        if(V % 2 != 0) V--;
        var.push_back(V);
      }
    }

    while(true){
      bool check = false;
      int index;
      for(int i = 0; i < var.size(); i++){
        if(var[i] >= 2 && check == false){
          index = i;
          check = true;
        }
        else if(var[i] >= 2 && check == true){
          var[i] -= 2;
          var[index] -= 2;
          check = false;
          cnt++;
        }
      }
      if(check == true){
        if(var[index] >= 6){
          var[index] -= 6;
        }
        else{
          break;
        }
      }
      if(check == false){
        break;
      }
    }
    cout << cnt << endl;
  }
}