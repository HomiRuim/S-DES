// Copyright 2024 <Erick Taira, Davi Bueno>
#include "SDES.hpp"
#include <bits/stdc++.h>
using namespace std;

int P10(int key){
	vector<int> ordem = {7, 5, 8, 3, 6, 0, 9, 1, 2, 4};
	int permuted_key = 0;
	for (int i = 0; i < 10; i++) {
		int verifica_bit = (key >> ordem[i]) & 1;
		permuted_key |=  (verifica_bit << (9 - i));
	}
	return permuted_key;
}

int P8(int key){
	vector<int> ordem = {4, 7, 3, 6, 2, 5, 0, 1};
	int permuted_key = 0;
	for (int i = 0; i < 8; i++) {
		int verifica_bit = (key >> ordem[i]) & 1;
		permuted_key |=  (verifica_bit << (7 - i));
	}
	return permuted_key;
}

int left_side(int permuted_key){
	return (permuted_key & 992) >> 5;
}

int right_side(int permuted_key){
	return permuted_key & 31;
}

int LS_1(int some_side){
	return (some_side & 16) >> 4 | ((some_side << 1) & 31);
}

int LS_2(int some_side){
	return (some_side & 24) >> 3 | ((some_side << 2) & 31);
}

int merge_sides(int left, int right){
	return (left << 5) | right;
}

pair<int, int> KeyScheduling(int key){
	int K1, K2;
	int permuted_key = P10(key);
	int parte_esquerda = LS_1(left_side(permuted_key));
	int parte_direita = LS_1(right_side(permuted_key));
	K1 = P8(merge_sides(parte_esquerda, parte_direita));
	K2 = P8(merge_sides(LS_2(parte_esquerda), LS_2(parte_direita)));
	return make_pair(K1, K2);
}

// fim da criação da chaves
// inicio da criptografia

int IP(int plaintext) {
    vector<int> ordem = {1, 5, 2, 0, 3, 7, 4, 6};
    int permuted = 0;
    for (int i = 0; i < 8; i++) {
        int bit = (plaintext >> (7 - ordem[i])) & 1;
        permuted |= (bit << (7 - i));
    }
	int resultIP = permuted;
    return resultIP;
}

int EP(int right) {
    vector<int> ordem = {3, 0, 1, 2, 1, 2, 3, 0};
    int expanded = 0;
    for (int i = 0; i < 8; i++) {
        int bit = (right >> (3 - ordem[i])) & 1;
        expanded |= (bit << (7 - i));
    }
    return expanded;
}

int XOR(int resultEP, int K) {
	int x = resultEP ^ K;
	return x;
}