#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Czas {
public:
	high_resolution_clock::time_point start;
	high_resolution_clock::time_point koniec;

	void czasStart() {
		start = high_resolution_clock::now();
	}

	void czasStop() {
		koniec = high_resolution_clock::now();
	}

	long czasTrwania() {
		return duration_cast<nanoseconds>(koniec - start).count();
	}
};