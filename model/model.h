#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QStringList>

class Model : public QObject {
    Q_OBJECT

   public:
    Model(QObject* parent) {};

    virtual std::string synthesis(QString language, QString text, QString option) = 0;

    virtual void save(QString language, QString text, QString option) = 0;

    QStringList& getLanguages() { return m_languages; }

   private:
    QStringList m_languages;
};

#endif  // MODEL_H
