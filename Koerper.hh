#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"

class Koerper {
public:

  virtual Vektor punkt()=0;
  virtual std::string name() {return "Koerper";}
  virtual double M()=0;  
  virtual double J_a() = 0;
};

#endif
