#ifndef MY_CONTACT_LISTENER_HPP
#define MY_CONTACT_LISTENER_HPP

#include <Box2D/Box2D.h>
#include <vector>
#include "userDataPointer.hpp"

/**
 * @class MyContactListener
 * @brief A custom contact listener class for handling Box2D contact events.
 */
class MyContactListener : public b2ContactListener {
public:
    /**
     * @brief Default constructor for MyContactListener.
     */
    MyContactListener();

    /**
     * @brief Called when two fixtures start to touch.
     * @param contact The contact object containing information about the contact.
     */
    void BeginContact(b2Contact* contact) override;

    /**
     * @brief Called when two fixtures cease to touch.
     * @param contact The contact object containing information about the contact.
     */
    void EndContact(b2Contact* contact) override;

    /**
     * @brief Destructor for MyContactListener.
     */
    ~MyContactListener();

private:
    /**
     * @struct ContactData
     * @brief Structure containing information about the contacting bodies.
     */
    struct ContactData {
        b2Body* bodyA; ///< Pointer to the first body in contact.
        b2Body* bodyB; ///< Pointer to the second body in contact.
    };

    std::vector<ContactData> contactsToDelete; ///< List of contacts to be deleted.

    /**
     * @brief Handles the contact event.
     * @param contact The contact object containing information about the contact.
     * @param begin True if it's the beginning of the contact, false if it's the end.
     */
    void HandleContact(b2Contact* contact, bool begin);
};

#endif // MY_CONTACT_LISTENER_HPP
