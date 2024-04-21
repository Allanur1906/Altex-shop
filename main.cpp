//#include <iostream>
//#include <vector>
//#include <string>
//
//class Produs {
//private:
//    std::string nume;
//    double pret;
//
//public:
//    Produs() : nume(""), pret(0.0) {}
//
//    Produs(const std::string& nume, double pret) : nume(nume), pret(pret) {}
//
//    Produs(const Produs& other) : nume(other.nume), pret(other.pret) {}
//
//    Produs& operator=(const Produs& other) {
//        if (this != &other) {
//            nume = other.nume;
//            pret = other.pret;
//        }
//        return *this;
//    }
//
//    double getPrice() const {
//        return pret;
//    }
//
//
//    const std::string & getName() const {
//        return nume;
//    }
//
//    ~Produs() {}
//
////    // Overloaded + operator as member function
//    Produs operator+(const Produs& other) const {
//        Produs result;
//        result.nume = "Combined Products";
//        result.pret = this->pret + other.pret;
//        return result;
//    }
//
//    double operator [](const Produs& other) const {
//        if(other.pret > this->pret){
//            return other.pret;
//        }
//        return this->pret;
//    }
//
//
//    friend bool operator==(const Produs& other,const Produs& another)  {
//        return another.pret == other.pret && another.nume == other.nume;
//    }
//
//    friend std::ostream& operator<<(std::ostream& os, const Produs& produs) {
//        os << "Nume: " << produs.nume << ", Pret: " << produs.pret;
//        return os;
//    }
//};
//
//
//
//class CosCumparaturi {
//private:
//    std::vector<Produs> produse;
//public:
//    void adaugaProdus(const Produs& produs) {
//        produse.push_back(produs);
//    }
//
//    double calculeazaTotal() const {
//        double total = 0.0;
//        for (const auto& produs : produse) {
//            total += produs.getPrice();
//        }
//        return total;
//    }
//
//    void afiseazaCos() const {
//        std::cout << "Cosul de cumparaturi:\n";
//        for (const auto& produs : produse) {
//            std::cout << produs << std::endl;
//        }
//        std::cout << "Total: $ " << calculeazaTotal() << std::endl;
//        std::cout << "--------------------------------------------\n";
//        std::cout << "******MULTUMESC PENRTU CUMPARATURI******:\n";
//    }
//};
//
//class Magazin {
//private:
//    std::vector<Produs> inventar;
//public:
//
//    void adaugaProdus(const Produs& produs) {
//        inventar.push_back(produs);
//    }
//
//    void afiseazaInventar() const {
//        std::cout << "Inventar magazin:\n";
//        for (const auto& produs : inventar) {
//            std::cout << produs << std::endl;
//        }
//    }
//
//    const Produs& getProdusDupaNume(const std::string& nume) const {
//        for (const auto& produs : inventar) {
//            if (produs.getName() == nume) {
//                return produs;
//            }
//        }
//        throw std::runtime_error("Produsul nu a fost gasit in inventar.");
//    }
//
//
//    [[nodiscard]] Produs recommendProduct() const {
//        //in  'cos'
//        // For demonstration,  the most expensive product in inventory
//        double maxPrice = 0.0;
//        const Produs* recommendedProdus = nullptr;
//        for (const auto& produs : inventar) {
//            if (produs.getPrice() > maxPrice) {
//                maxPrice = produs.getPrice();
//                recommendedProdus = &produs;
//            }
//        }
//        if (recommendedProdus)
//            return *recommendedProdus;
//        else
//            throw std::runtime_error("Nu s-a putut recomanda niciun produs.");
//    }
//};
//
//void umpleInventar(Magazin& magazin) {
//    magazin.adaugaProdus(Produs("Samsung", 100));
//    magazin.adaugaProdus(Produs("Redmi", 150));
//    magazin.adaugaProdus(Produs("Apple", 1000));
//    magazin.adaugaProdus(Produs("HP", 1000));
//    magazin.adaugaProdus(Produs("Lenovo", 600));
//    magazin.adaugaProdus(Produs("Macbook", 1200));
//    magazin.adaugaProdus(Produs("Husa", 10));
//    magazin.adaugaProdus(Produs("USB cablu", 10));
//    magazin.adaugaProdus(Produs("Casti", 100));
//    magazin.adaugaProdus(Produs("Sticla de protectie", 20));
//}
//
//int main() {
//    Magazin magazin;
//    umpleInventar(magazin);
//      CosCumparaturi cos;
//
//    std::cout << "Bine ati venit la magazinul online!\n";
//
//    while (true) {
//        std::cout << "\n------------------- Meniu -------------------\n";
//        std::cout << "1. Afiseaza inventar magazin\n";
//        std::cout << "2. Adauga produs in cos\n";
//        std::cout << "3. Afiseaza cos\n";
//        std::cout << "4. Checkout\n";
//        std::cout << "5. Recomanda produs\n";
//        std::cout << "6. Iesire\n";
//        std::cout << "--------------------------------------------\n";
//
//        int optiune;
//        std::cout << "Introduceti optiunea: ";
//        std::cin >> optiune;
//
//        switch (optiune) {
//            case 1: {
//                magazin.afiseazaInventar();
//                break;
//            }
//            case 2: {
//                std::string numeProdus;
//                std::cout << "Introduceti numele produsului de adaugat in cos: ";
//                std::cin >> numeProdus;
//                try {
//                    const Produs &produs = magazin.getProdusDupaNume(numeProdus);
//                    cos.adaugaProdus(produs);
//                    std::cout << numeProdus << " adaugat in cos.\n";
//                } catch (const std::runtime_error &e) {
//                    std::cout << e.what() << std::endl;
//                }
//                break;
//            }
//            case 3: {
//                cos.afiseazaCos();
//                break;
//            }
//            case 4: {
//                std::cout << "Checkout...\n";
//                cos.afiseazaCos();
//                return 0;
//            }
//            case 5: {
//                try {
//                    Produs recommendedProdus = magazin.recommendProduct();
//                    std::cout << "Produs recomandat: " << recommendedProdus << std::endl;
//                } catch (const std::runtime_error &e) {
//                    std::cout << e.what() << std::endl;
//                }
//                break;
//            }
//            case 6: {
//                std::cout << "Iesire...\n";
//                return 0;
//            }
//            default: {
//            }
//        }
//    }
//};


#include <iostream>
#include <vector>
#include <string>

// Abstract class for exceptions
class MyException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override = 0;
};

class ProductNotFoundException : public MyException {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Product not found in inventory";
    }
};

// Base class with virtual methods and destructor
class Produs {
protected:
    std::string nume;
    double pret;
    static int totalProduse;

public:
    Produs(std::string  nume, double pret) : nume(std::move(nume)), pret(pret) { totalProduse++; }
    Produs(const Produs& other) : nume(other.nume), pret(other.pret) { totalProduse++; }
    Produs& operator=(const Produs& other) {
        if (this!= &other) {
            nume = other.nume;
            pret = other.pret;
        }
        return *this;
    }
    virtual ~Produs() { totalProduse--; }

    [[nodiscard]] virtual double getPrice() const {
        return pret;
    }

    [[nodiscard]] virtual const std::string& getName() const {
        return nume;
    }

    static int getTotalProduse() { // Static function to get the total number of products
        return totalProduse;
    }

    friend std::ostream& operator<<(std::ostream& os, const Produs& produs) {
        os << "Nume: " << produs.nume << ", Pret: " << produs.pret;
        return os;
    }
};

int Produs::totalProduse = 0;

class Telefon : public Produs {
private:
    std::string model;

public:
    Telefon(const std::string& nume, double pret, std::string  model)
            : Produs(nume, pret), model(std::move(model)) {}

    [[nodiscard]] double getPrice() const override {
        return pret * 1;
    }

    const std::string& getModel() const {
        return model;
    }

    friend std::ostream& operator<<(std::ostream& os, const Telefon& telefon) {
        os << static_cast<const Produs&>(telefon) << ", Model: " << telefon.model;
        return os;
    }
};

class Computer : public Produs {
private:
    std::string procesor;

public:
    Computer(const std::string& nume, double pret, const std::string& procesor)
            : Produs(nume, pret), procesor(procesor) {}

    double getPrice() const override {
        return pret * 1;
    }

    const std::string& getProcesor() const {
        return procesor;
    }

    friend std::ostream& operator<<(std::ostream& os, const Computer& computer) {
        os << static_cast<const Produs&>(computer) << ", Procesor: " << computer.procesor;
        return os;
    }
};

class Gadget : public Produs {
public:
    Gadget(const std::string& nume, double pret) : Produs(nume, pret) {}

    double getPrice() const override {
        return pret * 1;
    }
};

class CosCumparaturi {
private:
    std::vector<Produs*> produse;

public:
    void adaugaProdus(Produs* produs) {
        produse.push_back(produs);
    }

    double calculeazaTotal() const {
        double total = 0;
        for (const auto& produs : produse) {
            total += produs->getPrice();
        }
        return total;
    }

    void afiseazaCos() const {
        std::cout << "Cosul de cumparaturi contine urmatoarele produse:" << std::endl;
        for (const auto& produs : produse) {
            std::cout << *produs << std::endl;
        }
        std::cout << "Total: " << calculeazaTotal() << std::endl;
    }

    ~CosCumparaturi() {
        for (auto produs : produse) {
            delete produs;
        }
    }

    void golesteCos() {

    }
};

class Magazin {
private:
    std::vector<Produs*> inventar;

public:
    void adaugaProdus(Produs* produs) {
        inventar.push_back(produs);
    }

    void afiseazaInventar() const {
        std::cout << "Inventarul contine urmatoarele produse:" << std::endl;
        for (const auto& produs : inventar) {
            std::cout << *produs << std::endl;
        }
    }

    Produs* getProdusDupaNume(const std::string& nume) {
        for (const auto& produs : inventar) {
            if (produs->getName() == nume) {
                return produs;
            }
        }
        throw ProductNotFoundException();
    }

    Produs* recommendProduct() {
        Produs* max_price_produs = nullptr;
        double max_price = 0;
        for (const auto& produs : inventar) {
            if (produs->getPrice() > max_price) {
                max_price = produs->getPrice();
                max_price_produs = produs;
            }
        }
        return max_price_produs;
    }

    ~Magazin() {
        for (auto produs : inventar) {
            delete produs;
        }
    }
};

void umpleInventar(Magazin& magazin) {
    magazin.adaugaProdus(new Telefon("Samsung", 500, "Galaxy"));
    magazin.adaugaProdus(new Telefon("Iphone", 1000, "15 pro"));
    magazin.adaugaProdus(new Computer("Dell", 2000, "Intel Core i7"));
    magazin.adaugaProdus(new Computer("Macbook", 2100, "Air2023"));
    magazin.adaugaProdus(new Gadget("Husa", 50));
    magazin.adaugaProdus(new Gadget("Sticla_protectie", 40));
    magazin.adaugaProdus(new Gadget("USB", 30));
    magazin.adaugaProdus(new Gadget("Casca", 55));
}

int main() {
    Magazin magazin;
    umpleInventar(magazin);

    CosCumparaturi cos;

    int optiune;
    do {
        std::cout << "\n\nBine ati venit in magazinul nostru!" << std::endl;
        std::cout << "1. Afiseaza inventarul" << std::endl;
        std::cout << "2. Adauga un produs in cos" << std::endl;
        std::cout << "3. Afiseaza cosul de cumparaturi" << std::endl;
        std::cout << "4. Calculeaza totalul cosului de cumparaturi" << std::endl;
        std::cout << "5. Cumpara produsele din cos" << std::endl;
        std::cout << "6. Recomanda un produs" << std::endl;
        std::cout << "7. Cauta un produs dupa nume" << std::endl;
        std::cout << "0. Iesire" << std::endl;
        std::cout << "Introduceti optiunea dorita: ";
        std::cin >> optiune;

        switch (optiune) {
            case 1:
                magazin.afiseazaInventar();
                break;
            case 2: {
                std::string nume;
                std::cout << "Introduceti numele produsului: ";
                std::cin >> nume;
                try {
                    Produs *produs = magazin.getProdusDupaNume(nume); // Using exception handling (requirement)
                    std::cout << "Produs adaugat in cos: " << *produs << std::endl;
                    cos.adaugaProdus(produs);
                } catch (const MyException &e) { // Using custom exception class (requirement)
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 3:
                cos.afiseazaCos();
                break;
            case 4:
                std::cout << "Total cos: " << cos.calculeazaTotal() << std::endl;
                break;
            case 5:
                std::cout << "Produsele au fost cumparate. Cosul a fost golit." << std::endl;
                cos.golesteCos();
                break;
            case 6: {
                Produs *produs = magazin.recommendProduct();
                std::cout << "Produsul recomandat este: " << *produs << std::endl;
                break;
            }
            case 7: {
                std::string numeProdus;
                std::cout << "Introduceti numele produsului de cautat: ";
                std::cin >> numeProdus;
                try {
                    Produs *produs = magazin.getProdusDupaNume(numeProdus); // Using exception handling (requirement)
                    std::cout << "Produs gasit: " << *produs << std::endl;
                } catch (const MyException &e) { // Using custom exception class (requirement)
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "La revedere!" << std::endl;
                break;
            default:
                std::cout << "Optiune invalida. Incercati din nou." << std::endl;
                break;
        }
    } while (optiune != 0);

    return 0;
}