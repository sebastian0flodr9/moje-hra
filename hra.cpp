#include <iostream>
using namespace std;

int main() {
    string jmeno;
    string narodnost;
    int zivoty = 20;
    int zlato = 10;
    int volba;
    char potvrd;

    cout << "Zdravim hrdino! Vitej v RPG hre!" << endl;
    cout << "Zadej jmeno sveho hrdiny: ";
    cin >> jmeno;

    cout << "\nAhoj, " << jmeno << "!" << endl;
    cout << "Mas " << zivoty << " zivotu." << endl;
    cout << "Mas " << zlato << " zlataku." << endl;
    cout << "Zacinas ve vesnici." << endl;

    int hp, mana, utok;

    do {
        volba = 0;

        while (volba < 1 || volba > 3) {
            cout << "\nVyber si hrdinu:\n";
            cout << "1) Paladin\n";
            cout << "2) Lovec\n";
            cout << "3) Mag\n";
            cout << "Tvoje volba: ";
            cin >> volba;

            if (volba == 1) {
                narodnost = "Paladin";
                hp = 5; mana = 5; utok = 3;
            }
            else if (volba == 2) {
                narodnost = "Lovec";
                hp = 4; mana = 3; utok = 4;
            }
            else if (volba == 3) {
                narodnost = "Mag";
                hp = 3; mana = 8; utok = 2;
            }
            else {
                cout << "Neplatna volba.\n";
                return 0;
            }
        }

        cout << "\nVybral jsi: " << narodnost << "\n";
        cout << "HP: " << hp << "\n";
        cout << "Mana: " << mana << "\n";
        cout << "Utok: " << utok << "\n";

        cout << "Potvrdit? (a/n): ";
        cin >> potvrd;

    } while (potvrd != 'a' && potvrd != 'A');

    cout << "\nZacinas jako " << jmeno << " " << narodnost << "!\n";

    cout << "Vse pripraveno, dobrodruzstvi muze zacit!" << endl;

    return 0;
}
