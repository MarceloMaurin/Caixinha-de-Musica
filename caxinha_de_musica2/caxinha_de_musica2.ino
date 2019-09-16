//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


//#include "max6675.h" //INCLUSÃO DE BIBLIOTECA
 
int ktcSO = 8; //PINO DIGITAL (SO)
int ktcCS = 9; //PINO DIGITAL (CS)
int ktcCLK = 10; //PINO DIGITAL (CLK / SCK)

//MAX6675 ktc(ktcCLK, ktcCS, ktcSO); //CRIA UMA INSTÂNCIA UTILIZANDO OS PINOS (CLK, CS, SO)
  
char info[40];
// These constants won't change. They're used to give names to the pins used:
int pinledOutVerde = 13;  // Analog input pin that the potentiometer is attached to
int pinledInVerde = A2; // Analog output pin that the LED is attached to

int pinledOutButton = A2;  // Analog input pin that the potentiometer is attached to
int pinledInButton = A3; // Analog output pin that the LED is attached to

int pinSpeak = 4;
boolean ledOnOff = true;

int ultimovalor;
int ultimamusica = 0;
char lastmusica[40]; 

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


/*
 * Definicao das notas
 * Segue o padrao de nomenclatura em ingles
 */
#define  C0 16.35
#define Db0 17.32
#define D0  18.35
#define Eb0 19.45
#define E0  20.60
#define F0  21.83
#define Gb0 23.12
#define G0  24.50
#define Ab0 25.96
#define LA0 27.50
#define Bb0 29.14
#define B0  30.87
#define C1  32.70
#define Db1 34.65
#define D1  36.71
#define Eb1 38.89
#define E1  41.20
#define F1  43.65
#define Gb1 46.25
#define G1  49.00
#define Ab1 51.91
#define LA1 55.00
#define Bb1 58.27
#define B1  61.74
#define C2  65.41
#define Db2 69.30
#define D2  73.42
#define Eb2 77.78
#define E2  82.41
#define F2  87.31
#define Gb2 92.50
#define G2  98.00
#define Ab2 103.83
#define LA2 110.00
#define Bb2 116.54
#define B2  123.47
#define C3  130.81
#define Db3 138.59
#define D3  146.83
#define Eb3 155.56
#define E3  164.81
#define F3  174.61
#define Gb3 185.00
#define G3  196.00
#define Ab3 207.65
#define LA3 220.00
#define Bb3 233.08
#define B3  246.94
#define C4  261.63
#define Db4 277.18
#define D4  293.66
#define Eb4 311.13
#define E4  329.63
#define F4  349.23
#define Gb4 369.99
#define G4  392.00
#define Ab4 415.30
#define LA4 440.00
#define Bb4 466.16
#define B4  493.88
#define C5  523.25
#define Db5 554.37
#define D5  587.33
#define Eb5 622.25
#define E5  659.26
#define F5  698.46
#define Gb5 739.99
#define G5  783.99
#define Ab5 830.61
#define LA5 880.00
#define Bb5 932.33
#define B5  987.77
#define C6  1046.50
#define Db6 1108.73
#define D6  1174.66
#define Eb6 1244.51
#define E6  1318.51
#define F6  1396.91
#define Gb6 1479.98
#define G6  1567.98
#define Ab6 1661.22
#define LA6 1760.00
#define Bb6 1864.66
#define B6  1975.53
#define C7  2093.00
#define Db7 2217.46
#define D7  2349.32
#define Eb7 2489.02
#define E7  2637.02
#define F7  2793.83
#define Gb7 2959.96
#define G7  3135.96
#define Ab7 3322.44
#define LA7 3520.01
#define Bb7 3729.31
#define B7  3951.07
#define C8  4186.01
#define Db8 4434.92
#define D8  4698.64
#define Eb8 4978.03
/* 
 *  Duracao das notas
 */
void Hello();
void Natal();

int length = 26;
char notes[] = "eeeeeeegcde fffffeeeeddedg";
int beats[] = { 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};
int tempo = 300;
 
//melodia do MARIO THEME
int melodia[] = {660,660,660,510,660,770,380,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,500,500,500,580,660,500,430,380,500,500,500,500,580,660,870,760,500,500,500,500,580,660,500,430,380,660,660,660,510,660,770,380};

//duraçao de cada nota
int duracaodasnotas[] = {100,100,100,100,100,100,100,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,60,80,60,80,80,80,80,80,80,60,80,60,80,80,80,80,80,60,80,60,80,80,80,80,80,80,100,100,100,100,100,100,100};


#define BPM 120    //  you can change this value changing all the others
#define H 2*Q //half 2/4
#define Q 60000/BPM //quarter 1/4 
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void Start_LCD(){
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

}

void Start_Serial(){
    Serial.begin(9600); //INICIALIZA A SERIAL
}

void Start_Temp(){

  delay(500); //INTERVALO DE 500 MILISSEGUNDOS
}

void Start_Button(){
  pinMode(pinledOutButton, OUTPUT);
  pinMode(pinledInButton, INPUT);
  digitalWrite(pinledOutButton, HIGH);
}

void Start_Led(){
  pinMode(pinledOutVerde, OUTPUT);
  pinMode(pinledInVerde, INPUT);
  digitalWrite(pinledOutVerde, HIGH);
  //digitalWrite(pinledInVerde, LOW);
}

void Start_Speak() {     
 pinMode(pinSpeak, OUTPUT);       

}


void setup()
{
  Start_Serial();
  Start_LCD();
  Start_Led();
  Start_Speak();
  Start_Button();
  Start_Temp();
  Hello();
  //Marcha();
  //Mario();
  //Natal();
  //Fim();
  ultimovalor = LOW;

}

void Fim() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(pinSpeak, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pinSpeak);
  }
}


void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(pinSpeak, HIGH);
    delayMicroseconds(tone);
    digitalWrite(pinSpeak, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}


void Natal() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
      blinky();
    } else {
      playNote(notes[i], beats[i] * tempo);
      blinky();
    }

    // pause between notes
    delay(tempo / 2); 
  }
}

void blinky() {
  if (ledOnOff == true) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    ledOnOff = !ledOnOff;
  }
  else {
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    ledOnOff = !ledOnOff;
  }
}

void Mario() {
  //for para tocar as 156 notas começando no 0 ate 156 ++ incrementado
        for (int nota = 0; nota < 156; nota++) {

              int duracaodanota = duracaodasnotas[nota];
              tone(pinSpeak, melodia[nota],duracaodanota);
  //pausa depois das notas
              int pausadepoisdasnotas[] ={150,300,300,100,300,550,575,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,150,300,350,150,350,150,300,150,600,150,300,350,150,150,550,325,600,150,300,350,150,350,150,300,150,600,150,300,300,100,300,550,575};
              delay(pausadepoisdasnotas[nota]);}

              noTone(pinSpeak);
}

// the loop routine runs over and over again forever:
void Marcha() {
  //tone(pin, note, duration)
    tone(pinSpeak,LA3,Q); 
    delay(1+Q); //delay duration should always be 1 ms more than the note in order to separate them.
    tone(pinSpeak,LA3,Q);
    delay(1+Q);
    tone(pinSpeak,LA3,Q);
    delay(1+Q);
    tone(pinSpeak,F3,E+S);
    delay(1+E+S);
    tone(pinSpeak,C4,S);
    delay(1+S);
    
    tone(pinSpeak,LA3,Q);
    delay(1+Q);
    tone(pinSpeak,F3,E+S);
    delay(1+E+S);
    tone(pinSpeak,C4,S);
    delay(1+S);
    tone(pinSpeak,LA3,H);
    delay(1+H);
    
    tone(pinSpeak,E4,Q); 
    delay(1+Q); 
    tone(pinSpeak,E4,Q);
    delay(1+Q);
    tone(pinSpeak,E4,Q);
    delay(1+Q);
    tone(pinSpeak,F4,E+S);
    delay(1+E+S);
    tone(pinSpeak,C4,S);
    delay(1+S);
    
    tone(pinSpeak,Ab3,Q);
    delay(1+Q);
    tone(pinSpeak,F3,E+S);
    delay(1+E+S);
    tone(pinSpeak,C4,S);
    delay(1+S);
    tone(pinSpeak,LA3,H);
    delay(1+H);
    
    tone(pinSpeak,LA4,Q);
    delay(1+Q);
    tone(pinSpeak,LA3,E+S);
    delay(1+E+S);
    tone(pinSpeak,LA3,S);
    delay(1+S);
    tone(pinSpeak,LA4,Q);
    delay(1+Q);
    tone(pinSpeak,Ab4,E+S);
    delay(1+E+S);
    tone(pinSpeak,G4,S);
    delay(1+S);
    
    tone(pinSpeak,Gb4,S);
    delay(1+S);
    tone(pinSpeak,E4,S);
    delay(1+S);
    tone(pinSpeak,F4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(pinSpeak,Bb3,E);
    delay(1+E);
    tone(pinSpeak,Eb4,Q);
    delay(1+Q);
    tone(pinSpeak,D4,E+S);
    delay(1+E+S);
    tone(pinSpeak,Db4,S);
    delay(1+S);
    
    tone(pinSpeak,C4,S);
    delay(1+S);
    tone(pinSpeak,B3,S);
    delay(1+S);
    tone(pinSpeak,C4,E);
    delay(1+E);
    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(pinSpeak,F3,E);
    delay(1+E);
    tone(pinSpeak,Ab3,Q);
    delay(1+Q);
    tone(pinSpeak,F3,E+S);
    delay(1+E+S);
    tone(pinSpeak,LA3,S);
    delay(1+S);
    
    tone(pinSpeak,C4,Q);
    delay(1+Q);
     tone(pinSpeak,LA3,E+S);
    delay(1+E+S);
    tone(pinSpeak,C4,S);
    delay(1+S);
    tone(pinSpeak,E4,H);
    delay(1+H);
    
     tone(pinSpeak,LA4,Q);
    delay(1+Q);
    tone(pinSpeak,LA3,E+S);
    delay(1+E+S);
    tone(pinSpeak,LA3,S);
    delay(1+S);
    tone(pinSpeak,LA4,Q);
    delay(1+Q);
    tone(pinSpeak,Ab4,E+S);
    delay(1+E+S);
    tone(pinSpeak,G4,S);
    delay(1+S);
    
    tone(pinSpeak,Gb4,S);
    delay(1+S);
    tone(pinSpeak,E4,S);
    delay(1+S);
    tone(pinSpeak,F4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(pinSpeak,Bb3,E);
    delay(1+E);
    tone(pinSpeak,Eb4,Q);
    delay(1+Q);
    tone(pinSpeak,D4,E+S);
    delay(1+E+S);
    tone(pinSpeak,Db4,S);
    delay(1+S);
    
    tone(pinSpeak,C4,S);
    delay(1+S);
    tone(pinSpeak,B3,S);
    delay(1+S);
    tone(pinSpeak,C4,E);
    delay(1+E);
    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(pinSpeak,F3,E);
    delay(1+E);
    tone(pinSpeak,Ab3,Q);
    delay(1+Q);
    tone(pinSpeak,F3,E+S);
    delay(1+E+S);
    tone(pinSpeak,C4,S);
    delay(1+S);
    
    tone(pinSpeak,LA3,Q);
    delay(1+Q);
     tone(pinSpeak,F3,E+S);
    delay(1+E+S);
    tone(pinSpeak,C4,S);
    delay(1+S);
    tone(pinSpeak,LA3,H);
    delay(1+H);
    
    delay(2*H);
    
}

void Hello(){
  lcd.setCursor(3,0);
  lcd.print("    Monica  ");
  lcd.setCursor(0,1);
  lcd.print("====================");
  lcd.setCursor(0,2);
  lcd.print("Caixinha  de  musica");
  lcd.setCursor(2,3);
  lcd.print("Power By Maurin!");
  delay(4000);
}

void Mensagem(){
  delay(300);
}

void Musica(){
  if (ultimamusica==3){
    sprintf(lastmusica,"Musica: Marcha ");
    Mensagem();
    Marcha();  
    ultimamusica = 0;
    Serial.println("Saiu Marcha");
  }  
  if (ultimamusica==2){
    sprintf(lastmusica,"Musica: Marcha ");
    Mensagem();
    Marcha();  
    ultimamusica++;
    Serial.println("Saiu Marcha");
  }
 if (ultimamusica==1){
    sprintf(lastmusica, "Musica: Natal ");
    Mensagem();
    Natal();  
    ultimamusica++;
    Serial.println("Saiu Natal");
  }
  if (ultimamusica==0){
    sprintf(lastmusica, "Musica: Mario ");
    Mensagem();
   
    //Mario();
    ultimamusica++;
    Serial.println("Saiu Mario");
  }  
}

void ApagaLampada(){
   digitalWrite(pinledOutVerde, HIGH);
}

void AcendeLampada(){
   digitalWrite(pinledOutVerde, LOW);
}

void Le_Botao(){
  int valor = digitalRead(pinledInButton);
  //valor = HIGH;
  if(valor==LOW){
    if(ultimovalor != valor){
      AcendeLampada();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
      Musica();
    }
  } else {
    if(ultimovalor != valor){
      sprintf(lastmusica," Abra a Caixa  ");
      Mensagem();
      ApagaLampada();
      Fim();
      
    }
  }
  ultimovalor = valor;
}

void Le_Temp(){
  Mensagem();
}

void Leituras(){
  Le_Botao();
  Le_Temp();
}


void loop(){
  
  Leituras();
  delay(500);
}
