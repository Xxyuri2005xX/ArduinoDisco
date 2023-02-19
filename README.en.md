# ArduinoDisco

Available Languages:

[![it](https://img.shields.io/badge/lang-it-green.svg)](https://github.com/Xxyuri2005xX/ArduinoDisco/blob/master/README.it.md)
[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/Xxyuri2005xX/ArduinoDisco/blob/master/README.en.md)
---

![EnFlag](https://user-images.githubusercontent.com/84080587/194774673-78c41fb4-463f-4ccd-86cf-5b8cb443272e.png)

the following project is about making an intelligent disco that adapts its track according to the number of people.
The project's variables and comments are all in italian.

the arduino sketch (to be loaded through its IDE) will be available in 2 versions (recognizable by the - "iso" tag): 
- Italian - IT
- English - EN

## Tinkercad project

![Tinkercad](https://user-images.githubusercontent.com/84080587/194775403-9f35a7ad-79f5-4fea-b5dc-288bc9b9d3bb.PNG)


## Coming SOON:
- ArduinoDisco v2
- ArduinoDisco v3

Version features:
|  | ArduinoDisco v1 | ArduinoDisco v2 | ArduinoDisco v3 |
| --------------- | --------------- | --------------- | --------------- |
| Release: | 09/10/2022  | SOON  | N/A |
| Web Support: | ❌ | ❔ | ✅ |
| Music Reading:| ❌ | ✅ | ✅ |
| Updated People count:| ❌ | ✅ | ✅ |

legend:
- ❌: no
- ❔: evaluation
- ✅: yes

## FAQ
Here you can find some frequently asked questions.

## More led implementation

To implement new RGB leds within the project, the following steps must be followed:
- Implement the new led into the circuit (**!YOU NEED 3 PINS EQUIPPED WITH PWM FOR OPERATION AND A CONNECTION TO THE 5V/MASS BASED ON THE TYPE OF LED USED**), to understand how to connect the led just look at the tinkercad diagram above
- Next take the following piece of code and insert it between the variables of the last RGB led (in the case of the code uploaded here on github led 2) and the other variables with this code snippet where `X` represents the led's ID number (1,2,3,etc) and `x` the PWM pin (11,10,9,etc):
  ```yml
  //led rgb X
  int redX = x;
  int blueX = x;
  int greenX = x;
  ```
- Next you need to declare the 3 new pins as OUTPUT in the sketch setup, then you need to paste the following code snippet under the last pinMode that declares OUTPUT before the input ones, where X is the ID number assigned above:
  ```yml
  pinMode(redX, OUTPUT);
  pinMode(blueX, OUTPUT);
  pinMode(greenX, OUTPUT);
  ```
- One of the last steps concerns the use of the LED in the function and its eventual activation if you wanted to use it with x number of people. In this case To implement enabling the led, simply find the brace in the last if for controlling the number of people (before even the loop closing one and before the debugging system) and insert this code snippet where `y` is the number of people you want and `X` is the identifying number (see above):
  ```yml
  if(people>=y) {
      rgbLedDisplay(redX, blueX, greenX, 
                  random(256), random(256), random(256));
    }
  ```
**!In case you want to implement the led together with another just copy the function without the if, also be warned NOT to change the last 3 parameters which are random number generators that create numbers between 0 and 255 so that the led changes color automatically**
