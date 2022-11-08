template<typename T, typename P>
T bin_pow(T n, P pow) {
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
	T res = 1;
	while (pow > 0) {
		if (pow&1)
			res = (res * n) % mod;
		n = (n * n) % mod;
		pow >>= 1;
	}
	return res;
}
