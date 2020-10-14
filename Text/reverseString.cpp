#include <iostream>
#include <string>

void reverseString(std::string& str) {
	if (str.empty()) {
		return;
	}
	
	long left = 0;
	long right = str.size() - 1;
	char tmp;

	while (right - left > 0) {
		tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;

		left++;
		right--;
	}
	
	for (const char x : str) {
		std::cout << x;
	}
}
