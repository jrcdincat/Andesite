#pragma once
#include "tuple"

class Player {
public: 
	Player();
	void update();
private: 
	std::tuple<float, float> speed; 
	std::tuple<float, float> position;
	float gravity;
	int health;
};