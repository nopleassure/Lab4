#include "Player.h"
#include <iostream>

Player::Player()
{
    power = false;
    playing = false;
    volume = 5;
    track = 1;
}

Player::Player(bool startPower, bool startPlaying, int startVolume, int startTrack)
{
    power = startPower;
    playing = startPlaying;

    if (startVolume >= 0 && startVolume <= 10)
    {
        volume = startVolume;
    }
    else
    {
        volume = 5;
    }

    if (startTrack >= 1 && startTrack <= 5)
    {
        track = startTrack;
    }
    else
    {
        track = 1;
    }

    if (power == false)
    {
        playing = false;
    }
}

void Player::changePower()
{
    if (power == true)
    {
        power = false;
        playing = false;
    }
    else
    {
        power = true;
    }
}

void Player::changePlay()
{
    if (power == true)
    {
        if (playing == true)
        {
            playing = false;
        }
        else
        {
            playing = true;
        }
    }
    else
    {
        std::cout << "Плеер выключен, включите его" << std::endl;
    }
}

void Player::volumeUp()
{
    if (power == true)
    {
        if (volume < 10)
        {
            volume = volume + 1;
        }
        else
        {
            std::cout << "Громкость уже максимальная" << std::endl;
        }
    }
    else
    {
        std::cout << "Плеер выключен, включите его" << std::endl;
    }
}

void Player::volumeDown()
{
    if (power == true)
    {
        if (volume > 0)
        {
            volume = volume - 1;
        }
        else
        {
            std::cout << "Громкость уже минимальная" << std::endl;
        }
    }
    else
    {
        std::cout << "Плеер выключен, включите его" << std::endl;
    }
}

void Player::nextTrack()
{
    if (power == true)
    {
        track = track + 1;
        if (track > 5)
        {
            track = 1;
        }
    }
    else
    {
        std::cout << "Плеер выключен, включите его" << std::endl;
    }
}

void Player::prevTrack()
{
    if (power == true)
    {
        track = track - 1;
        if (track < 1)
        {
            track = 5;
        }
    }
    else
    {
        std::cout << "Плеер выключен, включите его" << std::endl;
    }
}
