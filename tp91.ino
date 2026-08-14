#define buzzer 8
#define boton1 2
#define boton2 4
#define boton3 7

#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))

// Notas MIDI 1
#define F3 175
#define D4 294
#define B2 123
#define Ab2 117
#define E3 165
#define Db3 156
#define D3 147
#define Cb3 139
#define A2 110
#define Fb3 185
#define A3 220
#define G3 196
#define Gb3 208
#define Ab3 233
#define B3 247
#define E4 330
#define Db4 311
#define Cb4 277
#define F4 349
#define C3 131

const int midi1[25][3] = {
  {F3, 136, 818},
  {D4, 136, 273},
  {B2, 136, 136},
  {Ab2, 136, 1091},
  {F3, 136, 136},
  {E3, 136, 136},
  {Db3, 136, 136},
  {D3, 136, 409},
  {Cb3, 136, 545},
  {A2, 136, 273},
  {Fb3, 136, 136},
  {A3, 136, 545},
  {G3, 136, 273},
  {Gb3, 136, 273},
  {Ab3, 136, 273},
  {B3, 136, 273},
  {D4, 136, 273},
  {E4, 136, 273},
  {Db4, 136, 273},
  {Cb4, 136, 273},
  {B3, 136, 273},
  {A3, 136, 273},
  {F4, 136, 273},
  {C3, 136, 0}
};


// MIDI 2
#define F2 87
#define G2 98
#define E2 82
#define Gb2 104

const int midi2[21][3] = {
  {F2, 136, 136},
  {G2, 136, 136},
  {F2, 136, 273},
  {G2, 136, 136},
  {F2, 136, 136},
  {A2, 136, 0},
  {E2, 136, 273},
  {Gb2, 136, 136},
  {E2, 136, 273},
  {G2, 136, 136},
  {Ab2, 136, 0},
  {E2, 136, 136},
  {Gb2, 136, 273},
  {Ab2, 136, 136},
  {C3, 136, 0},
  {Db3, 136, 136},
  {F3, 136, 0},
  {Db3, 136, 0},
  {Cb3, 136, 136},
  {Db3, 136, 409},
  {F2, 136, 0}
};


// MIDI 3
const int midi3[20][3] = {
  {Gb2, 136, 273},
  {D3, 136, 273},
  {F3, 136, 136},
  {C3, 136, 409},
  {F3, 136, 273},
  {F3, 136, 273},
  {F3, 136, 136},
  {G3, 136, 136},
  {E3, 136, 409},
  {E3, 136, 136},
  {Cb3, 136, 136},
  {Gb2, 136, 136},
  {Cb3, 136, 0},
  {Ab2, 136, 136},
  {Cb3, 136, 0},
  {Ab2, 136, 273},
  {F3, 136, 273},
  {A2, 136, 136},
  {Cb3, 136, 273},
  {F3, 136, 0}
};


void playMidi(int pin, const int notes[][3], size_t len)
{
  for (int i = 0; i < len; i++)
  {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);

    noTone(pin);
    delay(notes[i][2]);
  }
}


void setup()
{
  pinMode(buzzer, OUTPUT);

  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(boton3, INPUT_PULLUP);
}


void loop()
{
  if (digitalRead(boton1) == LOW)
  {
    playMidi(buzzer, midi1, ARRAY_LEN(midi1));
  }
  else if (digitalRead(boton2) == LOW)
  {
    playMidi(buzzer, midi2, ARRAY_LEN(midi2));
  }
  else if (digitalRead(boton3) == LOW)
  {
    playMidi(buzzer, midi3, ARRAY_LEN(midi3));
  }
}