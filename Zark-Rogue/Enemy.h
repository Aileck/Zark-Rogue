#ifndef CAT_H
#define CAT_H

#include "creature.h"


class Enemy : public Creature {
public:
 
    Enemy(string name,string definition, int hp, int attack, int defense, int speed);

};

#endif