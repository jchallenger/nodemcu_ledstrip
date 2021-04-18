#ifndef __MY_led_animation__
#define __MY_led_animation__

#include <FastLED.h>

enum PLAYMODE { PAUSE = 0, PLAY, REPEAT, PING, PONG, LERP };
enum ANIMTYPE { SOLID = 0, BLINK, LOOP };

class led_animation
{
protected:
    /* data */
    unsigned long startTime = 0;
    long val = 0L;
    unsigned long scale = 1000;
    PLAYMODE mode = PLAYMODE::PAUSE;

    CRGB startColor;
    CRGB targetColor;
    float brightness = 1.0f;
    CRGB * led;

    uint8_t lerp(uint8_t a, uint8_t b, float f){
        return (a * (1.0f - f)) + (b * f);
    }
public:
    led_animation(CRGB &_led, PLAYMODE mode = PLAYMODE::REPEAT);
    ~led_animation();

    void update(long delta);
    void setDuration(unsigned long dur){ this->scale = dur; };
    void setBrightness(float brightness);
    CRGB * getTargetColor();

    float getProgress(){ return this->val > 0 ? ((float)this->val / (float)this->scale) : 0; }
    long getValue(){ return this->val; }
    void apply();
};

#endif
