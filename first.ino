#include <Morse.h>

Morse morse(13);

int m=0;
int input=0;
void setup() {
 Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0){
    input=Serial.read();

    switch(char(input)){
      case 32:   morse.w_space();  break;                                //space
      case 97:morse.dot(),morse.dash();  break;                          //a  
      case 98:morse.dash(),morse.dot(),morse.dot(),morse.dot(); break;   //b
      case 99:morse.dash(),morse.dot(),morse.dash(),morse.dot(); break;  //c
      case 100:morse.dash(),morse.dot(),morse.dot(); break;              //d
      case 101:morse.dot();  break;                                      //e
      case 102:morse.dot(),morse.dot(),morse.dash(),morse.dot();  break; //f
      case 103:morse.dash(),morse.dash(),morse.dot();  break;            //g
      case 104:morse.dot(),morse.dot(),morse.dot(),morse.dot();  break;  //h
      case 105:morse.dot(),morse.dot();   break;                         //i
      case 106:morse.dot(),morse.dash(),morse.dash(),morse.dash(); break;//j
      case 107:morse.dash(),morse.dot(),morse.dash(); break;             //k
      case 108:morse.dot(),morse.dash(),morse.dot(),morse.dot();  break; //l
      case 109:morse.dash(),morse.dash();  break;                        //m
      case 110:morse.dash(),morse.dot();   break;                        //n
      case 111:morse.dash(),morse.dash(),morse.dash();   break;          //o
      case 112:morse.dot(),morse.dash(),morse.dash(),morse.dot();  break;//p
      case 113:morse.dash(),morse.dash(),morse.dot(),morse.dash(); break;//q
      case 114:morse.dot(),morse.dash(),morse.dot();   break;            //r
      case 115:morse.dot(),morse.dot(),morse.dot();  break;              //s
      case 116:morse.dash();      break;                                 //t
      case 117:morse.dot(),morse.dot(),morse.dash();    break;           //u
      case 118:morse.dot(),morse.dot(),morse.dot(),morse.dash();  break; //v
      case 119:morse.dot(),morse.dash(),morse.dash();      break;        //w
      case 120:morse.dash(),morse.dot(),morse.dot(),morse.dash(); break; //x
      case 121:morse.dash(),morse.dot(),morse.dash(),morse.dash(); break;//y
      case 122:morse.dash(),morse.dash(),morse.dot(),morse.dot();  break;//z
    } 
  }

}
