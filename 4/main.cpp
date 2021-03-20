#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);

int main() {

	auto integers = randomIntegers();
	std::cout << "Integers: " << integers << "\n";
	std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";
}

bool isPrime(int element) {
	if (element == 0 || element == 1) {
		return false;
	}
	else {
		for (int i = 2; i < element; i++) {
			if (element % i == 0) {
				return false;
				break;
			}
		}
		return true;
	}
}

bool anyPrime(const std::vector<int>& values) {
	// TODO: return true if any of the values are prime numbers
	auto result = std::any_of(std::cbegin(values), std::cend(values), isPrime);

	return result;
}