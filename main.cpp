#include <complex.h>
#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <vector>
#include <functional>

int getValidation() {//validation
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

class Player;// declaration


class Item {
protected:
    string itemName;
public:
    Item (string cItemName) {
        itemName = cItemName;
    }
    virtual void use(Player*player) {
        cout<< "You used: "<<itemName<<endl;
    }

    string item_name(){
        return itemName;
    }


};





class Player {
    string Name;
    string Race;
    int warriors;
    int min_power;
    int max_power;
    int lives;
    int wisdom;

    vector <Item*> inventory;
public:
        Player (string cName, string cRace, int cwarriors,int cmin_power, int cmax_power, int clives, int cwisdom) {
            Name = cName;
            Race = cRace;
            warriors = cwarriors;
            min_power = cmin_power;
            max_power = cmax_power;
            lives = clives;
            wisdom = cwisdom;
        }
    ~Player() {
            for (Item* item : inventory) {
                delete item;
            }
        }
    void addItem(Item *newItem) {
           inventory.push_back(newItem);
           cout<<"Item received: "<< newItem->item_name()<<endl;
        }
    void showInventory() {
            cout<<"----Inventory----\n";
            if (inventory.empty()) {
                cout<<"Inventory empty\n\n";
            }
            else {
                for (int i= 0; i < inventory.size(); i++) {
                    cout<<i+1<<")"<<inventory[i]->item_name()<<endl;
                }
            }
        }
    void inventoryMenu() {
            bool run = true;
            while (run) {
                showInventory();
                if (inventory.empty()) {
                    run = false;
                }
                else {
                    cout << "0) Exit\n";
                    cout << "Choose item to use: ";
                    int choice = getValidation();
                    if (choice == 0) {
                        run = false;
                    }
                    else if (choice < 1 || choice > inventory.size()) {
                        cout << "Invalid choice!\n";
                        continue;
                    }
                    else{
                        useItem(choice -1);
                    }
                }
            }

        }

    //gpt
    void useItem(int index) {
            if (index < 0 || index >= inventory.size()) {
                cout << "Invalid item!\n";
                return;
            }

            inventory[index]->use(this);

            delete inventory[index];
            inventory.erase(inventory.begin() + index);
        }//
    void receiveItem(Item* item) {
            cout << "\nYou obtained: " << item->item_name() << "!\n";
            cout << "1) Use now\n";
            cout << "2) Save for later\n";
            cout << "Your choice: ";
            int choice = getValidation();
            if(choice == 1){
                item->use(this);
                delete item;
            }
            else if(choice == 2){
                addItem(item);
            }
            else{
                cout << "Invalid choice, saved to inventory.\n";
                addItem(item);
            }
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
    void set_wisdom(int wisdom) {
            this -> wisdom = wisdom;
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
    void LoseLive() {
            lives--;
            cout<< "Lives left: "<<lives<<endl;
            if(lives <= 0){

                cout << "\n----- GAME OVER -----\n";
                cout << "Your kingdom has fallen.\n";

                exit(0);

            }
        }

    [[nodiscard]] int wisdom1() const {
        return wisdom;
    }

    void chooseRace() {
            bool running = true;

            while (running){

                cout << "\nChoose your race:\n";//scene 1
                cout << "1 Humans\n";
                cout << "2 Elves\n";
                cout << "3 Dwarves\n";
                cout<<"Enter your choice: ";

                int choice = getValidation();//scene 1
                if(choice == 1) {

                    set_race("Humans");
                    set_warriors(25000);
                    set_min_power(20000);
                    set_max_power(22500);
                    set_wisdom(2);
                    running = false;
                }

                else if(choice == 2) {

                    set_race("Elves");
                    set_warriors(16000);
                    set_min_power(19000);
                    set_max_power(21500);
                    set_wisdom(3);
                    running = false;
                }

                else if (choice ==3) {

                    set_race("Dwarves");
                    set_warriors(12000);
                    set_min_power(21000);
                    set_max_power(23500);
                    set_wisdom(1);
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
                cout<<"Lives: "<<lives1()<<endl;
                cout <<"Wisdom: "<<wisdom1()<<"\n"<<endl;

            }
    };

class MobilizationTicket : public Item {
public:
    MobilizationTicket() : Item("Mobilization Ticket") {}
    void use(Player *player) override {
        cout<< "You used "<< itemName<<endl;
        player->set_warriors(player->warriors1() + 1000);
        player->set_min_power(player->min_power1() + 2000);
        player->set_max_power(player->max_power1() + 2000);

        cout<<"You got 1000 warriors and your power increased on 2000\n";
    }
};

class Weapon_Factory : public Item {
public:
    Weapon_Factory() : Item("Weapon Factory"){}
    void use(Player *player) {
        cout<<"You activated weapon Factory\n";
        const int POWER= 2000;
        player->set_min_power(player->min_power1()+POWER);
        player->set_max_power(player->max_power1()+POWER);
        cout<<"Your weapon upgraded power increased by 2000!\n";
    }
};

class Cannon : public Item {
public:
    Cannon() : Item("Cannon") {}

    void use(Player *player) override {
        cout << "You deployed a Cannon!\n";

        const int POWER = 1500;

        player->set_min_power(player->min_power1() + POWER);
        player->set_max_power(player->max_power1() + POWER);

        cout << "Your power increased by 1500!\n";
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
    bool battle(Player *player, Kingdom enemy) {//battle logic
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
            cout<<"Your power increased: "<<player->min_power1()<<"-"<<player->max_power1()<<endl;
            return true;
        }

        else {
            player->LoseLive();

            cout << "\nDefeat!\n";
            cout << "You lost one life.\n";
            cout << "Lives remaining: " << player->lives1() << endl;



            return false;
        }
    }


};
class Scenes {
protected:
    int id;
public:
    Scenes(){}
    int chooseAction(Player* player){
        int decision;
        bool run = true;
        while(run){
            cout << "\nWhat will you do?\n";
            cout << "1 Attack\n";
            cout << "2 Try diplomacy\n";
            cout << "3 See stats\n";
            cout << "4 Inventory\n";
            cout << "Enter your choice: ";
            decision = getValidation();
            if (decision == 4) {
                player->inventoryMenu();
                continue;
            }
            if(decision == 3){
                player->showStats();
                continue;
            }
            if(decision == 1 || decision == 2){
                run = false;
            }
            else{
                cout << "Enter number 1-4\n";
            }
        }
        return decision;
    }
    bool introRiddle(Player* player){//scene 2
        cout << "\nBefore your coronation a sage asks a riddle.\n\n";//puzzle
        cout << "I speak without a mouth and hear without ears.\n";
        cout << "I have no body but come alive with wind.\n";
        cout << "What am I?\n\n";
        cout << "1 Echo\n";
        cout << "2 Shadow\n";
        if(player->wisdom1() <= 2)
            cout << "3 Fire\n";
        if(player->wisdom1() == 1)
            cout << "4 Wind\n";
        cout << "\nYour answer: ";
        int answer = getValidation();
        cout << "\nYou step before your people and speak:\n";
        cout << "Our kingdom stands united. Together we will build a future no enemy can destroy.\n\n";

        const int REWARD = 400;
        if(answer == 1){
            cout << "The crowd erupts in cheers.\n";
            player->set_min_power(player->min_power1() + REWARD);
            player->set_max_power(player->max_power1() + REWARD);
            cout << "Power +400\n";
        }
        else{
            cout << "The crowd looks uncertain.\n";
            player->set_min_power(player->min_power1() - REWARD);
            player->set_max_power(player->max_power1() - REWARD);
            cout << "Power -400\n";
        }
        return true;
    }
    //GPT
    void retryScene(Player* player, function<void()> scene) {
        int before;

        do {
            before = player->lives1();
            scene();

            if(player->lives1() < before){
                cout << "\nRetrying scene...\n";
            }

        } while(player->lives1() < before);
    }//
    virtual void Scene1(Player *player) = 0;
    virtual void Scene2(Player *player) = 0;
    virtual void Scene3(Player *player) = 0;
    virtual void Scene4(Player *player) = 0;
    virtual void Scene5(Player *player) = 0;
    virtual void Scene6(Player *player) = 0;
    virtual void Scene7(Player *player) = 0;
    virtual void Scene8(Player *player) = 0;
    virtual void Scene9(Player *player) = 0;
    void finalScene(Player* player){
        cout << "\n----FINAL----\n";

        if(player->lives1() > 0){
            cout << "You united the world!\n";
        } else {
            cout << "Your kingdom fell...\n";
        }
    }
};


class peopleScenes : public Scenes {
public:
    int Humanchoose1(Player *player) {//scene 3

        cout << "Your scouts discovered two tribes nearby.\n";
        cout << "Goblins are cruel and aggressive creatures.\n";
        cout << "Diplomacy does not work with them. The language of force is more effective.\n\n";

        cout << "Trolls are more intelligent beings.\n";
        cout << "They can negotiate, but their strength is only slightly weaker than the great kingdoms.\n\n";
        cout << "\nYour advisor whispers:\n";
        cout << "\"Goblins are unpredictable,its better kill them first\"\n";//puzzle
        int x;

        bool run = true;
        while (run == true) {
            cout<<"With who will you contact \n";
            cout << "1 Goblins  \n";
            cout << "2 Trolls\n";
            cout <<"3 Kingdom's Stats\n";
            cout<<"Enter your choice: ";

            x = getValidation();

            if (x == 3) {
                player -> showStats();

                continue;
            }
            if (x >=1 && x<=2) {
                run = false;
            }
            else {
                cout<<"Enter a number between 1 and 3\n";
            }
        }
        return x;
    }


    void goblinRaid(Player* player){

        int loss = player->warriors1() * 0.15;

        player->set_warriors(player->warriors1() - loss);

        cout << "You lost " << loss << " warriors defending the capital.\n";
        const int PENALTY = 700;
        player->set_min_power(player->min_power1() - PENALTY);
        player->set_max_power(player->max_power1() - PENALTY);

        cout << "Your soldiers are demoralized.\n";
        cout << "Army power decreased by 700.\n";
    }
    bool trollPuzzle(Player *player) {
        cout << "\nThe Troll King asks a riddle.\n\n";
        cout << "The more you take, the more you leave behind.\n";
        cout << "What am I?\n\n";

        cout << "1 Footsteps\n";
        cout << "2 Shadows\n";
        cout << "3 Stones\n";
        cout << "\nYour answer: ";
        int answer = getValidation();
        while(answer < 1 || answer > 3){
            cout << "Enter number between 1-3\n";
            answer = getValidation();
        }
        if(answer == 1){
            cout << "The Troll King nods in approval.\n";
            return true;
        }
        else{
            cout << "The Troll King laughs. Wrong answer.\n";
            trollPunishment(player);
            return false;
        }
    }

    void trollPunishment(Player *player){

        cout << "The Troll King roars with laughter.\n";
        cout << "\"Wrong answer!\"\n";

        cout << "The trolls launch a sudden attack!\n";

        int loss = player->warriors1() * 0.10;

        player->set_warriors(player->warriors1() - loss);

        cout << "You lost " << loss << " warriors.\n";
        const int PENALTY = 500;

        player->set_min_power(player->min_power1() - PENALTY);
        player->set_max_power(player->max_power1() - PENALTY);

        cout << "Your army loses confidence.\n";
        cout << "Power decreased by 500.\n";
    }
    void goblin_troll(Player *player, int choice) {

        Kingdom goblins("Goblins", 25000, 14000, 17000);
        Kingdom trolls("Trolls", 10000, 15000, 18500);

        if (choice == 1) {
            cout<<"Scouts reported about Goblins:\n";
            cout<<"Warriors: " <<goblins.warriors1()<<endl;
            cout<<"Power: "<<goblins.min_power1()<<"-"<<goblins.max_power1()<<endl;
            bool running = true;
            while (running) {
                int decision = chooseAction(player);
                if (decision == 1){//goblins
                    bool win = goblins.battle(player, goblins);
                    if(win){
                        cout<<"You captured a Weapon Factory!\n";
                        Item *factory = new Weapon_Factory();
                        player->receiveItem(factory);
                        running = false;
                    }
                    else{
                        cout << "Your army retreats and regroups...\n";
                    }
                }
                else if (decision == 2){
                    cout<<"You attempt diplomacy...\n";
                    cout << "\n--- Ambush! ---\n";
                    cout << "While you tried diplomacy, the goblins attacked your kingdom!\n";
                    goblinRaid(player);
                    cout<<"You captured a Weapon Factory!\n";
                    Item *factory = new Weapon_Factory();
                    player->receiveItem(factory);
                    running = false;

                }
                else{
                    cout<<"Enter number 1-3\n";
                }
            }
        }
        else if (choice == 2){//trolls
            cout<<"Scouts reported about Trolls:\n";
            cout<<"Warriors: " <<trolls.warriors1()<<endl;
            cout<<"Power: "<<trolls.min_power1()<<"-"<<trolls.max_power1()<<endl;
            bool running = true;
            while (running){
                int decision = chooseAction(player);
                if (decision == 1){
                    bool win = trolls.battle(player, trolls);
                    if(win){
                        cout << "\n--- While your army fights the Trolls ---\n";
                        cout << "Goblins attack your kingdom!\n";
                        goblinRaid(player);
                        running = false;
                    }
                    else{
                        cout << "\nYour army retreats and regroups...\n";
                    }
                }
                else if (decision == 2){
                    bool solved = trollPuzzle(player);
                    if(solved){
                        cout<<"\nThe Troll King nods.\n";
                        Item* ticket = new MobilizationTicket();
                        player->receiveItem(ticket);
                        running = false;
                    }
                }
                else{
                    cout<<"Enter number 1-3\n";
                }
            }

        }
    }
    bool simpleBattle(Player* player, Kingdom enemy){
        cout << "\n--- Battle begins ---\n";
        int playerPower = rand() % (player->max_power1() - player->min_power1() + 1)+ player->min_power1();
        int enemyPower = rand() % (enemy.max_power1() - enemy.min_power1() + 1)+ enemy.min_power1();
        cout<<"Your army power: "<<playerPower<<endl;
        cout<<enemy.race1()<<" army power: "<<enemyPower<<endl;
        if(playerPower > enemyPower){
            cout<<"Victory!\n";
            return true;
        }
        else{
            cout<<"Defeat!\n";
            player->LoseLive();
            return false;
        }
    }
    void winterScene(Player *player) {
        cout<<"\n----Winter Crisis----\n";
        static bool winterApplied = false;
        cout << "Two months have passed since your last campaign.\n";
        cout << "Winter has come.\n";
        cout << "Food production has stopped.\n";
        cout << "Your people are beginning to starve.\n";
        cout << "Your scouts report:\n";
        cout << "A wealthy kingdom nearby has vast food reserves.\n";
        cout << "Their granaries are full and they are well prepared.\n\n";
        Kingdom winterKingdom("Rich Kingdom", 20000, 17000, 18000);
        cout<<"Scouts reported about Rich Kingdom:\n";
        cout<<"Warriors: " <<winterKingdom.warriors1()<<endl;
        cout<<"Power: "<<winterKingdom.min_power1()<<"-"<<winterKingdom.max_power1()<<endl;
        if(!winterApplied){
            player->set_min_power(player->min_power1() - 4500);
            player->set_max_power(player->max_power1() - 4500);
            cout<<"\nYou lost 4500 power because of hunger!\n";
            winterApplied = true;
        }

        bool running = true;
        while (running) {
            cout << "\nWhat will you do?\n";
            cout << "1 Attack before winter\n";
            cout << "2 Try diplomacy\n";
            cout << "3 Endure the winter\n";
            cout << "4 Show stats\n";
            cout << "5 Inventory\n";
            cout << "Enter your choice: ";
            int choice = getValidation();
            switch (choice) {
                case 4:
                    player->showStats();
                    continue;
                case 5:
                    player->inventoryMenu();
                    continue;
                case 1: {
                    cout<<"You march from the freezing lands\n";
                    bool win = simpleBattle(player, winterKingdom);
                    if (win) {
                        cout<<"Now you can not worry about food for rest time!\n";
                        if(!winterApplied){
                            player->set_min_power(player->min_power1() - 4500);
                            player->set_max_power(player->max_power1() - 4500);

                            cout<<"\nYou lost 4500 power because of hunger!\n";

                            winterApplied = true;
                        }
                    }
                    else{
                        cout << "Winter has weakened your forces\n";
                    }
                    running = false;
                    break;
                }

                case 2:{
                    cout<<"You tried Diplomacy";
                    cout << "The ruler tests your intelligence.\n";

                    cout << "Solve this:\n";
                    cout << "If 5 armies bring 10000 power,\n";
                    cout << "how much power do 9 armies bring?\n";
                    int answer = getValidation();
                    if(answer == 18000){
                        cout << "\nThe ruler is impressed by your wisdom.\n";
                        cout << "They join you and share their food.\n";
                        player->set_min_power(player->min_power1() + 4500);
                        player->set_max_power(player->max_power1() + 4500);
                        cout << "Power increased!\n";
                    }
                    else {
                        cout << "\nWrong answer.\n";
                        cout << "The ruler refuses your offer.\n";

                        cout << "1 Attack\n";
                        cout << "2 Endure winter\n";

                        int second = getValidation();

                        if(second == 1){
                            cout << "\nYou attack in desperation\n";

                            bool win = simpleBattle(player, winterKingdom);

                            if(win){
                                cout << "Victory despite everything!\n";
                                player->set_min_power(player->min_power1() + 1000 + 4500);
                                player->set_max_power(player->max_power1() + 1000 + 4500);
                            }
                        }
                        else{
                            cout << "\nYou endure the winter...\n";
                            player->set_min_power(player->min_power1() - 1000);
                            player->set_max_power(player->max_power1() - 1000);

                            cout << "Your army suffers even more.\n";
                        }
                    }

                    running = false;
                    break;
                }
                case 3: {
                    cout << "\nYou endure the winter...\n";
                    player->set_min_power(player->min_power1() - 1000);
                    player->set_max_power(player->max_power1() - 1000);

                    cout << "Your army suffers even more.\n";
                    running = false;
                    break;
                }
                default:
                    cout << "Enter number 1-5\n";
            }
        }
    }
    void socialScene(Player *player) {
        cout << "\n---------------------------------\n";
        cout << "        NEW CITIZENS\n";
        cout << "---------------------------------\n\n";
        cout << "After surviving the winter...\n";
        cout << "Refugees from different races arrive in your kingdom.\n";
        cout << "They seek shelter and a new life.\n\n";

        bool running = true;
        while (running) {
            cout << "What will you do?\n";
            cout << "1 Build homes for them\n";
            cout << "2 Refuse them\n";
            cout << "3 Show stats\n";
            cout << "4 Inventory\n";
            cout << "Enter your choice: ";

            int choice = getValidation();

            switch(choice){

                case 3:
                    player->showStats();
                    continue;

                case 4:
                    player->inventoryMenu();
                    continue;
                case 1: {
                    cout << "\nYou decide to accept all races into your kingdom.\n";
                    cout << "Houses are built. People feel equal and respected.\n";
                    cout << "Your kingdom grows stronger.\n";
                    player->set_min_power(player->min_power1() + 500);
                    player->set_max_power(player->max_power1() + 500);
                    cout << "Power +500\n";
                    running = false;
                    break;
                    case 2: {
                        cout << "\nYou refuse to accept them.\n";
                        cout << "Tension rises...\n";
                        cout << "A rebellion begins!\n\n";
                        cout << "Rebels are weak...\n";
                        cout << "But some of your own warriors join them.\n";
                        player->set_min_power(player->min_power1() - 4000);
                        player->set_max_power(player->max_power1() - 4000);
                        cout << "4000 power lost due to betrayal.\n";
                        cout << "\nYou crush the rebellion...\n";
                        player->set_min_power(player->min_power1() - 1000);
                        player->set_max_power(player->max_power1() - 1000);
                        cout << "1000 power lost in battle.\n";
                        cout << "Total loss: -5000 power\n";
                        running = false;
                        break;
                    }
                    default:
                    cout<<"Enter number 1-4\n";
                }
            }
        }
    }
    bool advisorPuzzle(Player *player) {
        cout<< "Advisor says:\nWhat comes down but never goes up?\n";

        cout << "1 Time\n";
        cout << "2 Rain\n";
        cout << "3 Self-confidence\n";
        cout << "\nYour answer: ";
        int answer = getValidation();
        while(answer < 1 || answer > 3){
            cout << "Enter number between 1-3\n";
            answer = getValidation();
        }
        if(answer == 2){
            cout << "Advisor gives you a clue: \nNorth army: VERY STRONG\nSouth army: WEAKER\n";
            return true;
        }

        player->LoseLive();
        cout << "\nWrong decision!\n";
        cout << "You sent your main army to the weaker enemy\n";
        cout << "The strong army breaks through!\n";


        return false;

    }
    void doubleAttack(Player *player) {
        cout<<"\n----Two Front War----\n";
        cout << "Your kingdom is under attack!\n";
        cout << "Two enemy armies approach from different sides.\n";
        cout<< "Your advisor will give you clue, when you will solve his puzzle\n";

        bool solved = advisorPuzzle(player);
        if (!solved) {
            cout<<"You miscalculated your strategy\n";
            cout << "Try again!\n\n";
            return;
        }
        cout << "\nYou correctly positioned your army!\n";
        cout << "Both attacks were successfully defended!\n";


    }
    void TraitorScene(Player *player) {
        cout << "\n----Betrayal Revealed----\n";
        cout << "Your advisor has been acting strangely...\n";
        cout << "Scouts report secret meetings with a mysterious race.\n\n";
        cout << "Solve this puzzle that decides when you have heard about it\n";
        cout << "What belongs to you but others use it more than you do?\n";
        cout << "1 Name\n2 Right hand\n3 Time\n";
        cout<< "Your answer: ";
        int answer = getValidation();
        if (answer == 1) {
            cout<< "You heard as soon as possible\n";
            cout << "The Shadow Clan attacked you but you were prepared\n";
            Kingdom ShadowClan("Shadow Clan", 18000, 17000, 19000);
            bool win = ShadowClan.battle(player, ShadowClan);
            if (win) {
                cout << "\nThe traitor is executed.\n";
                cout << "Your kingdom is safe.\n";

                cout << "A new loyal advisor joins you.\n";
                player->set_wisdom(player->wisdom1() + 1);
                cout << "Wisdom +1\n";
            }
        }
        else if (answer == 2 || answer == 3){
            cout << "It was late, they already bagan an attack\n";
            cout << "It was unexpectable attack, your army lost 4000 power\n";
            player->set_min_power(player->min_power1() - 4000);
            player -> set_max_power(player -> max_power1() - 4000);
            Kingdom ShadowClan("Shadow Clan", 18000, 17000, 19000);
            bool win = ShadowClan.battle(player, ShadowClan);
            if (win) {
                cout << "\nThe traitor is executed.\n";
                cout << "Your kingdom is safe.\n";

                cout << "A new loyal advisor joins you.\n";
                player->set_wisdom(player->wisdom1() + 1);
                cout << "Wisdom +1\n";
            }


        }
        else {
            cout << "Enter number 1-3\n";
        }
    }

    void publicSpeech(Player *player) {
        cout << "\n----Public Event----\n";
        cout<< "Solve math task to say speach\n";
        cout<< "2+2*2=?\n";
        cout << "Your answer: ";
        int answer  = getValidation();
        if (answer == 6) {
            cout << "\nYou speak with confidence.\n";
            cout << "\"This will never happen again!\"\n";
            cout << "People are inspired and regain hope.\n";
            cout << "\nAn engineer approaches you...\n";
            cout << "\"My ruler, I created something for you.\"\n";
            Item* cannon = new Cannon();
            player->receiveItem(cannon);
            cout<< "Your Power: "<<player->min_power1()<<"- "<< player-> max_power1()<<endl;
        }
        else {
            cout << "\nYou hesitate...\n";
            cout << "Your speech fails to convince the people.\n";
            cout << "Fear spreads across the kingdom.\n";

            player->set_min_power(player->min_power1() - 200);
            player->set_max_power(player->max_power1() - 200);
            cout << "Power -200\n";
            cout << "\nThe engineer leaves the kingdom...\n";
            cout << "You lost a valuable opportunity.\n";
            cout<< "Your Power: "<<player->min_power1()<<"- "<< player-> max_power1()<<endl;
        }
    }

    bool elfPuzzle(Player *player) {
        cout << "\nThe Elf Queen speaks:\n";
        cout << "\"Answer wisely, human...\"\n\n";
        cout<< "What do you throw out when you want to use it, but take in when you don’t want to use it?\n";
        cout<< "1 Anchor\n2 ball\n";
        cout<< "Your answer: ";
        bool running = true;
        while (running){
            int answer = getValidation();
            if(answer == 1){
                cout << "\nThe Queen smiles.\n";
                running = false;
                return true;
            }
            else if (answer == 2){
                cout << "\nThe Queen frowns.\n";
                running = false;
                return false;
            }
            else {
                cout<<"Enter number 1-2\n";
            }
        }
    }
    void elfScene(Player* player) {
        cout << "\n----Elven Kingdom----\n";
        cout << "You arrive at the Elven capital...\n";
        cout << "The Queen awaits your decision.\n\n";
        Kingdom elves("Elves", 22000, 20000, 25500);
        cout<<"Scouts reported about elves:\n";
        cout<<"Warriors: " <<elves.warriors1()<<endl;
        cout<<"Power: "<<elves.min_power1()<<"-"<<elves.max_power1()<<endl;
        bool running = true;
        while(running){
            int decision = chooseAction(player);
            if(decision == 1){
                cout << "\nYou chose war against the Elves!\n";
                bool win = elves.battle(player, elves);
                if(win){
                    cout << "\nYou defeated the Elves!\n";
                    player->set_min_power(player->min_power1() + 2500);
                    player->set_max_power(player->max_power1() + 2500);
                    cout << "Power +2500\n";
                    running = false;
                }
                else{
                    cout << "Your army retreats...\n";
                }
            }

            else if(decision == 2){
                bool solved = elfPuzzle(player);

                if(solved){
                    cout << "\nAn alliance is formed through marriage.\n";
                    cout << "The kingdoms are united.\n";
                    player->set_min_power(player->min_power1() + 3000);
                    player->set_max_power(player->max_power1() + 3000);
                    cout << "Power +3000\n";
                    running = false;
                }
                else{
                    cout << "\nDiplomacy failed!\n";
                    cout << "The Elves attack!\n";
                    player->set_min_power(player->min_power1() - 1000);
                    player->set_max_power(player->max_power1() - 1000);
                    cout << "Power -1000\n";
                    bool win = elves.battle(player, elves);
                    if(win){
                        cout << "\nYou barely won the war...\n";
                        running = false;
                    }
                    else{
                        cout << "You were pushed back...\n";
                    }
                }
            }
        }
    }
    void featScene(Player *player) {
        cout << "\n----Festival----\n";
        cout << "A grand feast is held in honor of your recent victories.\n";
        cout << "Music plays, nobles celebrate...\n";
        cout << "But suddenly, one Elf becomes aggressive and starts causing chaos!\n\n";
        bool running = true;
        while (running) {
            cout << "What will you do?\n";
            cout << "1 Kill the elf\n";
            cout << "2 Calm him down\n";
            cout << "Enter your choice: ";
            int choice = getValidation();
            switch (choice) {
                case 1: {
                    cout << "\nYou chose violence\n";
                    cout << "The elf is killed.\n";
                    cout << "But this causes outrage among the elves!\n";
                    cout << "A rebellion begins inside your kingdom!\n";

                    player->set_warriors(player->warriors1() - 2000);
                    player->set_min_power(player->min_power1() - 3000);
                    player->set_max_power(player->max_power1() - 3000);

                    cout << "You lost 2000 warriors and 3000 power.\n";

                    running = false;
                    break;
                }
                case 2:{
                    cout << "\nYou try to calm him down...\n";
                    cout << "He challenges your intelligence:\n";
                    cout << "Solve this:\n";
                    cout << "3 * 3 + 6 = ?\n";
                    cout << "Your answer: ";
                    int answer = getValidation();
                    if (answer == 15) {
                        cout << "\nYou speak wisely and calmly.\n";
                        cout << "The elf slowly regains control.\n";
                        cout << "The feast continues peacefully.\n";
                    }
                    else {
                        cout << "\nThe elf gets furious!\n";
                        cout << "\"You mock me?!\"\n";
                        cout << "He suddenly stabs you!\n";
                        player->LoseLive();
                    }

                    running = false;
                    break;
                }
                default:
                    cout << "Enter number 1 or 2\n";
            }
        }
    }
    void dwarfeScene(Player *player) {
        cout << "\n----Dwarven Kingdom----\n";
        cout << "You enter the mountains of the Dwarves...\n";
        cout << "Their warriors are unmatched in strength.\n";
        cout << "They respect only power and honor.\n\n";
        Kingdom dwarves("Dwarves", 30000, 23000, 27000);
        cout<<"Scouts reported about Dwarves:\n";
        cout<<"Warriors: " << dwarves.warriors1() << endl;
        cout<<"Power: "<< dwarves.min_power1() << "-" << dwarves.max_power1() << endl;

        bool running = true;
        while (running) {
            cout << "What will you do?\n";
            cout << "1 Armies fight\n";
            cout << "2 Fight 1 vs 1\n";
            cout << "3 Show stats\n";
            cout << "4 Inventory\n";
            cout << "Enter your choice: ";
            int choice = getValidation();
            switch (choice) {
                case 3:
                    player->showStats();
                    continue;
                case 4:
                    player->inventoryMenu();
                    continue;
                case 1: {
                    cout << "\nYou chose full-scale war!\n";

                    bool win = dwarves.battle(player, dwarves);

                    if (win) {
                        cout << "\nYou defeated the Dwarves!\n";
                        player->set_min_power(player->min_power1() + 3000);
                        player->set_max_power(player->max_power1() + 3000);
                        cout << "Power +3000\n";
                        running = false;
                    }
                    else {
                        cout << "Your army retreats from the mountains...\n";
                    }
                    break;
                }
                case 2: {
                    cout << "\nThe Dwarf King accepts your challenge.\n";
                    cout << "You will fight in a duel of minds and honor!\n\n";
                    int correct = 0;
                    cout << "Riddle 1:\n";
                    cout << "10 + 10*10/10 = ?\n";
                    cout << "Your answer: ";
                    int a1 = getValidation();
                    if (a1 == 20) correct++;
                    cout << "\nRiddle 2:\n";
                    cout << "550/2 = ?\n";
                    cout << "Your answer: ";
                    int a2 = getValidation();
                    if (a2 == 275) correct++;
                    cout << "\nRiddle 3:\n";
                    cout << "log(2)16 = ?\n";
                    cout << "Your answer: ";
                    int a3 = getValidation();
                    if (a3 == 4) correct++;

                    cout << "\nYou solved " << correct << " riddles.\n";
                    int chance;
                    if (correct == 3) {
                        chance = 80;
                    }
                    else if (correct == 2) {
                        chance = 50;
                    }
                    else {
                        chance = 10;
                    }
                    cout << "Your chance of victory: " << chance << "%\n";
                    int roll = rand() % 100;
                    cout << "Fell out: "<< roll<< endl;
                    if (roll < chance) {
                        cout << "\nYou defeated the Dwarf King in honorable combat!\n";
                        cout << "The Dwarves respect your strength.\n";

                        player->set_min_power(player->min_power1() + 3500);
                        player->set_max_power(player->max_power1() + 3500);

                        cout << "Power +3500\n";
                        running = false;
                    }
                    else {
                        cout << "\nYou lost the duel...\n";
                        cout << "The Dwarf King strikes you down!\n";
                        player->LoseLive();
                        running = false;
                    }
                    break;
                }
                    default:
                    cout<< "Enter number 1-4\n";

            }
        }
    }

        void Scene1(Player *player) override {
            retryScene(player, [this, player]() {
                int choice = Humanchoose1(player);
                goblin_troll(player,choice);
            });
        }
        void Scene2(Player *player) override {
            retryScene(player, [this, player]() {
                winterScene(player);
            });
        }
        void Scene3(Player *player) override {
            retryScene(player, [this, player]() {
                socialScene(player);
            });
        }
        void Scene4(Player *player) override {
            retryScene(player, [this, player]() {
                doubleAttack(player);
            });
        }
        void Scene5(Player *player) override {
            retryScene(player, [this, player]() {
               TraitorScene(player);
            });
        }
        void Scene6(Player *player) override {
            retryScene(player, [this, player]() {
               publicSpeech(player);
            });
        }
        void Scene7(Player *player) override {
        retryScene(player, [this, player]() {
              elfScene(player);
           });
    }
    void Scene8(Player *player) override {
        retryScene(player, [this, player]() {
        featScene(player);
            });
    }
        void Scene9(Player *player) override {
        retryScene(player, [this, player]() {
        dwarfeScene(player);
            });
    }

    };

    

    int main() {
        srand(time(0));
        Kingdom humans("Humans",25000,18000,20000);
        Kingdom elves("Elves",18000,20000,22000);
        Kingdom dwarves("Dwarves",12000,21000,23500);
        Player player("","",0,0,0,3,0);
        string inputName;
        cout<<"Enter your name: ";
        getline(cin,inputName);
        player.set_name(inputName);
        cout << "\nWelcome, ruler " << player.name() << "!\n\n";

        showLore();

        player.chooseRace();


        peopleScenes scene;
        scene.introRiddle(&player);
        if(player.race() == "Humans"){
            scene.Scene1(&player);
            scene.Scene2(&player);
            scene.Scene3(&player);
            scene.Scene4(&player);
            scene.Scene5(&player);
            scene.Scene6(&player);
            scene.Scene7(&player);
            scene.Scene8(&player);
            scene.Scene9(&player);
            scene.finalScene(&player);
        }
        else if(player.race() == "Elves"){
            cout << "\n[Elf storyline coming soon...]\n";
        }
        else if(player.race() == "Dwarves"){
            cout << "\n[Dwarf storyline coming soon...]\n";
        }
        return 0;
    }
