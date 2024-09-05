#include "mozillattsmodel.h"

#include <QDebug>

MozillaTtsModel::MozillaTtsModel(QObject* parent) : Model(parent) {
    QStringList& languages = getLanguages();
    languages.append({"not", "yet"});
}

std::string MozillaTtsModel::synthesis(QString language, QString text, QString option) {
    qDebug() << "MozillaTtsModel::synthesis";
    return "";
};

void MozillaTtsModel::save(QString language, QString text, QString option) {
    qDebug() << "MozillaTtsModel::save";
    return;
};
