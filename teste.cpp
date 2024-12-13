#include<bits/stdc++.h>
using namespace std;

int main(){
    int key = 56;
    vector<int> ordem = {4, 1, 5, 2, 6, 3, 8, 7};
    int permuted_key = 0;
    for (int i = 0; i < 8; i++) {
        int verifica_bit = (key >> ordem[i]) & 1;
        cout << verifica_bit;
        permuted_key |=  (verifica_bit << (7 - i));
    }
    return 0;
}
