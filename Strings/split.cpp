#include <string>
#include <vector>

std::vector<std::string> split(std::string s, char delimeter) {
	std::vector<std::string> v;
	unsigned int last = 0;
	while(last < s.size() && s[last] == delimeter) last++;
	for (unsigned int i = last; i < s.size(); ++i) {
		if (s[last] == delimeter) {
			last = i;
			continue;
		}
		if (s[i] == delimeter) {
			v.push_back(s.substr(last, i - last));
			last = i + 1;
		}
	}
	
	if (last < s.size() && s[last] != delimeter)
		v.push_back(s.substr(last, s.size() - last));
		
	return v;
}
