#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "box2dInclude.hpp"
#include "vehicle.hpp"
#include <SFML/Graphics.hpp>  // Include SFML graphics header
#include "userDataPointer.hpp"
#include "vehicle.hpp"
#include "buff.hpp"

using namespace BodyType;

class Collectable : public sf::Drawable {
public:
    Collectable(b2World* world, b2Vec2 position, float radius, Buff* buff);

    std::pair<float, float> GetPosition() const;
    
    void DeleteBody();

    float GetRadius();

    bool IsNullBody();

    void setDelete();

    bool getDelete();
    
    virtual void OnContact(Vehicle* car);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    mutable sf::Sprite sprite;
    sf::Texture texture;  // Declare texture as a member
    Buff* buff;
    b2Body* body;
    float radius_;  
    bool  toBeDeleted = false;
};

#endif
