const int l_speed = 6;
const int r_speed = 11;
const int r_c = 10;
const int r_cc = 9;
const int l_c = 3;
const int l_cc = 5;
char input;
// r refers to right, l for left, c for clockwise  ,and cc for counter clockwise

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  //if input is available  
  if (Serial.available() > 0) {
    //read it and store it in input variable
    input = (Serial.readString()).charAt(0);
  }
 //max speeds (speeed control here)
    analogWrite(r_speed,255);
    analogWrite(l_speed,255);
  
    if(input == 'F')
    {
      //left clockwise
      digitalWrite(l_c,HIGH);
      digitalWrite(l_cc,LOW);
      //right clockwise
      digitalWrite(r_c,HIGH);
      digitalWrite(r_cc,LOW);
      
    }
    if(input == 'B')
    {
      //left counter clockwise
      digitalWrite(l_cc,HIGH);
      digitalWrite(l_c,LOW);
      //right counter clockwise
      digitalWrite(r_cc,HIGH);
      digitalWrite(r_c,LOW);
    }
    if(input == 'R')
    {
      //left clockwise
      digitalWrite(l_c,HIGH);
      digitalWrite(l_cc,LOW);
      //right counter clockwise
      digitalWrite(r_c,LOW);
      digitalWrite(r_cc,HIGH);
    }
    if(input == 'L')
    {
      //left counter clockwise
      digitalWrite(l_c,LOW);
      digitalWrite(l_cc,HIGH);
      //right clockwise
      digitalWrite(r_c,HIGH);
      digitalWrite(r_cc,LOW);
    }
  
  
    if(input == 'r')
    {
      //left clockwise
      digitalWrite(l_c,HIGH);
      digitalWrite(l_cc,LOW);
      //right free spin(no power, no obstruction)
      digitalWrite(r_c,LOW);
      digitalWrite(r_cc,LOW);
    }
    if(input == 'l')
    {
      //left free spin(no power, no obstruction)
      digitalWrite(l_c,LOW);
      digitalWrite(l_cc,LOW);
      //right clockwise
      digitalWrite(r_c,HIGH);
      digitalWrite(r_cc,LOW);
    }
  
}
