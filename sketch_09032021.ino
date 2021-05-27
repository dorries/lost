
float distance1;
float distance2;
float distance3;
int flag=0;

void setup() {
  // Ultrasonic sensor modules
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);  

  //LED modules
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(10,OUTPUT);
 }

void loop() {
    //Ultrasonic sensor modules
  digitalWrite(2,LOW);
  delayMicroseconds(2);
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);
  distance1=pulseIn(3,HIGH)/58.00;
  
  digitalWrite(4,LOW);
  delayMicroseconds(2);
  digitalWrite(4,HIGH);
  delayMicroseconds(10);
  digitalWrite(4,LOW);
  distance2=pulseIn(5,HIGH)/58.00;
  
  digitalWrite(8,LOW);
  delayMicroseconds(2);
  digitalWrite(8,HIGH);
  delayMicroseconds(10);
  digitalWrite(8,LOW);
  distance3=pulseIn(9,HIGH)/58.00;
  
  
  if(flag==0)
  {
    if(distance1<10)
    {
     digitalWrite(6,LOW);
     delay(100);
     Serial.write("1");
     flag=1;
     }
     else{
       digitalWrite(6,HIGH);
       delay(100);
     }
  
    if(distance2<10)
    {
      digitalWrite(7,LOW);
      delay(100);
      Serial.write("2");
      flag=1;
     }
     else{
      digitalWrite(7,HIGH);
      delay(100);   
    } 
  
    if(distance3<10)
    {
      digitalWrite(10,LOW);
      delay(100);
      Serial.write("3");
      flag=1;
     }
     else{
      digitalWrite(10,HIGH);
      delay(100);   
    }  
  }
  
    if(distance1>=10 || distance2>=10 || distance3>=10)
    {
      flag=0;
      } 
}
