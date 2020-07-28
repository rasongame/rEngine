#include <Common/common.hpp>

using namespace Logger;

void Logger::printInfo(std::string msg) {
#ifdef LOGGER_SHOW_DATE
	std::time_t time = std::time(nullptr);
	std::tm tm = *std::localtime(&time);
	std::cout << std::put_time(&tm, "%R :: ==> ") << msg << std::endl;
#endif

}
void Logger::printError(std::string msg) {
#ifdef LOGGER_SHOW_DATE
	std::time_t time = std::time(nullptr);
	std::tm tm = *std::localtime(&time);
	std::cout << std::put_time(&tm, "%R :: ERROR ==>") << msg << std::endl;
#endif
}
void Logger::printWarning(std::string msg) {
#ifdef LOGGER_SHOW_DATE
	std::time_t time = std::time(nullptr);
	std::tm tm = *std::localtime(&time);
	std::cout << std::put_time(&tm, "%R :: WARNING ==>") << msg << std::endl;
#endif
}
