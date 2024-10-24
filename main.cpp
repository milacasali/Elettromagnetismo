#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <TMath.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TH1D.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TAxis.h>
#include <TStyle.h>


#include "particle.hpp"
#include "particle_type.hpp"
#include "resonance_type.hpp"

int main()
{
    gRandom->SetSeed();
    char proton_name='proton+';
    double proton_mass=0.93827;
    int proton_charge=1;

    char pion_name='pion+';
    double pion_mass=0.13957;
    int pion_charge=1;

    char kaon_name='kato+';
    double kaon_mass=0.49367;
    int kaon_charge=1;

    char proton_name='proton-';
    double proton_mass=0.93827;
    int proton_charge=-1;

    char pion_name='pion-';
    double pion_mass=0.13957;
    int pion_charge=-1;

    char kaon_name='kato-';
    double kaon_mass=0.49367;
    int kaon_charge=-1;

    char k_name='K*';
    double k_mass=0.89166;
    int k_charge=0;
    

    addParticleType(proton_name, proton_mass, proton_charge);
    addParticleType(pion_name, pion_mass, pion_charge);
    addParticleType(kaon_name, kaon_mass, kaon_charge);
    addParticleType(k_name, k_mass, k_charge);

    int n_events=1E5;
    int n_paticles=120;
    Particle event_particles[n_particles];
    for (int i=0; i<n_events; i++)
    {
        for (int j=0; j<n_particles; j++)
        {
            ParticleType particle_type= getRandomParticleType();
            Particle particle=generate_particle(particle_type);
            event_particles[j]=particle;
        }
    }


    return 0;
}

ParticleType getRandomParticleType()
{
    int n_particle_types=particle_types.size();
    int random_index=gRandom->Integer(n_particle_types);
    ParticleType particle_type=particle_types[random_index];
    return particle_type;
}

Particle generate_particle( ParticleType particle_type)
{
    double theta=gRandom->Uniform(0, TMath::Pi());
    double phi=gRandom->Uniform(0, 2*TMath::Pi());
    double p = gRandom->Exp(1);
    double px=p*sin(theta)*cos(phi);
    double py=p*sin(theta)*sin(phi);
    double pz=p*cos(theta);
    double name=particle_type.name;
    return Particle(name, px, py, pz);
}