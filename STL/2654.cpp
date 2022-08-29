#include <iostream>
#include <algorithm>

using namespace std;

struct candidate{
  string name;
  int power;
  int godkill;
  int death;
};

bool win(candidate A, candidate B){
  if(A.power > B.power){
    return A.power > B.power;
  }
  else{
    if(A.godkill > B.godkill){
      return A.godkill > B.godkill;
    }
    else{
      if(A.death > B.death){
        return A.death > B.death;
      } 
      else{
        return A.name.size() < A.name.size();
      }
    }
  }
}

int main(){

  int N;
  scanf("%d", &N);
  candidate pessoas[N];
  for(int i = 0; i < N; i++){
    cin >> pessoas[i].name;
    scanf("%d %d %d", &pessoas[i].power, &pessoas[i].godkill, &pessoas[i].death);
  }

  sort(pessoas, pessoas + N, win);

  cout << pessoas[0].name << endl;
}