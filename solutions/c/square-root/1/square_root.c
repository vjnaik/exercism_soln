#include "square_root.h"

int square_root(int n) {
    if (n == 0) return 0;

    // floor(log2(n))
    unsigned int lg2 = 0, t = n;
    while (t >>= 1) ++lg2;

    // initial guess: 2^{floor(log2(n))/2}
    unsigned x = 1u << (lg2 / 2);

    // 5 iterations
    for (int i = 0; i < 5; i++)
        x = (x + n / x) >> 1;

    return (int)x;
}