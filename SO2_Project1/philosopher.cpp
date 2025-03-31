#include "philosopher.h"

#include <chrono>
#include <random>
#include <iostream>

// mutex for syncing output (readability) (seems unnecessary after corrections)
//std::mutex coutMutex;

Philosopher::Philosopher(int id, std::mutex &left, std::mutex &right)
	: id(id), forkL(left), forkR(right) {
}

void Philosopher::think() { {
		std::string out = "Philosopher " + std::to_string(id) + " is thinking ";
		//std::lock_guard lock(coutMutex);
		std::cout << out << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1000 + rand() % 2000));
}

void Philosopher::eat() { {
		std::string out = "Philosopher " + std::to_string(id) + " is eating ";
		//std::lock_guard lock(coutMutex);
		std::cout << out << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1000 + rand() % 2000));
}


void Philosopher::life() {
	while (true) {
		think();

		// asymmetry assures no deadlock
		if (id % 2 == 0) {
			forkL.lock();
			forkR.lock();
		} else {
			forkR.lock();
			forkL.lock();
		}

		eat();

		forkL.unlock();
		forkR.unlock();
	}
}
