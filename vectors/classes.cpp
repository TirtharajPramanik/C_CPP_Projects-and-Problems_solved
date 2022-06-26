#include <iostream>

class Vector{
  public:
	  Vector(int s) :elem{new double[s]}, sz{s} {}
	  double& operator[](int i) {return elem[i];}
	  int size() {return sz;}
  private:
	  double* elem;
	  int sz;
};

double read_and_sum(int s) {
  Vector v(s);
  double sum = 0;
  for (int i = 0; i < v.size(); i++) {
    std::cout << "Enter a Double:	";
    std::cin >> v[i];
    sum += v[i];
  }
  return sum;
}

int main() {
  double sum = read_and_sum(5);
  std::cout << "Total Sum is:	" << sum << std::endl;
  return 0;
}
