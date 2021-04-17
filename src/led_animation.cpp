#include "led_animation.h"

led_animation::led_animation(CRGB &_led, PLAYMODE mode)
{
    this->mode = mode;
    this->startTime = millis();
    this->led = &_led;
    this->startColor = CRGB::Black;
    this->targetColor = (_led);
}

led_animation::~led_animation()
{
}

void led_animation::update(unsigned long delta){   
    PLAYMODE next = this->mode; 
    switch (this->mode)
    {
    case PLAYMODE::PAUSE:
        // Serial1.println("Nothing");
        break;
    case PLAYMODE::PLAY:
        this->val += delta; 
        next = PLAYMODE::PAUSE;
        break;
    case PLAYMODE::REPEAT:
        // this->val = lerp8by8(this->val, this->val+delta, ((float)delta/(float)this->scale)); 
        this->val += delta; 
        if(this->val > this->scale){
            this->val = 0;
        }
        break;
    case PLAYMODE::PING:
    case PLAYMODE::PONG:
    {
        //long dt = (this->mode == PLAYMODE::PING)? delta : delta * -1; 
        //this->val = lerp8by8(this->val, this->val+dt, delta/this->scale); 
        this->val += (this->mode == PLAYMODE::PING)? delta : delta * -1.f; 
        if(this->val > this->scale || this->val < 0 ){ 
            next = (this->mode == PLAYMODE::PING) ? PLAYMODE::PONG : PLAYMODE::PING;
        }
        break;
    }
    default:
        break;
    }

    // limits
    if(this->val > this->scale){ this->val = this->scale; this->mode = next; }
    if(this->val < 0 ){ this->val = 0; this->mode = next; }
}

void led_animation::apply(){
    this->led->setRGB(
        this->lerp(this->startColor.r, this->targetColor.r, this->getProgress()),
        this->lerp(this->startColor.g, this->targetColor.g, this->getProgress()),
        this->lerp(this->startColor.b, this->targetColor.b, this->getProgress())
    );
}
