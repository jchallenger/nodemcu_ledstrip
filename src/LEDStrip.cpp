#include "LEDStrip.h"
#include "led_animation.h"


LEDStrip::LEDStrip()
{
    this->lights = new std::vector<led_animation*>();
}

void LEDStrip::addLight(led_animation * ledAnim){
    this->lights->push_back(ledAnim);
}

void LEDStrip::update(float delta){
    for(int ii=0; ii < this->lights->size(); ii++){
        this->lights->at(ii)->update(delta);
    }
}

void LEDStrip::display(){
    for(int ii=0; ii < this->lights->size(); ii++){
        this->lights->at(ii)->apply();
    }
}
