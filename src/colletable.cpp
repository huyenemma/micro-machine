#include "collectable.hpp"

Collectable::Collectable(b2World* world, b2Vec2 position, float radius) : radius_(radius){
    // Define the collectable's shape
    b2CircleShape shape;
    shape.m_radius = radius;

    // Define the collectable's body definition
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(position.x, position.y);

    // Create the collectable's body
    body = world->CreateBody(&bodyDef);

    // Create the fixture for the collectable
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.isSensor = true; // Make the fixture a sensor to trigger contact without collision

    body->CreateFixture(&fixtureDef);

    // Set a custom user data to identify the collectable
    //b2BodyUserData data = body->GetUserData();
    //uintptr_t uintptrValue = reinterpret_cast<uintptr_t>(this);
    //data.pointer = uintptrValue;
    UserData* data = new UserData(); // Allocate UserData on the heap
    data->info.type = UserType::Collectable;
    data->info.pointer = this;
    body->GetUserData().pointer = reinterpret_cast<uintptr_t>(data); 
}


std::pair<float, float> Collectable::GetPosition(){
    b2Vec2 position = body->GetWorldCenter();
    return std::make_pair(position.x, position.y);
}


void Collectable::DeleteBody() {
    if((body != nullptr) && toBeDeleted) {
        std::cout<<"Deleted"<<std::endl;
        body->GetWorld()->DestroyBody(body);
        body =nullptr;
    }
}

float Collectable::GetRadius(){ return radius_; }

bool Collectable::IsNullBody(){ return body == nullptr; }

void Collectable::setDelete(){ toBeDeleted = true; }

bool Collectable::getDelete(){ return toBeDeleted; }