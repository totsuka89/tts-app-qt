#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QStringList>

class Model : public QObject
{
    Q_OBJECT

public:
    Model(QObject *parent = nullptr);

private:
    QStringList engines;
    QStringList languages;
};

#endif // MODEL_H
