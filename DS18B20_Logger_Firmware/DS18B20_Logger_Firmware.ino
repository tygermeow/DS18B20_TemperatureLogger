#include <Time.h>
#include <TimeLib.h>

#include <OneWire.h>
#include <DallasTemperature.h>
 
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  // start serial port
  Serial.begin(9600);

  // Start up the library
  sensors.begin();
}
 
 
void loop(void)
{
  float tempc,tempf;
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");
  tempc=sensors.getTempCByIndex(0);
  //tempf=tempc*(9/5)+32;
  tempf=tempc*1.8+32;
  //Serial.print("Temperature for Device 1 is: ");
  Serial.print(now());
  Serial.print("\t");
  Serial.print(tempf); // Why "byIndex"? 
  Serial.println("");
    // You can have more than one IC on the same bus. 
    // 0 refers to the first IC on the wire
    delay(10000);
 
}

