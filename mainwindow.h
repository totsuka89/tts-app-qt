#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QStringList>
#include <QTextEdit>

#include "audioplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);

    virtual ~MainWindow();

    QComboBox* getComboBoxEngine() const;

    QComboBox* getComboBoxLanguage() const;

    QTextEdit* getTextEdit() const;

    QLabel* getLabelOption() const;

    QLineEdit* getLineEditOption() const;

    QPushButton* getButtonPlay() const;

    QPushButton* getButtonSave() const;

    AudioPlayer& getAudioPlayer();

   private:
    Ui::MainWindow* ui;
    QStringList m_engines = {"Google", "Mozilla"};
    AudioPlayer m_player;
};
#endif  // MAINWINDOW_H
