#include "log.h"

#include <QString>
#include <chrono>
#include <iomanip>
#include <sstream>

Log& Log::getInstance() {
    static Log instance;
    return instance;
}

void Log::addLogger(std::shared_ptr<Logger> logger) { m_loggers.push_back(logger); }

void Log::output(std::string_view level, std::string_view message) const {
    QString dateTime = QString::fromStdString(getCurrentDateTime());

    QString logMessage = QString("[%1] [%2] %3").arg(dateTime, level.data(), message.data());

    for (const auto& logger : m_loggers) {
        logger->output(logMessage.toStdString());
    }
}

std::string Log::getCurrentDateTime() const {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
