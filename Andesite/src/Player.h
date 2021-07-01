#pragma once
#include "Actor.h"
#include "Animation/Animation.h"
#include "Physics/RigidBody.h"

class Player : Actor {
public: 
	Player() = default;
	Player(Properties* properties);
	~Player();

	virtual void Draw();
	virtual void Update(float dt);
	virtual void Clean();

	void MoveRight();
	void MoveLeft();
	void Idle();

private: 
	int row, frame, frameCount; 
	int animationSpeed;
	Animation* animation;
	RigidBody* rigidBody; 

	//std::tuple<float, float> position;
	float gravity;
	int health;
};