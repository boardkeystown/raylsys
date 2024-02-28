#include "linesmgr.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
// #include <cstdio>
#include <raymath.h>

namespace LINES {

// private

Line LinesMgr::computeLine(float distX, float distY) {
    this->currentLine.startPos = this->currentLine.endPos;
    this->currentLine.endPos.x = this->currentLine.startPos.x + (
        distX * this->currentLine.scale_factor
    );
    this->currentLine.endPos.y = this->currentLine.startPos.y + (
        distY * this->currentLine.scale_factor
    );

    float cos = std::cos(this->currentLine.radians);
    float sin = std::sin(this->currentLine.radians);

    float cx = this->currentLine.startPos.x;
    float cy = this->currentLine.startPos.y;
    // std::printf("%f,%f | ",cx,cy);
    
    float x = ((this->currentLine.endPos.x - cx) * cos) - ((this->currentLine.endPos.y - cy) * sin) + cx;
    float y = ((this->currentLine.endPos.x - cx) * sin) + ((this->currentLine.endPos.y - cy) * cos) + cy;
    this->currentLine.endPos.x = x;
    this->currentLine.endPos.y = y;
    // std::printf("%f,%f\n",this->currentLine.endPos.x,this->currentLine.endPos.x);

    if (this->currentLine.endPos.x < this->min_x) {
        this->min_x = this->currentLine.endPos.x;
    }
    if (this->currentLine.endPos.y < this->min_y) {
        this->min_y = this->currentLine.endPos.y;
    }
    if (this->currentLine.endPos.x > this->max_x) {
        this->max_x = this->currentLine.endPos.x;
    }
    if (this->currentLine.endPos.y > this->max_y) {
        this->max_y = this->currentLine.endPos.y;
    }

    return this->currentLine;
}

// public
LinesMgr::LinesMgr() :
    min_x(0.f),
    min_y(0.f),
    max_x(0.f),
    max_y(0.f)
{}
LinesMgr::~LinesMgr() {}

void LinesMgr::changeAngle(float angle) {
    constexpr const float RADC = {M_PI / 180.0f};
    this->currentLine.angle = std::fmod((this->currentLine.angle + angle),360);
    this->currentLine.radians = RADC * this->currentLine.angle;
}
void LinesMgr::forward(float distX, float distY) {
    Line line = this->computeLine(distX,distY);
    this->lines.push_back(line);
}
void LinesMgr::move(float distX, float distY) {
    Line _ = this->computeLine(distX,distY);
}
void LinesMgr::setOrigen(Vector2 origen) {
    this->currentLine.endPos=origen;
}

void LinesMgr::pushStack() {
    this->stack.push(this->currentLine);
}

void LinesMgr::popStack() {
    if (this->stack.size()) {
        this->currentLine = this->stack.top();
        this->stack.pop();
    }
}

bool LinesMgr::isSwappedLeftRight() {
    bool result = this->currentLine.swapped_left_right;
    return result;
}

void LinesMgr::swapRightLeft() {
    this->currentLine.swapped_left_right = 
        (this->currentLine.swapped_left_right) ? 
        false : true;
}

Vector2 LinesMgr::getSize() {
    return Vector2 {
        (std::abs(this->min_x)+this->max_x)*4.f,
        (std::abs(this->min_y)+this->max_y)*4.f
    };
}

void LinesMgr::clear() {
    this->lines.clear();
    this->currentLine = Line();
    this->stack = std::stack<Line>{};
}


} // namespace LINES