#include "led_animation.h"

led_animation::led_animation(CRGB &_led, PLAYMODE mode) {
  this->mode = mode;
  this->startTime = millis();
  this->led = &_led;
  this->hue = (rgb2hsv_approximate(_led).hue);
  this->startColor = rgb2hsv_approximate(_led);
  this->targetColor = rgb2hsv_approximate(_led);
}

led_animation::~led_animation() {}

void led_animation::update(long delta) {
  switch (this->mode) {
  case PLAYMODE::PAUSE: {
    // Serial1.println("Nothing");
    break;
  }
  case PLAYMODE::PLAY: {
    this->val += delta;
    this->mode = PLAYMODE::PAUSE;
    break;
  }
  case PLAYMODE::REPEAT: {
    // this->val = lerp8by8(this->val, this->val+delta,
    // ((float)delta/(float)this->scale));
    this->val += delta;
    if (this->val > this->scale) {
      this->val = 0;
    }
    break;
  }
  case PLAYMODE::PING: {
    this->val += delta;
    if (this->val > this->scale) {
      this->val = this->scale;
      this->mode = PLAYMODE::PONG;
    }
    break;
  }
  case PLAYMODE::PONG: {
    // long dt = (this->mode == PLAYMODE::PING)? delta : delta * -1;
    // this->val = lerp8by8(this->val, this->val+dt, delta/this->scale);
    this->val += (delta * -1);
    if (this->val < 0) {
      this->val = 0;
      this->mode = PLAYMODE::PING;
    }
    break;
  }
  default:
    break;
  }
}
