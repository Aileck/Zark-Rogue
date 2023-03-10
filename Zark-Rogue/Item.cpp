#include "Item.h"


Item::Item() :Checkeable("NO ITEM","NO ITEM") {
    this->type = NO_ITEM;
    this->location = CONSUMED;
}

Item::Item(string name, string description, ItemType type, bool inFloor):Checkeable(name, description)
{
    this->type = type;
    if (inFloor) {
        this->location = FLOOR;
    }
    else {
        this->location = INVENTORY;
    }
}

void Item::BeCheked()
{
    cout << this->GetBasicDefinition() << endl;
    cout << endl;
}

Item::ItemType Item::GetType()
{

    return this->type;
}

Item::ItemLocation Item::GetLocation()
{
    return this->location;
}

void Item::BePicked()
{
    location = INVENTORY;
}

void Item::BeDropped(){
    location = FLOOR;
}

void Item::BeConsumed()
{
    this->SetNameAndDefinition("Bottle", "It was a potion, but you've already finished drinking it. Maybe you can drop it.");
    this->type = BOTTLE;
}

int Item::GetUseTime()
{
    return useTime;
}

void Item::BeUsed()
{
    useTime++;
}

//string Item::BeUsed(World w)
//{
//    string out = "You tried to the ";
//
//    switch (this->type)
//    {
//    case Potion:
//        out += "the *potion*";
//
//        break;
//    case MAP:
//        out += "the *map*";
//        break;
//    case KEY:
//        out += "the *key*";
//        break;
//    case WEAPON:
//        out += "this is an errrrrrrrrrrrro";
//        break;
//    default:
//        break;
//    }
//
//    return out;
//}
