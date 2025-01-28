#include "particle.hpp"
#include <algorithm>
#include <iostream>

// C'tor
Particle::Particle(double x, double y, double z, double vx, double vy, double vz) 
	: x(x), y(y), z(z), vx(vx), vy(vy), vz(vz) {}

// Update particle position based on dt
void Particle::update(double dt) {

	x += vx * dt;
	y += vy * dt;
	z += vz * dt;

}

Box::Box(double sizeX, double sizeY, double sizeZ) 
	: sizeX(sizeX), sizeY(sizeY), sizeZ(sizeZ) {}

void Box::handleCollision(Particle& particle) {
	// Check boundry for each axis of particle, if there is a colousion then reverse the velocity
	// and keep the particle inside the bounds for this time, in the next iteration in the simulator
	// the update method will be called, so the location will be updated in the right direction

	// Check X boundries
	if (particle.x < 0 || particle.x > sizeX) {
		particle.vx  *= -1; // Reverse Velcity
		particle.x = std::clamp(particle.x, 0.0, sizeX);
	}

	// Check Y boundries
	if (particle.y < 0 || particle.y >sizeY) {
		particle.vy *= -1;
		particle.y = std::clamp(particle.y, 0.0, sizeY);

	}

	// check Z boundries
	if (particle.z < 0 || particle.z > sizeZ) {
		particle.vz *= -1;
		particle.z = std::clamp(particle.z, 0.0, sizeZ);

	}
}

void simulate(std::vector<Particle>& particles, Box& box, double dt, int steps) {
	// Run each particle with update and handle collusion methods
	for (int step = 0; step < steps; ++step)
	{
		for (auto& particle : particles)
		{
			particle.update(dt);
			box.handleCollision(particle);
		}
	}
}


