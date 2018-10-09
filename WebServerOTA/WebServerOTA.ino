#define LED_BUILTIN 2

void setup() {
  Serial.begin(115200);
  setupWIFI();
  setupOTA();
  setupWebServer();
  setupBlink();
}

void loop() {
  loopOTA();
  loopWebServer();
  loopBlink();
}
