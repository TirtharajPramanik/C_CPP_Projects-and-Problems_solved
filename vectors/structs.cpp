#include <iostream>

struct Vector {
  double* elem;
  int sz;
};

void vector_init(Vector& v, int s) {
  v.sz = s;
  v.elem = new double[s];
}

double read_and_sum(int s) {
  Vector v;
  vector_init(v, s);
  double sum = 0;
  for (int i = 0; i < s; i++) {
    std::cout << "Enter a Double:	";
    std::cin >> v.elem[i];
    sum += v.elem[i];
  }
  return sum;
}

int main() {
  double sum = read_and_sum(5);
  std::cout << "Total Sum is:	" << sum << std::endl;
  return 0;
}
