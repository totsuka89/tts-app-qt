#include "logger.h"

#include <QDebug>
#include <QFile>
#include <QString>

void QDebugLogger::output(std::string message) { qDebug() << message; }

void FileLogger::output(std::string message) {
    QFile fileLog("log.txt");
    if (fileLog.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&fileLog);
        out << QString(message.c_str()) << "\n";
        fileLog.close();
    }
}
