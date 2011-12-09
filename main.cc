#include <iostream>
#include <cmath>


const int    N = 10000;
const double p =     0.8;


double bindist(int n, double p, int k)
{
  return
    exp(
	          lgamma(n     + 1)
	-         lgamma(n - k + 1)
	-         lgamma(    k + 1)
	+      k                    * log(      p)
	+ (n - k)                   * log(1.0 - p)
	);
}


int main(int argc, char** argv)
{
  double s = 0.0;

  for (int k = 0; k <= N; k ++)
    s += bindist(N, p, k);

  std::cout << std::fixed << s << std::endl;
}
