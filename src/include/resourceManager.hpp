#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();

    void LoadImage(const std::string& key, const std::string& filename);
    const sf::Texture& GetImage(const std::string& key) const;

private:
    std::unordered_map<std::string, sf::Texture> textures;
};

#endif // RESOURCEMANAGER_HPP
