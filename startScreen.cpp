#include "startScreen.h"
startScreen::startScreen() {
    start_font.loadFromFile("Assets/Font/pixel.ttf");
    start_text.setFont(start_font);
    bind_text.setFont(start_font);
    up_text.setFont(start_font);
    down_text.setFont(start_font);
    right_text.setFont(start_font);
    left_text.setFont(start_font);
    play_text.setFont(start_font);
    leave_text.setFont(start_font);
    interact_text.setFont(start_font);
    start_text.setFillColor(Color::Green);
    bind_text.setFillColor(Color::Green);
    up_text.setFillColor(Color::Green);
    down_text.setFillColor(Color::Green);
    right_text.setFillColor(Color::Green);
    left_text.setFillColor(Color::Green);
    play_text.setFillColor(Color::Green);
    leave_text.setFillColor(Color::Green);
    interact_text.setFillColor(Color::Green);
    start_text.setString("Escape The Cubes.");
    bind_text.setString("Binds :");
    up_text.setString("Up : Z");
    down_text.setString("Down : S");
    right_text.setString("Right : D");
    left_text.setString("Left : Q");
    play_text.setString("Play : Enter or Space");
    leave_text.setString("Leave : Escape");
    interact_text.setString("Interact : E");
    start_text.setPosition(width / 2-200, 100);
    bind_text.setPosition(width / 2 - 300, 250);
    up_text.setPosition(width / 2 - 300, 350);
    down_text.setPosition(width / 2 - 300, 400);
    right_text.setPosition(width / 2 - 100, 400);
    left_text.setPosition(width / 2 - 500, 400);
    interact_text.setPosition(width / 2 +200, 375);
    play_text.setPosition(width / 2 +175, 500);
    leave_text.setPosition(width / 2+175, 600); 
}
void startScreen::show() {
    Level* level = new Level;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();

        window.draw(start_text);
        window.draw(bind_text);
        window.draw(up_text);
        window.draw(down_text);
        window.draw(right_text);
        window.draw(left_text);
        window.draw(interact_text);
        window.draw(leave_text);
        window.draw(play_text);

        if (Keyboard::isKeyPressed(Keyboard::Enter) or Keyboard::isKeyPressed(Keyboard::Space)) {
            level->level0();
            delete level;
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        window.display();
    }
    
}