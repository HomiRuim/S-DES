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
	CHECK(IP(642) == 17);

	CHECK(EP(1) == 130);

	CHECK(XOR(130, 164) == 38); //xor com a EP e chave K1

	CHECK(S_BOX0(38) == 3);

	CHECK(S_BOX1(38) == 3);

	CHECK(P4(3, 3) == 15);

	CHECK(XOR(1, 15) == 14);

	CHECK(merge_sides8bits(14, 1) == 225);

	CHECK(FK(1, 1, 164) == 225);

	CHECK(SW(14, 1) == 30); // fim da fk1

	CHECK(FK(1, 14, 67) ==  14);

	CHECK(IPminus(14) == 25);

	CHECK(Encryption(642, 642) == 25);
}
