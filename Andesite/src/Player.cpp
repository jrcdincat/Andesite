#include "pch.h"
#include "Player.h"
#include "InputManager.h"

Player::Player() {
	speed = std::make_tuple(0.0f, 0.0f);
	position = std::make_tuple(0.0f, 0.0f);
	gravity = 0.0f;
	health = 3;
}

void Player::setSpeed(float xSpeed, float ySpeed)
{
	std::get<0>(speed) = xSpeed; 
	std::get<1>(speed) = ySpeed;
}

std::tuple<float, float> Player::getSpeed()
{
	return speed;
}

void Player::update(){
	// update locations/events
	// update rendering
}