#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
struct Timer{
    sf::Clock m_clock;
    sf::Time m_duration;
    Timer(sf::Time duration){
        m_duration=duration;
    }
    bool isDone(){
        return m_clock.getElapsedTime()>=m_duration;
    }
    void restart(){
        m_clock.restart();
    }
    float getPassedTime(){
        return m_clock.getElapsedTime().asSeconds();
    }
};

struct AudioPlayer{
    sf::SoundBuffer m_buffer;
    sf::Sound m_sound;
    AudioPlayer(std::string file_path,float volume){
        if (!m_buffer.loadFromFile(file_path)) {
            std::cout<<"无法加载音频资源:"<<file_path;
        }
        m_sound.setBuffer(m_buffer);
        m_sound.setVolume(volume);
    }
    void play(){
        m_sound.play();
    }
};