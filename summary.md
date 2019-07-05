>冯健

>学号：18020100028

>2019/07/02~2019/07/05

## 第一天 开源硬件入门
- 硬件入门
开源硬件课程主要介绍了Arduino uno开发板，基于这块板子开源实现诸多功能，例如实现LED的闪烁控制，Morse电码等等，而且Arduino对初学者比较友好。

- 软件入门
在学习相关软件之前，老师推荐了Linux操作系统，并且强调Linux操作系统在以后编程工作学习中的重要性。但是我对安装系统或是双系统不太熟悉，担心操作不当影响到笔记本，保险起见，我在网上的博客上自己找教程安装虚拟机并安装Ubuntu，还去学习了一些Linux下常用的操作指令，以后也会多多练习，熟悉新的操作系统。之后老师推荐了本课程需要的三款软件：Arduino，fritzing，processing。

- Arduino
课程主要运用C语言在该软件上进行编程，并且可以把代码上传至板子实现功能。

- fritzing
可以实现电路，实物等实时模拟，十分快捷方便

- processing
利用编程语言可以绘制图形等艺术设计，功能十分强大。
## 第二天 代码学习
这一天老师带领我们通过编程进一步学习开源硬件，作为入门，我们首先学习Morse电码的工作原理，并尝试编写代码实现Morse电码，就是输入小写英文字母使板子上的LED灯按照电码的规律闪烁。学会了打包库然后调用，看老师写起来很轻松，一旦自己正在动手起来才发现并没有这么容易。从0到1的过程是最艰难痛苦的，所以我重新利用网络去学习遗漏或缺少的知识，遇到问题找百度或是在群里面发问，同学们的积极性非常高，群里都是在讨论各种各样问题。而当自己完成作业并上传Github时，成就感满满。

- 代码

``` c
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
```
## 第三天 虚拟操作
由于板子不够的问题没办法利用实物完成项目，所以我们在网上模拟了小车轮子以及七段数码管数字的控制。通过这两个例子，学习了小车控制的原理，利用高电平和低电平产生的电压差产生电流从而驱动电机，同时也学习了七段数码管的实现原理。
- 小车控制代码

```c
void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
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
          digitalWrite(11,LOW);
        digitalWrite(12,LOW);
          break;
        case 'a':
          left();
        digitalWrite(11,HIGH);
        digitalWrite(12,LOW);
          digitalWrite(3,LOW);
        digitalWrite(4,LOW);
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
```
- 七段数码管代码：

```c
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
```
## 第四天 模拟Morse电码
通过这些天的学习，我们对相关软件的操作变得熟悉了许多，所以在课程学习的最后一天，我们要实现Morse电码的网上模拟，主要的思路是编写函数实现点和划的功能。

- 代码：

```c
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
```
## 心得体会
虽然学习的时间只有短短的四天时间，但是也领会到了开源硬件的独特魅力。更有趣的是，在学习的过程中，学到了其他附加的知识技能：学习安装Linux并掌握常用操作，学会使用Github，学会了用tinkercad模拟开发板，学会了用arduino编程控制板子等等。所以时间虽短，但收获满满，希望也相信自己在以后的时间里可以更加深入地学习巩固这些技能，毕竟技多不压身，也可以得到快乐和成就感。
