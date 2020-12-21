#include "pch.h"
#include "Player.h"

Player::Player() {
	speed = std::make_tuple(0.0f, 0.0f);
	position = std::make_tuple(0.0f, 0.0f);
	gravity = 0.0f;
	health = 3; 
}

void Player::update(){
	// update locations/events
	// update rendering
}