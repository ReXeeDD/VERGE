#pragma once
#include<ostream>
#include <cmath>
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
	Vec2 operator*( float scalar) const{
		return { x * scalar, y * scalar };
	}
    Vec2 operator/(float scalar) const
	{
		return { x / scalar, y / scalar };
	}
    Vec2& operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vec2& operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }
    float Dot(const Vec2& other) const
    {
        return x * other.x + y * other.y;
    }
    float Cross(const Vec2& other) const
    {
        return x * other.y - y * other.x;
    }

    float Length() const
    {
        return std::sqrt(x * x + y * y);
    }

    constexpr float LengthSquared() const
    {
        return x * x + y * y;
    }

    Vec2 Normalized() const
    {
        float len = Length();
        if (len == 0.0f)
            return { 0.0f, 0.0f };

        return { x / len, y / len };
    }

    void Normalize()
    {
        float len = Length();
        if (len == 0.0f)
            return;

        x /= len;
        y /= len;
    }


    static Vec2 Zero()
    {
        return { 0.0f, 0.0f };
    }

};

inline std::ostream& operator<<(std::ostream& stream, const Vec2& v) {
	stream << "(" << v.x << ", " << v.y << ")";
	return stream;
}