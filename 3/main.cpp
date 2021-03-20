#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <numeric>
#include "Utility.h"
#include "Car.h"

int main() {

	auto cars = randomCars();
	std::cout << "Cars: " << cars << "\n";

	// TODO: print the average price and price range
	std::vector<Car> car = cars;
	std::vector<double> carprice;

	for (Car element : car) {
		carprice.push_back(element.price());
	}

	double average = (std::accumulate(std::begin(carprice), std::end(carprice), 0)) / carprice.size();

	std::cout << "The average price is: $" << average << "\n";

	double priceRange = *std::max_element(std::begin(carprice), std::end(carprice)) - *std::min_element(std::begin(carprice), std::end(carprice));

	std::cout << "The range is: $" << priceRange << "\n";
}