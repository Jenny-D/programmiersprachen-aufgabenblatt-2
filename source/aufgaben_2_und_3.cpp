#include <iostream>
#include <list>
#include <set>
#include <iterator>
#include <cstdlib>

int main() {
	std::list<unsigned int> l;
	for (int i = 0; i < 100; i++) {
		unsigned int x = std::rand() % 101;
		l.push_back(x);
	}

	std::set<unsigned int> s;
	for (int i : l) {
		s.insert(i);
	}

	std::cout << "In der Liste sind " << s.size() << " unterschiedliche Zahlen.\n";

	std::set<unsigned int> s2;
	for (int i = 0; i <= 100; i++) {
		auto x = s.find(i);
		if (x == s.end()) {
			s2.insert(i);
		}
	}
	std::cout << "Folgende Zahlen sind nicht in der Liste: ";
	for (std::set<unsigned int>::iterator pos = s2.begin(); pos != s2.end(); pos++) {
		std::cout << *pos << " ";
	}
}
