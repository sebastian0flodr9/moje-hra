#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string jmeno;
    string narodnost;
    int zivoty = 20;
    int maxzivoty = 20;
    int zlato = 20;
    int volba;
    char potvrd;

    int mana, hp, utok;
    int maxmana;

    int lvl = 1;
    int xp = 0; int xppotreba = 10;
     srand(time(0));


    cout << "Zdravim zdravim hrdino! Vitej v RPG hre!" << endl;
    cout << "Zadej jmeno sveho hrdiny: ";
    cin >> jmeno;

    cout << "\nAhoj, " << jmeno << "!" << endl;
    cout << "Mas " << zivoty << " zivotu." << endl;
    cout << "Mas " << zlato << " zlataku." << endl;
    cout << "Zacinas ve vesnici." << endl;


    do {
        volba = 0;

        while (volba < 1 || volba > 3) {
            cout << "\nVyber si hrdinu:\n";
            cout << "1) Paladin (vic HP, stredni utok, stredni mana)\n";
            cout << "2) Lovec (stredni HP, vysoky utok, nizka mana)\n";
            cout << "3) Mag (malo HP, nizky utok, vysoka mana)\n";
            cout << "Tvoje volba: ";
            cin >> volba;

            if (volba == 1) {
                narodnost = "Paladin";
                hp = 5;
                mana = 5;
                utok = 3;
            }
            else if (volba == 2) {
                narodnost = "Lovec";
                hp = 4;
                mana = 3;
                utok = 4;
            }
            else if (volba == 3) {
                narodnost = "Mag";
                hp = 3;
                mana = 8;
                utok = 2;
            }
            else {
                cout << "Neplatna volba.\n";
                return 0;
            }
        }
                maxmana = mana;
        cout << "\nVybral jsi: " << narodnost << "\n";
        cout << "HP: " << hp << "\n";
        cout << "Mana: " << mana << "\n";
        cout << "Utok: " << utok << "\n";

        cout << "Potvrdit? (a/n): ";
        cin >> potvrd;

    } while (potvrd != 'a' && potvrd != 'A');

    cout << "\nZacinas jako " << jmeno << " " << narodnost << "!\n";


    int vesnicevolba = 0;

     while(vesnicevolba != 5){
        cout << "\n--- Vesnice 1 ---\n";
        cout << "Tve zivoty: " << zivoty << "/" << maxzivoty << " | Mana: " << mana << "/" << maxmana << " | Utok: " << utok << " / Zlato: " << zlato << "\n";
        cout << "1) Doplnit zivoty (5 zlata)\n";
        cout << "2) Zvysit max zivoty (10 zlata)\n";
        cout << "3) Zvysit max manu (10 zlata)\n";
        cout << "4) Zvysit utok (15 zlata)\n";
        cout << "5) Odejit z vesnice\n";
        cout << "Tvoje volba: ";
        cin >> vesnicevolba;

     switch (vesnicevolba) {

    case 1: //doplnis zivoty si
        if (zlato >= 5) {
            zivoty = maxzivoty;
            zlato -= 5;
            cout << "Doplnil sis zivoty na maximum :)\n";
        } else {
            cout << "Nemas dost zlata broski\n";
        }
        break;

    case 2: // zvysisis si hp
        if (zlato >= 10) {
            maxzivoty += 5;
            zivoty = maxzivoty;
            zlato -= 10;
            cout << "Zvysil sis max HP o 5.\n";
        } else {
            cout << "Nemas dost zlata.\n";
        }
        break;

    case 3: // zvysisi max manu
        if (zlato >= 10) {
            maxmana += 2;
            mana = maxmana;
            zlato -= 10;
            cout << "Zvysil sis max manu o 2.\n";
        } else {
            cout << "Nemas dost zlata.\n";
        }
        break;

    case 4: // zvysis max utok
        if (zlato >= 15) {
            utok += 1;
            zlato -= 15;
            cout << "Zvysil sis utok o 1.\n";
        } else {
            cout << "Nemas dost zlata.\n";
        }
        break;

    case 5: // proste livnes vesnici
        cout << "Opoustis vesnici..\n";
        break;

    default:
        cout << "Neplatna volba.\n";
        break;
}

    cout << "\n vydavas se na cestu " << jmeno << "... \n";


    int monsterhp;
    int monsteratk;
    int pocetmonstr;
    int i;



    cout << "\nNarazil jsi na prvni monstrum!!!!!\n";
    monsterhp = 6;
    monsteratk = 2;
    pocetmonstr = 1;

    while (monsterhp > 0 && zivoty > 0){
        cout << "\n-----souboj s 1x monstrem----- \n";
        cout << "Tve HP: " << zivoty << "/" << maxzivoty << " | Mana: " << mana << "/" << maxmana << " | Level: " << lvl << " | XP: " << xp << "/" << xppotreba<< "\n";
        cout << "HP monstra: " << monsterhp << "\n";

        cout << "1) Utok\n";
        cout << "2) Specialni schopnost (pokud mas manu)\n";
        cout << "3) Obrana (snizeni dmg)\n";
        cout << "Tvoje volba: ";
        cin >> volba;

        int dmghrac = 0;
        int dmgmonstrum = monsteratk;

        if (volba == 1) {
            dmghrac = utok;
            cout << "Zautocil jsi a ubral " << dmghrac << " zivotu.\n";
        }
        else if (volba == 2) {
            if (mana > 0) {
                if (narodnost == "Paladin") {
                    dmghrac = utok + 2;
                    zivoty += 2;
                    if (zivoty > maxzivoty) zivoty = maxzivoty;
                    mana -= 1;
                    cout << "Paladin pouzil svatou ranu! Dmg+" << 2 << " a leceni +2.\n";
                }
                else if (narodnost == "Lovec") {
                    dmghrac = utok + 3;
                    mana -= 1;
                    cout << "Lovec pouzil presnou strelu! Dmg+" << 3 << ".\n";
                }
                else if (narodnost == "Mag") {
                    dmghrac = utok + 4;
                    mana -= 2;
                    cout << "Mag seslal ohnivou kouli! Dmg+" << 4 << ".\n";
                }
            } else {
                cout << "Nemas dost many, utocis normalne.\n";
                dmghrac = utok;
            }
        }
        else if (volba == 3) {
            dmghrac = utok / 2;
            dmgmonstrum = monsteratk / 2;
            cout << "Branis se, tvuj utok je mensi, ale i prijaty dmg.\n";
        }
        else {
            cout << "Zmatene stojis, nic nedelas.\n";
            dmghrac = 0;
        }

        monsterhp -= dmghrac;
        if (monsterhp < 0) monsterhp = 0;

        if (monsterhp > 0) {
            zivoty -= dmgmonstrum;
            cout << "Monstrum te zasahlo za " << dmgmonstrum << "!\n";
        }

        if (zivoty <= 0) {
            cout << "Byl jsi zabit. Konec hry\n";
            return 0;
}
}
}
  int drop;
    cout << "porazil jsi monstrum !! (hura!) \n";
    xp +=5  ;
    drop = rand() % 2;
     if (drop == 1) {
        zlato += 5;
        cout << "Ziskal jsi 5 zlata.\n";
    } else {
        zlato += 2;
        cout << "Tentokrat moc zlata nespadlo(2).\n";

    }






}
