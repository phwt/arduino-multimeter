#include <DHT.h>
#include <TM1637Display.h>
#define DHTPIN 9     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);
int button = 13;
int status = false;
int chk;
int stt = false;
float hum;  //Stores humidity value
float temp; //Stores temperature value
float temps;
float tempa;
float st;

 //// Initialize DHT sensor for normal 16mhz Arduino
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(button, INPUT_PULLUP);
}

  void dl(){
    display.showNumberDec(temp,false);
  }
  
  void ds(){
    display.showNumberDec(hum,false);
  }

void loop() {
  // put your main code here, to run repeatedly:
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  //Print temp and humidity values to serial monitor
  //Serial.print("Humidity: ");
  //Serial.print(hum);
  //Serial.print(" %, Temp: ");
  //Serial.print(temp);
  //Serial.println(" Celsius");
  display.setBrightness(1);
  //display.showNumberDec(temp,false) ;
  //display.showNumberDec(temp,false) ;
  st = digitalRead(button);
  Serial.println(st);

  if(st == 0) { 
    dl();
    //Serial.println("10");
    //status = true; 
    //display.showNumberDec(temp,false) ;
  }else if(st == 1) {
    ds();
    //Serial.println("11");
    //status = false;
    //display.showNumberDec(hum,false) ;
  }
  

  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  //display.showNumberDec(voltage,false,4,4) ;
  
  delay(1); 

}
