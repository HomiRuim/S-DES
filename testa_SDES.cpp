// Copyright 2024 <Erick Taira, Davi Bueno>
#include "SDES.hpp"
#include<bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testa SDES", "[single-file]" ) {
	int teste0 = 642;
	REQUIRE(P10(teste0) == 524 );

}
