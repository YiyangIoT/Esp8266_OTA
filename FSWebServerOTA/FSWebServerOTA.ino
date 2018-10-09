#define LED_BUILTIN 2

void setup() {
  Serial.begin(115200);
  setupWIFI();
  setupOTA();
  setupFSWebServer();
  setupBlink();
}

void loop() {
  loopOTA();
  loopFSWebServer();
  loopBlink();
}
