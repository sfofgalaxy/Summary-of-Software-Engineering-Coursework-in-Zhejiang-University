#include <iostream>
using namespace std;

class FileWriter
{  
public:		
	static void writeStringToFile(const char *strMessage)
	{
		cout << "write strmessage to file......" << endl;
	}
};
class ConsoleDisplayer
{
public:
	static void displayString(const char *strMessage)
	{
		cout << "display strMessage to console......" << endl;
	}
};

class LogAppender;
class Logger
{
public:
	Logger() : m_count(0){}
	void addAppender(LogAppender *appender);
	void writeLog(const char *log);
private:
	LogAppender *m_appenders[256];
	int m_count;
};

class LogAppender
{
public:
	virtual void writeLog(const char *log) = 0;
};

void Logger::addAppender(LogAppender *appender) 
{
	if(appender && m_count < 256)  
	{
		m_appenders[m_count++] = appender;  
	}
}
void Logger::writeLog(const char *log)
{
	for(int i = 0; i < m_count; i ++) 
	{
		m_appenders[i]->writeLog(log); 
	}
}

class FileAppender : public LogAppender  
{
public:							
	void writeLog(const char *log)  
	{
		FileWriter::writeStringToFile(log); 
	}
};
class ConsoleAppender : public LogAppender  
{
public:            
	void writeLog(const char *log)  
	{
		ConsoleDisplayer::displayString(log);  
	}
};

void main()
{
	Logger logger;
	logger.addAppender(new ConsoleAppender());
	logger.addAppender(new FileAppender());
	logger.writeLog("Hello world.");

}



