#include "Vollzylinder.hh"

#include <cmath>
#include <cstdlib>

Vollzylinder::Vollzylinder(double nr, double nl, double nm) {
  r_ = nr;
  l_ = nl;
  m_ = nm;
}

Vektor Vollzylinder::punkt() {
  double R = r_ * sqrt(rand()/(double)RAND_MAX);
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double z = l_ * (rand() / (double)RAND_MAX - 0.5);

 
  double x = r_ * cos(phi);
  double y = r_ * sin(phi);
  return Vektor(x, y, z);
};

double Vollzylinder::M() {
  return m_;
}

double Vollzylinder::J_a() {
  return 0.5 *m_*r_*r_;
}