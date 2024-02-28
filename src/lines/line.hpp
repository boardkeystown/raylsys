#pragma once
#include<raylib.h>
namespace LINES {

struct Line {
    Vector2 startPos;
    Vector2 endPos;
    float angle;
    float radians;
    float scale_factor;
    bool swapped_left_right;
    Line();
    Line(
        Vector2 startPos,
        Vector2 endPos,
        float angle,
        float radians,
        float scale_factor,
        bool swapped_left_right
    );
    Line(const Line &o);
    Line& operator=(const Line &o);
    ~Line();
    void draw(
        float thickness, 
        Color color=GREEN
    );
};

} // namespace LINES


