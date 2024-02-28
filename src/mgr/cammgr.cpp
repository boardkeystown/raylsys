#include "cammgr.hpp"
#include <raymath.h>

namespace MGR {

CamMgr::CamMgr(
    Vector2 world_size, 
    Vector2 screen_size
) {
    this->isPanning = false;
    this->panStartWorldPos = {
        0.0f,
        0.0f,
    };
    this->camera.target = Vector2 {
        world_size.x / 2.0f,
        world_size.y / 2.0f
    };
    this->camera.offset = Vector2 {
        screen_size.x / 2.0f,
        screen_size.y / 2.0f,
    };
    this->camera.rotation = 0.f;
    this->camera.zoom = 1.0f;
}
CamMgr::~CamMgr() {}

void CamMgr::update() {
    // keys
    if (IsKeyDown(KEY_RIGHT)) this->camera.target.x += 10;
    if (IsKeyDown(KEY_LEFT)) this->camera.target.x -= 10;
    if (IsKeyDown(KEY_UP)) this->camera.target.y -= 10;
    if (IsKeyDown(KEY_DOWN)) this->camera.target.y += 10;
    // mouse zoom
    this->camera.zoom += GetMouseWheelMove() * 0.05f;
    this->camera.zoom = (this->camera.zoom > 0.1f) ? this->camera.zoom : 0.1f;
    // mouse pan
    if (!this->isPanning && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();
        this->panStartWorldPos = GetScreenToWorld2D(mousePos,this->camera);
        this->isPanning = true;
    }
    if (this->isPanning && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();
        Vector2 currentWorldPos = GetScreenToWorld2D(mousePos,this->camera);
        Vector2 panDelta = Vector2Subtract(this->panStartWorldPos,currentWorldPos);
        this->camera.target = Vector2Add(this->camera.target,panDelta);
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        this->isPanning = false;
    }
}

// void CamMgr::draw() {
//     BeginMode2D(this->camera);
//     this->drawFunc();
//     EndMode2D();
// }

}