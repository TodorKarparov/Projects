#include <iostream>
#include <vector>
#include <unordered_map>

/**
You are given an array of n integers and a number k.
Determine whether there is a pairof elements in the array that sums to exactly k.
For example, given the array [1, 3, 7] andk = 8, the answer is “yes”,
but given k = 6 the answer is “no.”
*/


//Solution with hash table; O(n) time and space:

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> solution;
    solution.push_back(-1);
    solution.push_back(-1);

    std::unordered_map<int, int> m;
    for (size_t i = 0; i < nums.size(); i++) {
        m[nums[i]] = i;
    }

    for (size_t i = 0; i < nums.size(); i++) {
        int x = target - nums[i];
        if (m.count(x) && m[x] != i) {
            solution[0] = m[x];
            solution[1] = i;

            return solution;
        }
    }

    return solution;
}


//manual testing
// int main () {

//     std::vector<int> test_input;
//     test_input.push_back(2);
//     test_input.push_back(7);
//     test_input.push_back(11);
//     test_input.push_back(15);

//     std::vector<int> test_output = twoSum(test_input, 9);
//     std::cout << test_output[0] << " " << test_output[1];

//     std::cout << std::endl;
//     return 0;
// }
