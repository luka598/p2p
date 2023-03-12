#include <functional>
#include <queue>
#include <iostream>
#include "task.hpp"
#include "logger.hpp"

namespace Task{
	//
	// Task::Task
	//
	Task::Task(){}
	Task::~Task(){}
	void Task::run(TaskRunner *tr){
		std::cout << "TASK" << std::endl;
	}
	//
	// Task::TaskRunner
	//
	TaskRunner::TaskRunner(size_t nThreads)
		: stop(false), logger(Logger::Logger("Thread", 1))
	{
		std::cout << "Max threads: " << std::thread::hardware_concurrency() << std::endl;
		if (nThreads > std::thread::hardware_concurrency())
			std::cerr << "Can't allocate more threads than std::thread::hardware_concurrency()" << std::endl; 
		for (size_t i = 0; i<nThreads; i++){
			startThread();
		}
	}
	TaskRunner::~TaskRunner(){
		stop = true;
		queueCondition.notify_all();
		for (auto &t: threads){
			t.join();
		}
		std::cout << "Deleting TaskRunner" << std::endl;
	}
	void TaskRunner::workerLoop(){
		std::cout << "Started thread" << std::endl;
		while (true) {
				std::unique_lock<std::mutex> lock(queueMutex);
				queueCondition.wait(lock, [this]() { return !tasks.empty() || stop; });

				if (stop) {
					std::cout << "Stopping thread" << std::endl;
					return;
				}

				Task t = tasks.front();
				tasks.pop();
				lock.unlock(); 
				t.run(this);
			}
	}
	void TaskRunner::startThread() {
		threads.emplace_back(&TaskRunner::workerLoop, this);
	}
	void TaskRunner::add(Task t){
		tasks.push(t);
		queueCondition.notify_one();
	}
}

