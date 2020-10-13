#include <iostream> 

void fibonacciSequenceWithLength(size_t N) {
		if (N == 0) {
			return;
		}

		std::cout << 0;
		
		if (N == 1) {
			return;
		}

		std::cout << " " << 1;

		if (N == 2) {

			return;
		}

		size_t x1 = 0;
		size_t x2 = 1;
		size_t tmp;

		for (size_t i = 2; i < N; i++) {
			tmp = x2;
			x2 += x1;
			x1 = tmp;
			std::cout << " " << x2;
		} 

		std::cout << std::endl;
	}

	int main() {

		size_t N;
		std::cin >> N;

		fibonacciSequenceWithLength(N);

		return 0;
	}