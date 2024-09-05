#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QStringView>

#include "mainwindow.h"
#include "model/model.h"

class Controller : public QObject {
    Q_OBJECT

   public:
    explicit Controller(MainWindow* view);

    virtual ~Controller();

    void initialize();

   private slots:
    void onChangedText(QString name);

    void onClickedPlay();

    void onClickedSave();

   private:
    void setModel(const QStringView name);

    void updateView(const QStringView name) const;

    Model* m_model;
    MainWindow* m_view;
};

#endif  // CONTROLLER_H
