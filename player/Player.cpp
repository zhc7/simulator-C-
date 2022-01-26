//
// Created by zhc7 on 2022/1/22.
//

#include "Player.h"

Player::Player(const World &world) {

}

void Player::draw(World &world) {
    for (auto &e: world.entities) {
        e.draw(&canvas);
    }
}

void Player::play(vector<World> &worlds) {
    for (auto &w:worlds) {
        draw(w);
    }
}