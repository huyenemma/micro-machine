#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "box2dInclude.hpp"
#include "vehicle.hpp"
#include <SFML/Graphics.hpp>  
#include "userDataPointer.hpp"
#include "vehicle.hpp"
#include "buff.hpp"
#include "constant.hpp"
#include <SFML/Audio.hpp>

using namespace BodyType;

class Collectable : public sf::Drawable {
public:
    Collectable(b2World* world, b2Vec2 position, float radius, Buff* buff, const sf::Texture& texture);

    std::pair<float, float> GetPosition() const;
    
    void DeleteBody();

    float GetRadius();

    bool IsNullBody();

    void setDelete();

    bool getDelete();
    
    void OnContact(Vehicle* car);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    mutable sf::Sprite sprite_;
    sf::Texture texture_;  
    Buff* buff;
    b2Body* body;
    float radius_;  
    bool  toBeDeleted = false;

    sf::SoundBuffer hitBuffer;
    sf::Sound hit;

};

#endif
