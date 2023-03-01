#include "calculator/sub.h"
#include "calculator/sum.h"
#include "calculator/math.h"

int doMath(int a, int b, int op) {
    if(op == 1) {
        return calc::sum(a, b);
    } else {
        return calc::sub(a, b);
    }
}