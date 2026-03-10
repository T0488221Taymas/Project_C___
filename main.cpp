#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
#include <ctime>

int getValidation() {
    int x;
    cin>>x;
    while (cin.fail()) {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin>>x;
    }
    return x;
}
class Player {
    string Name;
    string Race;
    int warriors;
    int min_power;
    int max_power;
    int lives;
public:
        Player (string cName, string cRace, int cwarriors,int cmin_power, int cmax_power, int clives) {
            Name = cName;
            Race = cRace;
            warriors = cwarriors;
            min_power = cmin_power;
            max_power = cmax_power;
            lives = clives;
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
    void set_clives(int lives) {
            this->lives = lives;
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

    [[nodiscard]] int lives1() const {
        return lives;
    }
    void LoseLfve() {
            lives--;
        }

    void chooseRace() {
            bool running = true;

            while (running){

                cout << "\nChoose your race:\n";
                cout << "1 Humans\n";
                cout << "2 Elves\n";
                cout << "3 Dwarves\n";
                cout<<"Enter your choice: ";
                // cin>>choice;
                // if (cin.fail()) {
                //     cout<<"Invalid input, please enter a number"<<endl;
                //     cin.clear();//to delete the previous
                //     cin.ignore();
                //     continue;// not doing the rest code
                // }
                // cin.ignore();
                int choice = getValidation();//scene 1
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
                    cout<<"Enter a number from 1 to 3\n";
                }

            }
        }
            void showStats(){
                cout<<"----Kingdom Stats----\n";
                cout<<"Ruler: "<<name()<<endl;
                cout<<"Race: "<<race()<<endl;
                cout<<"Warriors: "<<warriors1()<<endl;
                cout<<"Power values between: "<<min_power1()<<"-"<< max_power1()<<endl;
                cout<<"Lives: "<<lives1()<<"\n"<<endl;
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
    bool battle(Player *player, Kingdom enemy) {
        cout << "---Battle begins---\n";
        int playerPower = rand()%(player->max_power1() - player->min_power1() + 1)+ player->min_power1();
        int enemyPower =rand() % (enemy.max_power1() - enemy.min_power1() + 1)+ enemy.min_power1();

        cout<<"Your army power: "<<playerPower<<endl;
        cout<<enemy.race1()<<" army power: "<<enemyPower<<endl;
        if(playerPower > enemyPower){

            cout<<"Victory!"<<enemy.race1()<< " tribe defeated.\n";

            int gained = enemy.warriors1()/6;

            player->set_warriors(player->warriors1() + gained);

            cout<<"Part of "<<enemy.race1()<<" warriors joined you: +"<<gained<<endl;
            player->set_min_power(player->min_power1() + 400);
            player->set_max_power(player->max_power1() + 400);
            return true;
        }

        else {
            player->LoseLfve();

            cout << "\nDefeat!\n";
            cout << "You lost one life.\n";
            cout << "Lives remaining: " << player->lives1() << endl;

            if(player->lives1() <= 0){

                cout << "\n----- GAME OVER -----\n";
                cout << "Your kingdom has fallen.\n";

                exit(0);

            }

            return false;
        }
    }


};
class Scenes {
public:
    void goblinRaid(Player* player){



        int loss = player->warriors1() * 0.15;

        player->set_warriors(player->warriors1() - loss);

        cout << "You lost " << loss << " warriors defending the capital.\n";

        player->set_min_power(player->min_power1() - 700);
        player->set_max_power(player->max_power1() - 700);

        cout << "Your soldiers are demoralized.\n";
        cout << "Army power decreased by 700.\n";
    }
    bool trollPuzzle() {

        cout << "The Troll King speaks:\n";
        cout << "\"Answer my riddle and we may become allies...\"\n\n";

        cout << "I speak without a mouth and hear without ears.\n";
        cout << "I have no body, but I come alive with wind.\n";
        cout << "What am I?\n\n";

        cout << "1 Echo\n";
        cout << "2 Shadow\n";
        cout << "3 Fire\n";
        cout<<"Your answer: ";

        int answer = getValidation();

        if(answer == 1){
            return true;
        }

        return false;
    }
    void trollPunishment(Player* player){

        cout << "The Troll King roars with laughter.\n";
        cout << "\"Wrong answer!\"\n";

        cout << "The trolls launch a sudden attack!\n";

        int loss = player->warriors1() * 0.10;

        player->set_warriors(player->warriors1() - loss);

        cout << "You lost " << loss << " warriors.\n";

        player->set_min_power(player->min_power1() - 500);
        player->set_max_power(player->max_power1() - 500);

        cout << "Your army loses confidence.\n";
        cout << "Power decreased by 500.\n";
    }
    void scene1(Player *player) {
        Kingdom goblins("Goblins", 25000, 14000, 17000);
        Kingdom trolls("Trolls", 10000, 15000, 18500);
        // int choice = getValidation();

        cout << "\n---- Scene 1 ----\n";
        cout << "Your scouts discovered two tribes nearby.\n";
        cout << "Goblins are cruel and aggressive creatures.\n";
        cout << "Diplomacy does not work with them. The language of force is more effective.\n\n";

        cout << "Trolls are more intelligent beings.\n";
        cout << "They can negotiate, but their strength is only slightly weaker than the great kingdoms.\n\n";
        cout << "\nYour advisor whispers:\n";
        cout << "\"Goblins are unpredictable,its better kill them first\"\n";//puzzle

        int choice;
        bool run = true;
        while (run == true) {
            cout<<"With who will you contact \n";
            cout << "1 Goblins  \n";
            cout << "2 Trolls\n";
            cout <<"3 Kingdom's Stats\n";
            cout<<"Enter your choice: ";

            choice = getValidation();//scene 1

            if (choice == 3) {
                player -> showStats();

                continue;
            }
            if (choice == 1) {
                cout<<"Scouts reported about Goblins: "<<endl;
                cout<<"Warriors: " <<goblins.warriors1()<<endl;
                cout<<"Power: "<<goblins.min_power1()<<"-"<<goblins.max_power1()<<endl;

                bool running = true;
                while (running == true) {

                    cout << "\nWhat will you do?\n";
                    cout << "1 Attack\n";
                    cout << "2 Try diplomacy\n";
                    cout<<"3 See stats\n";
                    cout<<"Enter your choice: ";
                    int decision = getValidation();

                    if (decision == 1) {
                        bool win = goblins.battle(player, goblins);
                        if(win){
                            running = false;
                            run = false;
                        }
                        else{
                            cout << "Your army retreats and regroups...\n";
                            cout << "You must decide again.\n";
                        }
                    }


                    else if (decision == 2){
                        cout<<"You attempt diplomacy...\n";
                        cout << "\n--- Ambush! ---\n";
                        cout << "While you tried diplomacy, the goblins attacked your kingdom!\n";
                        goblinRaid(player);
                        cout<<"After exploring there lands your people find weapons factory\n";//its an item that in future will give bonusses
                    }
                    else {
                        cout<<"Enter 1-3: "<<endl;
                    }
                }
            }
            else if (choice == 2) {
                cout<<"Scouts reported about Trolls: "<<endl;
                cout<<"Warriors: " <<trolls.warriors1()<<endl;
                cout<<"Power: "<<trolls.min_power1()<<"-"<<trolls.max_power1()<<endl;

                bool running = true;
                while (running == true) {
                    // int decision = getValidation();
                    cout << "\nWhat will you do?\n";
                    cout << "1 Attack\n";
                    cout << "2 Try diplomacy\n";
                    cout<<"3 See stats\n";
                    cout<<"Enter your choice: ";
                    int decision = getValidation();
                    if (decision == 3) {

                        player->showStats();

                        continue;
                    }

                if (decision == 1) {
                    bool win = trolls.battle(player, trolls);
                    if(win){
                        running = false;
                        run = false;
                        cout << "\n--- While your army fights the Trolls ---\n";
                        cout << "Goblins attack your unprotected kingdom!\n";
                        goblinRaid(player);

                    }
                    else{
                        cout << "\nYour army retreats and regroups...\n";
                        cout << "You must decide again.\n";
                    }
                }
                else if (decision == 2){
                    cout<<"You attempt diplomacy...\n";
                    bool solved = trollPuzzle();

                    if(solved){
                        cout << "\nThe Troll King nods.\n";
                        cout << "\"You are wise. You can once use a mobilisation ticket.\"\n";// item, will be written later
                        running = false;
                        run = false;
                    }
                    else{
                        trollPunishment(player);
                    }
                }
                else {
                    cout<<"Enter a number 1 - 3\n";

                }
            }
            }
            else {
                cout<<"Enter 1-3: "<<endl;
            }
        }
    }
};

    void balance(Player *player, Kingdom &humans, Kingdom &elves, Kingdom &dwarves){

        if(player->race() != "Humans"){
            humans.set_min_power(humans.min_power1() + 2000);
            humans.set_max_power(humans.max_power1() + 2000);
        }

        if(player->race() != "Elves"){
            elves.set_min_power(elves.min_power1() + 2000);
            elves.set_max_power(elves.max_power1() + 2000);
        }

        if(player->race() != "Dwarves"){
            dwarves.set_min_power(dwarves.min_power1() + 2000);
            dwarves.set_max_power(dwarves.max_power1() + 2000);
        }


    }

    int main() {
        srand(time(0));
        Kingdom humans("Humans",25000,18000,20000);
        Kingdom elves("Elves",18000,20000,22000);
        Kingdom dwarves("Dwarves",12000,21000,23500);
        Player player("","",0,0,0,3);
        string inputName;
        cout<<"Enter your name: ";
        cin>>inputName;
        player.set_name(inputName);
        cout << "\nWelcome, ruler " << player.name() << "!\n\n";

        showLore();

        player.chooseRace();
        balance(&player,humans, elves, dwarves);
        Scenes scene;
        scene.scene1(&player);

        return 0;
    }
