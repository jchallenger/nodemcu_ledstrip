#ifndef __MY_led_animation_blink__
#define __MY_led_animation_blink__

class led_animation;

class led_animation_blink : public led_animation {
private:
  /* data */
public:
  led_animation_blink(CRGB &_led, PLAYMODE mode = PLAYMODE::PING)
      : led_animation(_led, mode) {}
  ~led_animation_blink() {}

  void apply() {
    this->led->setHSV(this->hue, (this->getProgress() * this->saturation),
                      (this->getProgress() * this->brightness));
  }
};

#endif