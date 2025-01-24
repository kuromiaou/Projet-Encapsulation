#pragma once
#include "Objects.h"
class Key :
    public Objects
{
private:
public:
    Key(Vector2i,Texture);
    void interact(Player& player) override;
};

