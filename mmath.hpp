#ifndef mmath_hpp
#define mmath_hpp

#include <iostream>
#include <algorithm>
#include <concepts>
#include <cmath>

template <typename T>
concept ValidVecType = std::same_as<T, int> || std::same_as<T, float> || std::same_as<T, double>;

template <ValidVecType T>
struct Vec2
{
    T x{};
    T y{};

    Vec2<T> operator+(const Vec2<T> &other) const
    {
        Vec2<T> sum{this->x + other.x, this->y + other.y};
        return sum;
    }
    Vec2<T> &operator+=(const Vec2<T> &other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Vec2<T> operator-(const Vec2<T> &other) const
    {
        Vec2<T> diff{this->x - other.x, this->y - other.y};
        return diff;
    }

    Vec2<T> &operator-=(const Vec2<T> &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    Vec2<T> operator*(T scalar) const
    {
        Vec2<T> product{x * scalar, y * scalar};
        return product;
    }

    Vec2<T> &operator*=(T scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    T dotproduct(const Vec2<T> &other) const
    {
        return x * other.x + y * other.y;
    }

    T magnitudeSquared() const
    {
        return x * x + y * y;
    }

    auto magnitude() const
    {
        return std::sqrt(x * x + y * y);
    }

    Vec2<T> normalize() const
    {
        Vec2<T> normalized{};
        auto magnitude = this->magnitude();
        if (magnitude == 0)
        {
            return {0, 0};
        }
        normalized.x = x / magnitude;
        normalized.y = y / magnitude;
        normalized.x = normalized.x;
        normalized.y = normalized.y;
        return normalized;
    }

    auto distance(const Vec2<T> &other) const
    {
        return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
    }

    bool operator==(const Vec2<T> &other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vec2<T> &other) const
    {
        return x != other.x || y != other.y;
    }
    bool operator>(const Vec2<T> &other) const
    {
        return this->magnitude() > other.magnitude();
    }
    bool operator>=(const Vec2<T> &other) const
    {
        return this->magnitude() >= other.magnitude();
    }
    bool operator<(const Vec2<T> &other) const
    {
        return this->magnitude() < other.magnitude();
    }
    bool operator<=(const Vec2<T> &other) const
    {
        return this->magnitude() <= other.magnitude();
    }
};

#endif