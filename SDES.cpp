// Copyright 2024 <Erick Taira, Davi Bueno>
#include "SDES.hpp"
#include <bits/stdc++.h>
using namespace std;

int permutation(vector<int> ordem, int key){
	int permuted_key = 0;
	int tamanho = ordem.size();
	for (int i = 0; i < tamanho; i++) {
		int verifica_bit = (key >> ordem[i]) & 1;
		permuted_key |=  (verifica_bit << (tamanho - 1 - i));
	}
	return permuted_key;
}

int P10(int key){
	vector<int> ordem = {7, 5, 8, 3, 6, 0, 9, 1, 2, 4};
	return permutation(ordem, key);
}

int P8(int key){
	vector<int> ordem = {4, 7, 3, 6, 2, 5, 0, 1};
	return permutation(ordem, key);
}

int P4(int merged) {
	vector<int> ordem = {2, 0, 1, 3};
	return permutation(ordem, merged);
}

int IP(int text) {
	vector<int> ordem = {6, 2, 5, 7, 4, 0, 3, 1};
	return permutation(ordem, text);
}

int IP_1(int text) {
	vector<int> ordem = {4, 7, 5, 3, 1, 6, 0, 2};
	return permutation(ordem, text);
}

int EP(int right) {
	vector<int> ordem = {0, 3, 2, 1, 2, 1, 0, 3};
	return permutation(ordem, right);
}

int left_side_10bits(int permuted_key){
	return (permuted_key & 992) >> 5;
}

int left_side_8bits(int permuted_key){
	return (permuted_key & 240) >> 4;
}

int right_side_10bits(int permuted_key){
	return permuted_key & 31;
}

int right_side_8bits(int permuted_key){
	return permuted_key & 15;
}

int LS_1(int some_side){
	return (some_side & 16) >> 4 | ((some_side << 1) & 31);
}

int LS_2(int some_side){
	return (some_side & 24) >> 3 | ((some_side << 2) & 31);
}

int merge_sides10bits(int left, int right){
	return (left << 5) | right;
}

int merge_sides8bits(int left, int right){
	return (left << 4) | right;
}

int merge_sides4bits(int left, int right){
	return (left << 2) | right;
}

pair<int, int> KeyScheduling(int key){
	int K1, K2;
	int permuted_key = P10(key);
	int parte_esquerda = LS_1(left_side_10bits(permuted_key));
	int parte_direita = LS_1(right_side_10bits(permuted_key));
	K1 = P8(merge_sides10bits(parte_esquerda, parte_direita));
	K2 = P8(merge_sides10bits(LS_2(parte_esquerda), LS_2(parte_direita)));
	return make_pair(K1, K2);
}

int XOR(int left, int right) {
	return left ^ right;
}

int S_BOX0(int resultxor) {
	vector<vector<int>> S0 = {
		{1, 0, 3, 2},
		{3, 2, 1, 0},
		{0, 2, 1, 3},
		{3, 1, 3, 2}
	};
	int linha = ((resultxor & 0b1000) >> 3) | (resultxor & 0b0001);
	int coluna = (resultxor & 0b0110) >> 1;
	return S0[linha][coluna];
}

int S_BOX1(int resultxor) {
    vector<vector<int>> S1 = {
        {0, 1, 2, 3},
        {2, 0, 1, 3},
        {3, 0, 1, 0},
        {2, 1, 0, 3}
    };
	int linha = ((resultxor & 0b1000) >> 3) | (resultxor & 0b0001);
	int coluna = (resultxor & 0b0110) >> 1;
	return S1[linha][coluna];
}

int SW(int right, int left){
	left = left << 4;
	return right | left;
}

int FK(int left, int right, int subkey){
	int extended_right = EP(right);
	extended_right = XOR(extended_right, subkey);
	int s0 = S_BOX0(left_side_8bits(extended_right));
	int s1 = S_BOX1(right_side_8bits(extended_right));
	int merged = merge_sides4bits(s0, s1);
	merged = P4(merged);
	merged = XOR(merged, left);
	return merge_sides8bits(merged, right);
}

int Encryption(int plaintext, int key){
	pair<int, int> keys = KeyScheduling(key);
	int permuted_plaintext = IP(plaintext);
	int left = left_side_8bits(permuted_plaintext);
	int right = right_side_8bits(permuted_plaintext);
	int FK_1 = FK(left, right, keys.first);
	left = right_side_8bits(FK_1);
	right = left_side_8bits(FK_1);
	int FK_2 = FK(left, right, keys.second);
	return IP_1(FK_2);
}

int Decryption(int plaintext, int key){
	pair<int, int> keys = KeyScheduling(key);
	int permuted_plaintext = IP(plaintext);
	int left = left_side_8bits(permuted_plaintext);
	int right = right_side_8bits(permuted_plaintext);
	int FK_1 = FK(left, right, keys.second);
	left = right_side_8bits(FK_1);
	right = left_side_8bits(FK_1);
	int FK_2 = FK(left, right, keys.first);
	return IP_1(FK_2);
}


