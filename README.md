# Project Title:
## Apartment Rental Management System
# Description:
It represents a management system meant to respond to inquiries based on user input. The user must
first specify the intent of using the platform, getting to experience two possible interfaces: Tenant's view
or Host's view.

A tenant is able to input search criteria, such as location, number of rooms/ guests (1) and maximum price range per
individual (per night). A list of results is displayed containing the apartments that fit the chosen criteria.
Then, the individual is prompted to either choose an apartment, or return to the searching submenu. Once a choice is made, the
tenant has to enter the apartment ID assigned and specify the dates of their booking (2). Shortly after, the user
has to re-enter the number of guests, mentioning how many are underage, in order to compute the total price of their stay.
The last steps of their booking involve user registration and initiating card transfer process.

The host is prompted immediately to create an account and specify the number of apartments they plan to upload on the platform.
After specifying the apartment details, including the layout of rooms and their respective amenities, the host can view a floor plan
and access the updated search submenu.

# Technical implementations:

(1) - These choices are slightly different, considering an apartment might host more people due to its capacity,
however it might have fewer rooms than expected.

(2) - Each apartment has a vector of int variables, being the dates in the year on which it has already been booked by
other clients. Since the user must include a start and end date of their stay, this specific time interval is being checked
whether it's available or not, then the apartment is booked if it is not overlapping with another time frame.

# Nu primesc notă pentru că nu am pus titlu și descriere

## Cerințe obligatorii

Nerespectarea duce la nepunctarea proiectului

- programul va fi scris în C++
- programul va avea un meniu interactiv (doar pentru ilustrarea funcționalității)
- programul nu are erori de compilare
- programul nu are warning-uri (folosind -Wall)
- existența a minim un punct din fiecare cerință
- fară variabile globale
- datele membre private
- fara headere specifice unui sistem de operare (<windows.h>)
- teste unitare pentru cerințele implementate (unde se poate, dacă nu apar probleme cu setup-ul de teste 😅)
- folosirea a funcționalităților limbajului fără sens
- folosirea a funcționlităților limbajului cu scopul de a încălca "legal" o altă regulă
  - folosirea excesivă a claselor friend
  - folosirea excesviă a elementelor statice

## Tema 1

#### Cerințe
- [x] definirea a minim **2-3 clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic) (5p)
  - pentru o clasă:
    - [x] constructori de inițializare
    - [x] constructor supraîncărcat
    - [x] constructori de copiere
    - [x] `operator=` de copiere
    - [x] destructor
    - [x] `operator<<` pentru afișare (std::ostream)
    - [x] `operator>>` pentru citire (std::istream)
    - [x] alt operator supraîncărcat ca funcție membră
    - [x] alt operator supraîncărcat ca funcție non-membră
  - pentru celelalte clase se va definii doar ce e nevoie
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe (3p)
- nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [x] scenariu de utilizare a claselor definite (1p):
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [x] opțiune pentru citirea și afișarea a n obiecte (1p)

### Tema 2

#### Cerințe
- [x] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp` [(0.5p)](https://github.com/Ionnier/poo/tree/main/proiect/P01#separarea-implement%C4%83rii-metodelor-din-clase)
- [x] cât mai multe `const` [(0.5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#reminder-const-everywhere)
- [x] moșteniri [(5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#exemplu):
  - [x] minim o clasă de bază și **2 clase derivate**
  - [ ] încercați să derivați o clasă creată anterior
    - dacă nu reușiți
      - creați o altă clasă care poate fi integrată cu clasele anterioare
      - menționați de ce nu ați reușit și ce ați încercat
      
        mentiune: am incercat sa schimb logica clasei Reservation din proiectul 1 deoarece se comporta asemenea unui search engine, urmand ca SearchEngine sa devina o clasa de baza, insa nu mi-au venit idei pt a implementa clasele derivate AdvertisedSearchEngine si ComparisonSearchEngine.
        de aceea, am considerat ca ideea de a afisa un floor plan/ layout al unui apartament impreuna cu facilitatile fiecarei camere ar fi una practica.
      
  - [x] ilustrați [upcast](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)-ul și [downcast](https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast)-ul folosind funcții virtuale și pointeri la clasa de bază
    - aceasta va fi făcută prin **2-3** metode specifice temei alese
    - funcțiile pentru citire / afișare sau destructorul nu sunt incluse deși o să trebuiască să le implementați
  - [x] apelarea constructorului din clasa de bază din [constructori din derivate](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-la-derivare)
  - [x] suprascris [cc](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-de-copiere-la-derivare)/op= pentru copieri/atribuiri corecte
  - [x] destructor [virtual](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)
- [x] funcții și atribute `static` (în clase) [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L04#static)
- [x] excepții [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L04#exception-handling)
  - porniți de la `std::exception`
  - ilustrați propagarea excepțiilor
  - ilustrati upcasting-ul în blocurile catch
  - minim folosit într-un loc în care tratarea erorilor în modurile clasice este mai dificilă
- [x] folosirea unei clase abstracte (fie la exceptii, fie la moșteniri) [(0.5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#clase-abstracte)
- [x] actualizarea meniului & scenariului de utilizare [(0.5p)](https://github.com/Ionnier/oop-template-t1/blob/main/main.cpp#L16)
- [x] citirea și afișarea a n obiecte [(0.5p)](https://github.com/Ionnier/oop-template-t1/blob/main/main.cpp#L13)
  - poate fi combinat cu demonstrarea upcasting-ului & downcast-ului printr-un vector către o clasă de bază
  - poate fi făcut oriunde (dacă aveți deja o clasă cu un vector, de exemplu o clasă Coș cu un vector<Produs>)
- [x] existența unui pull request către branch-ul în care lucrați ce include adăugarea unei noi derivate ce evidențiază că modificările aduse sunt minimale (0.5p)
  - derivata nu poate fi una ștearsă și rescrisă
  - derivata va avea date membre noi + o modificare de comportament pe una dintre funcțiile virtuale

## Recomandare Tema

* rezolvați tema 1 cu niște itemi generali ca să puteți extinde tema cu ușurință la următoarele teme.
  - coș de cumpărături + produse
  - sistem de validare a documentelor + documente de identitate
  - sistem de gestionare a biletelor + bilet
* funcționalitatea creată să folosească metode ale obiectului generic
* ar fi bine ca relația de agregare să fie făcută cu un obiect general în stilul celor de mai sus ^
* branch-uri + commit-uri punctuale
