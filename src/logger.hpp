#pragma once
#include <string>
#include <sstream>
#include <iostream>

namespace Logger {
	class Level{
		public:
			Level(int l);
			int level;
	};

	class Logger{
		public:
			Logger(std::string name, int level);
			void log(int level, std::string message);
			void buffer(std::string message);
			void buffer(Level);
		private:
			std::string _name;
			int _level;
			std::string _buffer;
	};
}

template <typename T>
Logger::Logger* operator<< (Logger::Logger* logger, T value) {
    std::ostringstream oss;
    oss << value;
    logger->buffer(oss.str());
    return logger;
}
Logger::Logger* operator<< (Logger::Logger* logger, Logger::Level l);
