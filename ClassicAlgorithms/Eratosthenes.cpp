#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;


vector<size_t> eratosthenes(const size_t n) {
    bool arr[n+1] = {0};

    for (size_t i = 2; i < sqrt(n); i++) {
        if(!arr[i]) {
            for (size_t j = i*2; j < n; j += i) {
                arr[j] = true;
            }
        }
    }
    arr[0] = true;
    arr[1] = true;


    vector<size_t> v;
    for (size_t i = 0; i < n; i++) {
        if (!arr[i]) {
            v.push_back(i);
        }
    }

    return v;
}


// using erathostenes to check if a number is a square

// std::vector<size_t> getPrimeDivs(size_t x) {
//     vector<size_t> divisors;
//     vector<size_t> primes = eratosthenes(x);
//     for(size_t i = 0; primes[i] <= x; i++) {
//         size_t d = primes[i];
//         while (x%d == 0) {
//             x = x/d;
//             divisors.push_back(d);
//         }
//     }
//     return divisors;
// }

// bool checkSquare(size_t x) {
//     std::vector<size_t> divisors = getPrimeDivs(x);
//     bool even = false;
//     for (size_t i = 0; i < divisors.size()-1; i++) {
//         size_t count = 0;
//         for(size_t j = i; divisors[i] == divisors[j]; j++) {
//             count++;
//             i = j;
//         }
//         if(count%2 == 1) {
//             return false;
//         }

//     }

//     return true;
// }




// int main() {


//     vector<size_t> v = eratosthenes(50);
//     for (const size_t x : v) {
//         cout << x << " ";
//     }


//     return 0;
// }
