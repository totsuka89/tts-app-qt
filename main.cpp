#include <QApplication>

#include "TtsService.h"
#include "controller.h"
#include "log/log.h"
#include "log/logger.h"
#include "mainwindow.h"
#include "settings/settings.h"

int main(int argc, char* argv[]) {
    Log::getInstance().addLogger(std::make_shared<QDebugLogger>());
    Log::getInstance().addLogger(std::make_shared<FileLogger>());
    RAIREAR::Logger::Logger::getInstance().setCallback(
        [](std::string_view level, std::string_view message) {
            Log::getInstance().output(level, message);
        });

    Settings& settings = Settings::getInstance();
    if (!settings.loadSettings()) {
        settings.saveDefaultSettings();
    }

    QApplication a(argc, argv);

    MainWindow w;
    Controller controller(&w);
    controller.initialize();

    w.show();

    return a.exec();
}
