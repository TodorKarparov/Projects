#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

size_t factorialRec(unsigned int N) {
	if (N == 0) {
		return 1;
	}


	return N * factorialRec(N-1);
}

size_t factorialIter(unsigned int N) {
	if (N == 0) {
		return 1;
	}

	size_t result = 1;

	while (N > 0) {
		result *= N;
		N--;
	}

	return result;
}


TEST_CASE("testing factorialRec") {
	CHECK(factorialRec(0) == 1);
	CHECK(factorialRec(1) == 1);
	CHECK(factorialRec(2) == 2);
	CHECK(factorialRec(5) == 120);
	CHECK(factorialRec(6) == 720);
}

TEST_CASE("testing factorialIter") {
	CHECK(factorialIter(0) == 1);
	CHECK(factorialIter(1) == 1);
	CHECK(factorialIter(2) == 2);
	CHECK(factorialIter(5) == 120);
	CHECK(factorialIter(6) == 720);
}