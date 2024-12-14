#include<bits/stdc++.h>
using namespace std;

int P10(int key);

int left_side10bits(int key);

int right_side10bits(int key);

int left_side8bits(int key);

int right_side8bits(int key);

int LS_1(int half_key);

int LS_2(int half_key);

int merge_sides10bits(int left, int right);

int P8(int key);

pair<int,int> KeyScheduling(int key);

int IP(int plaintext);

int EP(int right);

int XOR(int resultEP, int K);

int S_BOX0(int resultxor);

int S_BOX1(int resultxor);

int P4(int left, int right);

int SW(int right, int left);

int merge_sides8bits(int left, int right);

int FK(int left, int right, int subkey);

int IPminus(int textocifrado);

int Encryption(int plaintext, int key);
