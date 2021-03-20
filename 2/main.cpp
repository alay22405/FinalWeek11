#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
	auto integers = randomIntegers();
	std::cout << "Initial: " << integers << "\n";

	// TODO: let is write to make the sequence for a bitonic sequence 
	std::vector<int> bitonicSequence = integers;

	//first half or write over/2
	int middle = bitonicSequence.size() / 2;
	std::sort(std::begin(bitonicSequence), std::end(bitonicSequence) - middle);

	//second half or write over
	std::sort(std::begin(bitonicSequence) + middle, std::end(bitonicSequence));
	std::reverse(std::begin(bitonicSequence) + middle, std::end(bitonicSequence));

	std::cout << "Bitonic: " << bitonicSequence << "\n";
}