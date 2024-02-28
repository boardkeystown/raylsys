#include "followrules.hpp"
#include "symbol.hpp"

namespace LSYS {
void followRules(
    LINES::LinesMgr &lineMgr,
    const std::string &rules,
    const std::array<float,2> length,
    const float angle
) {
    auto [distX,distY] = length;
    for (char symbol : rules) {
        switch (symbol) {
        case symbol::FORWARD_F:
            lineMgr.forward(distX,distY);
            break;
        case symbol::FORWARD_G:
            lineMgr.forward(distX,distY);
            break;
        case symbol::FORWARD_INVIABLE_F:
            lineMgr.move(distX,distY);
            break;
        case symbol::FORWARD_INVIABLE_G:
            lineMgr.move(distX,distY);
            break;
        case symbol::TURN_RIGHT:
            if (!lineMgr.isSwappedLeftRight()) {
                lineMgr.changeAngle(angle);
            } else {
                lineMgr.changeAngle(-angle);
            }
            break;
        case symbol::TURN_LEFT:
            if (!lineMgr.isSwappedLeftRight()) {
                lineMgr.changeAngle(-angle);
            } else {
                lineMgr.changeAngle(angle);
            }
            break;
        case symbol::SWAP_RIGHT_LEFT:
            lineMgr.swapRightLeft();
            break;
        case symbol::REVERSE_DIRECTION:
            lineMgr.changeAngle(-180.f);
            break;
        case symbol::PUSH_STACK:
            lineMgr.pushStack();
            break;
        case symbol::POP_STACK:
            lineMgr.popStack();
            break;
        case symbol::DRAW_DOT:
            // TODO
            break;
        case symbol::DECREMENT_ANGLE:
            // TODO
            break;
        case symbol::INCREMENT_ANGLE:
            // TODO
            break;
        case symbol::SCALE_FACTOR_DIV:
            // TODO
            break;
        case symbol::SCALE_FACTOR_MUL:
            // TODO
            break;
        default:
            /*do nothing!*/
            break;
        }
    }
}

} // namespace LSYS
