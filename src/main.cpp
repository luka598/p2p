#include <iostream>
#include <sstream>
#include "task.hpp"
#include "logger.hpp"

using namespace std;
namespace L = Logger;
typedef string str;

class HelloTask : public Task::Task {
	public:
		HelloTask(Logger::Logger *_l) : l(_l)
		{
			l << str("Initialized task") << Logger::Level(1);
		}
		void run(){
			l << str("Alo") << Logger::Level(1);
			n++;
		}
	private:
		int n = 0;
		Logger::Logger *l;
};

int main() {
	Logger::Logger l("MAIN", 1);
	Task::TaskRunner tr(1);
	tr.add(HelloTask(&l));
	tr.add(HelloTask(&l));
	tr.add(HelloTask(&l));
	tr.add(HelloTask(&l));
	&l << str("Test") << str("a") << Logger::Level(1);
	return 0;
}
