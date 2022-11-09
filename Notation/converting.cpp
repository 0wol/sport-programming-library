// TODO: подумать над названием раздела

#include <string>
#include <cctype>

template<typename T>
std::string convert_from_decimal(T n, unsigned int base, unsigned int length) {
	/* length: count of characters in result string */
	
	std::string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string res;
	while (n > 0) {
		res += s[n % base];
		n /= base;
	}
	
	while(res.size() < length) res += '0';
	
	reverse(res.begin(), res.end());
	res.resize(length); // for invalid queries
	
	return res;
}

template<typename T>
std::string convert_from_decimal(T n, unsigned int base) {	
	const std::string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string res;
	while (n > 0) {
		res += s[n % base];
		n /= base;
	}
	
	reverse(res.begin(), res.end());
	
	return res;
}

long long convert_to_decimal(std::string s, unsigned int base) {
	const std::string temp = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	int n = s.size();
	long long pow = 1;
	long long res = 0;
	for(int i = n - 1; i >= 0; --i){
		if (temp[base] <= s[i]) return -1;
		
		if ('0' <= s[i] && s[i] <= '9')
			res += pow * (s[i] - '0');
		else if('a' <= s[i] && s[i] <= 'z')
			res += pow * (10 + (s[i] - 'a'));
		else if('A' <= s[i] && s[i] <= 'Z')
			res += pow * (10 + (s[i] - 'A'));
		else return -1;
		pow *= base; // maybe % mod is needed for some cases
	}
	return res;
}
