// Ibotanist Prototype

// All requirements
#include <DHT.h>
#include <rgb_lcd.h>
#include <Arduino.h>
#include <Wire.h>

// The variables used for setting the colour of the LCD display
rgb_lcd lcd;
const int colorR = 150;
const int colorG = 50;
const int colorB = 0;

// The pin that the LED button is on
const int buttonPin = 4; 

// The values for the buttons states
int buttonState; 
int lastButtonState = HIGH;

// Setup values for Temp%Humid sensor
int displayMode = 0;
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

    // Setting button as an input
    pinMode(buttonPin, INPUT);

    dht.begin();
}


void loop() {
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

    int buttonState = digitalRead(buttonPin);

      // This handles the changing of the display mode
      if (buttonState != lastButtonState) {
        debug.print("Button Changed");
        if (displayMode == 0){
          displayMode++;
        } else {
          displayMode = displayMode -1;
        }
      }

    // Strings used to print to the LCD screen
    String Hum = "Humidity: ";
    String Temp = "Temperature: ";
    String Perc =  "%";
    String Cel = "C";

    // The values for Humidity and Temperature
    float tempVal = dht.readTemperature();
    Serial.print(tempVal);
    float humval = dht.readHumidity();
    Serial.print(humval);
    delay(2000);

    // Concatonated strings to be printed on LCD
    String printHumid = Hum + humval + Perc;
    String printTemp = Temp + tempVal + Cel;

    // Used to scroll through the temp display
    const char scrolltemp[] = {printTemp.c_str()};

    // This will be used if the statistic mode is enabled
    if (displayMode == 0) {
        lcd.setCursor(16, 0);
        lcd.print(printHumid);
        lcd.setCursor(16, 1);
        lcd.autoscroll();

        // This creates the scrolling effect of the text
        for(auto x : printTemp)
        {
            lcd.print(x);
            delay(750);
            // This checks for if the button is pressed during the text scroll, ITS VERY BUGGY
            if (buttonState != lastButtonState) {
              debug.print("Button Changed");
              if (displayMode == 0){
                displayMode++;
              } else {
                displayMode -= 1;
              }
            }
        }
        // turn off automatic scrolling
        lcd.noAutoscroll();
        // clear screen for the next loop:
        lcd.clear();
      // This will happen to show the tips
    } else if (displayMode == 1) {
      lcd.clear();
      lcd.autoscroll();
      // Loops through the list of tips
      for (int i = 0; i < 9; i++){
          // Doesn't fucking work lol
          debug.print(tips[i]);
          debug.print("\n");
          const char printTemp[] = {tips[i]};
          // for(auto x : printTemp){
          //   lcd.print(x);
          //   delay(750);
          // }
          // for(char printTip : tip){
          //   lcd.print(printTip);
          //   debug.print(printTip);
          //   delay(750);
          // }
          lcd.clear();
        }
      lcd.noAutoscroll();
    }

    delay(750);
}
