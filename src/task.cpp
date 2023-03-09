#include <functional>
#include <queue>
#include <iostream>
#include "task.hpp"

namespace Task{

	Task::Task(){}

	Task::~Task(){}
	void Task::run(TaskRunner tr){
		std::cout << "TASK" << std::endl;
	}

	TaskRunner::TaskRunner(size_t nThreads) : stop(false) {
		std::cout << "Max threads: " << std::thread::hardware_concurrency() << std::endl;
		for (size_t i=0; i<nThreads; i++){
			threads.emplace_back(
					[this] {
						while (true) {
							Task t;
							{
								std::unique_lock<std::mutex> lock(queueMutex);
								queueCondition.wait(lock, [this]{ return stop || !tasks.empty(); });
								if (stop && tasks.empty()) {
									return;
								}
								t = std::move(tasks.front());
								tasks.pop();
							}
							t.run(this);
						}
					});
		}
	}
	TaskRunner::~TaskRunner(){
		std::cout << "Deleting TaskRunner" << std::endl;
	}
	void TaskRunner::add(Task t){
		tasks.push(t);
	}
}

