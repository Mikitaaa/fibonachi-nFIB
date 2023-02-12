//необходимо найти остаток от деления n-го числа Фибоначчи на m


#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

class Fibonacci final {
 public:
  static int get_remainder(int64_t n, int m) {
    assert(n >= 1);
    assert(m >= 2);
      std::vector <int> per;
          per.push_back(0);
          per.push_back(1);
      int fib1=0, fib2=1, fiba=1;
      for(int i=2;i<=m*6;i++){
          fiba = (fib1%m + fib2%m)%m;
          fib1 = fib2;
          fib2 = fiba;
          per.push_back(fiba);
          if(fib1==0&&fib2==1){
              per.pop_back();
              per.pop_back();
              return per[n%per.size()];
          }
      }
      fib1=0;
      fib2=fiba=1;
      for(int i=2;i<=n;i++){
              fiba = (fib1 + fib2)%10;
                  fib1 = fib2;
                  fib2 = fiba;
    }
      return fiba % m;
  }
};

int main(void) {
  int64_t n;
  int m;
  std::cin >> n >> m;
  std::cout << Fibonacci::get_remainder(n, m) << std::endl;
  return 0;
}
