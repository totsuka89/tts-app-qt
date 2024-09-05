#include "googlettsmodel.h"

#include <TtsService.h>

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

#include "../settings/settings.h"

using namespace RAIREAR::TTS;

GoogleTtsModel::GoogleTtsModel(QObject* parent) : Model(parent) {
    QStringList& languages = getLanguages();
    languages.append({"ko-KR", "en-US"});
}

std::string GoogleTtsModel::synthesis(QString language, QString text, QString apiKey) {
    ParameterBuilder builder;
    const auto parameter = builder.setLanguage(language.toStdString())
                               .setText(text.toStdString())
                               .set("api_key", apiKey.toStdString())
                               .build();

    const auto tts = TtsServiceFactory::create(TtsType::GOOGLE);
    tts->setParameter(parameter);

    std::string result;
    try {
        result = tts->synthesis();
    } catch (std::exception e) {
        QMessageBox::information(nullptr, "Message Box",
                                 QString("Please check the connection status.\n"
                                         "Please check your API key."));
        return "";
    }

    Settings& settings = Settings::getInstance();
    if ((*settings.getJson())["google"]["api_key"] != apiKey.toStdString()) {
        (*settings.getJson())["google"]["api_key"] = apiKey.toStdString();
        settings.saveSettings();
    }

    return result;
};

void GoogleTtsModel::save(QString language, QString text, QString apiKey) {
    std::string result = synthesis(language, text, apiKey);

    QString fileName =
        QFileDialog::getSaveFileName(nullptr, "Save File", "result.mp3", "mp3 Files (*.mp3)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        file.open(QIODeviceBase::WriteOnly);

        QByteArray byteArray(result.c_str(), result.length());
        file.write(byteArray);

        file.flush();
        file.close();
    }
}
