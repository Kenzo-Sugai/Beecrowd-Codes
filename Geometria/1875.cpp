#include <iostream>

using namespace std;

int main(){
  int casos, gols;
  char marcou, sofreu;
  cin >> casos;
  while(casos--){
    int R = 0, G = 0, B = 0;
    cin >> gols;
    for(int i = 0; i < gols; i++){
      cin >> marcou >> sofreu;
      if(marcou == 'R'){
        switch(sofreu){
          case 'B':
            R+=1;
            break;
          case 'G':
            R+=2;
            break;
        }
      }
      if(marcou == 'G'){
        switch(sofreu){
          case 'R':
            G+=1;
            break;
          case 'B':
            G+=2;
            break;
        }
      }
      if(marcou == 'B'){
        switch(sofreu){
          case 'R':
            B+=2;
            break;
          case 'G':
            B+=1;
            break;
        }
      }
    }

    if(R == B && B == G){
      cout << "trempate" << endl;
    }
    else if((R == B || B == G || R == G) && B != 0 && G != 0 && R != 0){
      cout << "empate" << endl;
    }
    else{
      if(B > R && B > G){
        cout << "blue" << endl;
      }
      if(R > B && R > G){
        cout << "red" << endl;
      }
      if(G > B && G >> R){
        cout << "green" << endl;
      }
    }

  }
}