#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include "../../libs/nlohmann/json.hpp"
#include <iostream>
#include <fstream>

class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();
    
    void LoadImage(const std::string& key, const std::string& filename);
    const sf::Texture& GetImage(const std::string& key) const;

    void LoadFont(const std::string& key, const std::string& filename);
    const sf::Font& GetFont(const std::string& key) const;

    void LoadSoundBackground(const std::string& key, const std::string& filename);
    const sf::SoundBuffer& GetSoundBackground(const std::string& key) const;

    void LoadSoundStep(const std::string& key, const std::string& filename);
    const sf::SoundBuffer& GetSoundStep(const std::string& key) const;

    void LoadFromJson(const std::string& jsonFilePath);

private:
    std::unordered_map<std::string, sf::Texture> textures_;
    std::unordered_map<std::string, sf::Font> fonts_;
    std::unordered_map<std::string, sf::SoundBuffer> sounds_background;
    std::unordered_map<std::string, sf::SoundBuffer> sounds_step;
    sf::Texture defaultTexture_; 
};

#endif // RESOURCEMANAGER_HPP
