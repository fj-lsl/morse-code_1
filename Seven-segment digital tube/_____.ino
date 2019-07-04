int input=99;
void setup(){
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 Serial.begin(9600);
}
void loop()
{
  while(Serial.available()>0){
   /* Serial.print("I received number's ascall:");
    Serial.println(int(input));
                */
    
    input=Serial.read();
    switch(char(input)){
      case 48:zero();break;
        case 49:one();break;
        case 50:two();break;
        case 51:three();break;
        case 52:four();break;
        case 53:five();break;
        case 54:six();break;
        case 55:seven();break;
        case 56:eight();break;
        case 57:nine();break;
    }
  }
}

void zero(){
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
}

void one(){
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
}

void two(){
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
}

void three(){
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
}

void four(){
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
}

void five(){
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
}

void six(){
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
}

void seven(){
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
}

void eight(){
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
}

void nine(){
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
}
