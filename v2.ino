boolean animation[][4][16] = {
{{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}},
{{0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0}, {0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0}, {0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0}, {0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0}},
{{0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0}, {0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0}, {0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0}, {0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0}},
{{0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0}, {0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0}, {0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0}, {0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0}},
{{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0}},
{{0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0}, {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0}, {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0}, {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0}},
{{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}},
{{0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0}, {0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0}, {0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0}, {0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0}},
{{0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0}, {0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0}, {0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0}, {0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0}},
{{0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0}, {0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0}, {0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0}, {0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0}},
{{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0}},
{{0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0}, {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0}, {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0}, {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0}},

{{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}},
{{0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1}, {0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1}, {0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1}, {0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1}},
{{0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1}},

{{0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1}},
{{0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0}, {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0}, {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0}, {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0}},
{{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}, {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}, {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}, {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
{{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0}, {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0}, {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0}, {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0}},
{{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}, {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}, {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}, {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
{{0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0}, {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0}, {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0}, {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0}},
{{0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1}},

{{0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1}, {0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1}},
{{0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1}, {0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1}, {0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1}, {0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1}},
{{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}, {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}},
};

void setup(){
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}

void loop(){
  for (byte i = 0; i < sizeof(animation)/sizeof(animation[0]); ++i){
    long time = millis();
    while (millis() - time <= 100){
      for (byte x = 0; x < 4; ++x){
        state(animation[i][x], x, true);
        state(animation[i][x], x, false);
      }
    }
  }
}

void state(boolean frame[], byte layer, boolean state){
  switch (layer){
    case 0:
      digWrite(16, !state);
      break;
    case 1:
      digWrite(17, !state);
      break;
    case 2:
      digWrite(18, !state);
      break;
    case 3:
      digWrite(19, !state);
      break;
  }
    
  for (int i = 0; i < 16; ++i){
    if (frame[i]) {
      digWrite(i, state);
    }
  }
}

void digWrite(byte pin, boolean state){
  if (state) {
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }
}