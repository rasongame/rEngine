#include "Logger.hpp"
void Logger::printInfo(std::string msg) {
	std::time_t time = std::time(nullptr);
	std::tm tm = *std::localtime(&time);
	std::cout << std::put_time(&tm, "%R :: ==> ") << msg << std::endl;
}
void Logger::printError(std::string msg) {
	std::time_t time = std::time(nullptr);
	std::tm tm = *std::localtime(&time);
	std::cout << std::put_time(&tm, "%R :: ERROR ==>") << msg << std::endl;
}
void Logger::printWarning(std::string msg) {
	std::time_t time = std::time(nullptr);
	std::tm tm = *std::localtime(&time);
	std::cout << std::put_time(&tm, "%R :: WARNING ==>") << msg << std::endl;
}
