#ifndef RESONANCE_TYPE_HPP
#define RESONANCE_TYPE_HPP

#include "particle_type.hpp"

class ResonanceType : public ParticleType {
 public:
  double get_width() const;

  void print() const;

  ResonanceType(char name, double mass, int charge, double width);

 private:
  const double width_;
};

inline double ResonanceType::get_width() const { return width_; }

#endif