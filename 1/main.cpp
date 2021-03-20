#include <iostream>
	#include <random>
	#include <algorithm>
	#include <string>
	#include "Utility.h"
	#include "Car.h"
	
	int main() {
	    auto cars = randomCars();
	    std::cout << "Initial: " << cars << "\n";
	
	    // TODO: print out the cars in reverse order
	    std::vector<Car> reverse = cars;
	    std::reverse(std::begin(reverse), std::end(reverse));
	    std::cout << "Reversed: " << reverse << "\n";
	}