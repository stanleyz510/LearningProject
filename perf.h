#include <intrin.h>

using namespace std;

class Perf {
private:
	unsigned long long s, e;

	unsigned long long rdtsc(void) {
		return __rdtsc();
	}

public:
	Perf() {
		reset();
	}
	
	void start() {
		s = rdtsc();
	}
	
	void stop() {
		e = rdtsc();
	}
	
	long long get_result() {
		return e > s ? e - s : 0;
	}
	
	void reset() {
		s = 0;
		e = 0;
	}
};
