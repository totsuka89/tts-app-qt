#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QComboBox* getComboBoxEngine();
    QComboBox* getComboBoxLanguage();
    QTextEdit* getTextEdit();
    QPushButton* getButtonPlay();
    QPushButton* getButtonSave();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
