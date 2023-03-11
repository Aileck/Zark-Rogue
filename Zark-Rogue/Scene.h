#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <tuple>

#include "Checkeable.h";
#include "Enemy.h";
#include "Item.h";
#include "Weapon.h";

class Scene : public Checkeable {
public:
    Scene();
    Scene(string name, string definition, int id);

    int GetSceneID();
    void AddEnemy(Enemy* enemy);
    void AddItem(Item* item);
    void AddWeapon(Weapon* weapon);
    void SetLock(bool ifIsLocked);
    void SetHidden(bool ifIsHidden);
    bool isLocked();
    bool isHidden();
    void SetConnections(Scene* n, Scene* w, Scene* s, Scene* e, Scene* h);
    Checkeable* IfContains(string target);
    int CheckDestination(string target);

    void BeCheked();

private:
    int id;
    vector<Enemy*> enemies;
    vector<Item*> items;
    vector<Weapon*> weapons;
    bool locking;
    bool hiding;
    bool visited;
    /*
         N
         |
       W-+-E
         |
         S
       */
    Scene* north;
    Scene* east;
    Scene* west;
    Scene* south;
    Scene* hidden;
};



#endif