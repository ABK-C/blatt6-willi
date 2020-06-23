#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

int main() {
  const int N = 10000;     // Anzahl Integrationspunkte
  const double M = 2;      // Masse des Zylindermantels
  const double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Auflagepunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  std::unique_ptr<Vollzylinder> zm(new Vollzylinder(ZM_R, ZM_L));

  double J = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = zm->punkt();
    Vektor d = x - a;
    // Abstand Punkt x und Gerade a + t*u
    Vektor n = d.kreuz(u);
    // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = n.betrag()/u.betrag();
    std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;
            
  return 0;
}
