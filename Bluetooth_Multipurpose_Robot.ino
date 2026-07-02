#include <SoftwareSerial.h>


SoftwareSerial bt(2, 3);  

#define LF 8   
#define LB 9  
#define RF 10   
#define RB 11   


#define PF 4
#define PB 5
#define SF 6
#define SB 7
#define W 1

void setup() {

  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(W,OUTPUT);
  pinMode(PF, OUTPUT);
    pinMode(PB, OUTPUT);
      pinMode(SB, OUTPUT);
    pinMode(SF, OUTPUT);



  digitalWrite(PF, LOW);
  digitalWrite(PB, LOW);
  digitalWrite(SF, LOW);
    digitalWrite(SB, LOW);
   digitalWrite(W, LOW);

  bt.begin(9600);
}

void loop() {
  bt.listen();
  while (bt.available()) {
    char ch = bt.read();
    if(ch== 'F')
    {
      digitalWrite(LF, HIGH);
      digitalWrite(RF, HIGH);
      digitalWrite(LB, LOW);
      digitalWrite(RB, LOW);
    }

    else if (ch == 'B') { 
      digitalWrite(LB, HIGH);
      digitalWrite(RB, HIGH);
      digitalWrite(LF, LOW);
      digitalWrite(RF, LOW);
    }

    else if (ch == 'L') { 
      digitalWrite(LB, HIGH);
      digitalWrite(RF, HIGH);
      digitalWrite(LF, LOW);
      digitalWrite(RB, LOW);
      delay(1000);
          digitalWrite(LF, LOW);
      digitalWrite(LB, LOW);
      digitalWrite(RF, LOW);
      digitalWrite(RB, LOW);

    }

    else if (ch == 'R') {   
      digitalWrite(LF, HIGH);
      digitalWrite(RB, HIGH);
      digitalWrite(LB, LOW);
      digitalWrite(RF, LOW);
        delay(1000);
          digitalWrite(LF, LOW);
      digitalWrite(LB, LOW);
      digitalWrite(RF, LOW);
      digitalWrite(RB, LOW);
    }

    else if (ch == 'S') {
      digitalWrite(LF, LOW);
      digitalWrite(LB, LOW);
      digitalWrite(RF, LOW);
      digitalWrite(RB, LOW);
    }


    else if (ch == '1') {   
      digitalWrite(PF, HIGH);
        digitalWrite(PB, LOW);
        delay(1000);
          digitalWrite(PF,LOW);
            digitalWrite(PB, LOW);
    }

    else if (ch == '2') {   
    digitalWrite(PF, LOW);
        digitalWrite(PB,HIGH);
        delay(1000);
          digitalWrite(PF,LOW);
            digitalWrite(PB, LOW);
    }
    else if (ch == '3') {   
      digitalWrite(SF, HIGH);
       digitalWrite(SB, LOW);
    
   
    }
      else if (ch == '4') {   
      digitalWrite(SF, LOW);
       digitalWrite(SB, LOW);
   
   
    }
    else if (ch == '5') {   
      digitalWrite(W,HIGH);
   
    }
    else if (ch == '6') {   
      digitalWrite(W,LOW);
   
    }


  }
}
