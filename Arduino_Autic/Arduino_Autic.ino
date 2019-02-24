//-------------------------------------------------------------------
//----------------------- VIDI 257/258 ----------------------------------
//--- kod za upravljanje autićem uz pomoć bluetootha i smartphona ---
//--- napisan za potrebe članka u časopisu VIDI 256 - srpanj 2017. --
//-------------------------------------------------------------------
//
// Ovaj kod radi s Arduino Mega i Leonardo
// Bluetooth modul HC-05 ili HC-06 spojiti s digitlnim pinovima 
//                (Serial port 1) 0 i 1 (Tx i Rx pinovi)
//-------------------------------------------------------------------
// napisao: Hrvoje Šomođi, Vidi - 16.6.2017.
//-------------------------------------------------------------------
// Kod je izdan pod Creative Commons licencom - CC BY 3.0 HR
// https://creativecommons.org/licenses/by/3.0/hr/
// Možete umnažati i redistribuirati kod  u bilo kojem mediju ili formatu.
// Možete remiksirati, mijenjati i prerađivati kod u bilo koju svrhu, pa i komercijalnu.
// Morate adekvatno navesti autora, uvrstiti link na licencu i naznačiti eventualne izmjene.
// Možete to učiniti na bilo koji razuman način, ali ne smijete sugerirati da davatelj 
// licence izravno podupire Vas ili Vaše korištenje djela.
// Ne smijete dodavati pravne uvjete ili tehnološke mjere zaštite koji će druge pravno 
// ograničiti da čine ono što im licenca dopušta.
//

// bluetooth varijabla
int dataFromBt;

// Stražnji Motor
int eR = 5;  // PWM Pin
int inR1 = 12;
int inR2 = 13;

// Prednji Motor
int eF = 6;  // PWM Pin
int inF1 = 10;
int inF2 = 11;

// brzina
#define MAX_SPEED 255
int speed = MAX_SPEED;
int speedLevel;

void setup()
{
  // inicijalizacija bluetooth modula
  Serial1.begin(9600);

  // postavi zadanje pinove kao output pinove
  pinMode(eR, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);

  pinMode(eF, OUTPUT);
  pinMode(inF1, OUTPUT);
  pinMode(inF2, OUTPUT);

  // postavi vrijednosti zadanih pinova na LOW ili nulu
  // kako autić nebi nekontrolirano kretao prilikom bootanja Arduina
  analogWrite(eR, 0);
  digitalWrite(inR1, 0);
  digitalWrite(inR2, 0);
  analogWrite(eF, 0);
  digitalWrite(inF1, 0);
  digitalWrite(inF2, 0);
}

void loop()
{
  // čitaj s porta 1 i šalji na port 0 za debuging kod Leonarda ili Mega:
  // za Arduino UNO zakomentirate naredne 4 linije koda
  // tako da ispred njih stavite //
  if (Serial1.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
  
  // Primi li bluetooth informaciju, pročitaj ju
  if (Serial1.available()) {
    dataFromBt = Serial1.read();

  // Obradi primljena slova prema 
  // zadanoj namjeni s aplikacije Arduino bluetooth RC Car
  // koju pronađite na http://bit.ly/2rhdpq2
 
    switch(dataFromBt) {
      // naprijed
      case 'F': case 'f':
        setMotorRear(speed, 0);
        break;
      // nazad
      case 'B': case 'b':
        setMotorRear(speed, 1);
        break;
      // lijevo
      case 'L': case 'l':
        setMotorFront(speed, 1);
        break;
      // desno
      case 'R': case 'r':
        setMotorFront(speed, 0);
        break;
      // naprijed lijevo
      case 'G': case 'g':
        setMotorRear(speed, 0);
        setMotorFront(speed, 1);
        break;
      // naprijed desno
      case 'I': case 'i':
        setMotorRear(speed, 0);
        setMotorFront(speed, 0);
        break;
      // nazad desno
      case 'H': case 'h':
        setMotorRear(speed, 1);
        setMotorFront(speed, 1);
        break;
      // nazad lijevo
      case 'J': case 'j':
        setMotorRear(speed, 1);
        setMotorFront(speed, 0);
        break;
      // stop
      case 'S': case 's':
        setMotorRear(0, 0);
        setMotorFront(0, 0);
        break;
      // brzina
      case '1': case '2': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9': case '0':
        speedLevel = dataFromBt - '0';
        speed = MAX_SPEED - (10 - speedLevel) * 5;
        break;
      case 'q':
        speed = MAX_SPEED;
        break;
    }
  }
}

void setMotorRear(int speed, boolean reverse)
{
  analogWrite(eR, speed);
  digitalWrite(inR1, reverse);
  digitalWrite(inR2, !reverse);
}

void setMotorFront(int speed, boolean reverse)
{
  analogWrite(eF, speed);
  digitalWrite(inF1, !reverse);
  digitalWrite(inF2, reverse);
}
