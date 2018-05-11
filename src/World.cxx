// src/World.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/World.hxx"

#include <vector>

#include "../include/kinggame/Player.hxx"
#include "../include/kinggame/Room.hxx"

kinggame::World::World() {}

kinggame::World::~World() {}

kinggame::World::World(std::vector<Room> rooms) : rooms_(rooms) {}

void kinggame::World::set_player(kinggame::Player player) {
  this->p1_ = &player;
}
