#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TextureManager.h"

Player::Player(Properties* properties): Actor(properties) {
	row = 0;
	frameCount = 8;
	animationSpeed = 80;
	rigidBody = new RigidBody();
	animation = new Animation();
	animation->SetProperties(textureID, 0, 8, 80);
	//height = properties->height;
	//width = properties->height;
	//textureID = properties->textureID;
	//position = properties->position;
	//renderFlip = properties->renderFlip;
	//speed = std::make_tuple(0.0f, 0.0f);
	//position = std::make_tuple(0.0f, 0.0f);
	gravity = 0.0f;
	health = 3;
}

Player::~Player() {
	delete animation;
	delete rigidBody;
}

void Player::Draw() {
	animation->Draw(position.x, position.y, width, height);
	// TextureManager::GetInstance()->DrawFrame(textureID, position.x, position.y, width, height, row, frame);
}

void Player::Update(float dt) {
	rigidBody->Update(dt);
	position.x += rigidBody->GetPosition().x;
	// position.y += rigidBody->GetPosition().y;
	animation->Update();
	// frame = (SDL_GetTicks() / animationSpeed) % frameCount; 
}

void Player::Clean() {
	TextureManager::GetInstance()->Clean();
}

// Movement
void Player::MoveRight() {
	rigidBody->SetForceX(25 * FORWARD);
	animation->SetProperties("player_run", 0, 8, 80);
}

void Player::MoveLeft() {
	rigidBody->SetForceX(25 * BACKWARD);
	animation->SetProperties("player_run", 0, 8, 80, SDL_FLIP_HORIZONTAL);
}

void Player::Idle() {
	rigidBody->ResetForce();
	animation->SetProperties("player_idle", 0, 8, 80, SDL_FLIP_HORIZONTAL);
}