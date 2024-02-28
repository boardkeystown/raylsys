#include "button.hpp"
namespace UI {
// private
bool Button::isHover() {
    bool result = false;
    Vector2 mousePos = GetMousePosition();
    result = CheckCollisionPointRec(mousePos,this->position);
    return result;
}
bool Button::isClicked() {
    bool result = false;
    result = (
        isHover() &&
        IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
    );
    return result;
}
// public
Button::Button() {
    this->clicked = false;
    this->fontColor = BLACK;
    this->color = GREEN;
    this->hoverColor = YELLOW;
    this->defaultColor = GREEN;
    this->callBack = []() {/*do nothing*/};
}
Button::~Button() {}
void Button::input() {
    if (this->isClicked()) {
        this->clicked = true;
    }
    if (this->isHover()) {
        this->defaultColor = this->hoverColor;
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    } else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        this->defaultColor = this->color;
    }
}
void Button::update() {
    if (this->clicked) {
        this->callBack();
        this->clicked = false;
    }
}
void Button::render() {
    DrawRectangleRec(
        this->position,
        this->defaultColor
    );
    DrawText(
        this->text.c_str(),
        this->position.x,
        this->position.y + (static_cast<float>(this->fontSize) / 2.f),
        this->fontSize,
        this->fontColor
    );
}

void Button::setRectangle(
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
void Button::setPosition(
    float x,
    float y
) {
    this->position.x = x;
    this->position.y = y;
}
void Button::setSize(
    float width,
    float height
) {
    this->position.width = width;
    this->position.height = height;
}
void Button::setText(std::string text) {
    this->text = text;
}
void Button::setFontSize(int fontSize) {
    this->fontSize = fontSize;
}
int Button::getFontSize() {
    return this->fontSize;
}
void Button::setFontColor(Color color) {
    this->fontColor = color;
}
void Button::setColor(Color color) {
    this->color = color;
}
void Button::setHoverColor(Color color) {
    this->hoverColor = color;
}
void Button::setCallBack(std::function<void()> callBack) {
    this->callBack = callBack;
}
int Button::getTextWidth() {
    int result = 0;
    result = MeasureText(
        this->text.c_str(),
        this->fontSize
    );
    return result;
}

} // namespace UI
