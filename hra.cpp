#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string jmeno;
    string narodnost;
    int zivoty = 10;
    int maxzivoty = 10;
    int zlato = 20;
    int volba;
    char potvrd;

    int mana, hp, utok;
    int maxmana;

    int lvl = 1;
    int xp = 0;
    int xppotreba = 10;

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
                hp = 10;
                mana = 5;
                utok = 3;
            }
            else if (volba == 2) {
                narodnost = "Lovec";
                hp = 8;
                mana = 3;
                utok = 4;
            }
            else if (volba == 3) {
                narodnost = "Mag";
                hp = 6;
                mana = 8;
                utok = 2;
            }
            else {
                cout << "Neplatna volba.\n";
                volba = 0;
            }
        }
        maxmana = mana;
        maxzivoty = hp;
        zivoty = hp;

        cout << "\nVybral jsi: " << narodnost << "\n";
        cout << "HP: " << hp << "\n";
        cout << "Mana: " << mana << "\n";
        cout << "Utok: " << utok << "\n";

        cout << "ses si fakt jistej ze chces zrovna tohle?? (a/n): ";
        cin >> potvrd;

    } while (potvrd != 'a' && potvrd != 'A');

    cout << "\n Dobra volba, Zacinas jako " << jmeno << " " << narodnost << "!\n";

    int vesnicevolba = 0;

    while (vesnicevolba != 5) {
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

        case 2:// zvysisis si hp
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

        case 5:  // proste livnes vesnici
            cout << "Opoustis vesnici..\n";
            break;

        default:
            cout << "Neplatna volba.\n";
            break;
        }
    }

    cout << "\n vydavas se na cestu " << jmeno << "... \n";

    int monsterhp;
    int monsteratk;
    int pocetmonstr;
    int i;

    cout << "\nNarazil jsi na prvni monstrum!!!!!\n";
    monsterhp = 5;
    monsteratk = 2;
    pocetmonstr = 1;

    while (monsterhp > 0 && zivoty > 0) {
        cout << "\n-----souboj s 1x monstrem----- \n";
        cout << "Tve HP: " << zivoty << "/" << maxzivoty << " | Mana: " << mana << "/" << maxmana << " | Level: " << lvl << " | XP: " << xp << "/" << xppotreba << "\n";
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
                    cout << "Paladin pouzil svatou ranu! Dmg+2 a leceni +2.\n";
                }
                else if (narodnost == "Lovec") {
                    dmghrac = utok + 3;
                    mana -= 1;
                    cout << "Lovec pouzil presnou strelu! Dmg+3.\n";
                }
                else if (narodnost == "Mag") {
                    dmghrac = utok + 4;
                    mana -= 2;
                    cout << "Mag seslal ohnivou kouli! Dmg+4.\n";
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

    int drop;
    cout << "porazil jsi monstrum !! (hura!) \n";
    xp += 5;
    drop = rand() % 2;
    if (drop == 1) {
        zlato += 5;
        cout << "Ziskal jsi 5 zlata.\n";
    } else {
        zlato += 2;
        cout << "Tentokrat moc zlata nespadlo(2).\n";
    }

    if (xp >= xppotreba) {
        lvl++;
        xp -= xppotreba;
        xppotreba += 5;
        maxzivoty += 2;
        maxmana += 1;
        utok += 1;
        zivoty = maxzivoty;
        mana = maxmana;
        cout << "\nLEVEL UP! Mas momentalne level " << lvl << "!_!\n";
    }

    cout << "\n pokracujes dal a narazil jsi na dve monstra\n";

    for (int i = 0; i < 2; i++) {

        int monsterHp = 7;
        int monsteratk2 = 2;

        cout << "\n----- Souboj se dvema monstrama -----\n";

        while (monsterHp > 0 && zivoty > 0) {

            cout << "\n----- !!FIGHT!! -----\n";
            cout << "Tve HP: " << zivoty << "/" << maxzivoty
                 << " | Mana: " << mana << "/" << maxmana
                 << " | Level: " << lvl
                 << " | XP: " << xp << "/" << xppotreba << "\n";

            cout << "HP monstra: " << monsterHp << "\n";

            cout << "1) Utok\n";
            cout << "2) Specialni schopnost (pokud mas manu)\n";
            cout << "3) Obrana (snizeni dmg)\n";
            cout << "Tvoje volba: ";
            cin >> volba;

            int dmghrac = 0;
            int dmgmonstrum = monsteratk2;

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
                        cout << "Paladin pouzil svatou ranu! Dmg+2 a leceni +2.\n";
                    }
                    else if (narodnost == "Lovec") {
                        dmghrac = utok + 3;
                        mana -= 1;
                        cout << "Lovec pouzil presnou strelu! Dmg+3.\n";
                    }
                    else if (narodnost == "Mag") {
                        dmghrac = utok + 4;
                        mana -= 2;
                        cout << "Mag seslal ohnivou kouli! Dmg+4.\n";
                    }
                } else {
                    cout << "Nemas dost many, utocis normalne.\n";
                    dmghrac = utok;
                }
            }

            else if (volba == 3) {
                dmghrac = utok / 2;
                dmgmonstrum = monsteratk2 / 2;
                cout << "Branis se, tvuj utok je mensi, ale i prijaty dmg.\n";
            }

            else {
                cout << "jses hodne zmatenej takze radsi nic nedelas.\n";
                dmghrac = 0;
            }

            monsterHp -= dmghrac;
            if (monsterHp < 0) monsterHp = 0;

            if (monsterHp > 0) {
                zivoty -= dmgmonstrum;
                cout << "Monstrum te zasahlo za " << dmgmonstrum << "!\n";
            }

            if (zivoty <= 0) {
                cout << "Byl jsi zabit. Konec hry.\n";
                return 0;
            }
        }
    }

    cout << "Porazil jsi 2 monstra (uz ses velkej chlapak, mozna to i dohrajes)!\n";
    xp += 6;
    drop = rand() % 2;
    if (drop == 1) {
        zlato += 6;
        cout << "Ziskal jsi 6 zlata.\n";
    } else {
        zlato += 1;
        cout << "Tentokrat moc zlata nespadlo(1).\n";
    }

    if (xp >= xppotreba) {
        lvl++;
        xp -= xppotreba;
        xppotreba += 5;
        maxzivoty += 2;
        maxmana += 1;
        utok += 1;
        zivoty = maxzivoty;
        mana = maxmana;
        cout << "\nLEVEL UP! Mas momentalne level " << lvl << "!_!\n";
    }

    cout << " dosel jsi do druhe vesnice (omg ty jsi dosel az? hezky) ";

    vesnicevolba = 0;

    while (vesnicevolba != 5) {
        cout << "\n--- Vesnice 2 ---\n";
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

        case 5:  // proste livnes vesnici
            cout << "Opoustis vesnici..\n";
            break;

        default:
            cout << "Neplatna volba.\n";
            break;
        }

        cout << "\n vydavas se znovu na cestu " << jmeno << "... \n";
    }

    cout << "\n pokracujes dal a narazil jsi na dve monstra\n";

    for (int i = 0; i < 2; i++) {

        int monsterHp = 12;
        int monsteratk3 = 3;

        cout << "\n----- Souboj se trema monstrama -----\n";

        while (monsterHp > 0 && zivoty > 0) {

            cout << "\n----- FIGHT -----\n";
            cout << "Tve HP: " << zivoty << "/" << maxzivoty
                 << " | Mana: " << mana << "/" << maxmana
                 << " | Level: " << lvl
                 << " | XP: " << xp << "/" << xppotreba << "\n";

            cout << "HP monstra: " << monsterHp << "\n";

            cout << "1) Utok\n";
            cout << "2) Specialni schopnost (pokud mas manu)\n";
            cout << "3) Obrana (snizeni dmg)\n";
            cout << "Tvoje volba: ";
            cin >> volba;

            int dmghrac = 0;
            int dmgmonstrum = monsteratk3;

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
                        cout << "Paladin pouzil svatou ranu! Dmg+2 a leceni +2.\n";
                    }
                    else if (narodnost == "Lovec") {
                        dmghrac = utok + 3;
                        mana -= 1;
                        cout << "Lovec pouzil presnou strelu! Dmg+3.\n";
                    }
                    else if (narodnost == "Mag") {
                        dmghrac = utok + 4;
                        mana -= 2;
                        cout << "Mag seslal ohnivou kouli! Dmg+4.\n";
                    }
                } else {
                    cout << "Nemas dost many, utocis normalne.\n";
                    dmghrac = utok;
                }
            }

            else if (volba == 3) {
                dmghrac = utok / 2;
                dmgmonstrum = monsteratk3 / 2;
                cout << "Branis se, tvuj utok je mensi, ale i prijaty dmg.\n";
            }

            else {
                cout << "jses hodne zmatenej takze radsi nic nedelas.\n";
                dmghrac = 0;
            }

            monsterHp -= dmghrac;
            if (monsterHp < 0) monsterHp = 0;

            if (monsterHp > 0) {
                zivoty -= dmgmonstrum;
                cout << "Monstrum te zasahlo za " << dmgmonstrum << "!\n";
            }

            if (zivoty <= 0) {
                cout << "Byl jsi zabit. Konec hry.\n";
                return 0;
            }
        }
    }

    cout << "Porazil jsi 3 monstra (uz ses velkej chlapak, mozna to i dohrajes)!\n";
    xp += 10;
    drop = rand() % 2;
    if (drop == 1) {
        zlato += 9;
        cout << "Ziskal jsi 9 zlata.\n";
    } else {
        zlato += 3;
        cout << "Tentokrat spadlo malo zlata (3).\n";
    }

// VESNICE 3 – tady už jsi skoro frajer nejvìtšího kalibru

cout << "\nDorazil jsi do TRETII vesnice. Lidi na tebe koukaj s vykulenyma ocima jak na poloboha.\n";
cout << "Deti si o tobe povidaj, babky se krizi a jeden typek ti chce dokonce prodat hrnce.\n";

int vesniceVolba = 0;

while (vesniceVolba != 5) {
    cout << "\n--- Vesnice 3 ---\n";
    cout << "Tve zivoty: " << zivoty << "/" << maxzivoty << " | Mana: " << mana << "/" << maxmana << " | Utok: " << utok << " | Zlato: " << zlato << "\n";

    cout << "1) Doplnit zivoty (5 zlata)\n";
    cout << "2) Zvysit max zivoty (15 zlata)\n";
    cout << "3) Zvysit max manu (15 zlata)\n";
    cout << "4) Zvysit utok (20 zlata)\n";
    cout << "5) Odejit z vesnice\n";
    cout << "Tvoje volba: ";
    cin >> vesniceVolba;

    if (vesniceVolba == 1) {
        if (zlato >= 5) {
            zivoty = maxzivoty;
            zlato -= 5;
            cout << "Doplnil sis zivoty na maximum. Jsi ready na dalsi masakr.\n";
        } else cout << "Nemas dost zlata, chudacku.\n";
    }
    else if (vesniceVolba == 2) {
        if (zlato >= 15) {
            maxzivoty += 5;
            zivoty = maxzivoty;
            zlato -= 15;
            cout << "Zvysil sis max HP o 5. Jsi tank jak prase.\n";
        } else cout << "Nemas dost zlata.\n";
    }
    else if (vesniceVolba == 3) {
        if (zlato >= 15) {
            maxmana += 2;
            mana = maxmana;
            zlato -= 15;
            cout << "Zvysil sis max manu o 2. Magove ti tleskaj.\n";
        } else cout << "Nemas dost zlata.\n";
    }
    else if (vesniceVolba == 4) {
        if (zlato >= 20) {
            utok += 2;
            zlato -= 20;
            cout << "Zvysil sis utok o 2. Ted uz fakt boli, kdyz nekoho plesknes.\n";
        } else cout << "Nemas dost zlata.\n";
    }
    else if (vesniceVolba == 5) {
        cout << "Opoustis vesnici... lidi ti mavou, nekteri breci.\n";
    }
    else {
        cout << "Neplatna volba.\n";
    }
}

// MINIBOSS – tady zacina opravdovej problem
// ------------------------------------------------------

cout << "\nNa tve ceste se objevil nechutny drak shmak (MINIBOSS!) Vypada rozzurene a jde si primo pro tebe.\n";

int miniBossHP = 40;
int miniBossAtk = 6;

while (miniBossHP > 0 && zivoty > 0) {
    cout << "\n--- Souboj s minibossem ---\n";
    cout << "Tve HP: " << zivoty << "/" << maxzivoty
         << " | Mana: " << mana << "/" << maxmana
         << " | Level: " << lvl
         << " | XP: " << xp << "/" << xppotreba << "\n";
    cout << "HP minibosse: " << miniBossHP << "\n";

    cout << "1) Utok\n";
    cout << "2) Specialni schopnost\n";
    cout << "3) Obrana\n";
    cout << "Tvoje volba: ";
    cin >> volba;

    int dmgHrac = 0;
    int dmgMini = miniBossAtk;

    if (volba == 1) {
        dmgHrac = utok;
        cout << "Zautocil jsi a ubral " << dmgHrac << " zivotu.\n";
    }
    else if (volba == 2) {
        if (mana > 0) {
            if (narodnost == "Paladin") {
                dmgHrac = utok + 3;
                zivoty += 3;
                if (zivoty > maxzivoty) zivoty = maxzivoty;
                mana -= 2;
                cout << "Paladin pouzil silnou svatou ranu! Miniboss breci.\n";
            }
            else if (narodnost == "Lovec") {
                dmgHrac = utok + 4;
                mana -= 2;
                cout << "Lovec vystrelil tak presne, ze by se i Legolas stydel .\n";
            }
            else if (narodnost == "Mag") {
                dmgHrac = utok + 6;
                mana -= 3;
                cout << "Mag seslal ohnivou kouli jak z anime.\n";
            }
        } else {
            cout << "Nemas dost many, tak jen tak placnes.\n";
            dmgHrac = utok;
        }
    }
    else if (volba == 3) {
        dmgHrac = utok / 2;
        dmgMini = miniBossAtk / 2;
        cout << "Branis se. Miniboss se smeje, ale mene.\n";
    }
    else {
        cout << "Stojis a cumis. Miniboss te necha, protoze je mu te lito.\n";
        dmgHrac = 0;
    }

    miniBossHP -= dmgHrac;
    if (miniBossHP < 0) miniBossHP = 0;

    if (miniBossHP > 0) {
        zivoty -= dmgMini;
        cout << "Miniboss te zasahl za " << dmgMini << "!\n";
    }

    if (zivoty <= 0) {
        cout << "Miniboss te sejmul. Konec hry.\n";
        return 0;
    }
}

cout << "\nPORAZIL JSI DRAKA(jeste tomu utrepeni neni konec)! Lidi by ti staveli sochy, kdyby meli penize.\n";
xp += 20;
zlato += 30;
cout << "Ziskal jsi 20 XP a 30 zlata.\n";

if (xp >= xppotreba) {
    lvl++;
    xp -= xppotreba;
    xppotreba += 5;
    maxzivoty += 3;
    maxmana += 2;
    utok += 2;
    zivoty = maxzivoty;
    mana = maxmana;
    cout << "\nLEVEL UP! Mas ted level " << lvl << "!\n";
}

// VESNICE 4 – poslední zastávka pøed totálním masakrem

cout << "\nPo krvavém boji s minibossem dorazis do VESNICE 4.\n";
cout << "Lidi na tebe koukaj jak na absolutniho giga-chada.\n";
cout << "Jeden dedek rika: 'Tenhle kluk porazi i smrt, vsadim fusekle!'\n";

int vesnice4 = 0;

while (vesnice4 != 5) {
    cout << "\n--- Vesnice 4 ---\n";
    cout << "Tve zivoty: " << zivoty << "/" << maxzivoty
         << " | Mana: " << mana << "/" << maxmana
         << " | Utok: " << utok
         << " | Zlato: " << zlato << "\n";

    cout << "1) Doplnit zivoty (10 zlata)\n";
    cout << "2) Zvysit max zivoty (20 zlata)\n";
    cout << "3) Zvysit max manu (20 zlata)\n";
    cout << "4) Zvysit utok (25 zlata)\n";
    cout << "5) Odejit z vesnice\n";
    cout << "Tvoje volba: ";
    cin >> vesnice4;

    if (vesnice4 == 1) {
        if (zlato >= 10) {
            zivoty = maxzivoty;
            zlato -= 10;
            cout << "Doplnil sis zivoty na maximum. Jsi ready na Reckonuse.\n";
        } else cout << "Brasko, nemas ani deset zlataku, to je smutny.\n";
    }
    else if (vesnice4 == 2) {
        if (zlato >= 20) {
            maxzivoty += 7;
            zivoty = maxzivoty;
            zlato -= 20;
            cout << "Zvysil sis max HP o 7. Ted uz jsi skoro nesmrtelnej.\n";
        } else cout << "Nemas dost zlata.\n";
    }
    else if (vesnice4 == 3) {
        if (zlato >= 20) {
            maxmana += 3;
            mana = maxmana;
            zlato -= 20;
            cout << "Zvysil sis max manu o 3. Magove ti posilaji respekt.\n";
        } else cout << "Nemas dost zlata.\n";
    }
    else if (vesnice4 == 4) {
        if (zlato >= 25) {
            utok += 3;
            zlato -= 25;
            cout << "Zvysil sis utok o 3. Ted uz i Reckonus bude mit bopky.\n";
        } else cout << "Nemas dost zlata.\n";
    }
    else if (vesnice4 == 5) {
        cout << "Opoustis vesnici... vsichni ti drzi palce.\n";
    }
    else {
        cout << "Neplatna volba.\n";
    }
}

cout << "\nOpoustis posledni bezpecne misto...\n";
cout << "Pred tebou je jen ticho, temnota... a Reckonus ktery se pomalu blizi ze stinu.\n";
cout << "Nadechni se, hrdino. Ted zacina opravdova zkaza.\n";


// HLAVNI BOSS – RECKONUS, NICITEL SVETU

cout << "\nZem se zatresla... obloha potemnela...\n";
cout << "Pred tebou stoji HLAVNI BOSS: RECKONUS, NICITEL SVETU.\n";
cout << "Je tak velkej, ze bys ho nechtel potkat ani ve fronte na rohliky.\n";

int bossMaxHP = 120;
int bossHP = bossMaxHP;
int bossZakladDmg = 8;
int bossAktualniDmg = bossZakladDmg;
int bossOdolnost = 0;

while (bossHP > 0 && zivoty > 0) {

    cout << "\n--- Souboj s bossem RECKONUS ---\n";
    cout << "Tve HP: " << zivoty << "/" << maxzivoty
         << " | Mana: " << mana << "/" << maxmana
         << " | Level: " << lvl
         << " | XP: " << xp << "/" << xppotreba << "\n";
    cout << "HP bosse: " << bossHP << "/" << bossMaxHP << "\n";

    double bossPercent = (double)bossHP / bossMaxHP * 100.0;

    if (bossPercent > 80) { bossAktualniDmg = bossZakladDmg * 1; bossOdolnost = 0; }
    else if (bossPercent > 60) { bossAktualniDmg = bossZakladDmg * 2; bossOdolnost = 1; }
    else if (bossPercent > 40) { bossAktualniDmg = bossZakladDmg * 3; bossOdolnost = 2; }
    else if (bossPercent > 20) { bossAktualniDmg = bossZakladDmg * 4; bossOdolnost = 3; }
    else { bossAktualniDmg = bossZakladDmg * 5; bossOdolnost = -1; }

    // Boss utoci prvni
    cout << "Reckonus zvedl svou obrovskou pazouru...\n";
    zivoty -= bossAktualniDmg;
    cout << "A prastil te za " << bossAktualniDmg << " dmg! To bolelo i tvoje predky.\n";

    if (zivoty <= 0) {
        cout << "Reckonus te rozdrtil jak housku na svacinu.\n";
        return 0;
    }

    cout << "\nTvuj tah!\n";
    cout << "1) Utok\n";
    cout << "2) Specialni schopnost\n";
    cout << "3) Obrana\n";
    cout << "Tvoje volba: ";
    cin >> volba;

    int dmgHrac = 0;

    if (volba == 1) {
        dmgHrac = utok;
        cout << "Zautocil jsi za " << dmgHrac << " dmg.\n";
    }
    else if (volba == 2) {
        if (mana > 0) {
            if (narodnost == "Paladin") {
                dmgHrac = utok + 4;
                mana -= 3;
                cout << "Paladinova mega svata rana! Reckonus se zakyval.\n";
            }
            else if (narodnost == "Lovec") {
                dmgHrac = utok + 6;
                mana -= 3;
                cout << "Lovcova smrtici strela! Reckonusovi se nelibi.\n";
            }
            else if (narodnost == "Mag") {
                dmgHrac = utok + 8;
                mana -= 4;
                cout << "Mag seslal ohnivou bouøi jak z anime final fightu!\n";
            }
        } else {
            cout << "Nemas manu, tak jen tak placnes.\n";
            dmgHrac = utok;
        }
    }
    else if (volba == 3) {
        dmgHrac = utok / 2;
        cout << "Branis se. Reckonus se smeje, ale nervozne.\n";
    }
    else {
        cout << "Zmatene nic nedelas.\n";
        dmgHrac = 0;
    }

    if (bossOdolnost >= 0) dmgHrac -= bossOdolnost;
    else dmgHrac /= 2;

    if (dmgHrac < 0) dmgHrac = 0;

    cout << "Reckonus dostal " << dmgHrac << " dmg.\n";
    bossHP -= dmgHrac;
}

cout << "\nRECKONUS PADL NA KOLENA...\n";
cout << "A s poslednim vydechem rika: 'Takovej frajer... jsem dlouho nevidel...'\n";
cout << "\n*** GRATULUJU, " << jmeno << "! PORAZIL JSI HLAVNIHO BOSSE A DOKONCIL HRU! ***\n";
cout << "Lidi ti budou stavet sochy, psat pisne a mozna ti i nekdo koupi kofolu.\n";
cout << "Jsi LEGENDARni hrdina.\n";

    return 0;
}
