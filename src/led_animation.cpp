#include "led_animation.h"

led_animation::led_animation(CRGB &_led, PLAYMODE mode) {
  this->mode = mode;
  this->startTime = millis();
  this->led = &_led;
  this->startColor = CRGB::Black;
  this->targetColor = (_led);
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

void led_animation::apply() {
  this->led->setRGB(
      this->lerp(this->brightness * this->startColor.r,
                 this->brightness * this->targetColor.r, this->getProgress()),
      this->lerp(this->brightness * this->startColor.g,
                 this->brightness * this->targetColor.g, this->getProgress()),
      this->lerp(this->brightness * this->startColor.b,
                 this->brightness * this->targetColor.b, this->getProgress()));
}

void led_animation::setBrightness(float b) { this->brightness = b; }