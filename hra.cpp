#include <iostream>
using namespace std;

int main() {
    string jmeno;
    int zivoty = 100;
    int zlato = 10;

    cout << "zdravim hrdino! vitej v RPG hre!" << endl;
    cout << "Zadej jmeno sveho hrdiny: ";
    cin >> jmeno;

    cout << "Ahoj, " << jmeno << "!" << endl;
    cout << "Mas " << zivoty << " zivotu." << endl;
    cout << "Mas " << zlato << " zlatych." << endl;

    cout << "Zacinas ve vesnici." << endl;

    if (zivoty <= 0) {
        cout << "Chyba: hrdina nema zivoty!" << endl;
        return 1;
    }

    if (zlato < 0) {
        cout << "Chyba: zaporne zlato!" << endl;
        return 1;
    }

    cout << "Vse pripraveno, dobrodruzstvi muze zacit!" << endl;

    return 0;
}
