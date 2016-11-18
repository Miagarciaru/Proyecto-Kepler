// Implicit Midpoint Method
#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

// Declaración de funciones
double f1 (double q1, double q2);
double f2 (double q1, double q2);
void Midpoint (double t, double h, double & q1, double & q2, double & p1, double & p2);

int main ()
{
  const double h = 0.0005;
  const double e = 0.6;
  double q1, q2, p1, p2, H, L, t;
  q1 = 1.0-e;
  p1 = 0;
  q2 = 0;
  p2 = std::sqrt((1.0+e)/(1.0-e));
  for (t = 0; t <= 20.0*PI; t += h) {
    H = (1.0/2.0)*(p1*p1 + p2*p2) - 1.0/std::sqrt(q1*q1 + q2*q2);
    L = (q1*p2) - (q2*p1);
    std::cout << t << "\t" << q1 << "\t" << q2 << "\t" << H << "\t" << L << std:: endl;
    Midpoint(t, h, q1, q2, p1, p2);
  } 
  return 0;
}

double f1 (double t, double q1, double q2)
{
  return -q1 / std::pow((q1*q1)+(q2*q2), 3.0/2.0);   
}

double f2 (double t, double q1, double q2)
{
  return -q2 / std::pow((q1*q1)+(q2*q2), 3.0/2.0);
}

// Método implícito del punto medio 
void Midpoint (double t, double h, double & q1, double & q2, double & p1, double & p2)
{
  double q10, q20, q1m, q2m;
  q10 = q1;
  q20 = q2;
  q1 = q1 + h*p1;
  q2 = q2 + h*p2;
  q1m = (q10+q1)/2.0;
  q2m = (q20+q2)/2.0;
  p1 = p1 + h*f1(t + h/2, q1m, q2m);
  p2 = p2 + h*f2(t + h/2, q1m, q2m);
}
