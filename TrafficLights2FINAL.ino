/*
  ————————————————————————————————————————————————————————————————————
  Programmer: Niyati Sharma
  Date: Nov 16th 2022
  —————————————————————————————————————————————————————————————————————
  Program: A traffic light system using LEDs, buttons, and interupts
  —————————————————————————————————————————————————————————————————————
  Description: Using two buttons to control a traffic light
  system using LEDs
  —————————————————————————————————————————————————————————————————————
  Connections: pins 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, power
  —————————————————————————————————————————————————————————————————————
  Bot: 13A
  —————————————————————————————————————————————————————————————————————
*/

//-----------------------------------------------------------------
//Global area - Everything in this section applies to all functions
//-----------------------------------------------------------------

const byte BUTTONONE = 2; //Gives button a connection to pin 2
const byte BUTTONTWO = 3; //Gives button a connection to pin 3

int buttonpressedflag1 = 0;  //Flag for button 1 with 0 as value
int buttonpressedflag2 = 0;//Flag for button 2 with 0 as value

//-----------------------------------------------------------------
//Setup area - All code in this section runs once
//-----------------------------------------------------------------

void setup()
{
  //Will interupt a new code when buttons are clicked
  attachInterrupt(digitalPinToInterrupt(2), buttonPressed1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), buttonPressed2, CHANGE);

  pinMode(BUTTONONE, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(BUTTONTWO, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);

  //-----------------------------------------------------------------
  //loop area - All code in this section runs repeatedly
  //-----------------------------------------------------------------
}
void loop()
{
  //red1, red2, green1, redWalk1, redWalk2
  digitalWrite(4, LOW); //
  digitalWrite(9, HIGH); 
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH); //Since button not pressed by pedestrian, the red crosswalk 1 light stays on
  digitalWrite(12, HIGH); //Since button not pressed by pedestrian, the red crosswalk 2 light stays on

  if (buttonpressedflag2 == 1)
  {

    digitalWrite(12, LOW);
    digitalWrite(8, HIGH);
    delay(2000);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(12, HIGH);
    delay(2000);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(2000);

    buttonpressedflag2 = 0;
  }

  else if (buttonpressedflag2 == 0)
  {

    delay(2000);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    delay(2000);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(2000);
  }

  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);

  if (buttonpressedflag1 == 1)
  {
    digitalWrite(7, LOW);
    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(11, LOW);
    digitalWrite(13, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(7, HIGH);
    delay(2000);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    delay(2000);

    buttonpressedflag1 = 0;
  }

  else if (buttonpressedflag1 == 0)
  {

    delay(2000);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    delay(2000);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    delay(2000);
  }
}

//-------------------------------------------------------
// Button 1 Interrupt when clicked
//-------------------------------------------------------
void buttonPressed1()
{
  buttonpressedflag1 = 1; //If button 1 is clicked, set value of flag to 1
}

//-------------------------------------------------------
// Button 2 Interrupt when clicked
//-------------------------------------------------------
void buttonPressed2()
{
  buttonpressedflag2 = 1; //If button 2 is clicked, set value of flag to 1
}

//No code goes beyond this point
