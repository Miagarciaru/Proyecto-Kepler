// Störmer–Verlet Method
#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;
const int N = 2; // Dos dimensiones
const double h = 0.00055;
const double e = 0.6;

// Declaración de funciones
double f (double t, double q[N], int ii);
void SV (double t, double h, double (&q)[N], double (&p)[N]);

int main ()
{
  double H, L, t;
  double q[N] = {1.0-e, 0};
  double p[N] = {0, std::sqrt((1.0+e)/(1.0-e))};
  for (t = 0; t <= 20.0*PI; t += h) {
    H = (1.0/2.0)*(p[0]*p[0] + p[1]*p[1]) - 1.0/std::sqrt(q[0]*q[0] + q[1]*q[1]);
    L = (q[0]*p[1]) - (q[1]*p[0]);
    std::cout << t << "\t" << q[0] << "\t" << q[1] << "\t" << H << "\t" << L << std:: endl;
    SV(t, h, q, p);
  } 
  return 0;
}

double f (double t, double q[N], int ii)
{
  return -q[ii] / std::pow(q[0]*q[0] + q[1]*q[1], 3.0/2.0);   
}

// Método Störmer–Verlet 
void SV (double t, double h, double (&q)[N], double (&p)[N])
{
  double pm[N];
  int ii;
  for (ii = 0; ii < N; ++ii) {
    pm[ii] = p[ii] + (h/2.0)*f(t, q, ii);
    q[ii] = q[ii] + h*pm[ii];
  }
  for (ii = 0; ii < N; ++ii) {
    p[ii] = pm[ii] + (h/2.0)*f(t, q, ii);
  }
}
