#include "DHTesp.h"
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>    
#include "EspMQTTClient.h"  
int t_p=5;
int e_p=18;
float ss=0.034;
long durn;
float dist_cm;
#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4
char  temperaturaJson[100];
char  umidadeJson[100];
char  distanciaJson[100];
float temperatura;
float umidade;
 
 
EspMQTTClient client
(
  "Wokwi-GUEST",                //nome da sua rede Wi-Fi
  "",           //senha da sua rede Wi-Fi
  "mqtt.tago.io",       //Endereço do servidor MQTT
  "Default",            //User é sempre default pois vamos usar token
  "40819502-f29e-4ad5-8473-8f8e1c296a6e",              // Código do Token
  "esp32",              //Nome do device
  1883                  //Porta de comunicação padrao
);
 
 
const int DHT_PIN = 15;
 
DHTesp dhtSensor;
 
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
 
 
 
 
void setup() {
 
  Serial.begin(115200);
  pinMode(t_p, OUTPUT);
  pinMode(e_p, INPUT);
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  Serial.println("Conectando WiFi");
  while(!client.isWifiConnected()){
    Serial.print('.');
    client.loop();
    delay(1000);
  }
  Serial.println("Conectado!");
 
  Serial.println("Conectando com o broker MQTT");
  while(!client.isMqttConnected()){
    Serial.print('.');
    client.loop();
    delay(1000);
  }
  Serial.println("Conectado!");
}
 
void onConnectionEstablished()
{}
 
void loop()
 {
 
  digitalWrite(t_p, LOW);
  delayMicroseconds(2);
  digitalWrite(t_p, HIGH);
  delayMicroseconds(10);
  digitalWrite(t_p,LOW);
  durn=pulseIn(e_p,HIGH);
  dist_cm=durn*ss/2;
  Serial.print("distance= ");
  Serial.println(dist_cm);
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  Serial.println("Temp: " + String(data.temperature, 1) + "°C");
  Serial.println("Humidity: " + String(data.humidity, 1) + "%");
  Serial.println("---");
 
  delay(1000);
 
  lcd.setCursor(0, 0);
  lcd.print("  Temp: " + String(data.temperature, 1) + "\xDF"+"C  ");
  lcd.setCursor(0, 1);
  lcd.print(" Humidity: " + String(data.humidity, 1) + "% ");
 
  delay(1000);
 
  lcd.clear();
  digitalWrite(t_p, LOW);
  delayMicroseconds(2);
  digitalWrite(t_p, HIGH);
  delayMicroseconds(10);
  digitalWrite(t_p,LOW);
  durn=pulseIn(e_p,HIGH);
  dist_cm=durn*ss/2;
  Serial.print("distance= ");
  Serial.println(dist_cm);
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(dist_cm);
  lcd.print("cm");
 
 
  StaticJsonDocument<300> documentoJson1;
  documentoJson1["variable"] = "temperatura";
  documentoJson1["value"] = data.temperature;
  documentoJson1["unit"] = "°C";
  serializeJson(documentoJson1, temperaturaJson);
  Serial.println("Enviando dados de temperatura");
  Serial.println(temperaturaJson);
  client.publish("topicoDAHER", temperaturaJson);
 
  StaticJsonDocument<300> documentoJson2;
  documentoJson2["variable"] = "umidade";
  documentoJson2["value"] = data.humidity;
  documentoJson2["unit"] = "%";
  serializeJson(documentoJson2, umidadeJson);
  Serial.println("Enviando dados de umidade");
  Serial.println(umidadeJson);
  client.publish("topicoDAHER", umidadeJson);
 
  StaticJsonDocument<300> documentoJson3;
  documentoJson3["variable"] = "distancia";
  documentoJson3["value"] = dist_cm;
  documentoJson3["unit"] = "cm";
  serializeJson(documentoJson3, distanciaJson);
  Serial.println("Enviando dados de distancia");
  Serial.println(distanciaJson);
  client.publish("topicoDAHER", distanciaJson);
  delay(5000);
 
 
 
  client.loop();
 
}