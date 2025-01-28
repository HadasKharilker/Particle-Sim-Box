//main.cpp
#include "particle.hpp"
#include <random>
#include <iostream>


int main() {
	// Define box size
	double boxSizeX = 10.0, boxSizeY = 10.0, boxSizeZ = 10.0;
	// Create Box
	Box box(boxSizeX, boxSizeY, boxSizeZ);

	// Create particles
	std::vector<Particle> particles;
	std::random_device rd; //  Creates a random_device object used for generating random numbers.
	
	std::mt19937 gen(rd()); // : Creates a random number generator object (mt19937), 
							//initialized with the seed from the random_device object created earlier.
	
	std::uniform_real_distribution<> disPos(1.0, 9.0); //Creates a uniform real number distribution that generates random values between 1.0 and 9.0, 
														//used for determining the position of the particles.
	
	std::uniform_real_distribution<> disVel(-1.0, 1.0); //Creates a uniform real number distribution that generates random values between -1.0 and 1.0, 
														//used for determining the velocity of the particles.

	for (int i = 0; i < 10; ++i) {
		particles.emplace_back(disPos(gen), disPos(gen), disPos(gen), disVel(gen), disVel(gen), disVel(gen));
	//emplace_back is a function in std::vector (and other STL containers) that allows you to add a new element to the vector directly, 
	//without creating a temporary object and copying it.
	}

	// Simulate particles
	double dt = 0.01; //Time step
	int steps = 1000; // Number of steps
	simulate(particles, box, dt, steps);

	// Print final positions of particles
	for (auto& particle : particles) {
		std::cout << "Particle at (" << particle.x << "," << particle.y << ',' << particle.z << ")" <<std::endl;

	}

	return 0;
}
