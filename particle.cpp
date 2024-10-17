#include "particle.hpp"

#include "particle_type.hpp"
#include "resonance_type.hpp"

#include <stdexcept>

const int* Particle::findParticle(char name) {
  int* index = nullptr;

  for (int i = 0; i < n_particle_type_; ++i) {
    if (particle_type_[i]->get_name() == name) {
      *index = i;
      continue;
    }
  }

  return index;
}

void Particle::addParticleType(char name, double mass, int charge,
                               double width = 0) {
  if (findParticle(name)) { return; }

  if (n_particle_type_ < max_n_particle_type_) {
    if (width) {
      particle_type_[n_particle_type_] =
          new ResonanceType(name, mass, charge, width);
    } else {
      particle_type_[n_particle_type_] = new ParticleType(name, mass, charge);
    }
    ++n_particle_type_;
  } else {
    throw std::runtime_error("Array is full, cannot add more particle types.");
  }
}

Particle::Particle(char name, double px = 0, double py = 0, double pz = 0)
    : px_(px)
    , py_(py)
    , pz_(pz) {
  const int* index = findParticle(name);
  if (!index) {
    throw std::runtime_error(
        "Particle name not found, unable to create Particle.");
  }
  index_ = *index;
}