#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
class Logger
{
public:
	Logger() {};
	void printInfo(std::string msg);
	void printError(std::string msg);
	void printWarning(std::string msg);
	~Logger() {};
};
