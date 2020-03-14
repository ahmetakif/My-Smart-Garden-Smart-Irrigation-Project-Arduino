#include <Servo.h>

#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11



Servo myservo;  



const int buzzer = 11;



float soil = 0;

float ldr = 0;

float humidity = 0;

float temp = 0; 

float water = 10000;

float evapor = 0;

float soilwr = 0;



DHT dht(DHTPIN, DHTTYPE);



void setup() {

  pinMode(buzzer,OUTPUT);

  pinMode(10,OUTPUT);

  digitalWrite(10,0);  

  dht.begin();

  Serial.begin(9600);

  Serial.println("AKILLI BAHCEM");

  Serial.println("HOSGELDINIZ");

  clo();

  delay(2000);

}

  

void op() {

  digitalWrite(buzzer,1);

  delay(40);

  digitalWrite(buzzer,0);

  delay(90);

  digitalWrite(buzzer,1);

  delay(40);

  digitalWrite(buzzer,0);

  myservo.attach(3);

  myservo.write(0);

  delay(2000);

  myservo.detach();

}



void clo() {

  myservo.attach(3);

  myservo.write(50);

  delay(2000);

  myservo.detach();

}



void loop() {

  ldr = analogRead(A7);               

  soil = analogRead(A6);

  humidity = dht.readHumidity(); 

  temp = dht.readTemperature();

  Serial.print("ldr:");

  Serial.println(ldr);

  Serial.print("soil: ");

  Serial.println(soil);

  Serial.print("humidity: ");

  Serial.println(humidity);

  Serial.print("temp: ");

  Serial.println(temp);

  

  evapor = (temp - 20)*0,9 + ldr/1000;

  soilwr = soil/200;

  water = water - soilwr - evapor;

  Serial.print("Water: ");

  Serial.println(water);

  

  if (water < 2000) {

    op();

    delay(5000);

    clo();

    water = water + 5000;

  }

  

  delay(1000);      

}

