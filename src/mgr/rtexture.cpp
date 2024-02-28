#include "rtexture.hpp"
namespace MGR {

Rtexture::Rtexture(int width, int height) {
    this->texture = LoadRenderTexture(width,height);
}
Rtexture::~Rtexture() {
    UnloadRenderTexture(this->texture);
}

void Rtexture::buildTexture(std::function<void()> mkTexture) {
    BeginTextureMode(this->texture);
    mkTexture();
    EndTextureMode();
}
void Rtexture::draw() {
    DrawTextureRec(
        this->texture.texture,
        Rectangle{
            0,0,
            static_cast<float>(this->texture.texture.width),
            -static_cast<float>(this->texture.texture.height)},
            Vector2{0,0},
            WHITE
    );
}

}