#include <cstdlib>
#include "SDES.hpp"
#include "SDES.cpp"
#include<bits/stdc++.h>
using namespace std;

int main(){
    int opcao;
    int plaintext;
    int ciphertext;
    int key;
    while(true){
        cout << "Para criptografar, insira 1:\nPara descriptografar, insira 2:\nPara sair, insira 3:\n";
        cin >> opcao;
        if(opcao == 1){
            while(true){
                cout << "Insira o plaintext(valores entre 0 e 255):";
                cin >> plaintext;
                if(plaintext >= 0 && plaintext <= 255)
                    break;
            }
            while(true){
                cout <<"Insira a key(valores entre 0 e 1023):";;
                cin >> key;
                if(key >= 0 && key <= 1023)
                    break;
            }
            system("clear");
            cout << "Texto Encriptografado: " << Encryption(plaintext, key) << "\n";
            cout << "Chave: " << key << "\n";
            cout << "===========================================================\n";
        }else if(opcao == 2){
            while(true){
                cout << "Insira o ciphertext(valores entre 0 e 255):";
                cin >> ciphertext;
                if(ciphertext >= 0 && plaintext <= 255)
                    break;
            }
            while(true){
                cout <<"Insira a key(valores entre 0 e 1023):";
                cin >> key;
                if(key >= 0 && key <= 1023)
                    break;
            }
            system("clear");
            cout << "Texto Descriptografado: " << Decryption(ciphertext, key) << "\n";
            cout << "Chave: " << key << "\n";
            cout << "===========================================================\n";

        }else if(opcao == 3){
            cout << "===========================================================\n";
            break;
        }else{
            cout << "Insira um valor válido.\n";
            cout << "===========================================================\n";
        }
    }
    return 0;
}
