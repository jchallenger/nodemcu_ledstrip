#ifndef __MY_led_animation_rainbow__
#define __MY_led_animation_rainbow__

class led_animation;

class led_animation_rainbow : public led_animation {
private:
  /* data */
public:
  led_animation_rainbow(CRGB &_led, PLAYMODE mode = PLAYMODE::REPEAT)
      : led_animation(_led, mode) {}
  ~led_animation_rainbow() {}

  void apply() {
    this->led->setHSV(this->hue, this->getProgress() * 255,
                      this->brightness * 255);
  }
};

#endif