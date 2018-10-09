#define LED_BUILTIN 2

void setup() {
  setupOTA();
  setupBlink();
}

void loop() {
  loopOTA();
  loopBlink();
}
