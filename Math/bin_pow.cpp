template<typename T, typename P>
T bin_pow(T n, P pow) {
    /* raise a number to a power */
    T res = 1;
    while (pow > 0) {
        if (pow&1)
            res = (res * n);
        n *= n;
        pow >>= 1;
    }
    return res;
}

template<typename T, typename P>
T bin_pow(T n, P pow, T mod) {
    /* raise a number to a power and returns a remainder modulo mod */
    T res = 1;
    while (pow > 0) {
        if (pow&1)
            res = (res * n) % mod;
        n = (n * n) % mod;
        pow >>= 1;
    }
    return res;
}
