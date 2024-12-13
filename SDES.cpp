// Copyright 2024 <Erick Taira, Davi Bueno>
#include "SDES.hpp"
#include <bits/stdc++.h>
using namespace std;

int P10(int key){
	vector<int> ordem = {7, 5, 8, 3, 6, 0, 9, 1, 2, 4};
	int permuted_key; permuted_key = 0;
	for (int i = 0; i < 10; i++) {
		int verifica_bit = (key >> ordem[i]) & 1;
		permuted_key = permuted_key | (verifica_bit << (9 - i));
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


