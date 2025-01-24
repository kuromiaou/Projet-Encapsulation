#pragma once
#include "Objects.h"
class Potion :
    public Objects
{
private:
public:
    Potion(Vector2i,Texture&);
    void interact(Player& player) override;
};