#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include "Koerper.hh"
#include <iostream>
#include <fstream>
#include <memory>

std::ofstream fout("Tabelle.txt");

const int N = 10000;     // Anzahl Integrationspunkte


double traegheit(Koerper *k, Vektor a, Vektor u) {
  double J_b = 0;     // Massentraegheitsmoment
  double m = k->M() / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = k->punkt();
    Vektor d = x - a;
    // Abstand Punkt x und Gerade a + t*u
    Vektor n = d.kreuz(u);
    // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = n.betrag()/u.betrag();
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J_b += m * r * r;
  }
  if (k->name() == "Vollzylinder") {
    J_b = 0.5*J_b;
  }
 fout << k->J_a() << "        |" << J_b << "       |";
}


double tabelle(double ZM_R, double ZM_L, double M, Vektor a, Vektor u) {
  fout << ZM_R <<"m   |" << ZM_L << "m   |" << M << "kg    |" << a << "  |" << u << "  |";
    std::unique_ptr<Koerper> k(new Zylindermantel(ZM_R,ZM_L,M)); traegheit(k.get(),a,u);
    std::unique_ptr<Koerper> l(new Vollzylinder(ZM_R,ZM_L,M)); traegheit(l.get(),a,u);
  fout << "\n";
}

int main() {
fout << "R    |L    |M      |a        |u        |Jzm_a    |Jzm_b        |Jvz_a    |Jvz_b" << std::endl;
Vektor a= (0,0,0);
Vektor u = (0,0,1);
  tabelle(1,1,1,a,u);    
  tabelle(1,1,2,a,u);
  tabelle(2,1,1,a,u);

Vektor a_ = (0,1,0);
tabelle(1,1,1,a_,u);
tabelle(1,1,2,a_,u);

Vektor a__=(0,2,0);
tabelle(2,1,1,a__,u);


  return 0;
}
