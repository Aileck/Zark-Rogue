#include "Enemy.h"

Enemy::Enemy():Creature("NO ENEMY","NO ENEMY",0,0,0,0)
{
}

Enemy::Enemy(string name, string definition, int hp, int attack, int defense, int speed):Creature(name, definition, hp, attack,defense,speed) {
	SetHold(new Item());
}

void Enemy::SetHold(Item* hold)
{
	this->hold = hold;
}

Item* Enemy::DropHold() {
	return hold;
}

void Enemy::CheckIfDead()
{
	if (currentHP <= 0) {
		isDead = true;
		cout << this->GetName() << " is dead." << endl;
		AddDefinition("And it is already killed by you.");
		//if(hold.GetType() != Item::ty)
	}
}
