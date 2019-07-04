void setup() {

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

int income=0;
void loop() {
  if(Serial.available()>0){
    income=Serial.read();
    switch(income){
      case 'w':
          forward();
        break;
        case 's':
          backward();
          break;
        case 'd':
          right();
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
          break;
        case 'a':
          left();
        digitalWrite(11,HIGH);
        digitalWrite(12,LOW);
          break;
        case 'f':
          stop();
          break;
      default:
          break;
    }
  } 
}
void backward(){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}
void forward(){
  digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
}
void right(){
  digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);

}
void left(){
  digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
}
void stop(){
  digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
}
