#pragma once
#include <functional>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "logger.hpp"

namespace Task{
	class Task;
	class TaskRunner;

	class Task {
		public:
			Task();
			~Task();
			void run(TaskRunner *tr);
	};

	class TaskRunner {
		public:
			TaskRunner(size_t nThreads);
			~TaskRunner();
			void startThread();
			void add(Task t);
			void workerLoop();
		private:
			std::queue<Task> tasks;
			std::mutex queueMutex;
			std::condition_variable queueCondition;
			bool stop;
			std::vector<std::thread> threads;
			std::mutex _mutex;
			Logger::Logger logger;
	};
}
