#include "./include/resourceManager.hpp"


ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() {}


void ResourceManager::LoadImage(const std::string& key, const std::string& filename) {
    sf::Texture texture;
    if (texture.loadFromFile(filename)) {
        textures[key] = std::move(texture);
    } else {
        std::cerr << "Failed to load image: " << filename << std::endl;
    }
}

const sf::Texture& ResourceManager::GetImage(const std::string& key) const {
    auto it = textures.find(key);
    if (it != textures.end()) {
        return it->second;
    } else {
        throw std::runtime_error("Texture not found: " + key);
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

    for (const auto& item : json["map"]) {
        LoadImage(item["id"], item["texturePath"]);
    }

    for (const auto& item : json["vehicle"]) {
        LoadImage(item["id"], item["texturePath"]);
    }
    for (const auto& item : json["collectable"]) {
        LoadImage(item["id"], item["texturePath"]);
    }
    for (const auto& item : json["obstacle"]) {
        LoadImage(item["id"], item["texturePath"]);
    }
}