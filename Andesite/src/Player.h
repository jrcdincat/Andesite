#pragma once

class Player {
public: 
	Player();
	void update();
	void setSpeed(float speedX, float speedY);
	std::tuple<float, float> getSpeed();
private: 
	std::tuple<float, float> speed; 
	std::tuple<float, float> position;
	float gravity;
	int health;
};