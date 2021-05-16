#pragma once

struct Vector2f {
	float x, y;
	Vector2f()
		:x(0.0f), y(0.0f)
	{
	}
	Vector2f(float xParam, float yParam)
		:x(xParam), y(yParam)
	{
	}
};