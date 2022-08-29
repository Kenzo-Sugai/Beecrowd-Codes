#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){

  int N, command, x;
  

  while(cin >> N){
    int q = 0, pq = 0, s = 0, total = 0;
    queue<int> Q;
    priority_queue<int> PQ;
    stack<int> S;
    for(int i = 0; i < N; i++){
      cin >> command >> x;
      if(command == 1){
        Q.push(x); PQ.push(x); S.push(x);
      }
      if(command == 2){
        total++;
        if(Q.front() == x)
          q++;
        if(PQ.top() == x)
          pq++;
        if(S.top() == x)
          s++;
        Q.pop(); PQ.pop(); S.pop();
      }
    }
    q = (q/total)*100;
    pq = (pq/total)*100;
    s = (s/total)*100;

    if(q > pq && q > s)
      cout << "queue" << endl;
    else if(pq > q && pq > s)
      cout << "priority queue" << endl;
    else if(s > q && s > pq)
      cout << "stack" << endl;
    else{
      if((q == 0 && pq == 0 && s ==0))
        cout << "impossible" << endl;
      else
        cout << "not sure" << endl;
    }
    // cout << "Queue: " << q << "%" << endl;
    // cout << "Priority_Queue: " << pq << "%" << endl;
    // cout << "Stack: " << s << "%" << endl;
  }
}