#include "./include/resourceManager.hpp"


ResourceManager::ResourceManager() {
    if (!defaultTexture_.loadFromFile("../img/runninggoat.png")) {
        std::cerr << "Failed to load default texture." << std::endl;
    }
}

ResourceManager::~ResourceManager() {
    // Release all loaded textures
    for (auto& pair : textures_) {
        pair.second.~Texture();  // The SFML Texture class does not require explicit release, but this is an example
    }

    // Release all loaded fonts
    for (auto& pair : fonts_) {
        pair.second.~Font();  // The SFML Font class does not require explicit release, but this is an example
    }

    // Release all loaded sound buffers for background sounds
    for (auto& pair : sounds_background) {
        pair.second.~SoundBuffer();  // The SFML SoundBuffer class does not require explicit release, but this is an example
    }

    // Release all loaded sound buffers for step sounds
    for (auto& pair : sounds_step) {
        pair.second.~SoundBuffer();  // The SFML SoundBuffer class does not require explicit release, but this is an example
    }

}


void ResourceManager::LoadImage(const std::string& key, const std::string& filename) {
    if (textures_.find(key) != textures_.end()) {
        std::cerr << "Warning: The texture " << key << " is already loaded" << std::endl;
        return; 
    }
    
    sf::Texture texture;
    if (texture.loadFromFile(filename)) {
       textures_[key] = std::move(texture);
    } else {
        std::cerr << "Failed to load image: " << filename << std::endl;
        textures_[key] = defaultTexture_;
    }
}

const sf::Texture& ResourceManager::GetImage(const std::string& key) const {
    auto it =textures_.find(key);
    if (it !=textures_.end()) {
        return it->second;
    } else {
        std::cerr << "Texture not found: " << key << ". Using default texture." << std::endl;
        return defaultTexture_;
    }
}

void ResourceManager::LoadFont(const std::string& key, const std::string& filename) {
    if (fonts_.find(key) != fonts_.end()) {
        std::cerr << "Warning: The font " << key << " is already loaded" << std::endl;
        return; 
    }

    sf::Font font;
    if (font.loadFromFile(filename)) {
        fonts_[key] = std::move(font);
    } else {
        std::cerr << "Failed to load font: " << filename << std::endl;
        // Handle default font case or error
    }
}

const sf::Font& ResourceManager::GetFont(const std::string& key) const {
    auto it = fonts_.find(key);
    if (it != fonts_.end()) {
        return it->second;
    } else {
        std::cerr << "Font not found: " << key << ". Using default font." << std::endl;
        // Return default font or handle error
    }
}


void ResourceManager::LoadSoundBackground(const std::string& key, const std::string& filename) {
    if (sounds_background.find(key) != sounds_background.end()) {
        std::cerr << "Warning: The sound " << key << " is already loaded" << std::endl;
        return; 
    }

    sf::SoundBuffer sound;
    if (sound.loadFromFile(filename)) {
        sounds_background[key] = std::move(sound);
    } else {
        std::cerr << "Failed to load sound: " << filename << std::endl;
        // Handle default font case or error
    }
}

const sf::SoundBuffer& ResourceManager::GetSoundBackground(const std::string& key) const{
    auto it = sounds_background.find(key);
    if (it != sounds_background.end()) {
        return it->second;
    } else {
        std::cerr << "Sound not found: " << key << ". Using default sound." << std::endl;
        // Return default font or handle error
    }
}

void ResourceManager::LoadSoundStep(const std::string& key, const std::string& filename) {
    if (sounds_step.find(key) != sounds_step.end()) {
        std::cerr << "Warning: The sound " << key << " is already loaded" << std::endl;
        return; 
    }

    sf::SoundBuffer sound;
    if (sound.loadFromFile(filename)) {
        sounds_step[key] = std::move(sound);
    } else {
        std::cerr << "Failed to load sound: " << filename << std::endl;
        // Handle default font case or error
    }
}

const sf::SoundBuffer& ResourceManager::GetSoundStep(const std::string& key) const{
    auto it = sounds_step.find(key);
    if (it != sounds_step.end()) {
        return it->second;
    } else {
        std::cerr << "Sound not found: " << key << ". Using default sound." << std::endl;
        // Return default font or handle error
    }
}

void ResourceManager::LoadFromJson(const std::string& jsonFilePath) {
    std::ifstream file(jsonFilePath);
    
    if (!file.is_open()) {
        std::cerr << "Unable to open JSON file: " << jsonFilePath << std::endl;
        return;
    }

    nlohmann::json json;
    file >> json;

    for (const auto& item : json["background"]) {
        LoadImage(item["id"], item["path"]);
    }
    for (const auto& item : json["vehicle"]) {
        LoadImage(item["id"], item["path"]);
    }
    for (const auto& item : json["collectable"]) {
        LoadImage(item["id"], item["path"]);
    }
    for (const auto& item : json["obstacle"]) {
        LoadImage(item["id"], item["path"]);
    }
    for (const auto& item : json["font"]) {
        LoadFont(item["id"], item["path"]);
    }
    for (const auto& item : json["sound_background"]) {
        LoadSoundBackground(item["id"], item["path"]);
    }
    for (const auto& item : json["sound_step"]) {
        LoadSoundStep(item["id"], item["path"]);
    }
}