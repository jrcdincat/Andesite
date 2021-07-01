#pragma once
#include "../Vector2f.h";

#define UNITMASS 1.0f
#define GRAVITY 9.8f
#define FORWARD 1
#define BACKWARD -1
#define UPWARD 1
#define DOWNWARD -1

class RigidBody {
public: 
	RigidBody() {
		mass = UNITMASS;
		gravity = GRAVITY;
	}
	
	// Setters
	inline void SetMass(float massValue) { mass = massValue; }
	inline void SetGravity(float gravityValue) { gravity = gravityValue; }

	inline void SetForce(Vector2f forceValue) { force = forceValue; }
	inline void SetForceX(float forceX) { force.x = forceX; }
	inline void SetForceY(float forceY) { force.y = forceY; }
	inline void ResetForce() { force = Vector2f(0, 0); }

	inline void SetFriction(Vector2f frictionValue) { friction = frictionValue; }
	inline void SetFrictionX(float frictionX) { friction.x = frictionX; }
	inline void SetFrictionY(float frictionY) { friction.y = frictionY; }
	inline void ResetFriction() { friction = Vector2f(0, 0); }

	// Getters
	inline float GetMass() { return mass; }
	inline Vector2f GetVelocity() { return velocity; }
	inline Vector2f GetAcceleration() { return acceleration; }
	inline Vector2f GetPosition() { return position; }

	void Update(float deltaTime) {
		acceleration.x = (force.x + friction.x) / mass;
		acceleration.y = (force.y / mass) + gravity;
		velocity = acceleration * deltaTime; 
		position = velocity * deltaTime;
	}

private: 
	float mass; 
	float gravity; 

	Vector2f force; 
	Vector2f friction; 
	Vector2f velocity; 
	Vector2f acceleration; 
	Vector2f position; 
};