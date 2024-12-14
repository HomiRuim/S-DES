// Copyright 2024 <Erick Taira, Davi Bueno>
#include "SDES.hpp"
#include<bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testa SDES", "[single-file]" ) {
	// 642 == 1010000010
	CHECK(P10(642) == 524 );

	CHECK(left_side10bits(642) == 20);

	CHECK(right_side10bits(642) == 2);

	CHECK(LS_1(16) == 1);

	CHECK(LS_2(16) == 2);

	CHECK(merge_sides10bits(20, 2) == 642);

	CHECK(P8(56) == 164);

	CHECK(P8(131) == 67);

	CHECK(KeyScheduling(642).first == 164);

	CHECK(KeyScheduling(642).second == 67);
	// teste de criptografia começa aqui
	CHECK(IP(215) == 221);

	CHECK(EP(13) == 235);

	CHECK(XOR(235, 164) == 79);

	CHECK(S_BOX0(4) == 3);

	CHECK(S_BOX1(15) == 3);

	CHECK(P4(15) == 15);

	CHECK(XOR(13, 15) == 2);

	CHECK(merge_sides8bits(2, 13) == 45);

	CHECK(FK(13, 13, 164) == 45);

	CHECK(SW(2, 13) == 210);

	CHECK(FK(13, 2, 67) == 50);

	CHECK(IP_1(50) == 168);

	CHECK(Encryption(215, 642) == 168);

	CHECK(Decryption(168, 642) == 215);
}
