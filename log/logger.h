#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
   public:
    virtual void output(std::string message) = 0;
};

class QDebugLogger : public Logger {
   public:
    void output(std::string message);
};

class FileLogger : public Logger {
   public:
    void output(std::string message);
};

#endif  // LOGGER_H
