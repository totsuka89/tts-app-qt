#include "controller.h"

#include <QString>
#include <stdexcept>

#include "model/googlettsmodel.h"
#include "model/mozillattsmodel.h"
#include "settings/settings.h"

Controller::Controller(MainWindow* view) : m_model(nullptr), m_view(view) {
    connect(m_view->getComboBoxEngine(), &QComboBox::currentTextChanged, this,
            &Controller::onChangedText);
    connect(m_view->getButtonPlay(), &QPushButton::clicked, this, &Controller::onClickedPlay);
    connect(m_view->getButtonSave(), &QPushButton::clicked, this, &Controller::onClickedSave);
}

Controller::~Controller() {
    if (m_model) {
        delete m_model;
    }
}

void Controller::setModel(const QStringView name) {
    if (m_model) {
        delete m_model;
    }

    if (name == QString("Google")) {
        m_model = new GoogleTtsModel();
    } else if (name == QString("Mozilla")) {
        m_model = new MozillaTtsModel();
    } else {
        throw std::runtime_error("Not support tts engine.");
        return;
    }

    m_view->getComboBoxLanguage()->clear();
    m_view->getComboBoxLanguage()->addItems(m_model->getLanguages());

    updateView(name);
}

void Controller::initialize() {
    auto comboBoxEngine = m_view->getComboBoxEngine();
    setModel(comboBoxEngine->currentText());
}

void Controller::onChangedText(QString name) { setModel(name); }

void Controller::onClickedPlay() {
    QString language = m_view->getComboBoxLanguage()->currentText();
    QString text = m_view->getTextEdit()->toPlainText();
    QString option = m_view->getLineEditOption()->text();

    std::string result = m_model->synthesis(language, text, option);
    m_view->getAudioPlayer().play(result);
}

void Controller::onClickedSave() {
    QString language = m_view->getComboBoxLanguage()->currentText();
    QString text = m_view->getTextEdit()->toPlainText();
    QString option = m_view->getLineEditOption()->text();

    m_model->save(language, text, option);
}

void Controller::updateView(const QStringView name) const {
    if (name == QString("Google")) {
        m_view->getLabelOption()->setText("API key");
        QString apiKey(
            (*Settings::getInstance().getJson())["google"]["api_key"].get<std::string>().c_str());
        m_view->getLineEditOption()->setText(apiKey);
        m_view->getLineEditOption()->setEnabled(true);
        m_view->getLineEditOption()->setPlaceholderText("Please enter a valid API key.");
    } else if (name == QString("Mozilla")) {
        m_view->getLabelOption()->setText("Option");
        m_view->getLineEditOption()->clear();
        m_view->getLineEditOption()->setEnabled(false);
        m_view->getLineEditOption()->setPlaceholderText("");
    }

    m_view->getTextEdit()->clear();
}
