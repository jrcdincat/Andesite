#pragma once

class Vector2f {
public: 
	float x, y;

	Vector2f()
		:x(0.0f), y(0.0f)
	{
	}
	Vector2f(float xParam, float yParam)
		:x(xParam), y(yParam)
	{
	}

	// Multiply vector by scalar
	inline Vector2f operator * (const float scalar) const {
		return Vector2f(x * scalar, y * scalar);
	}
};