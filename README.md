# SO2_projekt - 1. Problem Jedzących Filozofów
---
## Jak uruchomić program?


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