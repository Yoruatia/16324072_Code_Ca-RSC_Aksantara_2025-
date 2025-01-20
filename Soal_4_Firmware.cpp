#include <Wire.h>  // Library untuk I2C
#include <SPI.h>   // Library untuk SPI

// SPI Configuration
const int spiCS = 10;  // Pin Chip Select untuk perangkat SPI

void setup() {
  // Inisialisasi I2C
  Wire.begin(); 
  Serial.begin(9600);  // Debug output
  
  // Inisialisasi SPI
  pinMode(spiCS, OUTPUT);  
  SPI.begin();
  digitalWrite(spiCS, HIGH);  // Set CS ke HIGH (tidak aktif)

  Serial.println("I2C dan SPI Initialized");
}

void loop() {
  // Contoh komunikasi I2C
  Wire.beginTransmission(0x3C);  // Alamat I2C perangkat
  Wire.write("Hello I2C!");      // Data yang dikirim ke perangkat I2C
  Wire.endTransmission();
  delay(500);

  // Contoh komunikasi SPI
  digitalWrite(spiCS, LOW);      // Aktifkan perangkat SPI
  SPI.transfer(0x42);            // Kirim data
  digitalWrite(spiCS, HIGH);     // Nonaktifkan perangkat SPI
  delay(500);
}