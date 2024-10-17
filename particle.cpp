#include "particle.hpp"

#include "particle_type.hpp"
#include "resonance_type.hpp"

#include <iostream>
#include <stdexcept>

std::array<ParticleType*, Particle::max_n_particle_type_>
    Particle::particle_types_  = {nullptr, nullptr, nullptr, nullptr,
                                  nullptr, nullptr, nullptr};
int Particle::n_particle_type_ = 0;

int Particle::findParticle(char name) {
  int index = -1;
  for (int i = 0; i < n_particle_type_; ++i) {
    if (particle_types_[i]->get_name() == name) {
      index = i;
      continue;
    }
  }

  return index;
}

void Particle::addParticleType(char name, double mass, int charge,
                               double width) {
  if (n_particle_type_ >= max_n_particle_type_) {
    throw std::runtime_error("Array is full, cannot add more particle types.");
  }

  if (findParticle(name) != -1) {
    std::cout << "This name already belongs to another particle.\n";
    return;
  }

  ParticleType* new_particle_type;

  if (width) {
    new_particle_type = new ResonanceType(name, mass, charge, width);
  } else {
    new_particle_type = new ParticleType(name, mass, charge);
  }

  for (int i = 0; i < max_n_particle_type_; ++i) {
    if (new_particle_type == particle_types_[i]) {
      std::cout << "Cannot add the same particle with different names.";
      return;
    }
  }

  particle_types_[n_particle_type_] = new_particle_type;
  ++n_particle_type_;
}

Particle::Particle(char name, double px, double py, double pz)
    : px_(px)
    , py_(py)
    , pz_(pz) {
  const int index = findParticle(name);

  if (index == -1) {
    throw std::runtime_error(
        "Particle name not found, unable to create Particle.");
  }

  index_ = index;
}

void Particle::printParticleTypes() {
  for (int i = 0; i < n_particle_type_; ++i) { particle_types_[i]->print(); }
}

void Particle::printParticle() const {
  std::cout << '[' << index_ << "] Particle "
            << particle_types_[index_]->get_name() << "   Momentum = (" << px_
            << ", " << py_ << ", " << pz_ << ")\n";
}