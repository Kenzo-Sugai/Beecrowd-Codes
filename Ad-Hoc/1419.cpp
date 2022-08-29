#include <iostream>

using namespace std;

int main(){
  int R, M, L, cnt, saveM, Mtotal = 0, Ltotal = 0;
  while(cin >> R){
    Mtotal = 0; Ltotal = 0;
    cnt = 1;
    if(R == 0){
      break;
    }

    bool verification = false;
    for(int i = 0; i < R; i++){
      cin >> M;
      Mtotal += M;
      if(M == saveM && verification == false){
        cnt++;
        //cout << "STREAK: " << cnt << endl;
      }
      else{
        //cout << "STREAK BREAK" << endl;
        cnt = 1;
      }
      if(cnt == 3){
        verification = true;
        //cout << "STREAK COMPLETE" << endl;
        Mtotal += 30;
      }
      saveM = M;
      
    }
    verification = false;
    for(int i = 0; i < R; i++){
      cin >> M;
      Ltotal += M;
      if(M == saveM && verification == false){
        cnt++;
        //cout << "STREAK: " << cnt << endl;
      }
      else{
        //cout << "STREAK BREAK" << endl;
        cnt = 1;
      }
      if(cnt == 3){
        verification = true;
        //cout << "STREAK COMPLETE" << endl;
        Ltotal += 30;
      }
      saveM = M;
    }
    //cout << "M: " << Mtotal << endl;
    //cout << "L: " << Ltotal << endl;
    if(Mtotal == Ltotal){
      cout << "T" << endl;
    }
    if(Mtotal > Ltotal){
      cout << "M" << endl;
    }
    if(Mtotal < Ltotal){
      cout << "L" << endl;
    }

  }
}