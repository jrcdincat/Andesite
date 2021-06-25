#pragma once
#include "Actor.h"
#include "Animation/Animation.h"

class Player : Actor {
public: 
	Player() = default;
	Player(Properties* properties);
	~Player();

	virtual void Draw();
	virtual void Update(float dt);
	virtual void Clean();

	void setSpeed(float speedX, float speedY);
	std::tuple<float, float> getSpeed();
private: 
	int row, frame, frameCount; 
	int animationSpeed;
	Animation* animation;

	std::tuple<float, float> speed; 
	//std::tuple<float, float> position;
	float gravity;
	int health;
};