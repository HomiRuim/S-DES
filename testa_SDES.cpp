// Copyright 2024 <Erick Taira, Davi Bueno>
#include "SDES.hpp"
#include<bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testa SDES", "[single-file]" ) {
	// 642 == 1010000010
	CHECK(P10(642) == 524 );

	CHECK(left_side(642) == 20);

	CHECK(right_side(642) == 2);

	CHECK(LS_1(16) == 1);

	CHECK(LS_2(16) == 2);

	CHECK(merge_sides(20, 2) == 642);

	CHECK(P8(56) == 164);

	CHECK(P8(131) == 67);

	CHECK(KeyScheduling(642).first == 164);

	CHECK(KeyScheduling(642).second == 67);
	// teste de criptografia começa aqui
	CHECK(IP(642) == 17);

	CHECK(EP(1) == 130);

	CHECK(XOR(130, 164) == 38); //xor com a EP e chave K1
}
