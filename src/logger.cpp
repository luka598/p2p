#include <string>
#include <sstream>
#include <iostream>
#include <Poco/Format.h>
#include <thread>
#include "logger.hpp"

namespace Logger {
	Level::Level(int l) : level(l) {};

	Logger::Logger(std::string name, int level)
		: _name(name), _level(level)
	{
	}
	void Logger::log(int level, std::string message)
	{
		std::stringstream ss;
		ss << std::this_thread::get_id();

		std::cout << Poco::format("[%d]%s@%s: %s", level, _name, ss.str(), message) << std::endl;
	}
	void Logger::buffer(std::string message)
	{
		_buffer += message;
	}
	void Logger::buffer(Level l)
	{
		log(l.level, _buffer);
		_buffer.clear();
	}
}
Logger::Logger* operator<< (Logger::Logger* logger, Logger::Level l){logger->buffer(l); return logger;};
