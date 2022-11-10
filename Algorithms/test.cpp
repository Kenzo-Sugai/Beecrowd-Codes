#include <iostream>
#include <vector>

using namespace std;

int n, value;
string type;

class FenwickTree{

  public:

    vector<int> arr;
    vector<int> BIT;

    void Create();
    void Update(int i, int v);
    int Sum(int i);
    void PrintBIT();

};

void FenwickTree::Create(){
  BIT.resize(n+1);
  for(int i = 1; i <= n; i++){
    BIT[i] = 0;
  }
  for(int i = 0; i < arr.size(); i++){
    FenwickTree::Update(i, arr[i]);
  }
}

void FenwickTree::Update(int i, int v){
  i += 1;
  for(;i <= n; i += i&(-i)){
    BIT[i] += v;
  }
}

int FenwickTree::Sum(int i){
  int sum {0};
  for(; i > 0; i -= i&(-i)){
    sum += BIT[i];
  }
  return sum;
}

void FenwickTree::PrintBIT(){
  for(int i = 1; i < BIT.size(); i++){
    cout << BIT[i] << " ";
  }
  cout << endl;
}

int main(){

    cin >> n;

    FenwickTree FT;

    for(int i = 0; i < n; i++){
        cin >> value;
        FT.arr.push_back(value);
    }

    FT.Create();

    int val;
    char t;
    while(scanf("%c %d", &t, &val) != EOF){
        if(t == 'a'){
            FT.Update(val-1, -FT.arr[val-1]);
        }
        if(t == '?'){
            cout << FT.Sum(val-1) << endl;
        }
    }
}
