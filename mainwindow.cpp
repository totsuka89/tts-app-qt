#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    getComboBoxEngine()->addItems(m_engines);
}

MainWindow::~MainWindow() { delete ui; }

QComboBox* MainWindow::getComboBoxEngine() const { return ui->comboBoxEngine; }

QComboBox* MainWindow::getComboBoxLanguage() const { return ui->comboBoxLanguage; }

QLabel* MainWindow::getLabelOption() const { return ui->labelOption; }

QLineEdit* MainWindow::getLineEditOption() const { return ui->lineEditOption; }

QTextEdit* MainWindow::getTextEdit() const { return ui->textEdit; }

QPushButton* MainWindow::getButtonPlay() const { return ui->buttonPlay; }

QPushButton* MainWindow::getButtonSave() const { return ui->buttonSave; }

AudioPlayer& MainWindow::getAudioPlayer() { return m_player; }
