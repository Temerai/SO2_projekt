#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <mutex>
#include <condition_variable>

class Philosopher {
public:
	Philosopher(int id, std::mutex& left, std::mutex& right);
	void life();
private:
	int id;
	std::mutex& forkL;
	std::mutex& forkR;
	void think();
	void eat();
};

#endif //PHILOSOPHER_H
