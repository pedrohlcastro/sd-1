#include <WiFi.h>

const char* ssid = "yourNetworkName";
const char* password =  "yourNetworkPass";
 
const uint16_t port = 8090;
const char * host = "192.168.1.83";

#ifdef __cplusplus
  extern "C" {
#endif
 
uint8_t temprature_sens_read();
 
#ifdef __cplusplus
}
#endif
 
uint8_t temprature_sens_read();

void setup()
{
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
 
}
 
void loop()
{
    WiFiClient client;
 
    if (!client.connect(host, port)) {
 
        Serial.println("Connection to host failed");
 
        delay(1000);
        return;
    }
    int measurement = 0;
 
    measurement = hallRead();
    Serial.println("Connected to server successful!");
    Serial.print("Temperature: ");
    
    Serial.print((temprature_sens_read() - 32) / 1.8);
   
    
    Serial.println(" C");

    client.print(measurement + "-" + (temprature_sens_read() - 32) / 1.8);
    
 
    Serial.println("Disconnecting...");
//    client.stop();
 
    delay(10000);
}
