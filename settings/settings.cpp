#include "settings.h"

#include <QFile>

using json = nlohmann::json;

void Settings::saveDefaultSettings() {
    m_json["google"]["api_key"] = "";

    saveSettings();
}

void Settings::saveSettings() const {
    QFile file(SETTINGS_FILE_NAME);
    if (!file.open(QIODevice::WriteOnly)) {
        throw std::runtime_error("Cannot create settings file.");
        return;
    }

    file.write(m_json.dump(4).c_str());
    file.close();
}

bool Settings::loadSettings() {
    QFile file(SETTINGS_FILE_NAME);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QByteArray fileData = file.readAll();
    m_json = json::parse(fileData.data());

    file.close();

    return true;
}
