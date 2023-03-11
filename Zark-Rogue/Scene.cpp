#include "Scene.h"

Scene::Scene():Checkeable("No way", "No way")
{
	//Dead end scene
	id = 0;
}

void Scene::BeCheked() {
	Checkeable::BeCheked();
	if (this->GetCheckTime() == 1) {
		cout << GetBasicDefinition() << endl;
	}
}

Scene::Scene(string name, string definition, int id) :Checkeable(name, definition)
{
	this->id = id;

	//If is locked by a key
	this->locking = false;
	this->visited = false;

	//Initialy wihout any connection, to be set later
	SetConnections(new Scene(), new Scene(), new Scene(), new Scene(), new Scene());
}

int Scene::GetSceneID() {
	return this->id;
}

void Scene::AddEnemy(Enemy* enemy)
{
    enemies.push_back(enemy);
}

void Scene::AddItem(Item* item)
{
    items.push_back(item);
}

void Scene::AddWeapon(Weapon* weapon)
{
    weapons.push_back(weapon);
}


void Scene::SetLock(bool ifIsLocked)
{
	locking = ifIsLocked;
}

void Scene::SetHidden(bool ifIsHidden)
{
	this->hiding = ifIsHidden;
}

bool Scene::isLocked()
{
	return this->locking;
}

bool Scene::isHidden()
{
	return this->hiding;
}


Checkeable* Scene::IfContains(string target)
{
    // To deal check object action, check if this scene contain...

    // Enemy
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies.at(i)->GetName(true) == target) {
            enemies.at(i)->BeCheked();
            return enemies.at(i);
        }
    }

    // Item
    for (int i = 0; i < items.size(); i++) {
        if (items.at(i)->GetName(true) == target) {
            return items.at(i);
        }
    }

    // Weapon
    for (int i = 0; i < weapons.size(); i++) {
        if (weapons.at(i)->GetName(true) == target) {
            weapons.at(i)->BeCheked();
            return weapons.at(i);
        }
    }

    Checkeable* notfound = new Checkeable();
    return notfound;
}

void Scene::SetConnections(Scene* n, Scene* w, Scene* s, Scene* e, Scene* h)
{
    //Set 4 connections and a hidden room if exists
    this->north = n;
    this->east = e;
    this->south = s;
    this->west = w;

    this->hidden = h;

    //We are declaring that h is hidden room
    if (h->GetSceneID() != 0) {
        h->SetHidden(true);
    }
}

int Scene::CheckDestination(string target) {
    //To deal goto action
    if (target == "north" || target == "n") {
        return north->GetSceneID();
    }

    if (target == "west" || target == "w") {
        return west->GetSceneID();
    }

    if (target == "south" || target == "s") {
        return south->GetSceneID();
    }

    if (target == "east" || target == "e") {
        return east->GetSceneID();
    }

    if (target == "hidden" || target == "h") {
        return hidden->GetSceneID();
    }

    else
        return -1;
}
