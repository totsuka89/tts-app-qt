#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

#include "json.hpp"

class Settings {
   public:
    static Settings& getInstance() {
        static Settings instance;
        return instance;
    }

    nlohmann::json* getJson() { return &m_json; }

    void saveDefaultSettings();

    void saveSettings() const;

    bool loadSettings();

   private:
    Settings() = default;

    Settings(const Settings& other) = delete;

    Settings& operator=(const Settings& other) = delete;

    Settings(Settings&& other) = delete;

    Settings& operator=(Settings&& other) = delete;

    const QString SETTINGS_FILE_NAME = "settings.json";

    nlohmann::json m_json;
};

#endif  // SETTINGS_H
