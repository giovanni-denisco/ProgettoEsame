# Progetto Registro Attività

Questo progetto implementa un registro che permette di inserire, rimuovere e visualizzare le attività svolte durante la giornata.

## 1. Classe Activity

La classe `Activity` rappresenta le singole attività con seguenti attributi e funzioni:

### Attributi

- `int hourTimeStart`, `int minTimeStart`: ore e minuti di inizio dell'attività
- `int hourTimeEnd`, `int minTimeEnd`: ore e minuti di fine dell'attività
- `std::string description`: la descrizione dell'attività
- `std::string title`: il titolo dell'attività

### Metodi

Metodi Getter degli attributi:

- `int getHourTimeStart() const;`
- `int getMinTimeStart() const;`
- `int getHourTimeEnd() const;`
- `int getMinTimeEnd() const;`
- `std::string getDescription() const;`
- `std::string getTitle() const;`

Metodi Setter degli attributi:

- `void setHourTimeStart(int h) const;`
- `void setMinTimeStart(int m) const;`
- `void setHourTimeEnd(int h) const;`
- `void setMinTimeEnd(int m) const;`
- `void setDescription(const std::string& desc) const;`
- `void setTitle(const std::string& t) const;`

### Test

La classe `Activity` ha anche un file `testActivity` che lancia test e controlla il giusto funzionamento dei suoi metodi.

## 2. Classe Register

La classe `Register` permette all'utente di svolgere rimozione, aggiunta e visualizzazione delle attività presenti nel sistema gestite con un vettore. All'interno della classe sono presenti i seguenti attributi e metodi:

### Attributi

- `std::vector<Activity> activities`: vettore che contiene le attività, sul quale è molto semplice lavorare

### Metodi

- `void addActivity(const Activity& a)`: permette di aggiungere un attività
- `void removeActivity(int index)`: permette di rimuovere un attività attraverso un indice
- `void showActivities() const`; mostra le attività presenti
- `bool isEmpty() const`: rende `True` se il vettore è vuoto e `False` in caso contrario
- `int numberActivities() const`: rende un `int` con il numero di attività presenti

### Test

La classe `Register` ha anche un file `testRegister` che lancia test e controlla il giusto funzionamento dei suoi metodi.

## 3. Menu

Questo file contiene un solo metodo `void showMenu(Register& registro)` che prende in ingresso un oggetto di tipo `Register` e crea l'interfaccia del menù. Questa, implementata all'interno del file `Menu.cpp`, realizzato tramite la libreria `NCurses`, propone varie voci da poter cliccare per svolgere le varie funzioni nel registro all'interno di una finestra creata nel terminale. Le opzioni sono gestite attraverso un ciclo con le variabili `highlight`, che permette di scorrere le voci in modo circolare, e `choice` che rappresenta la scelta dell'utente. Per ogni scelta è sempre possibile ritornare al menù iniziale dal quale si può uscire attraverso l'apposita voce `Esci`.

## Esempio di utilizzo

1. Lancio del programma e visualizzazione del menù
2. visualizzare che il registro è vuoto
3. aggiungere un attività inserendo titolo, descrizione e orario di inizio e fine
4. visualizzare l'attività
5. rimuovere l'attività
6. uscire dal programma


