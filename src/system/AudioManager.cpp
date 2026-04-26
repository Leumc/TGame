#include "AudioManager.hpp"
#include "../structs.hpp"

bool AudioManager::addAudio(std::string identifier,std::string path,float volume){
    auto it=m_map.find(identifier);
    if(it!=m_map.end())return false;
    auto player=std::make_unique<AudioPlayer>(path,volume);
    m_map.emplace(identifier,std::move(player));
    return true;
}

bool AudioManager::setVolume(std::string identifier,float volume){
    auto it=m_map.find(identifier);
    if(it==m_map.end())return false;
    it->second->m_sound.setVolume(volume);
    return true;
}

bool AudioManager::playAudio(std::string identifier){
    auto it=m_map.find(identifier);
    if(it==m_map.end())return false;
    it->second->play();
    return true;
}