#include "rational_numbers.h"

static rational_t _create_rational(int16_t num, int16_t den) {
    rational_t temp;
    temp.numerator = num;
    temp.denominator = den;
    return temp;
}

static int16_t _gcd(int16_t a, int16_t b) {
    while (b != 0) {
        int16_t remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

static rational_t _fix_sign(rational_t a) {
    if (a.denominator < 0) {
        return _create_rational(-a.numerator, -a.denominator);
    }
    return a;
}

rational_t add(rational_t a, rational_t b) {
    rational_t temp;
    temp.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
    temp.denominator = a.denominator * b.denominator;
    return reduce(temp);
}

rational_t subtract(rational_t a, rational_t b) {
    b = _create_rational(-b.numerator, b.denominator);
    return add(a, b);
}

rational_t multiply(rational_t a, rational_t b) {
    rational_t temp;
    temp.numerator = a.numerator * b.numerator;
    temp.denominator = a.denominator * b.denominator;
    return reduce(temp);
}

rational_t divide(rational_t a, rational_t b) {
    rational_t temp = _create_rational(b.denominator, b.numerator);
    return multiply(a, temp);
}

rational_t absolute(rational_t a) {
    rational_t temp;
    a = _fix_sign(a);
    temp.numerator = (a.numerator < 0) ? -a.numerator: a.numerator;
    temp.denominator = a.denominator;
    return reduce(temp);
}

rational_t exp_rational(rational_t a, int16_t b) {
    rational_t temp;
    if (a.numerator == 0) {
        return _create_rational(0, 1);
    }
    if (b == 0) {
        return _create_rational(1, 1);
    }
    if (b < 0) {
        a = _create_rational(a.denominator, a.numerator);
        b = -b;
    }
    temp = a;
    b--;
    while (b > 0) {
        temp = multiply(temp, a);
        b--;
    }
    return temp;
}

float exp_real(uint16_t a, rational_t b) {
    return pow(a, (float)b.numerator/b.denominator);
}

rational_t reduce(rational_t a) {
    rational_t temp;
    int16_t gcd;
    a = _fix_sign(a);
    if (a.numerator < 0) {
        int16_t pos_a = -a.numerator;
        gcd = _gcd(pos_a, a.denominator);
        temp.numerator = -1 * (pos_a / gcd);
    } else {
        gcd = _gcd(a.numerator, a.denominator);
        temp.numerator = a.numerator / gcd;
    }
    temp.denominator = a.denominator / gcd;
    return temp;
}