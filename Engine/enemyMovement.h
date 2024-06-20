#pragma once
#include "enemy.h"
#include "Graphics.h"
#include "Player.h"

class enemyMovement {
    enemy e;
    int x_min, y_min, x_max, y_max;

    bool vertical_checker_upward = false;
    bool vertical_checker_downward = true;
    bool horizontal_checker_forward = false;
    bool horizontal_checker_backward = false;

    bool vertical_checker_upward_cw = false;
    bool vertical_checker_downward_cw = false;
    bool horizontal_checker_forward_cw = true;
    bool horizontal_checker_backward_cw = false;

    bool vertical_checker_upward_h = false;
    bool vertical_checker_downward_h = false;
    bool horizontal_checker_forward_h = true;
    bool horizontal_checker_backward_h = false;

    bool vertical_checker_upward_v = false;
    bool vertical_checker_downward_v = true;
    bool horizontal_checker_forward_v = false;
    bool horizontal_checker_backward_v = false;

public:
    player* p = nullptr;  

    void set(int ex_min, int ey_min, int ex_max, int ey_max, enemy enemy) {
        x_min = ex_min;
        y_min = ey_min;
        x_max = ex_max;
        y_max = ey_max;
        e = enemy;
    }

    void moveAntiClockWise(Graphics& gfx) {
        e.drawEnemy(gfx);

        if (vertical_checker_downward) {
            e.vertical_movement_downward();
            if (e.y + e.radius >= y_max) {
                vertical_checker_downward = false;
                horizontal_checker_forward = true;
            }
        }
        else if (horizontal_checker_forward) {
            e.horizontal_movement_forward();
            if (e.x + e.radius >= x_max) {
                horizontal_checker_forward = false;
                vertical_checker_upward = true;
            }
        }
        else if (vertical_checker_upward) {
            e.vertical_movement_upward();
            if (e.y - e.radius <= y_min - 5) {
                vertical_checker_upward = false;
                horizontal_checker_backward = true;
            }
        }
        else if (horizontal_checker_backward) {
            e.horizontal_movement_backward();
            if (e.x - e.radius <= x_min - 5) {
                vertical_checker_downward = true;
                horizontal_checker_backward = false;
            }
        }
    }

    void moveClockWise(Graphics& gfx) {
        e.drawEnemy(gfx);
        if (horizontal_checker_forward_cw) {
            e.horizontal_movement_forward();
            if (e.x + e.radius >= x_max) {
                horizontal_checker_forward_cw = false;
                vertical_checker_downward_cw = true;
            }
        }
        else if (vertical_checker_downward_cw) {
            e.vertical_movement_downward();
            if (e.y + e.radius >= y_max) {
                vertical_checker_downward_cw = false;
                horizontal_checker_backward_cw = true;
            }
        }
        else if (horizontal_checker_backward_cw) {
            e.horizontal_movement_backward();
            if (e.x - e.radius <= x_min - 5) {
                horizontal_checker_backward_cw = false;
                vertical_checker_upward_cw = true;
            }
        }
        else if (vertical_checker_upward_cw) {
            e.vertical_movement_upward();
            if (e.y - e.radius <= y_min - 5) {
                vertical_checker_upward_cw = false;
                horizontal_checker_forward_cw = true;
            }
        }
    }

    void horizontal_movement(Graphics& gfx) {
        e.drawEnemy(gfx);

        if (horizontal_checker_forward_h) {
            e.horizontal_movement_forward();
            if (e.x + e.radius >= x_max) {
                horizontal_checker_forward_h = false;
                horizontal_checker_backward_h = true;
            }
        }
        else if (horizontal_checker_backward_h) {
            e.horizontal_movement_backward();
            if (e.x - e.radius <= x_min - 5) {
                horizontal_checker_forward_h = true;
                horizontal_checker_backward_h = false;
            }
        }
    }

    void vertical_movement(Graphics& gfx) {
        e.drawEnemy(gfx);

        if (vertical_checker_downward_v) {
            e.vertical_movement_downward();
            if (e.y + e.radius >= y_max) {
                vertical_checker_downward_v = false;
                vertical_checker_upward_v = true;
            }
        }
        else if (vertical_checker_upward_v) {
            e.vertical_movement_upward();
            if (e.y - e.radius <= y_min - 5) {
                vertical_checker_downward_v = true;
                vertical_checker_upward_v = false;
            }
        }
    }

    bool checkcollision() {
        if (p && (p->x + 5 >= e.x - e.radius && p->x - 5 <= e.x + e.radius && p->y + 11 >= e.y - e.radius && p->y - 5 <= e.y + e.radius)) {
            return true;
        }
        return false;
    }
};
