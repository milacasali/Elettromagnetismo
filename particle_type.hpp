#ifndef PARTICLE_TYPE_HPP
#define PARTICLE_TYPE_HPP

class ParticleType {
 public:
  char   get_name() const;
  double get_mass() const;
  int    get_charge() const;

  virtual void print() const;

  ParticleType(char name, double mass, int charge);

 private:
  const char   name_;
  const double mass_;
  const int    charge_;
};

inline char   ParticleType::get_name() const { return name_; }
inline double ParticleType::get_mass() const { return mass_; }
inline int    ParticleType::get_charge() const { return charge_; }

#endif