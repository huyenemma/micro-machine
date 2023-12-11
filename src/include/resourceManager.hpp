/**
 * @file ResourceManager.hpp
 * @brief ResourceManager class header.
 *
 * This file contains the definition of the ResourceManager class, which handles the loading,
 * storing, and accessing of game resources like images, fonts, and sounds.
 */

#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include "../../libs/nlohmann/json.hpp"
#include <iostream>
#include <fstream>

/**
 * @class ResourceManager
 * @brief Manages game resources including images, fonts, and sounds.
 *
 * The ResourceManager class is responsible for loading, storing, and providing access to various
 * game resources. It uses an internal mapping to link resource keys to their corresponding loaded resources.
 */
class ResourceManager {
public:
    /**
     * @brief Constructs a ResourceManager object.
     */
    ResourceManager();

    /**
     * @brief Destroys the ResourceManager object.
     */
    ~ResourceManager();
    
    /**
     * @brief Loads an image from a file and stores it with a given key.
     *
     * @param key A string to identify the image resource.
     * @param filename The file path of the image to load.
     */
    void LoadImage(const std::string& key, const std::string& filename);

    /**
     * @brief Retrieves an image resource by its key.
     *
     * @param key The string key of the image resource.
     * @return A reference to the sf::Texture object.
     */
    const sf::Texture& GetImage(const std::string& key) const;

    /**
     * @brief Loads a font from a file and stores it with a given key.
     *
     * @param key A string to identify the font resource.
     * @param filename The file path of the font to load.
     */
    void LoadFont(const std::string& key, const std::string& filename);

    /**
     * @brief Retrieves a font resource by its key.
     *
     * @param key The string key of the font resource.
     * @return A reference to the sf::Font object.
     */
    const sf::Font& GetFont(const std::string& key) const;

    /**
     * @brief Loads a background sound from a file and stores it with a given key.
     *
     * @param key A string to identify the sound resource.
     * @param filename The file path of the sound to load.
     */
    void LoadSoundBackground(const std::string& key, const std::string& filename);

    /**
     * @brief Retrieves a background sound resource by its key.
     *
     * @param key The string key of the sound resource.
     * @return A reference to the sf::SoundBuffer object.
     */
    const sf::SoundBuffer& GetSoundBackground(const std::string& key) const;

    /**
     * @brief Loads a step sound from a file and stores it with a given key.
     *
     * @param key A string to identify the step sound resource.
     * @param filename The file path of the sound to load.
     */
    void LoadSoundStep(const std::string& key, const std::string& filename);

    /**
     * @brief Retrieves a step sound resource by its key.
     *
     * @param key The string key of the step sound resource.
     * @return A reference to the sf::SoundBuffer object.
     */
    const sf::SoundBuffer& GetSoundStep(const std::string& key) const;

    /**
     * @brief Loads resources defined in a JSON configuration file.
     *
     * This method loads various resources specified in a JSON file, such as textures and sounds.
     *
     * @param jsonFilePath Path to the JSON file containing resource definitions.
     */
    void LoadFromJson(const std::string& jsonFilePath);

private:
    std::unordered_map<std::string, sf::Texture> textures_; ///< Stores loaded textures.
    std::unordered_map<std::string, sf::Font> fonts_; ///< Stores loaded fonts.
    std::unordered_map<std::string, sf::SoundBuffer> sounds_background; ///< Stores loaded background sounds.
    std::unordered_map<std::string, sf::SoundBuffer> sounds_step; ///< Stores loaded step sounds.
    sf::Texture defaultTexture_; ///< Default texture used as a fallback.
};

#endif // RESOURCEMANAGER_HPP
