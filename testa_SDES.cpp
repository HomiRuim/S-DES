// Copyright 2024 <Erick Taira, Davi Bueno>
#include "SDES.hpp"
#include<bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testa SDES", "[single-file]" ) {
	int teste0 = 642;
	CHECK(P10(teste0) == 524 );

	CHECK(left_side(teste0) == 20);

	CHECK(right_side(teste0) == 2);
}
