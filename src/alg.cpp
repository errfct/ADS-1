// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>

bool checkPrime(uint64_t value) {
    if (value < 2) return false;
    if (value == 2) return true;
    if (value % 2 == 0) return false;

    uint64_t limit = static_cast<uint64_t>(std::sqrt(value));
    for (uint64_t i = 3; i <= limit; i += 2) {
        if (value % i == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0;
    if (n == 1) return 2;

    uint64_t count = 1;
    uint64_t num = 3;

    while (count < n) {
        if (checkPrime(num)) {
            ++count;
            if (count == n) return num;
        }
        num += 2;
    }
    return num;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t num = value + 1;
    while (!checkPrime(num)) {
        ++num;
    }
    return num;
}

uint64_t sumPrime(uint64_t hb) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hb; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lb, uint64_t hb) {
    uint64_t count = 0;
    uint64_t prev = 0;

    for (uint64_t i = lb; i < hb; ++i) {
        if (checkPrime(i)) {
            prev = i;
            break;
        }
    }

    if (prev == 0) return 0;

    for (uint64_t i = prev + 1; i < hb; ++i) {
        if (checkPrime(i)) {
            if (i - prev == 2) {
                ++count;
            }
            prev = i;
        }
    }
    return count;
}
