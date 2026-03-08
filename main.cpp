#include <iostream>
#include <string>
using namespace std;

class Player {
    string Name;
    string Race;
    int warriors;
    int min_power;
    int max_power;
public:
        Player (string cName, string cRace, int cwarriors,int cmin_power, int cmax_power) {
            Name = cName;
            Race = cRace;
            warriors = cwarriors;
            min_power = cmin_power;
            max_power = cmax_power;
        }

    void set_name(string name) {
        Name = name;
    }

    void set_race(string race) {
        Race = race;
    }

    void set_warriors(int warriors) {
        this->warriors = warriors;
    }

    void set_min_power(int min_power) {
        this->min_power = min_power;
    }

    void set_max_power(int max_power) {
        this->max_power = max_power;
    }

    [[nodiscard]] string name() const {
        return Name;
    }

    [[nodiscard]] string race() const {
        return Race;
    }

    [[nodiscard]] int warriors1() const {
        return warriors;
    }

    [[nodiscard]] int min_power1() const {
        return min_power;
    }

    [[nodiscard]] int max_power1() const {
        return max_power;
    }

    void chooseRace() {
            bool running = true;
            while (running){
                int choice;
                cout << "\nChoose your race:\n";
                cout << "1 Humans\n";
                cout << "2 Elves\n";
                cout << "3 Dwarves\n";
                cin>>choice;
                if (cin.fail()) {
                    cout<<"Invalid input, please enter a number"<<endl;
                    cin.clear();//to delete the previous
                    cin.ignore();
                    continue;// not doing the rest code
                }
                cin.ignore();

                if(choice == 1) {

                    set_race("Humans");
                    set_warriors(25000);
                    set_min_power(18000);
                    set_max_power(20000);
                    running = false;
                }

                else if(choice == 2) {

                    set_race("Elves");
                    set_warriors(18000);
                    set_min_power(20000);
                    set_max_power(22000);
                    running = false;
                }

                else if (choice ==3) {

                    set_race("Dwarves");
                    set_warriors(12000);
                    set_min_power(21000);
                    set_max_power(23500);
                    running = false;
                }
                else {
                    cout<<"Number should be from 1-3, please try again\n";
                }
            }
        }
            void showStats(){
                cout<<"----Kingdom Stats----\n";
                cout<<"Ruler: "<<name()<<endl;
                cout<<"Race: "<<race()<<endl;
                cout<<"Warriors: "<<warriors1()<<endl;
                cout<<"Power values between: "<<min_power1()<<"-"<< max_power1()<<endl;
            }
    };
void showLore() {

    cout << "---------------------------------\n";
    cout << "            LORE\n";
    cout << "---------------------------------\n\n";

    cout << "For centuries the world has been divided between several races.\n";
    cout << "Three great nations dominate the continent.\n\n";

    cout << "Humans are the most numerous race.\n";
    cout << "Their armies are large, but individual soldiers are weaker.\n\n";

    cout << "Elves are fewer in number but highly skilled warriors.\n";
    cout << "Their discipline and training make them extremely dangerous.\n\n";

    cout << "Dwarves are the smallest nation.\n";
    cout << "However every dwarf is raised as a fierce warrior.\n";
    cout << "Though their numbers are small, their strength is unmatched.\n\n";

    cout << "In addition to these nations, many smaller races exist:\n";
    cout << "Beastfolk, nomadic tribes, and other minor kingdoms.\n";
    cout << "They are weaker than the great nations but unpredictable.\n\n";

    cout << "For many years tension has grown between the races.\n";
    cout << "Wars have been fought, alliances broken.\n\n";

    cout << "Now a new ruler rises...\n";
    cout << "You.\n\n";

    cout << "Will you unite the world through diplomacy...\n";
    cout << "or conquer it through war?\n\n";
}
class Kingdom {
    string race;
    int warriors;
    int min_power;
    int max_power;
public:
    Kingdom (string cRace, int cwarriors,int cmin_power, int cmax_power) {
        race = cRace;
        warriors = cwarriors;
        min_power = cmin_power;
        max_power = cmax_power;
    }



    void set_race(string race) {
        this->race = race;
    }

    void set_warriors(int warriors) {
        this->warriors = warriors;
    }

    void set_min_power(int min_power) {
        this->min_power = min_power;
    }

    void set_max_power(int max_power) {
        this->max_power = max_power;
    }


    [[nodiscard]] string race1() const {
        return race;
    }


    [[nodiscard]] int warriors1() const {
        return warriors;
    }

    [[nodiscard]] int min_power1() const {
        return min_power;
    }

    [[nodiscard]] int max_power1() const {
        return max_power;
    }

};
class Scenes {
public:
    void scene1(Player *player) {
        Kingdom goblins("Goblins", 25000, 14000, 17000);
        Kingdom trolls("Trolls", 10000, 15000, 18500);
        int choice;
        cout << "\n---- Scene 1 ----\n";
        cout << "Your scouts discovered two tribes nearby.\n";
        cout << "Goblins are cruel and aggressive creatures.\n";
        cout << "Diplomacy rarely works with them. The language of force is more effective.\n\n";

        cout << "Trolls are more intelligent beings.\n";
        cout << "They can negotiate, but their strength is only slightly weaker than the great kingdoms.\n\n";

        // cout << "1 Goblins  \n";
        // cout << "2 Trolls\n";
        // cout <<"3 Kingdom's Stats\n";
        bool run = true;
        while (run == true) {
            cout << "1 Goblins  \n";
            cout << "2 Trolls\n";
            cout <<"3 Kingdom's Stats\n";
            cin>> choice;
            if (cin.fail()) {
                cout<<"Invalid input, please enter a number"<<endl;
                cin.clear();//to delete the previous
                cin.ignore();
                continue;// not doing the rest code
            }
            cin.ignore();
            if (choice == 3) {
                player -> showStats();

                continue;
            }
            if (choice == 1 || choice == 2) {
                run = false;
            }
            else {
                cout<<"Enter 1-3: "<<endl;
            }
        }
        if (choice == 1) {
            cout<<"Scouts reported about Goblins: "<<endl;
            cout<<"Warriors: " <<goblins.warriors1()<<endl;
            cout<<"Power: "<<goblins.min_power1()<<"-"<<goblins.max_power1()<<endl;
        }
        else if (choice == 2) {
            cout<<"Scouts reported about Trolls: "<<endl;
            cout<<"Warriors: " <<trolls.warriors1()<<endl;
            cout<<"Power: "<<trolls.min_power1()<<"-"<<trolls.max_power1()<<endl;
        }
    }
};
int main() {
    Player player("","",0,0,0);
    string inputName;
    cout<<"Enter your name: ";
    cin>>inputName;
    player.set_name(inputName);
    cout << "\nWelcome, ruler " << player.name() << "!\n\n";

    showLore();

    player.chooseRace();

    Scenes scene;
    scene.scene1(&player);

    return 0;
}
