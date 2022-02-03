#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

int main() {
  string start, end;
  int line, column, line_end, column_end, i = 0;

  while(cin >> start >> end){ 
    line = int(start[1])-48;
    column = int(start[0])-96;
    line_end = int(end[1])-48;
    column_end = int(end[0])-96;
    int pos = column*10 + line;
    int pos_end = column_end*10 + line_end;

    //cout << "Start: " << pos << endl;
    //cout << "End: " << pos_end << endl;

    if(pos == pos_end){
      cout << "To get from " << start << " to " << end << " takes 0 knight moves." << endl;
      break; 
    }

    queue<int> Q;
    Q.push(pos);

    vector<int> d(88*88, -1);
    vector<int> p(88*88, -1);
    vector<bool> cor(88*88, false);
    d[pos] = 0;
    cor[pos] = true;
    while(!Q.empty()){
        int u = Q.front();
        //cout << "u: " << u << endl;
        Q.pop();  
          if(cor[u] == true){
            if(u+12 <= 88 && u+12 >= 11 && cor[u+12] == false && (u+12) % 10 != 0 && (u+12) % 10 != 9){
              //cout << "IF 1: " << u+12 << endl;
              d[u+12] = d[u] +1;
              p[u+12] = u;
              cor[u+12] = true;
              Q.push(u+12);
              if(u+12 == pos_end){
                cout << "To get from " << start << " to " << end << " takes " << d[pos_end] << " knight moves." << endl;
                break;
              }
            }
            if(u+21 <= 88 && u+21 >= 11 && cor[u+21] == false && (u+21) % 10 != 0 && (u+21) % 10 != 9){
              //cout << "IF 2: " << u+21 << endl;
              d[u+21] = d[u] +1;
              p[u+21] = u;
              cor[u+21] = true;
              Q.push(u+21);
              if(u+21 == pos_end){
                cout << "To get from " << start << " to " << end << " takes " << d[pos_end] << " knight moves." << endl;
                break;
              }
            }
            if(u+19 <= 88 && u+19 >= 11 && cor[u+19] == false && (u+19) % 10 != 0 && (u+19) % 10 != 9){
              //cout << "IF 3: " << u+19 << endl;
              d[u+19] = d[u] +1;
              p[u+19] = u;
              cor[u+19] = true;
              Q.push(u+19);
              if(u+19 == pos_end){
                cout << "To get from " << start << " to " << end << " takes " << d[pos_end] << " knight moves." << endl;
                break;
              }
            }
            if(u+8 <= 88 && u+8 >= 11 && cor[u+8] == false && (u+8) % 10 != 0 && (u+8) % 10 != 9){
              //cout << "IF 4: " << u+8 << endl;
              d[u+8] = d[u] +1;
              p[u+8] = u;
              cor[u+8] = true;
              Q.push(u+8);
              if(u+8 == pos_end){
                cout << "To get from " << start << " to " << end << " takes " << d[pos_end] << " knight moves." << endl;
                break;
              }
            }
            if(u-12 <= 88 && u-12 >= 11 && cor[u-12] == false && (u-12) % 10 != 0 && (u-12) % 10 != 9){
              //cout << "IF 5: " << u-12 << endl;    
              d[u-12] = d[u] +1;
              p[u-12] = u;
              cor[u-12] = true;
              Q.push(u-12);
              if(u-12 == pos_end){
                cout << "To get from " << start << " to " << end << " takes " << d[pos_end] << " knight moves." << endl;
                break;
              }
            }
            if(u-21 <= 88 && u-21 >= 11 && cor[u-21] == false && (u-21) % 10 != 0 && (u-21) % 10 != 9){
              //cout << "IF 6: " << u+21 << endl;
              d[u-21] = d[u] +1;
              p[u-21] = u;
              cor[u-21] = true;
              Q.push(u-21);
              if(u-21 == pos_end){
                cout << "To get from " << start << " to " << end << " takes " << d[pos_end] << " knight moves." << endl;
                break;
              }
            }
            if(u-19 <=  88 && u-19 >= 11 && cor[u-19] == false && (u-19) % 10 != 0 && (u-19) % 10 != 9){
              //cout << "IF 7: " << u-19 << endl;
              d[u-19] = d[u] +1;
              p[u-19] = u;
              cor[u-19] = true;
              Q.push(u-19);
              if(u-19 == pos_end){
                cout << "To get from " << start << " to " << end << " takes " << d[pos_end] << " knight moves." << endl;
                break;
              }
            }
            if(u-8 <= 88 && u-8 >= 11 && cor[u-8] == false && (u-8) % 10 != 0 && (u-8) % 10 != 9){
              //cout << "IF 8: " << u-8 << endl;
              d[u-8] = d[u] +1;
              p[u-8] = u;
              cor[u-8] = true;
              Q.push(u-8);
              if(u-8 == pos_end){
                cout << "To get from " << start << " to " << end << " takes " << d[pos_end] << " knight moves." << endl;
                break;
              }
            }
          }
        }
  }
}
