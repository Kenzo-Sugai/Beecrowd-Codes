#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
  int N, n = 1, j = 0;
  //cout << "Digite a quantidade de vagões:" << endl;
  cin >> N;
  while(true){
  stack<int> org;
  stack<int> B;
  vector<int> wagons;
  vector<int> wagons_sort;
    if(n == 0){
      //cout << "Digite a quantidade de vagões:" << endl;
      scanf("%d", &N);
      if( N == 0){
        break;
      }
      if(N == 1){
        cout << "Yes" << endl << endl;
      }
    }
    for(int i = 0; i < N; i++){
      //cout << "Vagão número " << i+1 << endl;
      scanf("%d", &n);
      wagons.push_back(n);
      wagons_sort.push_back(i+1);
      if(n == 0){
        wagons.clear();
        cout << endl;
        break;
      }
    }
    for(int i = 0; i < N; i++){
      if(wagons[N-i-1] == wagons_sort[N-j-1]){
        //cout << wagons[N-i-1] << " Foi para o lado B" << endl;
        B.push(wagons[N-i-1]);
        j++;
      }
      else{
        if(!org.empty() && org.top() == wagons_sort[N-j-1]){
          //cout << org.top() << " Foi para o lado B" << endl;
          B.push(org.top());
          org.pop();
          j++;
          i--;
        }
        else{
          if(!org.empty() && org.top() > wagons[N-i-1]){
            break;
          }
          else{
            //cout << wagons[N-i-1] << " Foi para a estação" << endl;;
            org.push(wagons[N-i-1]);
          }
        }
      }
    }
    while(!org.empty()){
      if(org.top() == wagons_sort[N-j-1]){
        B.push(org.top());
          org.pop();
          j++;
      }
      else{
        break;
      }
    }
    if(B.size() == N && n != 0){
      printf("Yes\n");
    }
    if(B.size() != N && n != 0){
      printf("No\n");
    }
    /*while(!org.empty()) org.pop();
    while(!B.empty()) B.pop();
    wagons.clear();
    wagons_sort.clear();*/
    j = 0;
  }
} 
