#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

HANDLE hConsole;

class Hero {
private:
    // --------------- Hero ---------------- //
    int health = 0;
    int strangth = 0;
    int knowledge = 0;
    int armor = 0;
    int sleight = 0;
    int karma = 0;
    string raceOfHero = "spirit";
    string nameOfHero;
    string weapon = "-";

    // --------------- Choices ---------------- //
    int racePicker;
    int heroChoices;

    // --------------- Private methods ----------- //
    void creatingOfHero(void);
    void becomingADemon(void);
    void talkWithVoice(int numOfDialog);
    int death(int typeOfDeath);

public:

    Hero(void) {
        creatingOfHero();
        heroInfo();
    };


    void heroInfo(void);

};


// ------------------------ Methods of class Hero -------------------- //


void Hero::creatingOfHero(void)
{
    // ------------------- Creating a Hero ---------------------- //
    cout << "Pick the race of your Hero: \n1. Human \n2. Elf \n3. Orc\n"; cin >> racePicker;

    switch (racePicker)
    {
    case 1:
        health = 100;
        strangth = 50;
        knowledge = 10;
        armor = 10;
        sleight = 10;
        karma = 1;
        raceOfHero = "Human";
        weapon = "knife";
        break;

    case 2:
        health = 100;
        strangth = 25;
        knowledge = 15;
        armor = 5;
        sleight = 15;
        karma = 1;
        raceOfHero = "Elf";
        weapon = "bow";
        break;

    case 3:
        health = 100;
        strangth = 75;
        knowledge = 5;
        armor = 10;
        sleight = 5;
        karma = 1;
        raceOfHero = "Orc";
        weapon = "axe";
        break;

    case -1:
        talkWithVoice(0);
        break;

    default:
        cout << "You did not choose any race." << endl;
        death(0);
        break;
    }
}

void Hero::becomingADemon(void)
{
    cout << "You felt the power in your hands and for a moment it seemed to you that you can do anything." << endl;
    cout << "\tVoice: - Now, you became the Demon" << endl;

    health = 110;
    strangth = 85;
    knowledge = 10;
    armor = 0;
    sleight = 15;
    karma = -1;
    raceOfHero = "Demon";
    weapon = "fists";

    cout << "\tVoice: - We'll meet Again :)";
}

int Hero::death(int typeOfDeath)
{
    switch (typeOfDeath)
    {
    case 0:
        cout << "You became a spirit and were left to wander in an endless void..." << endl;
        SetConsoleTextAttribute(hConsole, 2);
        cout << "Game: Next time choosing carefully!" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        break;
    case 1:
        SetConsoleTextAttribute(hConsole, 4);
        cout << "DEATH" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        break;
    }
    return 0;
}

void Hero::heroInfo(void)
{
    SetConsoleTextAttribute(hConsole, 14);
    cout << endl << "Race:   \t" << raceOfHero << endl;
    cout << "Health: \t" << health << endl;
    cout << "Strangth: \t" << strangth << endl;
    cout << "Knowledge: \t" << knowledge << endl;
    cout << "Armor:  \t" << armor << endl;
    cout << "Sleight: \t" << sleight << endl;
    cout << "Karma:  \t" << karma << endl;
    cout << "Weapon: \t" << weapon << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void Hero::talkWithVoice(int whichChat)
{
    switch (whichChat)
    {
      
    case 0:
        cout << "You walked around the gate and couldn't choose your race..." << endl;
        cout << "\tVoice: - Hey, you. You didn't choose the race... I can help you, but it is not for free :)" << endl;
        cout << "Hero: - What do you need?" << endl;
        cout << "\tVoice: - Your soul..." << endl;
        cout << "1. Agree 2. Disagree" << endl; cin >> heroChoices;
        if (heroChoices == 1) {
            cout << "You sold your soul to the devil..." << endl;
            cout << "\tVoice: - Good deal" << endl;
            becomingADemon();
        }
        else {
            cout << "You felt bad, you bent your head and saw a hole in your body." << endl;
            cout << "\tVoice: - Wrong choice!" << endl;
            death(1);
        }
        break;
    }
}




// ---------------------------- MAIN -------------------------------------- //

int main()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    Hero nikita;

    return 0;
}