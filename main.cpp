#include <iostream>
#include <vector>
#include <string>

class Produs {
public:
    std::string nume;
    double pret;

    Produs() : nume(""), pret(0.0) {}

    Produs(std::string nume, double pret) : nume(nume), pret(pret) {}

    
    Produs(const Produs& other) : nume(other.nume), pret(other.pret) {}

    
    Produs& operator=(const Produs& other) {
        if (this != &other) {
            nume = other.nume;
            pret = other.pret;
        }
        return *this;
    }

    
    ~Produs() {}
};

std::ostream& operator<<(std::ostream& os, const Produs& produs) {
    os << "Nume: " << produs.nume << ", Pret: " << produs.pret;
    return os;
}

class CosCumparaturi {
public:
    std::vector<Produs> produse;

    void adaugaProdus(const Produs& produs) {
        produse.push_back(produs);
    }

    double calculeazaTotal() const {
        double total = 0.0;
        for (const auto& produs : produse) {
            total += produs.pret;
        }
        return total;
    }

    void afiseazaCos() const {
        std::cout << "Cosul de cumparaturi:\n";
        for (const auto& produs : produse) {
            std::cout << produs << std::endl;
        }
        std::cout << "Total: $" << calculeazaTotal() << std::endl;
    }
};

class Magazin {
public:
    std::vector<Produs> inventar;

    void adaugaProdus(const Produs& produs) {
        inventar.push_back(produs);
    }

    void afiseazaInventar() const {
        std::cout << "Inventar magazin:\n";
        for (const auto& produs : inventar) {
            std::cout << produs << std::endl;
        }
    }

    const Produs& getProdusDupaNume(const std::string& nume) const {
        for (const auto& produs : inventar) {
            if (produs.nume == nume) {
                return produs;
            }
        }
        throw std::runtime_error("Produsul nu a fost gasit in inventar.");
    }
};

void umpleInventar(Magazin& magazin) {
    magazin.adaugaProdus(Produs("Samsung", 100));
    magazin.adaugaProdus(Produs("Redmi", 150));
    magazin.adaugaProdus(Produs("Apple", 1000));
    magazin.adaugaProdus(Produs("HP", 1000));
    magazin.adaugaProdus(Produs("Lenovo", 600));
    magazin.adaugaProdus(Produs("Macbook", 1200));
    magazin.adaugaProdus(Produs("Husa", 10));
    magazin.adaugaProdus(Produs("USB cablu", 10));
    magazin.adaugaProdus(Produs("Casti", 100));
    magazin.adaugaProdus(Produs("Sticla de protectie", 20));
}

int main() {
    Magazin magazin;
    umpleInventar(magazin);

    CosCumparaturi cos;

    std::cout << "Bine ati venit la magazinul online!\n";

    while (true) {
        std::cout << "\n------------------- Meniu -------------------\n";
        std::cout << "1. Afiseaza inventar magazin\n";
        std::cout << "2. Adauga produs in cos\n";
        std::cout << "3. Afiseaza cos\n";
        std::cout << "4. Checkout\n";
        std::cout << "5. Iesire\n";
        std::cout << "--------------------------------------------\n";

        int optiune;
        std::cout << "Introduceti optiunea: ";
        std::cin >> optiune;

        switch (optiune) {
            case 1: {
                magazin.afiseazaInventar();
                break;
            }
            case 2: {
                std::string numeProdus;
                std::cout << "Introduceti numele produsului de adaugat in cos: ";
                std::cin >> numeProdus;
                try {
                    const Produs& produs = magazin.getProdusDupaNume(numeProdus);
                    cos.adaugaProdus(produs);
                    std::cout << numeProdus << " adaugat in cos.\n";
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                cos.afiseazaCos();
                break;
            }
            case 4: {
                std::cout << "Checkout...\n";
                cos.afiseazaCos();
                return 0;
            }
            case 5: {
                std::cout << "Iesire...\n";
                return 0;
            }
            default: {
                std::cout << "Optiune invalida. Va rugam sa introduceti un numar intre 1 si 5.\n";
                break;
            }
        }
    }

    return 0;
}
