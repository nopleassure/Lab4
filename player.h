#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player();
    Player(bool startPower, bool startPlaying, int startVolume, int startTrack);

    void changePower();
    void changePlay();
    void volumeUp();
    void volumeDown();
    void nextTrack();
    void prevTrack();

    void setVolume(int newVolume);
    void setTrack(int newTrack);

    bool getPower();
    bool getPlaying();
    int getVolume();
    int getTrack();

    void show();

private:
    bool power;
    bool playing;
    int volume;
    int track;
};

#endif

