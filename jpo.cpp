#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

class Zadanie {
public:
    std::string opis;
    bool wykonane;

    Zadanie(const std::string& opis, bool wykonane = false)
        : opis(opis), wykonane(wykonane) {}
};

class OrganizatorZadan {
private:
    std::vector<Zadanie> zadania;
    std::string nazwaPliku;

    void zapiszDoPliku() {
        std::ofstream plik(nazwaPliku);
        for (const auto& zadanie : zadania) {
            plik << zadanie.opis << "\n" << zadanie.wykonane << "\n";
        }
    }

    void wczytajZPliku() {
        std::ifstream plik(nazwaPliku);
        if (plik.is_open()) {
            std::string opis;
            bool wykonane;
            while (std::getline(plik, opis)) {
                plik >> wykonane;
                plik.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                zadania.emplace_back(opis, wykonane);
            }
        }
    }

public:
    OrganizatorZadan(const std::string& nazwaPliku) : nazwaPliku(nazwaPliku) {
        wczytajZPliku();
    }

    ~OrganizatorZadan() {
        zapiszDoPliku();
    }

    void dodajZadanie(const std::string& opis) {
        zadania.emplace_back(opis);
    }

    void usunZadanie(int index) {
        if (index >= 0 && index < zadania.size()) {
            zadania.erase(zadania.begin() + index);
        }
    }

    void edytujZadanie(int index, const std::string& nowyOpis) {
        if (index >= 0 && index < zadania.size()) {
            zadania[index].opis = nowyOpis;
        }
    }

    void oznaczJakoWykonane(int index) {
        if (index >= 0 && index < zadania.size()) {
            zadania[index].wykonane = true;
        }
    }

    void wyswietlZadania() const {
        for (int i = 0; i < zadania.size(); ++i) {
            std::cout << i + 1 << ". " << (zadania[i].wykonane ? "[x] " : "[ ] ") << zadania[i].opis << "\n";
        }
    }

    void menu() {
        int wybor;
        do {
            std::cout << "1. Dodaj zadanie\n";
            std::cout << "2. Usun zadanie\n";
            std::cout << "3. Edytuj zadanie\n";
            std::cout << "4. Oznacz jako wykonane\n";
            std::cout << "5. Wyswietl zadania\n";
            std::cout << "6. Wyjdz\n";
            std::cout << "Wybierz opcje: ";
            std::cin >> wybor;

            std::string opis;
            int index;

            switch (wybor) {
                case 1:
                    std::cout << "Podaj opis zadania: ";
                    std::cin.ignore();
                    std::getline(std::cin, opis);
                    dodajZadanie(opis);
                    break;
                case 2:
                    std::cout << "Podaj numer zadania do usuniecia: ";
                    std::cin >> index;
                    usunZadanie(index - 1);
                    break;
                case 3:
                    std::cout << "Podaj numer zadania do edycji: ";
                    std::cin >> index;
                    std::cout << "Podaj nowy opis zadania: ";
                    std::cin.ignore();
                    std::getline(std::cin, opis);
                    edytujZadanie(index - 1, opis);
                    break;
                case 4:
                    std::cout << "Podaj numer zadania do oznaczenia jako wykonane: ";
                    std::cin >> index;
                    oznaczJakoWykonane(index - 1);
                    break;
                case 5:
                    wyswietlZadania();
                    break;
                case 6:
                    break;
                default:
                    std::cout << "Nieprawidlowy wybor, sprobuj ponownie.\n";
                    break;
            }
        } while (wybor != 6);
    }
};

int main() {
    OrganizatorZadan organizator("zadania.txt");
    organizator.menu();
    return 0;
}
