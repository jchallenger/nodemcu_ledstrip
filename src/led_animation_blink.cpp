#include "led_animation.h"
#include "led_animation_blink.h"

void led_animation_blink::apply(){
    this->led->setRGB(
        this->lerp(this->startColor.r, this->targetColor.r, this->getProgress()),
        this->lerp(this->startColor.g, this->targetColor.g, this->getProgress()),
        this->lerp(this->startColor.b, this->targetColor.b, this->getProgress())
    );
}