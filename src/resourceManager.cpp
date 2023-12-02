#include "./include/resourceManager.hpp"


ResourceManager::ResourceManager() {
    if (!defaultTexture_.loadFromFile("../img/runninggoat.png")) {
        std::cerr << "Failed to load default texture." << std::endl;
    }
}

ResourceManager::~ResourceManager() {}


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
}