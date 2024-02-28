#include "line.hpp"

#include <raymath.h>

namespace LINES {
Line::Line() :
    startPos({0.f,0.f}),
    endPos({0.f,0.f}),
    angle(0.f),
    radians(0.f),
    scale_factor(1.0f),
    swapped_left_right(false)
{}

Line::Line(
    Vector2 startPos,
    Vector2 endPos,
    float angle,
    float radians,
    float scale_factor,
    bool swapped_left_right
) :
    startPos(startPos),
    endPos(endPos),
    angle(angle),
    radians(radians),
    scale_factor(scale_factor),
    swapped_left_right(swapped_left_right)
{}

Line::Line(const Line &o) {*this=o;}
Line& Line::operator=(const Line &o) {
    this->startPos = o.startPos;
    this->endPos = o.endPos;
    this->angle = o.angle;
    this->radians = o.radians;
    this->scale_factor = o.scale_factor;
    this->swapped_left_right = o.swapped_left_right;
    return *this;
}
Line::~Line() {}

void Line::draw(
    float thickness,
    Color color
) {
    float radians = {thickness/2.f};

    DrawLineEx( 
        this->startPos,
        this->endPos,
        thickness,
        color
    );
    DrawCircleV(
        this->startPos,
        radians,
        color
    );
    DrawCircleV(
        this->endPos,
        radians,
        color
    );
    
    // DrawLineEx( 
    //     Vector2Subtract(offset,this->startPos),
    //     Vector2Subtract(offset,this->endPos),
    //     thickness,
    //     color
    // );
    // DrawCircleV(
    //     Vector2Subtract(offset,this->startPos),
    //     radians,
    //     color
    // );
    // DrawCircleV(
    //     Vector2Subtract(offset,this->endPos),
    //     radians,
    //     color
    // );
}

} // namespace LINES