#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QAudioOutput>
#include <QBuffer>
#include <QMediaPlayer>
#include <QObject>

class AudioPlayer : public QObject {
    Q_OBJECT

   public:
    AudioPlayer();

    virtual ~AudioPlayer();

    void setData(const std::string_view data);

    void play();
    void play(const std::string_view data);

    void stop();

   private:
    QBuffer* m_data;
    QAudioOutput m_audioOutput;
    QMediaPlayer m_player;
};

#endif  // AUDIOPLAYER_H
