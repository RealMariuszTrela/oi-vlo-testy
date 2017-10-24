# oi-vlo-testy
Testy do pierwszego etapu XXV Olimpiady Informatycznej.

Dostępny jest też skrypt ocen (wzięty od Olimpiady Informatycznej), który na Linuksie pozwala łatwo przetestować rozwiązanie na wszystkich testach.



Instrukcja od Olimpiady:

ocen (dla Linuxa)
---------------------------------
(c) 2001-2012, Olimpiada Informatyczna

WYMAGANIA

Skrypt potrzebuje komendy time. W Debianie znajduje sie ona w pakiecie
o nazwie time. Nalezy zauwazyc, ze jest ona inna niz wbudowana w Basha
komenda o tej samej nazwie.

SPOSOB UZYCIA:

Nalezy wejsc do katalogu ocen i skopiowac do niego rozwiazania,
a nastepnie wydac komendê

./ocen ID
    gdzie ID jest identyfikatorem zadania

  Ocenienie rozwiazania zadania ID na podstawie wszystkich
  testow zawartych w zestawie.
  (gdzie ID oznacza trzyliterowy identyfikator zadania)
  
  Jesli biezacy katalog zawiera plik ID.e to uznawany jest on za kod
  wykonywalny z rozwiazaniem, 
  w innym przypadku skrypt szuka plikow: ID.c, ID.cpp, ID.pas i 
  automatycznie kompiluje znalezione zrodlo.
  
  Przyklad:
     ./ocen wys

-

Mozna tez wydac komende

./ocen ID NR
    gdzie ID jest identyfikatorem zadania
          NR jest numerem testu

  Ocenienie rozwiazania zadania ID na podstawie testu o numerze NR

  Przyklad:
     ./ocen wys 1

-

DO CZEGO SLUZY SKRYPT:
- wstepnego sprawdzenia poprawnosci formalnej rozwiazan
  (np. poprawnego nazwania plikow exe, in, out)
- moze byc pomocny przy testowaniu wlasnych rozwiazan,
  jednak wymaga to opracowania wlasnych zestawow testow i
  naniesienia odpowiednich zmian w oi.conf

UWAGI:
- Twoj program powinien dzialac i konczyc dzialanie bez jakiejkolwiek
  interakcji uzytkownikiem (wprowadzanie danych, nacisniecie klawisza,
  dotkniecie myszy etc.).  Sprawdz czy w wysylanym rozwiazaniu nie umiesciles
  ReadKey, ReadLn, getchar, scanf, ktorych zadaniem jest oczekiwanie na
  potwierdzenie zakonczenia programu przez uzytkownika.

  Pamietaj jesli Twoj program wymaga interakcji uzytkownika, to przy
  ostatecznym sprawdzeniu moze okazac sie, ze Twoj program dostanie 0 pkt z
  powodu przekroczenia limitu czasu (rozwiazania testowane sa mechanicznie!!!).

- program "compare" jest bardzo uproszczony, stad jesli Twoje odpowiedzi
  nie spelniaja dokladnie skladni podanej w tresci zadania, moga
  zostac uznane za niepoprawne.

- domyslnie nie jest ustawiony zaden limit pamieciowy. Mozna go ustawic w pliku
  oi.conf.

- w niektorych zadaniach dopuszczalne jest wiele poprawnych odpowiedzi,
  w takim wypadku musisz napisac wlasny program weryfikujacy poprawnosc
  odpowiedzi,

JAK PISAC WLASNE PROGRAMY DO WERYFIKACJI ODPOWIEDZI:
[Już to zrobiłem do zadań Plan metra i Prawnicy]

Niektore zadania dopuszczaja wiele poprawnych odpowiedzi, w takim
przypadku program "compare" (ocen/bin/compare) moze okazac sie 
niewystarczajacy.
Mozesz napisac wlasny program weryfikujacy poprawnosc odpowiedzi,
musi on jednak spelniac nastepujace zalozenia:
- powinien nazywac sie IDchk.e, gdzie ID to trzyliterowy
  identyfikator zadania, i znajdowac sie w katalogu ocen/bin
- w przypadku poprawnej odpowiedzi powinien w pierwszej linii
  standardowego wyjscia napis "OK"
- program sprawdzajacy moze zakladac, ze
   a) zostanie uruchomiony w katalogu zawierjacym pliki ID.in, ID.out
   b) jego pierwszy parametr bedzie zawieral nazwe pliku z odpowiedzia
      wygenerowana przez testowany program
   c) drugi parametr bedzie zawieral nazwe pliku z prawidlowa odpowiedzia
      (lub plikiem ulatwiajacym weryfikacje), zazwyczaj bedzie to
      ocen/out/ID?.out, gdzie ? oznacza numer testu
   d) trzeci parametr zawiera nazwe pliku z danymi wejsciowymi

DO CZEGO NIE SLUZY SKRYPT:
- ostatecznej oceny rozwiazania!

--
Wiecej informacji na temat Olimpiady mozna znalezc pod adresami:
  http://www.oi.edu.pl/

Wszelkie uwagi na temat tego pakietu prosimy zglaszac w
Systemie Internetowym Olimpiady w dziale Pytania
  http://sio.mimuw.edu.pl/



Opis testów:

Pionek:
	1-100:		n<=5		|xi|,|yi|<=3
	101-200:	n<=10		|xi|,|yi|<=100
	201-300:	n<=20		|xi|,|yi|<=10^4
	301-380:	n<=2000		|xi|,|yi|<=10^4
	381-400:	n<=2*10^5	|xi|,|yi|<=10^4

Plan metra:
	1-400:		n<=10		li,di<=200
	401-500:	n<=3000		li,di<=5000
	501-600:	n<=3000		li,di<=10^6
	601-650:	n<=10^5		li,di<=10^6
	651-670:	n<=5*10^5	li,di<=10^6
Testy 661-670 to drzewa o długiej średnicy, reszta to losowe drzewa.

Powódź:
	1-300:		mn<=10		H<=4
	301-400:	mn<=2000	H<=10^9
	401-450:	mn<=2*10^5	H<=5
	451-475:	mn<=5*10^5	H<=10^9		min(m, n)=1
	476-500:	mn<=5*10^5	H<=10^9

Prawnicy:
	1-100:		n<=10		bi<=10
	101-350:	n<=20		bi<=10^9
	351-450:	n<=300		bi<=300
	451-480:	n<=5000		bi<=10^9
	481-490:	n<=10^6		bi<=10^9	k=1 lub k=n
	491-500:	n<=10^6		bi<=10^9

Różnorodność:
	1-100:		n,m,k<=5	C<=25
	101-200:	n,m,k<=15	C<=200
	201-300:	n,m,k<=100	C<=10^5
	301-340:	n,m,k<=600	C<=100
	341-380:	n,m,k<=600	C<=10^5
	381-390:	n,k<=3000	C<=10^5		m<=2k
	391-400:	n,m,k<=3000	C<=10^5


Zadania Plan metra i Prawnicy mają dodatkowo zakodzone sprawdzanie wyjścia w folderze bin/
(Do poprawy - napisać komunikaty o błędach).

Repozytorium jest publiczne, także zachęcam do dodawania też swoich własnych testów, jeżeli są niezbędne (to znaczy istnieje rozwiązanie, które przechodzi wszystkie dotychczasowe testy, a nowego nie).

