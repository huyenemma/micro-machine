#include "./include/resourceManager.hpp"
#include <iostream>

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
