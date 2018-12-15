int up=400;
int down=100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  digitalWrite(4,HIGH);
  delay(1000);
  up=analogRead(1)+50;
  delay(1000);
  digitalWrite(4,LOW);
  delay(1000);
  down=analogRead(1)+30;
  Serial.println(up);
  Serial.println(down);

}

void loop() {  
  int input=digitalRead(3);
  //Serial.println(input);
  if(input==1) digitalWrite(4,HIGH);
  else digitalWrite(4,LOW);
  //delay(10);
  int re=analogRead(1);
  //delay(5);
  //Serial.println(re);
  if(re>up) 
  {
    digitalWrite(2,HIGH);
  }
  else if(re<down) 
  {
    digitalWrite(2,LOW);
  }
  else
  {
    digitalWrite(4,LOW);
    //delay(10);
    if(analogRead(1)<down) digitalWrite(2,HIGH);
    else digitalWrite(2,LOW);
  }
}
