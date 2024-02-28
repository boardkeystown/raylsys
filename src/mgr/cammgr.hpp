#pragma once
#include <raylib.h>
// #include <functional>
namespace MGR {
class CamMgr {
private:
    bool isPanning;
    Vector2 panStartWorldPos;
public:
    Camera2D camera;
    // std::function<void()> drawFunc;
public:
    CamMgr(Vector2 world_size,
           Vector2 screen_size);
    ~CamMgr();
public:
    void update();
    // void draw();
};

} // namespace name
