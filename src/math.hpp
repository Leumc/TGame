float easeOut(float t, float duration) {
    if (t >= duration) return 1.0f;
    float x = t / duration;
    return 1.0f - (1.0f - x) * (1.0f - x);   // 二次缓出
}