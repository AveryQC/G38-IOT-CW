// Ibotanist Prototype

// All requirements
#include <DHT.h>
#include <rgb_lcd.h>
#include <Arduino.h>
#include <Wire.h>
#include <ezButton.h>

// The variables used for setting the colour of the LCD display
rgb_lcd lcd;
const int colorR = 150;
const int colorG = 50;
const int colorB = 0;

// 0 = show statistics, 1 = show tips
int displayMode = 0;

// Setup object for Temp&Humid sensor
#define DHTTYPE DHT20
DHT dht(DHTTYPE);

// Setting the debugging location
#if defined(ARDUINO_ARCH_AVR)
    #define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
    #define debug  SerialUSB
#else
    #define debug  Serial
#endif

void setup() {
    // Setting the speed of the serial port
    debug.begin(115200);
    Wire.begin();

    // Setting start variables for LCD
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);

    dht.begin();
}


void loop() {
  // TIPS
    // The list of the tips that will be outputted
    const char* tips[9]
      = { 
          "Use good-quality potting soil - Good potting soil promotes healthy roots!",
          "Increase humidity and prevent drafts - Indoor conditions can be dry and drafty. Keep plants away from heater vents, doorways and drafty windows.", 
          "Water your plants regulaury, make sure the soil is always damp.",
          "Fertilize Houseplants Periodically - Consider using fertilizer from time to time.",
          "Repot Overgrown Houseplants - If your plant is getting too big for it's pot, it's time to upsize!", 
          "Remove Dust From Plants - This can prevent the leaves from being able to get the sunlight they need.",
          "Deadhead Flowers and Remove Dying Leaves - Make sure to remove any dead leaves or flower from your plant.",
          "Find a site with the right light - Consider leaving your plant in a south facing window.",
          "Use ice cubes to water -  going away? leave some ice cube in the plant pots to slowly water your plants."
        };

  // PRINTING TO LCD SCREEN
    // Strings used to print to the LCD screen
    String Hum = "Humidity: "; String Perc =  "%";
    String Temp = "Temperature: "; String Cel = "C";
    String Lilev = "Light level: "; String Lum = "lm";

    // The values for Humidity, Temperature, Light
    float tempVal = dht.readTemperature();
    float humval = dht.readHumidity();
    float lightVal = analogRead(A3);
    delay(1000);

    // Concatonated strings to be printed on LCD
    String printHumid = Hum + humval + Perc;
    String printTemp = Temp + tempVal + Cel;
    String printLight = Lilev + lightVal + Lum;

    // Used to scroll through the temp display
    const char scrolltemp[] = {printTemp.c_str()};

    // This will be used if the statistic mode is enabled
    if (displayMode == 0) {
      lcd.setCursor(16, 0);
      lcd.print(printHumid);
      lcd.setCursor(16, 1);
      lcd.autoscroll();

      // This creates the scrolling effect of the text
      for(auto x : printTemp){
        lcd.print(x);
        delay(750);         
      }
      // turn off automatic scrolling
      lcd.noAutoscroll();
      // clear screen for the next loop:
      lcd.clear();

      lcd.setCursor(16, 0);
      lcd.print(printTemp);
      lcd.setCursor(16, 1);
      lcd.autoscroll();

      // This creates the scrolling effect of the text
      for(auto x : printLight){
        lcd.print(x);
        delay(750);         
      }
      // turn off automatic scrolling
      lcd.noAutoscroll();
      // clear screen for the next loop:
      lcd.clear();



      // This will show the tips
    } else if (displayMode == 1) {
      lcd.clear();
      lcd.autoscroll();
      // Loops through the list of tips
      for (int i = 0; i < 9; i++){
          
          debug.print(tips[i]);
          debug.print("\n");
          
          delay(750);
          lcd.clear();
        }
      lcd.noAutoscroll();
    }

    delay(750);
}
