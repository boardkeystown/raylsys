#pragma once
#include <functional>
#include <raylib.h>

namespace MGR {
class Rtexture {
private:
    RenderTexture2D texture;
public:
    Rtexture(int width, int height);
    ~Rtexture();
    void buildTexture(std::function<void()> mkTexture);
    void draw();
};

}