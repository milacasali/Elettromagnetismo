#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "particle_type.hpp"
#include "resonance_type.hpp"

#include <array>

class Particle {
 public:
  int  get_index() const;
  void set_index(char name);

  static void addParticleType(char name, double mass, int charge,
                              double width = 0);

  Particle(char name, double px = 0, double py = 0, double pz = 0);

 private:
  static std::array<ParticleType*, 7> particle_type_;
  static const int                    max_n_particle_type_ = 7;
  static int                          n_particle_type_;

  int index_;

  const double px_;
  const double py_;
  const double pz_;

  static const int* findParticle(char name);
  // puntatore perché può restituire un valore nullo se il nome non esiste
};

#endif