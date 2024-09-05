#ifndef LOG_H
#define LOG_H

#include <memory>
#include <vector>

#include "logger.h"

class Log {
   public:
    static Log& getInstance();

    void addLogger(std::shared_ptr<Logger> logger);

    void output(std::string_view level, std::string_view message) const;

   private:
    Log() = default;

    Log(const Log& other) = delete;

    Log& operator=(const Log& other) = delete;

    Log(Log&& other) = delete;

    Log& operator=(Log&& other) = delete;

    [[nodiscard]] std::string getCurrentDateTime() const;

    std::vector<std::shared_ptr<Logger>> m_loggers;
};

#endif  // LOG_H
