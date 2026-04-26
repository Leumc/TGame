#include "../structs.hpp"
#include <unordered_map>
#include <memory>

class AudioManager {
  private:
    std::unordered_map<std::string, std::unique_ptr<AudioPlayer>> m_map;

  public:
    AudioManager(){}
    bool addAudio(std::string identifier,std::string path,float volume);
    bool setVolume(std::string identifier,float volume);
    bool playAudio(std::string identifier);
};