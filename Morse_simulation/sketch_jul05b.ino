int _pin=10;
int _dottime=250;
int input=0;

void setup() {
  pinMode(_pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0){
    input=Serial.read();

    switch(char(input)){
      case 32: w_space();  break;                                //space
      case 97:dot(),dash();  break;                              //a  
      case 98:dash(),dot(),dot(),dot(); break;                   //b
      case 99:dash(),dot(),dash(),dot(); break;                  //c
      case 100:dash(),dot(),dot(); break;                        //d
      case 101:dot();  break;                                    //e
      case 102:dot(),dot(),dash(),dot();  break;                 //f
      case 103:dash(),dash(),dot();  break;                      //g
      case 104:dot(),dot(),dot(),dot();  break;                  //h
      case 105:dot(),dot();   break;                             //i
      case 106:dot(),dash(),dash(),dash(); break;                //j
      case 107:dash(),dot(),dash(); break;                       //k
      case 108:dot(),dash(),dot(),dot();  break;                 //l
      case 109:dash(),dash();  break;                            //m
      case 110:dash(),dot();   break;                            //n
      case 111:dash(),dash(),dash();   break;                    //o
      case 112:dot(),dash(),dash(),dot();  break;                //p
      case 113:dash(),dash(),dot(),dash(); break;                //q
      case 114:dot(),dash(),dot();   break;                      //r
      case 115:dot(),dot(),dot();  break;                        //s
      case 116:dash();      break;                               //t
      case 117:dot(),dot(),dash();    break;                     //u
      case 118:dot(),dot(),dot(),dash();  break;                 //v
      case 119:dot(),dash(),dash();      break;                  //w
      case 120:dash(),dot(),dot(),dash(); break;                 //x
      case 121:dash(),dot(),dash(),dash(); break;                //y
      case 122:dash(),dash(),dot(),dot();  break;                //z
    } 
  }
}

void dot(){
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void dash(){
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}
void c_space(){
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
}

void w_space(){
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
}
