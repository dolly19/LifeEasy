int trigPin = 9;
int echoPin = 10;  

int revleft4 = 4;       //REVerse motion of Left motor
int fwdleft5 = 5;       //ForWarD motion of Left motor
int revright6 = 6;      //REVerse motion of Right motor
int fwdright7 = 7;      //ForWarD motion of Right motor
long duration, distance;
int state ;

void setup() {
 
  delay(random(500,2000));  
  Serial.begin(9600);
  pinMode(revleft4, OUTPUT);      
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);         
}

void loop() {
  if(Serial.available() > 0){
    state = Serial.read();
  if (state<=0)
  {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);  
  duration = pulseIn(echoPin, HIGH); 
  distance = duration / 58.2;
  delay(100);
  if (distance > 10)            
  {
    digitalWrite(fwdright7, HIGH);// move forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW);
    delay(30);
    digitalWrite(fwdright7, LOW);  //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);
    delay(20);                                                    
  }
  else if (distance <= 10)
  {
    digitalWrite(fwdright7, LOW);              
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);
    delay(500);
    digitalWrite(fwdright7, LOW);  //movebackword        
    digitalWrite(revright6, HIGH);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, HIGH);
    delay(200);
    digitalWrite(fwdright7, LOW);                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);  
    delay(1000);
    digitalWrite(fwdright7, LOW);      
    digitalWrite(revright6, HIGH);  
    digitalWrite(revleft4, LOW);                                
    digitalWrite(fwdleft5, LOW);  
    delay(200);
    Serial.print(state);
  }
  }
}
Serial.print(state);
}
