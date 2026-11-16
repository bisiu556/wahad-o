// ============================
// SYGNALIZATOR 1
// ============================

#define ZIELONE_1 13
#define CZERWONE_1 12


// ============================
// SYGNALIZATOR 2
// ============================

#define ZIELONE_2 4
#define CZERWONE_2 2


// ============================
// SYGNALIZATOR 3
// ============================

#define ZIELONE_3 8
#define CZERWONE_3 7


// ============================
// SYGNALIZATOR 4
// ============================

#define ZIELONE_4 11
#define CZERWONE_4 10


// ============================
// CZASY
// ============================

#define CZAS_ZIELONE 4000
#define CZAS_WSZYSTKIE_CZERWONE 2000


// ============================
// ZMIENNE
// ============================

unsigned long poprzedniCzas = 0;

int numerSygnalizatora = 1;

bool zielone = true;


// ============================
// SETUP
// ============================

void setup()
{
  pinMode(ZIELONE_1, OUTPUT);
  pinMode(CZERWONE_1, OUTPUT);

  pinMode(ZIELONE_2, OUTPUT);
  pinMode(CZERWONE_2, OUTPUT);

  pinMode(ZIELONE_3, OUTPUT);
  pinMode(CZERWONE_3, OUTPUT);

  pinMode(ZIELONE_4, OUTPUT);
  pinMode(CZERWONE_4, OUTPUT);


  // Na początku:
  // sygnalizator 1 zielony
  // pozostałe czerwone

  ustawSygnalizator(1);

  poprzedniCzas = millis();
}


// ============================
// LOOP
// ============================

void loop()
{
  unsigned long teraz = millis();


  // ----------------------------
  // JEDNO ZIELONE - 4 SEKUNDY
  // ----------------------------

  if (zielone == true)
  {
    if (teraz - poprzedniCzas >= CZAS_ZIELONE)
    {
      // Wszystkie czerwone
      wszystkieCzerwone();

      zielone = false;

      poprzedniCzas = teraz;
    }
  }


  // ----------------------------
  // WSZYSTKIE CZERWONE - 2 SEKUNDY
  // ----------------------------

  else
  {
    if (teraz - poprzedniCzas >= CZAS_WSZYSTKIE_CZERWONE)
    {
      // Następny sygnalizator
      numerSygnalizatora++;

      if (numerSygnalizatora > 4)
      {
        numerSygnalizatora = 1;
      }

      // Włącz następny zielony
      ustawSygnalizator(numerSygnalizatora);

      zielone = true;

      poprzedniCzas = teraz;
    }
  }
}


// ============================
// WSZYSTKIE CZERWONE
// ============================

void wszystkieCzerwone()
{
  // Czerwone ON
  digitalWrite(CZERWONE_1, HIGH);
  digitalWrite(CZERWONE_2, HIGH);
  digitalWrite(CZERWONE_3, HIGH);
  digitalWrite(CZERWONE_4, HIGH);

  // Zielone OFF
  digitalWrite(ZIELONE_1, LOW);
  digitalWrite(ZIELONE_2, LOW);
  digitalWrite(ZIELONE_3, LOW);
  digitalWrite(ZIELONE_4, LOW);
}


// ============================
// USTAWIENIE SYGNALIZATORA
// ============================

void ustawSygnalizator(int numer)
{
  // Najpierw wszystkie czerwone
  wszystkieCzerwone();


  if (numer == 1)
  {
    digitalWrite(CZERWONE_1, LOW);
    digitalWrite(ZIELONE_1, HIGH);
  }


  if (numer == 2)
  {
    digitalWrite(CZERWONE_2, LOW);
    digitalWrite(ZIELONE_2, HIGH);
  }


  if (numer == 3)
  {
    digitalWrite(CZERWONE_3, LOW);
    digitalWrite(ZIELONE_3, HIGH);
  }


  if (numer == 4)
  {
    digitalWrite(CZERWONE_4, LOW);
    digitalWrite(ZIELONE_4, HIGH);
  }
}
