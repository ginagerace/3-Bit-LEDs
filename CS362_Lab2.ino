//Gina Gerace, 664765515, ggerac3
//Lab 2
//Use 2 push buttons to increment or decrement a counter. The counter's 
//   value should be shown in binary on three LEDs.
//I expect the Debounce code to take care of any bouncing going on in the push buttons.
//    I expect using the push buttons will change the LEDs.
//I used code snippets from Ladyada Lesson 5. And i refered to the Arduino Button tutorial.

int button1 = 4;                //button to decrease counter
int button2 = 3;                //button to increase counter
int led1 = 10;
int led2 = 11;
int led3 = 12;

int count = 0;                  //will hold value to represent in binary

//for button1
int val1;                       // variable for reading the pin status
int val2;                       // variable for reading the delayed/debounced status
int buttonState1;               // variable to hold the button state

//for button2
int val3;                       // variable for reading the pin status
int val4;                       // variable for reading the delayed/debounced status
int buttonState2;               // variable to hold the button state


void setup() {
  // Set the switch pins as input
  pinMode(button1, INPUT); 
  pinMode(button2, INPUT);    

  // Set the LED pins to output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);                     // Set up serial communication at 9600bps
  buttonState1 = digitalRead(button1);    // read the initial state for button 1
  buttonState2 = digitalRead(button2);    // read the initial state for button 2
}

void loop() {
  //if button1 is pressed
  val1 = digitalRead(button1);       // read input value and store it in val
  delay(10);                         // 10 milliseconds is a good amount of time
  val2 = digitalRead(button1);       // read the input again to check for bounces
  if (val1 == val2) {                // make sure we got 2 consistant readings!
    if (val1 != buttonState1) {      // the button state has changed!
      if (val1 == LOW)               // check if the button is pressed
        count--;                     // decrease count by 1
    }
    buttonState1 = val1;             // save the new state in our variable
  }

  //if button2 is pressed
  val3 = digitalRead(button2);       // read input value and store it in val
  delay(10);                         // 10 milliseconds is a good amount of time
  val4 = digitalRead(button2);       // read the input again to check for bounces
  if (val3 == val4) {                // make sure we got 2 consistant readings!
    if (val3 != buttonState2) {      // the button state has changed!
      if (val3 == LOW)               // check if the button is pressed
        count++;                     // increase count by 1
    }
    buttonState2 = val3;             // save the new state in our variable
  }

  //make sure count is between 0 and 7
  if(count < 0)
    count = 0;
  if(count > 7)
    count = 7;

  //display number in binary
  if(count & B001)
    digitalWrite(led1, HIGH);
  else
    digitalWrite(led1, LOW);
  if(count & B010)
    digitalWrite(led2, HIGH);
  else
    digitalWrite(led2, LOW);
  if(count & B100)
    digitalWrite(led3, HIGH);
  else
    digitalWrite(led3, LOW);
}
