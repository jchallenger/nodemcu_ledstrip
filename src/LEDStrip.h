#ifndef __MY_LEDStrip__
#define __MY_LEDStrip__

#include <FastLED.h>
#include <vector>

#include "led_animation.h"
#include "led_animation_blink.h"

class LEDStrip
{
private:
    std::vector<led_animation*> * lights;

public:
    LEDStrip();
    ~LEDStrip(){}

    void addLight(led_animation * anim);
    void setBrightness(float percent);
    led_animation * getLight(int num = 0){ return this->lights->at(num); }
    void update(float delta);
    void display();
};

#endif