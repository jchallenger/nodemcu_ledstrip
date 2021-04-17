#ifndef __MY_led_animation__
#define __MY_led_animation__

#include <FastLED.h>

enum PLAYMODE { PAUSE = 0, PLAY, REPEAT, PING, PONG, LERP };
enum ANIMTYPE { SOLID = 0, BLINK, LOOP };

class led_animation
{
protected:
    /* data */
    long startTime = 0;
    long val = 0;
    long scale = 1000;
    PLAYMODE mode = PLAYMODE::PAUSE;

    CRGB startColor;
    CRGB targetColor;
    CRGB * led;

    uint8_t lerp(uint8_t a, uint8_t b, float f){
        return (a * (1.0f - f)) + (b * f);
    }
public:
    led_animation(CRGB &_led, PLAYMODE mode = PLAYMODE::REPEAT);
    ~led_animation();

    void update(unsigned long delta);
    void setDuration(unsigned long dur){ this->scale = dur; };

    float getProgress(){ return ((float)this->val / (float)this->scale); }
    long getValue(){ return this->val; }
    void apply();
};

#endif
