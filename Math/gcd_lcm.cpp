template<typename T>
T gcd(T a, T b) {
    /* returns the greatest common divisor
       ex. gcd(12343, 76543) = 1 */
    while (a != 0)  {
        b %= a;
        swap(a, b);
    }
    return b;
}

template<typename T>
T lcm(T a, T b) {
    /* returns the least common multiple
       ex. lcm(28, 21) = 84 */
    return (a / gcd<T>(a, b)) * b;
}
