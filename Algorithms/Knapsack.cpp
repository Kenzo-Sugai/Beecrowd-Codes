#include <iostream>
#include <vector>

using namespace std;

struct conteudo {

    int valor;
    int peso;
};

int tam;
vector<conteudo> mochila;

int Knapsack(int i, int tamanho){
    if(tamanho == 0 or i == 0) return 0;

    if(mochila[i - 1].peso > tamanho)
        return Knapsack(i - 1, tamanho);
    else {
        int item = mochila[i - 1].valor + Knapsack(i - 1,(tamanho - mochila[i - 1].peso));
        int no_item = Knapsack(i - 1, tamanho);

        return max(item, no_item);
    }

}

int main(){

    int N, t, w, sum = 0;
    double v;

    while(cin >> N){
        if(!N) return 0;

        mochila.clear();

        cin >> tam;

        for(int i = 0; i < N; i++){
            cin >> t >> w;
            mochila.push_back({t, w});
        }

        cout << Knapsack(N, tam) << endl;

    }

}
