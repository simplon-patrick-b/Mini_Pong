#include <SoftwareSerial.h>
#include <Minitel.h>

Minitel m;
int x = 0;
int Y = 0;
int Z = 0;
int ballx = 9;
int bally = 6;
int d = 1;
int pa = 0;
int pb = 0;

void setup() {
  m.clearScreen();
  
  m.graphicMode();
  m.moveCursorTo(1, 1);
  while(x < 40){
    m.graphic("111111");
    x++;
    }
  x = 0;
  
  m.moveCursorTo(1, 24);
  while(x < 40){
    m.graphic("111111");
    x++;
    }
  x = 2;
  
  /*while(x < 24){
    m.moveCursorTo(20, x);
    m.graphic("010101");
    m.graphic("101010");
    x = x + 2;
  }*/

  m.textMode();
  m.charSize(SIZE_NORMAL);
  m.text("PONG", 19, 24);
  m.text("Appuie pour commencer !", 1, 1);

  while(digitalRead(2) == 0){
  }

  x = 0;
  m.graphicMode();
  m.moveCursorTo(1, 1);
  while(x < 40){
    m.graphic("111111");
    x++;
    }

  m.textMode();
  m.moveCursorTo(5, 1);
  m.text("0");
  m.moveCursorTo(36, 1);
  m.text("0");
}

void loop() {
  Y = map(analogRead(A1), 0, 1023, 2, 24);
  Z = map(analogRead(A2), 0, 1023, 2, 24);

  m.graphicMode();
  m.moveCursorTo(1, Y);
  m.graphic("111111");
  m.moveCursorTo(40, Z);
  m.graphic("111111");
  m.moveCursorTo(ballx, bally);
  m.graphic("111111");
  m.moveCursorTo(1, Y);
  m.graphic("000000");
  m.moveCursorTo(40, Z);
  m.graphic("000000");
  m.moveCursorTo(ballx, bally);
  m.graphic("000000");

  if(d == 1){
    hd();
  }
  if(d == 2){
    bd();
  }
  if(d == 3){
    bg();
  }
  if(d == 4){
    hg();
  }

  if(bally == 2){
    if(d == 1){
      d = 2; 
    }
    if(d == 4){
      d = 3;
    }
  }

  if(ballx == 39 || ballx == 38){
    if(bally == Z || bally == Z+1 || bally == Z-1){
      if(d == 2){
        d = 3;
      }
      if(d == 1){
        d = 4;
      }
    }
    else{
      pa = pa + 1;
      String A = String(pa);
      m.textMode();
      m.moveCursorTo(5, 1);
      m.text(A);
      ballx = 9;
      bally = 6;
      d = 1;
    }
  }

  if(bally == 23 && d == 3){
    d = 4;
  }

  if(ballx == 2 || ballx == 3){
    if(bally == Y || bally == Y+1 || bally == Y-1){
      if(d == 4){
        d = 1;
      }
      if(d == 3){
        d = 2;
      }
    }
    else{
      pb = pb + 1;
      String B = String(pb);
      m.textMode();
      m.moveCursorTo(36, 1);
      m.text(B);
      ballx = 9;
      bally = 6;
      d = 1;
    }
  }

}

void hd() {
  ballx = ballx + 2;
  bally--;
}

void bd() {
  ballx = ballx + 2;
  bally++;
}

void bg() {
  ballx = ballx - 2;
  bally++;
}

void hg() {
  ballx = ballx - 2;
  bally--;
}
