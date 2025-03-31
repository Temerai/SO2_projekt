# SO2_projekt - 1. Problem Jedzących Filozofów
---
## Jak uruchomić program?
### 1. Sklonuj repozytorium projektu
1. Otwórz wiersz poleceń
2. Wykonaj następujące komendy:
```shell
git clone https://github.com/Temerai/SO2_projekt.git
cd SO2_projekt

```

### 2. Pobierz i zainstaluj CMake (3.30 lub nowszy)
Link --> https://cmake.org/download/

### 3. Kompilator
Do kompilacji projektu proponuję wykorzystać Visual Studio. Nie jest to wymagane natomiast dalsza część instrukcji 
to przewiduje. Wykorzystany może zostać dowolny kompilator C++.

### 4. Kompilacja projektu
W folderze z projektem wykonaj następujace komendy:
```shell
cd SO2_Project1
mkdir build
cd build
cmake ..
cmake --build .
```

### 5. Uruchomienie programu
W celu uruchomienia programu nawiguj do miejsca utworzenia pliku wykonywalnego (np. Debug przy wzkorzystaniu Visual 
Studio) i wykonaj:
```shell
SO2_Project1 <liczba_filozofow>
```
W miejsce <liczba_filozofow> wstaw wybraną liczbę filozofów > 1.

---
## Jak zatrzymac program?
W aktualnej wersji program działa bez końca. W celu zakończenia działania programu należy użyć skrótu Ctrl+C.

---
## Opis problemu
Problem jedzących filozofów to klasyczny problem synchronizacji w programowaniu wielowątkowym, zaproponowany przez 
E.W. Dijkstrę w 1965 roku. Opisuje sytuację, w której pięciu filozofów siedzi przy okrągłym stole i na przemian 
myśli oraz je. Między nimi znajduje się pięć widelców, a każdy filozof potrzebuje dwóch widelców (po jednym z lewej 
i prawej strony), aby móc jeść. 

Na potrzeby zadania program obsługuje wybraną liczbę filozofów (podawaną jako argument przy uruchamianiu). Liczba 
widelców równa jest 
wybranej liczbie filozofów.

### Wyzwania
- Unikanie zakleszczenia (deadlock) – sytuacji, w której każdy filozof trzyma jeden widelec i czeka na drugi, co 
prowadzi do zablokowania się wszystkich.
- Unikanie zagłodzenia (starvation) – sytuacji, w której niektóry filozof nigdy nie dostaje obu widelców.
- Zapewnienie poprawnej synchronizacji – aby filozofowie mogli jeść i myśleć w sposób zgodny z regułami.

---
## Role wątków
- Każdy filozof to oddzielny wątek (std::thread).
- Liczba filozofów jest określana na starcie.

---
## Sekcje krytyczne i synchronizacja
- Każdy widelec jest chroniony przez std::mutex.
- Aby uniknąć deadlocka, filozofowie parzysti podnoszą lewy widelec najpierw, a nieparzysti prawy.
- Każdy filozof myśli i je przez losowy czas (1000-3000 ms).