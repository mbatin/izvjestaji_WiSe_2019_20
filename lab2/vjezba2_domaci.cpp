#include <DHT.h>
#include <BH1750.h>
#define DHTPIN 2    
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter(0x23);
int freeRam ();

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
  Serial.println(F("BH1750 Test"));
}

void loop() {
  delay(2000);
  float h;
  float t;
  float f;
   h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F(" %\t"));
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F(" *C "));
  Serial.print(f);
  Serial.print(F(" *F\t"));
  Serial.print(F("Heat index: "));
  Serial.print(dht.computeHeatIndex(t, h, false));
  Serial.print(F(" *C "));
  Serial.print(dht.computeHeatIndex(f, h));
  Serial.println(F(" *F"));
  Serial.print(F("Light: "));
  Serial.print(lightMeter.readLightLevel());
  Serial.println(F(" lx"));
  Serial.print(F("Free SRAM: "));
  Serial.print(freeRam());
  Serial.print(F(" bytes"));
}
int freeRam ()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}