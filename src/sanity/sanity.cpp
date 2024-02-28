#include "sanity.hpp"

#include <raylib.h>

#include "mgr/rtexture.hpp"
#include "mgr/cammgr.hpp"

#include "lines/line.hpp"
#include "lines/linesmgr.hpp"

#include "lsys/readjson.hpp"
#include "lsys/rule.hpp"
#include "lsys/ruleset.hpp"
#include "lsys/expandlsys.hpp"
#include "lsys/followrules.hpp"

#include "ui/menubar.hpp"
#include "ui/button.hpp"

#include "utils/dialog/openFileDialog.hpp"

Sanity::Sanity() {}
Sanity::~Sanity() {
    CloseWindow();
}
void Sanity::run() {
    Vector2 screen_size {
        1020.f,
        720.f
    };
    InitWindow(
        static_cast<int>(screen_size.x),
        static_cast<int>(screen_size.y),
        "Sanity");
    SetTargetFPS(60);
    MGR::CamMgr cam(
    screen_size,
    screen_size
    );
    std::string file{".\\rulesets\\test.json"};
    LSYS::Ruleset ruleset = LSYS::readJson(file);
    std::string rules = LSYS::expandlsys(
        ruleset.iterations,
        ruleset.axiom,
        ruleset.rules
    );
    LINES::LinesMgr linesMgr;
    LSYS::followRules(
        linesMgr,
        rules,
        ruleset.length,
        ruleset.angle
    );
    UI::Button button;
    button.setText("OPEN RULESET");
    button.setFontSize(12);
    button.setRectangle(
        0,
        0,
        button.getTextWidth(),
        20
    );
    button.setCallBack([&linesMgr](){
        std::string fp = Utils::Dialog::OpenFileDialog();
        std::printf("clicked!\n");
        std::printf("%s\n",fp.c_str());
        if (fp.size()) {
            linesMgr.clear();
            LSYS::Ruleset ruleset = LSYS::readJson(fp);
            std::string rules = LSYS::expandlsys(
                ruleset.iterations,
                ruleset.axiom,
                ruleset.rules
            );
            LSYS::followRules(
                linesMgr,
                rules,
                ruleset.length,
                ruleset.angle
            );
    }

    });
    UI::Menubar menu;
    menu.setRectangle(
        0,
        0,
        GetScreenWidth(),
        20
    );
    menu.setColor(RED);
    menu.appendButton(button);
    auto IsLineInView =[](const LINES::Line& line, const Camera2D& camera) {
        // Adjust viewport calculation for camera zoom and offset
        float halfScreenWidth = GetScreenWidth() / 2.0f;
        float halfScreenHeight = GetScreenHeight() / 2.0f;
        float viewportWidth = halfScreenWidth / camera.zoom;
        float viewportHeight = halfScreenHeight / camera.zoom;
        float left = camera.target.x - viewportWidth;
        float top = camera.target.y - viewportHeight;
        float right = camera.target.x + viewportWidth;
        float bottom = camera.target.y + viewportHeight;
        // Check if any of the line's endpoints are within the viewport
        bool startInViewport = (
            line.startPos.x >= left && line.startPos.x <= right && 
            line.startPos.y >= top && line.startPos.y <= bottom
        );
        bool endInViewport = (
            line.endPos.x >= left && line.endPos.x <= right && 
            line.endPos.y >= top && line.endPos.y <= bottom
        );
        return startInViewport || endInViewport;
    };
    while (!WindowShouldClose()) {
        // input
        menu.input();
        // update
        cam.update();
        menu.update();
        // render
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(cam.camera);
        for (auto &line : linesMgr.lines) {
            if (IsLineInView(line,cam.camera))
                line.draw(5.f);
        }
        EndMode2D();
        menu.render();
        EndDrawing();
    }
}