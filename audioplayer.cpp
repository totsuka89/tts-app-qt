#include "audioplayer.h"

#include <stdexcept>

AudioPlayer::AudioPlayer() {
    m_player.setAudioOutput(&m_audioOutput);
    m_data = nullptr;
}

AudioPlayer::~AudioPlayer() {
    stop();

    if (m_data) {
        delete m_data;
    }
}

void AudioPlayer::setData(const std::string_view data) {
    if (m_data) {
        delete m_data;
    }

    m_data = new QBuffer();

    QByteArray byteArray(data.data(), data.length());
    m_data->setData(byteArray);
    m_data->open(QIODevice::ReadOnly);
}

void AudioPlayer::play() {
    if (!m_player.isAvailable()) {
        throw std::runtime_error("Audio player is not available.");
        return;
    }

    stop();

    m_player.setSourceDevice(m_data);
    m_player.play();
}

void AudioPlayer::play(const std::string_view data) {
    setData(data);
    play();
}

void AudioPlayer::stop() {
    if (!m_player.isAvailable()) {
        throw std::runtime_error("Audio player is not available.");
        return;
    }

    if (m_player.isPlaying()) {
        m_player.stop();
    }
}
