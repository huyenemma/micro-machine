#ifndef BUFF_VECTOR_HPP
#define BUFF_VECTOR_HPP

#include "buff.hpp"

class BuffVector {
private:
    std::vector<Buff*> buffs;

public:
    void Update(){
        //apply buff for existing buff and decrease the remaining duration
        for (auto it = buffs.begin(); it != buffs.end();) {
            Buff* buff = *it;

            buff->ApplyEffect();
            
            if (buff->Tick() <= 0) {
                // Remove the buff if its duration is zero or negative
                it = buffs.erase(it);
                delete buff; // Assuming Buff objects are created with new in Buff constructor
            } else {
                // Move to the next buff
                ++it;
            }
        }
    }

    void AddBuff(Buff* buff){
        buffs.push_back(buff);
    }


};
#endif