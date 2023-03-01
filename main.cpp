#include <iostream>

#include "calculator/math.h"
#include "common/type_def.h"
#include "config.h"
#include "new_test_lib/new_calc.h"

#ifdef USE_SUPER_CALC
#include "super_calc/SuperCalc.h"
#endif

int main() {
#ifdef enable_name
  std::cout << project_name << std::endl;
#endif

#ifdef USE_SUPER_CALC
  SuperCalc Calc;
  std::cout << Calc.calc(2.3, 3.2) << std::endl;
#else
  std::cout << doMath(10, 2, 2) << std::endl;
#endif

  std::cout << NewCalculator::calc(4.0, 3.0) << std::endl;

  return 0;
}
