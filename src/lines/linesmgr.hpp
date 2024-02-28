#pragma once

#include <vector>
#include <stack>
#include <raylib.h>
#include "line.hpp"

namespace LINES {

class LinesMgr {

private:
    float min_x;
    float min_y;
    float max_x;
    float max_y;
    std::stack<Line> stack;
public:
    std::vector<Line> lines;
private:
    Line currentLine;
private:
    Line computeLine(float distX, float distY);
public:
    LinesMgr();
    ~LinesMgr();
    void changeAngle(float angle);
    void forward(float distX, float distY);
    void move(float distX, float  distY);
    void setOrigen(Vector2 origen);
    void pushStack();
    void popStack();
    bool isSwappedLeftRight();
    void swapRightLeft();
    Vector2 getSize();
    void clear();
};

} // namespace LINES
