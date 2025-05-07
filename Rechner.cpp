#include "Rechner.h"

double Rechner::readNumber(const std::string &prompt)
{
    double number{0};
    enum error{NONE, INVALID_INPUT};
    error err = INVALID_INPUT;



    while (err == INVALID_INPUT) {
        std::cout << prompt << std::endl;
        std::cin >> number;
        if (!std::cin.fail()) {
            err = NONE; // Eingabe war gültig, Fehler zurücksetzen
        } else {
            std::cout << "Ungültige Eingabe. Bitte geben Sie eine gültige Zahl ein: " << std::endl;
            std::cin.clear(); // Fehlerflag zurücksetzen
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
        }
    }

    return number;
}

char Rechner::readOperator()
{
    char op;
    enum error{NONE, INVALID_INPUT};
    error err = INVALID_INPUT;

    while (err == INVALID_INPUT) {
        std::cout << "Gib den Operator ein (+, -, *, /, pow):" << std::endl;
        std::cin >> op;
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == 'p') {
            err = NONE; // Eingabe war gültig, Fehler zurücksetzen
        } else {
            std::cout << "Ungültige Eingabe. Bitte geben Sie einen gültigen Operator ein: " << std::endl;
            std::cin.clear(); // Fehlerflag zurücksetzen
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
        }
    }

    return op;
}

double Rechner::calculate(const double &a, const double &b, const char &op, error &err)
{
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                err = DIVISION_BY_ZERO;
                return 0; // oder eine andere Fehlerbehandlung
            }
        case 'p':
            return std::pow(a, b);
        default:
            err = INVALID_OPERATOR;
            return 0; // oder eine andere Fehlerbehandlung
    }
}

std::optional<double> Rechner::berechne()
{
    double result{};

    //copy input values to class variables
    a = input_a;
    b = input_b;
    op = input_op;


    result = calculate(a, b, op, err);
    if (err == DIVISION_BY_ZERO) {
        std::cout << "Fehler: Division durch Null ist nicht erlaubt." << std::endl;
        return std::nullopt; 
    } else if (err == INVALID_OPERATOR) {   
        std::cout << "Fehler: Ungültiger Operator." << std::endl;
        return std::nullopt;; 
    } else if (err != NONE) {
        std::cout << "Ein unbekannter Fehler ist aufgetreten." << std::endl;
        return std::nullopt;; 
    }

    return result;
}
    