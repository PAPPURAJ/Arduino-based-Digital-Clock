
#include <virtuabotixRTC.h> //Library used
int intencity = 255;
int del = 1;
int H=1,M=0,te,blinker=0;


//Wiring SCLK -> 6, I/O -> 7, CE -> 8
//Or CLK -> 6 , DAT -> 7, Reset -> 8

virtuabotixRTC myRTC(4, 3, 2);

void setup() { pinMode(A0,INPUT_PULLUP);
   pinMode(12,INPUT_PULLUP);
    pinMode(0,INPUT_PULLUP);

    
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5,OUTPUT);

 
  

  Serial.begin(9600);

myRTC.updateTime();
M=myRTC.minutes;

te = myRTC.hours;
                              if (te > 12)
                                te -= 12;
                              else if (te == 0)
                                te = 12;
                              digitalWrite(6, 0);
                              digitalWrite(9, 0);
                              digitalWrite(10, 1);
                              digitalWrite(11, 0);
                              H=te;

  // seconds, minutes, hours, day of the week, day of the month, month, year
  //myRTC.setDS1302Time(00, 00, 2, 5, 18, 03, 2020);

}



void loop() {
 
  
  if(!digitalRead(12)){


                       
                            
                                      
                              myRTC.updateTime();
                              digitalWrite(6, 1);
                              digitalWrite(9, 0);
                              digitalWrite(10, 0);
                              digitalWrite(11, 0);
                              M=myRTC.minutes;
                              digit(M%10);
                            
                              
                              delay(del);
                            
                              
                              myRTC.updateTime();
                              digitalWrite(6, 0);
                              digitalWrite(9, 1);
                              digitalWrite(10, 0);
                              digitalWrite(11, 0);

                              if(blinker++<75)
                                  digitalWrite(5,1);
                                else
                                   digitalWrite(5,0);
                                if(blinker>=130)
                                  blinker=0;

                              
                              digit(M/10);
                              delay(del);
                              
                              myRTC.updateTime();
                              te = myRTC.hours;
                              if (te > 12)
                                te -= 12;
                              else if (te == 0)
                                te = 12;
                              digitalWrite(6, 0);
                              digitalWrite(9, 0);
                              digitalWrite(10, 1);
                              digitalWrite(11, 0);
                              H=te;
                              digit(H%10);
                            
                              
                              delay(del);
                            
                              
                              myRTC.updateTime();
                             
                               digitalWrite(6, 0);
                              digitalWrite(9, 0);
                              digitalWrite(10, 0);
                              digitalWrite(11, 1);
                              
//                              else{
//                                    digitalWrite(6, 0);
//                              digitalWrite(9, 0);
//                              digitalWrite(10, 0);
//                              digitalWrite(11, 0);
//                              }
//                             
//                              digit(H/10);
//                              delay(del);

    Serial.println("In if");
  }

  else{
    Serial.println("Else");

          if(!digitalRead(0)){

            delay(150); M++;
          }
           

           if(!digitalRead(A0)){
            delay(150);
            H++;
           }
              
                 if(H>12)
                                H=1;

                           if(M>59)
                            
                           
                              M=0;
                         

                                
                              digitalWrite(6, 1);
                              digitalWrite(9, 0);
                              digitalWrite(10, 0);
                              digitalWrite(11, 0);
                              digit(M%10);
                            
                              
                              delay(2);
                            
                              digitalWrite(6, 0);
                              digitalWrite(9, 1);
                              digitalWrite(10, 0);
                              digitalWrite(11, 0);
                              digit(M/10);
                              delay(2);
                              
                             
                                
                              digitalWrite(6, 0);
                              digitalWrite(9, 0);
                              digitalWrite(10, 1);
                              digitalWrite(11, 0);
                              digit(H%10);
                            
                              
                              delay(2);
                            
                              
                              digitalWrite(6, 0);
                              digitalWrite(9, 0);
                              digitalWrite(10, 0);
                              digitalWrite(11, 1);
                         
                              digit(H/10);
                              delay(2);
                              
    myRTC.setDS1302Time(00, M, H, 5, 18, 03, 2020);

    
  }



}



void digit(int p) {
  digitalWrite(A1, 1);
  digitalWrite(A2, 1);
  digitalWrite(A3, 1);
  digitalWrite(A4, 1);
  digitalWrite(A5, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);

  switch (p) {
    case 0: {
        digitalWrite(A1, 0);
        digitalWrite(A2, 0);
        digitalWrite(A3, 0);
        digitalWrite(A4, 0);
        digitalWrite(A5, 0);
        digitalWrite(7, 0);


        break;
      }

    case 1: {
        digitalWrite(A2, 0);
        digitalWrite(A3, 0);
        break;
      }

    case 2: {
        digitalWrite(A1, 0);
        digitalWrite(A2, 0);
        digitalWrite(8, 0);
        digitalWrite(A5, 0);
        digitalWrite(A4, 0);
        break;
      }
    case 3: {
        digitalWrite(A1, 0);
        digitalWrite(A2, 0);
        digitalWrite(A3, 0);
        digitalWrite(A4, 0);
        digitalWrite(8, 0);
        break;
      }
    case 4: {
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(A2, 0);
        digitalWrite(A3, 0);
        break;
      }
    case 5: {
        digitalWrite(A1, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(A3, 0);
        digitalWrite(A4, 0);
        break;
      }
    case 6: {
        digitalWrite(A1, 0);
        digitalWrite(A3, 0);
        digitalWrite(A4, 0);
        digitalWrite(A5, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        break;
      }
    case 7: {
        digitalWrite(A1, 0);
        digitalWrite(A2, 0);
        digitalWrite(A3, 0);
        break;
      }
    case 8: {
        digitalWrite(A1, 0);
        digitalWrite(A2, 0);
        digitalWrite(A3, 0);
        digitalWrite(A4, 0);
        digitalWrite(A5, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        break;
      }

    case 9: {
        digitalWrite(A1, 0);
        digitalWrite(A2, 0);
        digitalWrite(A3, 0);
        digitalWrite(A4, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        break;
      }





  }




}










//int del=3;
void Display(int a, int b, int c, int d) {
  myRTC.updateTime();
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digit(myRTC.minutes % 10);
  //delay(del);
  myRTC.updateTime();
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digit(myRTC.minutes / 10);
  //delay(del);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digit(myRTC.hours % 10);
  //delay(del);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digit(myRTC.hours / 10);
  //delay(del);



}




void serial(){

  //myRTC.updateTime();


   Serial.print("Current Date / Time: ");
   Serial.print(myRTC.dayofmonth); //You can switch between day and month if you're using American system
   Serial.print("/");
   Serial.print(myRTC.month);
   Serial.print("/");
   Serial.print(myRTC.year);
   Serial.print(" ");
   Serial.print(myRTC.hours);
   Serial.print(":");
   Serial.print(myRTC.minutes);
   Serial.print(":");
   Serial.println(myRTC.seconds);
  Display(myRTC.hours/10,myRTC.hours%10,myRTC.seconds/10,myRTC.seconds%10);
  
}