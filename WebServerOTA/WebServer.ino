//#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
#include <ESP8266WebServer.h>
//#include <ESP8266mDNS.h>

ESP8266WebServer server(80);

const int led = 2;

void handleA0() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/json", String("{\"A0\":") + analogRead(A0) + "}");
}

void handleBlink() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "This is Blink Function!");

  for (int i = 0; i < 10; i++) {
    digitalWrite(led, 1);
    delay(1500);
    digitalWrite(led, 0);
    delay(1500);
  }
}

void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/plain", "hello from esp8266!");
  delay(1000);
  digitalWrite(led, 0);
}

void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setupWebServer(void) {
  server.on("/", handleRoot);
  server.on("/blink", handleBlink);
  server.on("/a0", handleA0);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loopWebServer(void) {
  server.handleClient();
}
