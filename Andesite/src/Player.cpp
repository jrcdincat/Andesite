#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TextureManager.h"

Player::Player(Properties* properties) {
	row = 0;
	frameCount = 8;
	animationSpeed = 80;
	height = properties->height;
	width = properties->height;
	textureID = properties->textureID;
	position = properties->position;
	renderFlip = properties->renderFlip;
	speed = std::make_tuple(0.0f, 0.0f);
	//position = std::make_tuple(0.0f, 0.0f);
	gravity = 0.0f;
	health = 3;
}

void Player::Draw() {
	TextureManager::GetInstance()->DrawFrame(textureID, position.x, position.y, width, height, row, frame);
}

void Player::Update(float dt) {
	frame = (SDL_GetTicks() / animationSpeed) % frameCount; 
}

void Player::Clean() {
	TextureManager::GetInstance()->Clean();
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