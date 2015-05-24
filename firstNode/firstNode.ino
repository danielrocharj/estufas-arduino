#include <DHT.h>
#define DHTPIN 11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int ldrPin = 5;
char idNode[] = "ABB01F";
float u, t;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  t = dht.readTemperature();
  u = dht.readHumidity();
  Serial.print("ID : ");
  Serial.print(idNode);
  Serial.print(" , ");
  Serial.print("luz : ");
  Serial.print(vlrLDR());
  Serial.print(" , ");
  Serial.print("temp : ");
  Serial.print(t);
  Serial.print(" , ");
  Serial.print("umidAr : ");
  Serial.println(u);
}

int vlrLDR() {
  int l = analogRead(ldrPin);
  return l;
}
