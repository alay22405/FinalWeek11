#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
#include <string>
#include "Utility.h"
#include "Car.h"

std::vector<int> createElevationMap();

int main() {
    auto range = createElevationMap();
    std::cout << "Elevation Map: " << range << "\n";

    // I would love to see the solution for this Trapping Rain water, because I tried many times to find my mistakes but I couldn't get it. 
    int trap(std::vector <int> &height) {

        int n = height.size();

        int sum = 0;
        int left = 0;
        int right = 0;

        for (int i = 1; i < n - 1; i++)
        {
            left = height[i];
            for (int j = 0; j < i; j++)
            {
                left = min(left, height[j]);
            }
            right = height[i];

            for (int j = i + 1; j < n; j++)
            {

                right = max(right, height[j]);
            }
            sum = sum + (min(left, right) - height[i]);
        }
        return sum;
    }

};

std::vector<int> createElevationMap() {
    // generate elevation data
    std::mt19937 generator{ std::random_device{}() };
    std::exponential_distribution<> elevationDist{ 0.5 };
    auto elevationCreator = [&generator, &elevationDist]() {
        return static_cast<int>(elevationDist(generator));
    };
    auto elevationMap = randomVectorOfObjects<int, decltype(elevationCreator)>(elevationCreator);

    // ensure there is only one highest peak
    auto firstMaxPeakIt = std::max_element(elevationMap.begin(), elevationMap.end());
    *firstMaxPeakIt += 1;

    return elevationMap;
}