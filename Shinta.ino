
#include <ros.h>
#include <turtlesim/Velocity.h>
#define motorkiriplus 2
#define motorkirimin 4

#define motorkananplus 5
#define motorkananmin 7

#define motorkiripwm 3
#define motorkananpwm 6
ros::NodeHandle  nh;

void turn_left(){
 digitalWrite(motorkiriplus,HIGH);
 digitalWrite(motorkirimin,LOW);
 
 
 digitalWrite(motorkananplus,LOW);
 digitalWrite(motorkananmin,HIGH);

 
}
void stop(){
 digitalWrite(motorkiriplus,LOW);
 digitalWrite(motorkirimin,LOW);
 
 
 digitalWrite(motorkananplus,LOW);
 digitalWrite(motorkananmin,LOW);
 
}
void turn_right(){
 digitalWrite(motorkiriplus,LOW);
 digitalWrite(motorkirimin,HIGH);
 
 
 digitalWrite(motorkananplus,HIGH);
 digitalWrite(motorkananmin,LOW);
}

void forward(){
  digitalWrite(motorkiriplus,HIGH);
 digitalWrite(motorkirimin,LOW);
 
 
 digitalWrite(motorkananplus,HIGH);
 digitalWrite(motorkananmin,LOW);
}

void backward(){
  digitalWrite(motorkiriplus,LOW);
 digitalWrite(motorkirimin,HIGH);
 
 
 digitalWrite(motorkananplus,LOW);
 digitalWrite(motorkananmin,HIGH);
}

void messageCb( const turtlesim::Velocity& vel){
  if (vel.linear==2.0){
   forward();
  }
  else if(vel.linear==-2.0)
  {
    backward();
  }
  else if(vel.angular==2.0)
  {
    turn_right();
  }
  else if(vel.angular==-2.0)
  {
    turn_left();
  }else
  {
    stop();
  }  
  delay(100);
  stop();
  
}

ros::Subscriber<turtlesim::Velocity> sub("turtle1/command_velocity", &messageCb );

void setup()
{ 
 pinMode(motorkiriplus, OUTPUT);
 pinMode(motorkananpwm, OUTPUT);
 pinMode(motorkirimin, OUTPUT);

pinMode(motorkananplus, OUTPUT);
  pinMode(motorkananmin, OUTPUT);
  pinMode(motorkananpwm, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  digitalWrite(motorkiripwm,HIGH);
  digitalWrite(motorkananpwm,HIGH);
  delay(1);
}

