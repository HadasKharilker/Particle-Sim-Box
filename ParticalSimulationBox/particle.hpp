// particle.hpp
#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <vector>

struct Particle {

	double x, y, z; // Position
	double vx, vy, vz; // Velocity

	Particle(double x, double y, double z, double vx, double vy, double vz);

	void update(double dt);


};

class Box {
public:
	// Size of the Box
	double sizeX, sizeY, sizeZ;

	Box(double sizeX, double sizeY, double sizeZ);

	void handleCollision(Particle& particle);

};

void simulate(std::vector<Particle>& particles, Box& box, double dt, int steps);

#endif //# PARTICLE_HPP
