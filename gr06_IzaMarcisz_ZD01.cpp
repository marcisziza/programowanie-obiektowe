#include <iostream>
#include <string>   //import bibliotek
 
using namespace std;
 
class Bohater { //definicja klasy "Bohater"
  private:      //prywatne pola
    string pseudonim;  
    string klasa;
    int sila_ataku;
    static int licznik; //licznik obiektów klasy "Bohater"
 
  public:   //publiczne pola i metody
    Bohater(){ //domyślny konstruktor
      pseudonim = "Brak";
      klasa = "Brak";
      sila_ataku = 0;
      licznik++;    //inkrementacja licznika
    }
 
    Bohater(const Bohater &Bohater, int sila_ataku) { //konstruktor kopiujacy
      pseudonim = Bohater.pseudonim;
      klasa = Bohater.klasa;
      this -> sila_ataku = sila_ataku;  //ustawienie siły obiektu na wartość podaną jako parametr konstruktora kopiującego
      licznik++;
    }    
 
    Bohater(string pseudonim, string klasa, int sila_ataku) {   //konstruktor wieloargumentowy nadający wartość pól klasy
      this -> pseudonim = pseudonim;
      this -> klasa = klasa;
      this -> sila_ataku = sila_ataku;
      licznik++;
    }
    string get_wyswietlanie_pseudonimu() { //metoda zwracajaca wartosc pola "pseudonim"
      return pseudonim;
    }
    string get_wyswietlanie_klasy() { //metoda zwracajaca wartosc pola "klasa"
      return klasa;
    }
    int get_wyswietlanie_sily() { //metoda zwracajaca wartosc pola "atak"
      return sila_ataku;
    }
    static int get_wyswietlanie_licznika(){ //statyczna metoda zwracajaca wartosc pola "licznik"
      return licznik;
    }
    void set_nowa_sila(int s) { //metoda umozliwiajaca zmiane wartosci pola sila_ataku
      sila_ataku = s;
    }
    void set_nowy_pseudonim(string p) { //metoda umozliwiajaca zmiane wartosci pola pseudonim
      pseudonim = p;
    }
 
    void wyswietlanie_wartosci();   //deklaracja metody wyświetlającej wartości pól klasy
};
void Bohater::wyswietlanie_wartosci() { //definicja metody poza ciałem klasy
        cout << "Pseudonim bohatera: " << get_wyswietlanie_pseudonimu() << endl;
        cout << "Klasa bohatera: " << get_wyswietlanie_klasy() << endl;
        cout << "Sila ataku bohatera: " << get_wyswietlanie_sily() << endl;
    }
 
int Bohater::licznik = 0;   //definicja statycznego pola "licznik" klasy "Bohater"
 
 
int main() {
 
  Bohater* bohater1 = new Bohater("Zawisza Czarny", "Rycerz", 0); //deklaracja dynamicznego obiektu typu "Bohater", przy użyciu konstruktora wieloargumentowego
 
  bohater1 -> wyswietlanie_wartosci();
 
  bohater1 -> set_nowa_sila(5); bohater1 -> wyswietlanie_wartosci(); //zmiana wartosci pola sila_ataku oraz ponowne wypisanie wartosci
 
  Bohater** tab2d = new Bohater*[2]; //utworzenie dynamicznej tablicy obiektow
  for(int i = 0; i < 2; i++){
    tab2d[i] = new Bohater[2];
  }
 
  for(int i = 0; i < 2; i++){   //przypisywanie wartości pól obiektom w tablicy
    for(int j = 0; j < 2; j++){
      tab2d[i][j].set_nowy_pseudonim("pseudonim" + to_string(i));
      tab2d[i][j].set_nowa_sila(i * 2 + j);
    }
  }
 
  int suma = 0;
 
  for(int i = 0; i < 2; i++){   //sumowanie i wyświetlanie wartości pola "siła" obiektów w tablicy
    for(int j = 0; j < 2; j++){
        suma += tab2d[i][j].get_wyswietlanie_sily();
        cout << tab2d[i][j].get_wyswietlanie_pseudonimu() << " ma sile rowna " << tab2d[i][j].get_wyswietlanie_sily() << endl;
    }
  }
 
  cout << "Suma sil: " << suma << endl;
  cout << "Licznik: " << Bohater::get_wyswietlanie_licznika() << endl;  //wyświetlenie licznika obiektów klasy "Bohater"
 
  for(int i = 0; i < 2; i++) delete[] tab2d[i]; //usuwanie dynamicznie utworzonych obiektów
  delete[] tab2d;
  cout << "Licznik: " << Bohater::get_wyswietlanie_licznika() << endl;
 
  return 0;
}