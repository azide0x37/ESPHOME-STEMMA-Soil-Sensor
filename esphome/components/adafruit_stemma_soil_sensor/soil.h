#include "esphome.h"
#include "Adafruit_seesaw.h"

//using namespace esphome;

class SOIL : public PollingComponent, public Sensor {
 public:
  
  Adafruit_seesaw myself;
  Sensor *temperature_sensor = new Sensor();
  Sensor *humidity_sensor = new Sensor();

  // Update every 15s (value in ms)
  SOIL() : PollingComponent(15000) { }

  void setup() override {
    myself.begin(0x36);
  }

  void update() override {
	float temperature = myself.getTemp();
    temperature_sensor->publish_state(temperature);
    float humidity = myself.touchRead(0);
    humidity_sensor->publish_state(humidity);
  }
};