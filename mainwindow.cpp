#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QComboBox* MainWindow::getComboBoxEngine() {
    return ui->comboBoxEngine;
}

QComboBox* MainWindow::getComboBoxLanguage() {
    return ui->comboBoxLanguage;
}

QTextEdit* MainWindow::getTextEdit() {
    return ui->textEdit;
}

QPushButton* MainWindow::getButtonPlay() {
    return ui->buttonPlay;
}

QPushButton* MainWindow::getButtonSave() {
    return ui->buttonSave;
}
