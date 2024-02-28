#include "menubar.hpp"
namespace UI {
// private
// public 
Menubar::Menubar(/* args */) {}
Menubar::~Menubar() {}
void Menubar::input() {
    for (auto &btn : this->buttons) {
        btn.input();
    }
}
void Menubar::update() {
    for (auto &btn : this->buttons) {
        btn.update();
    }
}
void Menubar::render() {
    DrawRectangleRec(
        this->position,
        this->color
    );
    for (auto &btn : this->buttons) {
        btn.render();
    }
}
void Menubar::setRectangle(
    float x,
    float y,
    float width,
    float height
) {
    this->position = Rectangle {
        x,
        y,
        width,
        height
    };
} 
void Menubar::setColor(Color color) {
    this->color = color;
}
void Menubar::appendButton(Button button) {
    this->buttons.emplace_back(button);
}
} // namespace UI
