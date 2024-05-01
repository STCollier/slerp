static inline float bounceOut(float x) {
    const float n1 = 7.5625;
    const float d1 = 2.75;

    if (x < 1 / d1) {
        return n1 * x * x;
    } else if (x < 2 / d1) {
        return n1 * (x -= 1.5 / d1) * x + 0.75;
    } else if (x < 2.5 / d1) {
        return n1 * (x -= 2.25 / d1) * x + 0.9375;
    } else {
        return n1 * (x -= 2.625 / d1) * x + 0.984375;
    }
}

#define C1 (1.70158)
#define C2 (C1 * 1.525)
#define C3 (C1 + 1)
#define C4 ((2 * M_PI) / 3)
#define C5 ((2 * M_PI) / 4.5)

static inline float slerp_impr(float v0, float v1, float t);
static inline float slerp(float v0, float v1, float t);

static inline float sl_linear(float x);
static inline float sl_easeInQuad(float x);
static inline float sl_easeOutQuad(float x);
static inline float sl_easeInOutQuad(float x);
static inline float sl_easeInCubic(float x);
static inline float sl_easeOutCubic(float x);
static inline float sl_easeInOutCubic(float x);
static inline float sl_easeInQuart(float x);
static inline float sl_easeOutQuart(float x);
static inline float sl_easeInOutQuart(float x);
static inline float sl_easeInQuint(float x);
static inline float sl_easeOutQuint(float x);
static inline float sl_easeInOutQuint(float x);
static inline float sl_easeInSine(float x);
static inline float sl_easeOutSine(float x);
static inline float sl_easeInOutSine(float x);
static inline float sl_easeInExpo(float x);
static inline float sl_easeOutExpo(float x);
static inline float sl_easeInOutExpo(float x);
static inline float sl_easeInCirc(float x);
static inline float sl_easeOutCirc(float x);
static inline float sl_easeInOutCirc(float x);
static inline float sl_easeInBack(float x);
static inline float sl_easeOutBack(float x);
static inline float sl_easeInOutBack(float x);
static inline float sl_easeInElastic(float x);
static inline float sl_easeOutElastic(float x);
static inline float sl_easeInOutElastic(float x);
static inline float sl_easeInBounce(float x);
static inline float sl_easeOutBounce(float x);
static inline float sl_easeInOutBounce(float x);

enum EASINGS {
    SL_LINEAR,
    SL_EASE_IN_QUAD,
    SL_EASE_OUT_QUAD,
    SL_EASE_IN_OUT_QUAD,
    SL_EASE_IN_CUBIC,
    SL_EASE_OUT_CUBIC,
    SL_EASE_IN_OUT_CUBIC,
    SL_EASE_IN_QUART,
    SL_EASE_OUT_QUART,
    SL_EASE_IN_OUT_QUART,
    SL_EASE_IN_QUINT,
    SL_EASE_OUT_QUINT,
    SL_EASE_IN_OUT_QUINT,
    SL_EASE_IN_SINE,
    SL_EASE_OUT_SINE,
    SL_EASE_IN_OUT_SINE,
    SL_EASE_IN_EXPO,
    SL_EASE_OUT_EXPO,
    SL_EASE_IN_OUT_EXPO,
    SL_EASE_IN_CIRC,
    SL_EASE_OUT_CIRC,
    SL_EASE_IN_OUT_CIRC,
    SL_EASE_IN_BACK,
    SL_EASE_OUT_BACK,
    SL_EASE_IN_OUT_BACK,
    SL_EASE_IN_ELASTIC,
    SL_EASE_OUT_ELASTIC,
    SL_EASE_IN_OUT_ELASTIC,
    SL_EASE_IN_BOUNCE,
    SL_EASE_OUT_BOUNCE,
    SL_EASE_IN_OUT_BOUNCE
};

typedef struct {
    float from, to;
} slerp_values_t;

typedef struct {
    enum EASINGS type;
    slerp_values_t values;
    float time;
} slerp_t;

static float slerp_to(slerp_t lerp, float step);
static float slerp_from(slerp_t lerp, float step);

#ifdef SLERP_H
#define SLERP_VERSION 1.0

#include <math.h>

static float slerp_to(slerp_t lerp, float step) {
    if (lerp.time < 1.0) {
        lerp.time += step;
    }

    switch (lerp.type) {
        case SL_LINEAR:
            return slerp(lerp.values.from, lerp.values.to, sl_linear(lerp.time));
        case SL_EASE_IN_QUAD:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInQuad(lerp.time));
        case SL_EASE_OUT_QUAD:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutQuad(lerp.time));
        case SL_EASE_IN_OUT_QUAD:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutQuad(lerp.time));
        case SL_EASE_IN_CUBIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInCubic(lerp.time));
        case SL_EASE_OUT_CUBIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutCubic(lerp.time));
        case SL_EASE_IN_OUT_CUBIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutCubic(lerp.time));
        case SL_EASE_IN_QUART:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInQuart(lerp.time));
        case SL_EASE_OUT_QUART:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutQuart(lerp.time));
        case SL_EASE_IN_OUT_QUART:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutQuart(lerp.time));
        case SL_EASE_IN_QUINT:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInQuint(lerp.time));
        case SL_EASE_OUT_QUINT:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutQuint(lerp.time));
        case SL_EASE_IN_OUT_QUINT:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutQuint(lerp.time));
        case SL_EASE_IN_SINE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInSine(lerp.time));
        case SL_EASE_OUT_SINE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutSine(lerp.time));
        case SL_EASE_IN_OUT_SINE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutSine(lerp.time));
        case SL_EASE_IN_EXPO:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInExpo(lerp.time));
        case SL_EASE_OUT_EXPO:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutExpo(lerp.time));
        case SL_EASE_IN_OUT_EXPO:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutExpo(lerp.time));
        case SL_EASE_IN_CIRC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInCirc(lerp.time));
        case SL_EASE_OUT_CIRC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutCirc(lerp.time));
        case SL_EASE_IN_OUT_CIRC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutCirc(lerp.time));
        case SL_EASE_IN_BACK:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInBack(lerp.time));
        case SL_EASE_OUT_BACK:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutBack(lerp.time));
        case SL_EASE_IN_OUT_BACK:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutBack(lerp.time));
        case SL_EASE_IN_ELASTIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInElastic(lerp.time));
        case SL_EASE_OUT_ELASTIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutElastic(lerp.time));
        case SL_EASE_IN_OUT_ELASTIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutElastic(lerp.time));
        case SL_EASE_IN_BOUNCE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInBounce(lerp.time));
        case SL_EASE_OUT_BOUNCE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutBounce(lerp.time));
        case SL_EASE_IN_OUT_BOUNCE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutBounce(lerp.time));
        default:
            // Linear lerp if unknown
            return slerp(lerp.values.from, lerp.values.to, sl_linear(lerp.time));
    }
}

static float slerp_from(slerp_t lerp, float step) {
    if (lerp.time > 0.0) {
        lerp.time -= step;
    }

    switch (lerp.type) {
        case SL_LINEAR:
            return slerp(lerp.values.from, lerp.values.to, sl_linear(lerp.time));
        case SL_EASE_IN_QUAD:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInQuad(lerp.time));
        case SL_EASE_OUT_QUAD:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutQuad(lerp.time));
        case SL_EASE_IN_OUT_QUAD:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutQuad(lerp.time));
        case SL_EASE_IN_CUBIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInCubic(lerp.time));
        case SL_EASE_OUT_CUBIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutCubic(lerp.time));
        case SL_EASE_IN_OUT_CUBIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutCubic(lerp.time));
        case SL_EASE_IN_QUART:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInQuart(lerp.time));
        case SL_EASE_OUT_QUART:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutQuart(lerp.time));
        case SL_EASE_IN_OUT_QUART:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutQuart(lerp.time));
        case SL_EASE_IN_QUINT:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInQuint(lerp.time));
        case SL_EASE_OUT_QUINT:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutQuint(lerp.time));
        case SL_EASE_IN_OUT_QUINT:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutQuint(lerp.time));
        case SL_EASE_IN_SINE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInSine(lerp.time));
        case SL_EASE_OUT_SINE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutSine(lerp.time));
        case SL_EASE_IN_OUT_SINE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutSine(lerp.time));
        case SL_EASE_IN_EXPO:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInExpo(lerp.time));
        case SL_EASE_OUT_EXPO:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutExpo(lerp.time));
        case SL_EASE_IN_OUT_EXPO:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutExpo(lerp.time));
        case SL_EASE_IN_CIRC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInCirc(lerp.time));
        case SL_EASE_OUT_CIRC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutCirc(lerp.time));
        case SL_EASE_IN_OUT_CIRC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutCirc(lerp.time));
        case SL_EASE_IN_BACK:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInBack(lerp.time));
        case SL_EASE_OUT_BACK:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutBack(lerp.time));
        case SL_EASE_IN_OUT_BACK:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutBack(lerp.time));
        case SL_EASE_IN_ELASTIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInElastic(lerp.time));
        case SL_EASE_OUT_ELASTIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutElastic(lerp.time));
        case SL_EASE_IN_OUT_ELASTIC:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutElastic(lerp.time));
        case SL_EASE_IN_BOUNCE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInBounce(lerp.time));
        case SL_EASE_OUT_BOUNCE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeOutBounce(lerp.time));
        case SL_EASE_IN_OUT_BOUNCE:
            return slerp(lerp.values.from, lerp.values.to, sl_easeInOutBounce(lerp.time));
        default:
            // Linear lerp if unknown
            return slerp(lerp.values.from, lerp.values.to, sl_linear(lerp.time));
    }
}

// Imprecise method, which does not guarantee v = v1 when t = 1, due to floating-point arithmetic error.
// This method is monotonic. This form may be used when the hardware has a native fused multiply-add instruction.
static inline float slerp_impr(float v0, float v1, float t) {
    return v0 + t * (v1 - v0);
}

// Precise method, which guarantees v = v1 when t = 1. This method is monotonic only when v0 * v1 < 0.
// Lerping between same values might not produce the same value
static inline float slerp(float v0, float v1, float t) {
    return (1 - t) * v0 + t * v1;
}
static inline float sl_linear(float x) {
    return x;
}

static inline float sl_easeInQuad(float x) {
    return x * x;
}

static inline float sl_easeOutQuad(float x) {
    return 1 - (1 - x) * (1 - x);
}

static inline float sl_easeInOutQuad(float x) {
    return x < 0.5 ? 2 * x * x : 1 - pow(-2 * x + 2, 2) / 2;
}

static inline float sl_easeInCubic(float x) {
    return x * x * x;
}

static inline float sl_easeOutCubic(float x) {
    return 1 - pow(1 - x, 3);
}

static inline float sl_easeInOutCubic(float x) {
    return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}

static inline float sl_easeInQuart(float x) {
    return x * x * x * x;
}

static inline float sl_easeOutQuart(float x) {
    return 1 - pow(1 - x, 4);
}

static inline float sl_easeInOutQuart(float x) {
    return x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
}

static inline float sl_easeInQuint(float x) {
    return x * x * x * x * x;
}

static inline float sl_easeOutQuint(float x) {
    return 1 - pow(1 - x, 5);
}

static inline float sl_easeInOutQuint(float x) {
    return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
}

static inline float sl_easeInSine(float x) {
    return 1 - cos((x * M_PI) / 2);
}

static inline float sl_easeOutSine(float x) {
    return sin((x * M_PI) / 2);
}

static inline float sl_easeInOutSine(float x) {
    return -(cos(M_PI * x) - 1) / 2;
}

static inline float sl_easeInExpo(float x) {
    return x == 0 ? 0 : pow(2, 10 * x - 10);
}

static inline float sl_easeOutExpo(float x) {
    return x == 1 ? 1 : 1 - pow(2, -10 * x);
}

static inline float sl_easeInOutExpo(float x) {
    return x == 0
      ? 0
      : x == 1
      ? 1
      : x < 0.5
      ? pow(2, 20 * x - 10) / 2
      : (2 - pow(2, -20 * x + 10)) / 2;
}

static inline float sl_easeInCirc(float x) {
    return 1 - sqrt(1 - pow(x, 2));
}

static inline float sl_easeOutCirc(float x) {
    return sqrt(1 - pow(x - 1, 2));
}

static inline float sl_easeInOutCirc(float x) {
    return x < 0.5
      ? (1 - sqrt(1 - pow(2 * x, 2))) / 2
      : (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
}

static inline float sl_easeInBack(float x) {
    return C3 * x * x * x - C1 * x * x;
}

static inline float sl_easeOutBack(float x) {
    return 1 + C3 * pow(x - 1, 3) + C1 * pow(x - 1, 2);
}

static inline float sl_easeInOutBack(float x) {
    return x < 0.5
      ? (pow(2 * x, 2) * ((C2 + 1) * 2 * x - C2)) / 2
      : (pow(2 * x - 2, 2) * ((C2 + 1) * (x * 2 - 2) + C2) + 2) / 2;
}

static inline float sl_easeInElastic(float x) {
    return x == 0
      ? 0
      : x == 1
      ? 1
      : -pow(2, 10 * x - 10) * sin((x * 10 - 10.75) * C4);
}

static inline float sl_easeOutElastic(float x) {
    return x == 0
      ? 0
      : x == 1
      ? 1
      : pow(2, -10 * x) * sin((x * 10 - 0.75) * C4) + 1;
}

static inline float sl_easeInOutElastic(float x) {
    return x == 0
      ? 0
      : x == 1
      ? 1
      : x < 0.5
      ? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * C5)) / 2
      : (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * C5)) / 2 + 1;
}

static inline float sl_easeInBounce(float x) {
    return 1 - bounceOut(1 - x);
}

static inline float sl_easeOutBounce(float x) {
    return bounceOut(x);
}

static inline float sl_easeInOutBounce(float x) {
    return x < 0.5
      ? (1 - bounceOut(1 - 2 * x)) / 2
      : (1 + bounceOut(2 * x - 1)) / 2;
}

#endif