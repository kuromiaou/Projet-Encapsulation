#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Manager.h"
#include "Level.h"
class startScreen
{
private:
public:
	startScreen();
	Font start_font;
	Text start_text, bind_text,up_text,down_text,left_text,right_text,leave_text,play_text,interact_text;
	void show();
};

