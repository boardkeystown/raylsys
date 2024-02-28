#pragma once
#include <raylib.h>
#include <functional>
#include <string>
namespace UI {
class Button {
private:
    Rectangle position;
    Color defaultColor;
    Color color;
    Color hoverColor;
    std::string text;
    int fontSize;
    Color fontColor;
    bool clicked;
    std::function<void()> callBack;
private:
    bool isHover();
    bool isClicked();
public:
    Button();
    ~Button();
    void input();
    void update();
    void render();
public:
    void setRectangle(
        float x,
        float y,
        float width,
        float height
    );
    void setPosition(
        float x,
        float y
    );
    void setSize(
        float width,
        float height
    );
    void setText(std::string text);
    void setFontSize(int fontSize);
    int getFontSize();
    void setFontColor(Color color);
    void setColor(Color color);
    void setHoverColor(Color color);
    void setCallBack(std::function<void()> callBack);
    int getTextWidth();
};
} // namespace UI
