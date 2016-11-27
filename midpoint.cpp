// Implicit Midpoint Method
#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;
const int N = 2; // Dos dimensiones
const double h = 0.0005;
const double e = 0.6;

// Declaración de funciones
double f (double t, double q[N], int ii);
void Midpoint (double t, double h, double (&q)[N], double (&p)[N]);

int main ()
{
  double H, L, t;
  double q[N] = {1.0-e, 0};
  double p[N] = {0, std::sqrt((1.0+e)/(1.0-e))};
  for (t = 0; t <= 20.0*PI; t += h) {
    H = (1.0/2.0)*(p[0]*p[0] + p[1]*p[1]) - 1.0/std::sqrt(q[0]*q[0] + q[1]*q[1]);
    L = (q[0]*p[1]) - (q[1]*p[0]);
    std::cout << t << "\t" << q[0] << "\t" << q[1] << "\t" << H << "\t" << L << std:: endl;
    Midpoint(t, h, q, p);
  } 
  return 0;
}

double f (double t, double q[N], int ii)
{
  return -q[ii] / std::pow(q[0]*q[0] + q[1]*q[1], 3.0/2.0);   
}

// Método implícito del punto medio 
void Midpoint (double t, double h, double (&q)[N], double (&p)[N])
{
  double qt[N], qm[N];
  int ii;
  for (ii = 0; ii < N; ++ii) {
    qt[ii] = q[ii] + h*(p[ii] + (h/2.0)*f(t, q, ii));
    qm[ii] = (q[ii]+qt[ii])/2.0;
  }
  for (ii = 0; ii < N; ++ii) {
    q[ii] = qt[ii];
  }
  for (ii = 0; ii < N; ++ii) {
    p[ii] = p[ii] + h*f(t + h/2.0, qm, ii);
  }
}
