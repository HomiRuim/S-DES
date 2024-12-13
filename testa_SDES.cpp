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
}
