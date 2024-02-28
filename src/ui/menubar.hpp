#pragma once
#include <raylib.h>
#include <vector>
#include "button.hpp"
namespace UI {
class Menubar {
private:
    Rectangle position;
    Color color;
    std::vector<Button> buttons;
public:
    Menubar(/* args */);
    ~Menubar();
    void input();
    void update();
    void render();
    void setRectangle(
        float x,
        float y,
        float width,
        float height
    );
    void setColor(Color color);
    void appendButton(Button button);
};
} // namespace UI