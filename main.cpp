#include <iostream>
#include <vector>
#include <string>
using namespace std;
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


    Produs operator+(const Produs& other) const {
        Produs result;
        result.nume = "Combined Products";
        result.pret = this->pret + other.pret;
        return result;
    }
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
        cout<<"------------------------------------------\n\n";
        cout <<"-----------COSUL DE CUMPARATURI-----------\n\n";
        for (const auto& produs : produse) {
            std::cout << produs << std::endl;
        }
        std::cout << "Total: $ " << calculeazaTotal() << std::endl;
        cout<<"-----------------------------------------\n";
        cout<<"        MULTUMESSC PENRTU CUMPARATURI\n\n";}
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
            cout << produs << std::endl;
        }
    }

    const Produs& getProdusDupaNume(const std::string& nume) const {
        for (const auto& produs : inventar) {
            if (produs.nume == nume) {
                return produs;
            }
        }
        throw runtime_error("Produsul nu a fost gasit in inventar.");
    }


    Produs recommendProduct(const CosCumparaturi& cos) const {

        double maxPrice = 0.0;
        const Produs* recommendedProdus = nullptr;
        for (const auto& produs : inventar) {
            if (produs.pret > maxPrice) {
                maxPrice = produs.pret;
                recommendedProdus = &produs;
            }
        }
        if (recommendedProdus)
            return *recommendedProdus;
        else
            throw runtime_error("Nu s-a putut recomanda niciun produs.");
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
        cout << "\n------------------- Meniu -------------------\n";
        cout << "1. Afiseaza inventar magazin\n";
        cout << "2. Adauga produs in cos\n";
        cout << "3. Afiseaza cos\n";
        cout << "4. Checkout\n";
        cout << "5. Recomanda produs\n";
        cout << "6. Iesire\n";
        cout << "--------------------------------------------\n";

        int optiune;
        cout << "Introduceti optiunea: ";
        cin >> optiune;

        switch (optiune) {
            case 1: {
                magazin.afiseazaInventar();
                break;
            }
            case 2: {
                string numeProdus;
                cout << "Introduceti numele produsului de adaugat in cos: ";
                cin >> numeProdus;
                try {
                    const Produs &produs = magazin.getProdusDupaNume(numeProdus);
                    cos.adaugaProdus(produs);
                    cout << numeProdus << " adaugat in cos.\n";
                } catch (const std::runtime_error &e) {
                    cout << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                cos.afiseazaCos();
                break;
            }
            case 4: {
                cout << "Checkout...\n";
                cos.afiseazaCos();
                return 0;
            }
            case 5: {
                try {
                    Produs recommendedProdus = magazin.recommendProduct(cos);
                    cout << "Produs recomandat: " << recommendedProdus << std::endl;
                } catch (const std::runtime_error &e) {
                    cout << e.what() << std::endl;
                }
                break;
            }
            case 6: {
                cout << "Iesire...\n";
                return 0;
            }
            default: {

            }
        }
    }
};