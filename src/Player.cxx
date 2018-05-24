// src/Player.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Player.hxx"

#include <iostream>
#include <string>
#include <vector>

#include "../include/kinggame/Obj.hxx"
#include "../include/kinggame/World.hxx"

kinggame::Player::Player() : curr_room_(nullptr), hp_(100), inventory_{} {}

void kinggame::Player::set_world(kinggame::World &world) {
  this->world_ = &world;
  this->curr_room_ = this->world_->get_room(0);
}

inline int kinggame::Player::hp() { return this->hp_; }

inline std::string kinggame::Player::name() { return this->name_; }

void kinggame::Player::set_name(std::string name) { this->name_ = name; }

void kinggame::Player::action(std::string cmd) {
  if (cmd == "l") {
    this->look();
  } else if (this->curr_room_->has_path(cmd)) {
    this->move(cmd);
  } else {
    std::cout << "Action not recognized.\n";
  }
}

/*void kinggame::Player::action(std::string verb, std::string obj) {
  if (true) {

  } else {
    std::cout << "Action not recognized.\n";
  }
}*/

/*void kinggame::Player::action(std::string verb, std::string obj,
                              std::string prep, std::string obj2) {}*/

void kinggame::Player::look() { std::cout << this->curr_room_->info(); }

void kinggame::Player::move(std::string direction) {
  this->curr_room_ = this->curr_room_->get_path(direction)->link();
  this->look();
}

// void kinggame::Player::take(std::string obj) {}
