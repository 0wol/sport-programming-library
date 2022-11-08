template<typename T>
T gcd(T a, T b) {
	while (a != 0)  {
		b %= a;
		swap(a, b);
	}
	return b;
}

template<typename T>
T lcm(T a, T b) {
	return (a / gcd<T>(a, b)) * b;
}