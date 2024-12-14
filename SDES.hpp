#include<bits/stdc++.h>
using namespace std;

int Decryption(int cyphertext, int key);

int Encryption(int plaintext, int key);

int EP(int right);

int FK(int right, int left, int subkey);

int IP(int plaintext);

int IP_1(int plaintext);

pair<int, int> KeyScheduling(int key);

int left_side_10bits(int key);

int left_side_8bits(int key);

int LS_1(int half_key);

int LS_2(int half_key);

int merge_sides10bits(int left, int right);

int merge_sides4bits(int left, int right);

int merge_sides8bits(int left, int right);

int P10(int key);

int P4(int right);

int P8(int key);

int permutation(vector<int> ordem, int text);

int right_side_10bits(int key);

int right_side_8bits(int key);

int S_BOX0(int resultxor);

int S_BOX1(int resultxor);

int SW(int right, int left);

int XOR(int resultEP, int K);

