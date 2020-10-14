#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <vector>

bool creditCardValidator(std::string cardNumber) {
	if (cardNumber.size() < 13 || cardNumber.size() > 19) {
		return false;
	}

	std::vector<int> number;

	for (char x : cardNumber) {
		number.push_back((int)x - 48);
	}	

	int sum = 0;
	int flag = 0;

	for (size_t i = number.size() - 1; i > 0; i--) {
		flag++;
		if (!(flag % 2)) {
			number[i] *= 2;
		}
		if (number[i] > 9) {
			number[i] -= 9;
		}
		sum += number[i];
	}

	flag++;

	if (!(flag % 2)) {
		number[0] *= 2;
	}

	if (number[0] > 9) {
		number[0] -= 9;
	}

	sum += number[0];

	if (sum % 10) {
		return false;
	}


	return true;
}

TEST_CASE("Card validation") {
	CHECK(creditCardValidator("4556568491029316"));
	CHECK(creditCardValidator("4916456293726666"));
	CHECK(creditCardValidator("4036892459658717680"));
	CHECK(creditCardValidator("5103070111911978"));
	CHECK(creditCardValidator("5535302018908528"));
	CHECK(creditCardValidator("5554053038007660"));
	CHECK(creditCardValidator("376097410872743"));
	CHECK(creditCardValidator("348858301621555"));
	CHECK(creditCardValidator("343054122218723"));
	CHECK(creditCardValidator("6011649593556929"));
	CHECK(creditCardValidator("6011791209498888"));
	CHECK(creditCardValidator("6011604759779861790"));
	CHECK(creditCardValidator("3544652811240857"));
	CHECK(creditCardValidator("3529862783669426"));
	CHECK(creditCardValidator("3539629033676572874"));
	CHECK(creditCardValidator("5498764283272234"));
	CHECK(creditCardValidator("5436823390117701"));
	CHECK(creditCardValidator("5460271138231732"));
	CHECK(creditCardValidator("5038818189837974"));
	CHECK(creditCardValidator("6304086139076714"));
	CHECK(creditCardValidator("6763232077796335"));
	CHECK(creditCardValidator("4175009538858087"));
	CHECK(creditCardValidator("4913882214459041"));
	CHECK(creditCardValidator("4175009181768658"));
	CHECK(creditCardValidator("30254130182360"));
	CHECK(creditCardValidator("30165989170233"));
	CHECK(creditCardValidator("30541464611208"));
	CHECK(creditCardValidator("6377476745772511"));
	CHECK(creditCardValidator("6372675305792802"));
}




