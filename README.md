# Sterownik 4 Sygnalizatorów Świetlnych (Arduino)

Projekt w języku C++ dla platformy Arduino, realizujący automatyczne, cykliczne sterowanie **czteroma niezależnymi sygnalizatorami świetlnymi** (każdy wyposażony w diodę czerwoną i zieloną). 

Program został napisany w sposób bezblokujący (z wykorzystaniem funkcji `millis()` zamiast `delay()`), co zapewnia płynność działania i możliwość łatwej rozbudowy o dodatkowe funkcje (np. przyciski, czujniki).

---

## 🚦 Jak działa algorytm?

Program działa w ciągłej pętli składającej się z dwóch głównych faz bezpieczeństwa:

1. **Faza Zielonego Światła (4 sekundy):**
   * Jeden wybrany sygnalizator świeci na **zielono**, podczas gdy pozostałe trzy świecą na **czerwono**.
2. **Faza Wszystkich Czerwonych (2 sekundy):**
   * Po upływie czasu zielonego, wszystkie sygnalizatory przechodzą w stan **czerwony**. Działa to jako bezpieczny bufor (czas ewakuacji skrzyżowania / przejścia).
3. **Zmiana kierunku:**
   * Po zakończeniu przerwy program przełącza się na kolejny numer sygnalizatora (`1 -> 2 -> 3 -> 4 -> 1`).

---

## 📌 Podłączenie pinów (Schemat)

Konfiguracja pinów cyfrowych Arduino zdefiniowana w kodzie:

| Sygnalizator | Dioda Zielona | Dioda Czerwona |
| :--- | :--- | :--- |
| **Sygnalizator 1** | Pin `13` | Pin `12` |
| **Sygnalizator 2** | Pin `4` | Pin `2` |
| **Sygnalizator 3** | Pin `8` | Pin `7` |
| **Sygnalizator 4** | Pin `11` | Pin `10` |

> *Pamiętaj o zastosowaniu odpowiednich rezystorów (np. 220Ω – 330Ω) szeregowo z każdą diodą LED!*

---

## ⏱️ Konfiguracja czasów

W sekcji `#define CZASY` możesz w każdej chwili zmienić czas trwania poszczególnych faz:

```cpp
#define CZAS_ZIELONE 4000          // Czas zielonego światła w milisekundach (domyślnie 4s)
#define CZAS_WSZYSTKIE_CZERWONE 2000 // Czas przerwy w milisekundach (domyślnie 2s)
