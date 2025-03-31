#include "philosopher.h"
#include <vector>
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: \n" << argv[0] << " <number_of_philosophers>\n";
		return 1;
	}

	int philCount = std::atoi(argv[1]);
	if (philCount < 2) {
		std::cerr << "Number of philosophers has to be greater than 1.\n";
		return 1;
	}

	std::vector<std::thread> phils;
	std::vector<std::mutex> forks(philCount);

	for (int i = 0; i < philCount; ++i) {
		// create and add a new thread to phils, thread is given Philosopher::life to execute
		phils.emplace_back(&Philosopher::life, Philosopher(i, forks[i], forks[(i + 1) % philCount]));
	}

	for (auto& f : phils) {
		f.join();
	}

	return 0;
}
