#include "main.h"
#include "Rechner.h"
#include "VectorCalc.hpp"
#include <list>
#include <iostream>

int main() {
    double a{0}, b{0};
    char op{'+'};
    const char exitChar{'q'};
    bool exit{false};
    char choice{};

    VectorCalc myVectorCalc({1, 2, 3, 4, 5}); // Erstellen eines Objekts der Klasse VectorCalc
    std::cout << "Die Summe der Vektoren ist: " << myVectorCalc.addVector() << std::endl; // Aufruf der Methode addVector()


    do {

        Rechner myRechner(a, b, op); // Erstellen eines Objekts der Klasse Rechner

        std::cout << "Willkommen zum einfachen Taschenrechner!" << std::endl;
        std::cout << "Bitte geben Sie zwei Zahlen und einen Operator ein." << std::endl;
        myRechner.input_a = myRechner.readNumber("Gib die erste Zahl ein: zum Beispiel: 12.5");
        myRechner.input_b = myRechner.readNumber("Gib die zweite Zahl ein: zum Beispiel: 3.5");    
        myRechner.input_op = myRechner.readOperator();

        auto result = myRechner.berechne(); // Aufruf der Methode berechne()

        if (!result.has_value()) {
            std::cout << "Fehler bei der Berechnung!" << std::endl;
        }else {
            std::cout << myRechner.input_a << " " << myRechner.input_op << " " << myRechner.input_b << " = " << result.value() << std::endl;
        }

        std::cout << "Druecken Sie eine beliebige Taste, um fortzufahren oder 'q', um zu beenden." << std::endl;
        
        std::cin >> choice;  
        exit = (choice == exitChar); // Überprüfen, ob der Benutzer 'q' eingegeben hat
        if (exit) {
            std::cout << "Taschenrechner wird beendet." << std::endl;
        } else {
            std::cout << "Taschenrechner wird fortgesetzt." << std::endl;
        }

    } while (exit == false);

    return 0;
}


