#pragma once
#include<ostream>
struct Vec2 {
	float x, y;

	Vec2(float x_in=0.0f,float y_in=0.0f):x(x_in),y(y_in){}

	~Vec2() {}

	Vec2 operator+(const Vec2& other)const {
		return { x + other.x,y + other.y };
	}
	Vec2 operator-(const Vec2& other)const {
		return { x - other.x,y - other.y };
	}
};

inline std::ostream& operator<<(std::ostream& stream, const Vec2& v) {
	stream << "(" << v.x << ", " << v.y << ")";
	return stream;
}