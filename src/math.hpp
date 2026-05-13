#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include <random>

inline float easeOut(float t, float duration) {
    if (t >= duration) return 1.0f;
    float x = t / duration;
    return 1.0f - (1.0f - x) * (1.0f - x);   // 二次缓出
}

inline float angleBetween(const sf::Vector2f& from, const sf::Vector2f& to,float& cosf,float& sinf) {
    float dx = to.x - from.x;
    float dy = to.y - from.y;
    // atan2 返回弧度（y 在前，x 在后）
    float radians = std::atan2(dy, dx);
    cosf=std::cosf(radians);
    sinf=std::sinf(radians);
    // 转为角度
    float degrees = radians * 180.f / 3.14159265f;
    // SFML 的旋转正方向是顺时针，而 atan2 是逆时针，所以取负
    return degrees;
}

inline float randfloat(float minv,float maxv){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(minv,maxv);
    return dist(gen);
}