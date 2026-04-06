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

    int temp_power_bonus = 0;
    bool acceptedHybrid = false;

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
    void setAcceptedHybrid(bool val){
            acceptedHybrid = val;
        }
    bool getAcceptedHybrid() const{
            return acceptedHybrid;
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

    void setTempBonus(int bonus){
            temp_power_bonus = bonus;
        }
    int getTempBonus() const{
            return temp_power_bonus;
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
    void use(Player *player) override{
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

class NatureSpiritCall : public Item {
public:
    NatureSpiritCall() : Item("Nature Spirit Call") {}
    void use(Player* player) override {
        cout << "You call the Great Spirit of Nature!\n";
        cout << "It will aid you in the next battle.\n";
        player->setTempBonus(4000);
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

        int bonus = player->getTempBonus();
        int playerMin = player->min_power1() + bonus;
        int playerMax = player->max_power1() + bonus;
        int playerPower = rand() % (playerMax - playerMin + 1) + playerMin;
        int enemyPower = rand() % (enemy.max_power1() - enemy.min_power1() + 1) + enemy.min_power1();
        cout << "Your army power: " << playerPower << endl;
        cout << enemy.race1() << " army power: " << enemyPower << endl;

        if(playerPower > enemyPower){
            cout << "Victory! " << enemy.race1() << " tribe defeated.\n";
            int gained = enemy.warriors1() / 6;
            player->set_warriors(player->warriors1() + gained);
            cout << "Part of " << enemy.race1() << " warriors joined you: +" << gained << endl;
            player->set_min_power(player->min_power1() + 400);
            player->set_max_power(player->max_power1() + 400);
            cout << "Your power increased: " << player->min_power1() << "-" << player->max_power1() << endl;
        }
        else {
            player->LoseLive();
            cout << "\nDefeat!\n";
            cout << "You lost one life.\n";
            cout << "Lives remaining: " << player->lives1() << endl;
        }
        player->setTempBonus(0);
        return playerPower > enemyPower;
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

class elfStory : public Scenes{
public:
    bool elfPuzzleTree() {
        cout << "\n--- Elven Campaign ---\n";
        cout << "You approach an ancient tree in the heart of the forest.\n";

        cout << "\nThe tree speaks:\n";
        cout << "\"Answer my riddle, ruler of the elves.\"\n\n";

        cout << "I have keys but no locks.\n";
        cout << "I have space but no room.\n";
        cout << "You can enter but cannot go outside.\n";
        cout << "What am I?\n\n";

        cout << "1 Keyboard\n";
        cout << "2 Book\n";
        cout << "Your answer: ";

        int answer = getValidation();

        while(answer < 1 || answer > 2){
            cout << "Enter number between 1-2\n";
            answer = getValidation();
        }

        if(answer == 1){
            cout << "\nThe ancient tree whispers:\n";
            cout << "The forest spirits respect wisdom.\n";
            cout << "With them diplomacy will be easy.\n";
            return true;
        }
        else{
            cout << "Wrong answer.\n";
            return false;
        }
    }
    bool puzzleBeastfolkRiddle() {
        cout << "\nThe Beastfolk leader challenges you with a riddle.\n\n";

        cout << "I have cities but no houses.\n";
        cout << "I have rivers but no water.\n";
        cout << "I have forests but no trees.\n";
        cout << "What am I?\n\n";

        cout << "1 Map\n";
        cout << "2 Shadow\n";
        int answer = getValidation();
        if(answer == 1){
            cout << "Correct answer.\n";
            return true;
        }
        else if(answer == 2){
            cout << "Wrong answer.\n";
            return false;
        }
        else{
            cout << "Enter number between 1 and 2\n";
            return false;
        }
    }
    int ElfChooseWolvesSpirits(Player *player){
        int x;
        do {
            cout << "\n1 Beastfolk\n";
            cout << "2 Spirits\n";
            cout << "3 Stats\n";
            cout << "4 Inventory\n";
            cout << "Choice: ";
            x = getValidation();
            switch(x){
                case 3:
                    player->showStats();
                    break;
                case 4:
                    player->inventoryMenu();
                    break;
            }
        } while(x != 1 && x != 2);

        return x;
    }
    void wolvesScene(Player* player){
        Kingdom Beastfolk("Beastfolk", 14000, 16000, 19000);
        cout << "\nScouts reported about Beastfolk:\n";
        cout << "Pack strength: " << Beastfolk.warriors1() << endl;
        cout << "Power: " << Beastfolk.min_power1() << "-" << Beastfolk.max_power1() << endl;
        bool running = true;
        while(running){
            int decision = chooseAction(player);
            switch(decision){
                case 1: {
                    cout << "\nYou attack the Beastfolk!\n";
                    bool win = Beastfolk.battle(player, Beastfolk);
                    if(win){
                        cout << "You dominated the wolf packs.\n";
                        player->set_warriors(player->warriors1() + 1500);
                        cout << "Warriors +1500\n";
                        running = false;
                    }
                    break;
                }
                case 2: {
                    cout << "\nYou try to tame the Beastfolk\n";
                    cout << "Alpha wolf asks:\n";
                    cout << "What runs but never walks?\n";
                    cout << "1 River\n2 Fire\n";
                    int answer = getValidation();
                    if(answer == 1){
                        cout << "\nThe alpha accepts you.\n";
                        cout << "You receive Mobilization Ticket!\n";

                        Item* ticket = new MobilizationTicket();
                        player->receiveItem(ticket); // ← инвентарь тут

                        running = false;
                    }
                    else{
                        cout << "\nThe Beastfolks attack!\n";
                        player->LoseLive();
                        running = false;
                    }
                    break;
                }
                default:
                    cout << "Enter number 1-2\n";
            }
        }
    }
    void spiritsScene(Player* player){
        cout << "\nYou enter sacred forest...\n";
        cout << "The air becomes calm...\n";
        cout << "\nThe spirits recognize you as an elf ruler.\n";
        cout << "They do not test you.\n";
        cout << "They join your kingdom willingly.\n\n";
        player->set_min_power(player->min_power1() + 1500);
        player->set_max_power(player->max_power1() + 1500);
        cout << "Power +1500\n";
        cout << "\nThe Great Spirit grants you a blessing...\n";
        Item* spiritCall = new NatureSpiritCall();
        player->receiveItem(spiritCall);
    }
    void beastfolks_spirits(Player* player){
        int choice = ElfChooseWolvesSpirits(player);
        switch(choice){
            case 1:
                wolvesScene(player);
                break;
            case 2:
                spiritsScene(player);
                break;
        }
    }
    void elfWinterDilemma(Player* player){
    cout << "\n----Fading Forest----\n";
    cout << "Winter has come...\n";
    cout << "Your forest is dying.\n";
    cout << "Magic weakens. Trees lose their glow.\n\n";
    cout << "Scouts report another forest nearby...\n";
    cout << "But it belongs to the Dark Elves.\n\n";
    cout << "They are weaker than your people...\n";
    cout << "But your army is weakened by winter.\n\n";
    bool running = true;
    do {
        cout << "\nWhat will you do?\n";
        cout << "1 Move to new forest (risk battle)\n";
        cout << "2 Stay and endure winter\n";
        cout << "3 Show stats\n";
        cout << "4 Inventory\n";
        cout << "Choice: ";
        int choice = getValidation();

        switch(choice){
            case 3:
                player->showStats();
                break;
            case 4:
                player->inventoryMenu();
                break;
            case 1: {
                cout << "\nYou move to a new forest...\n";
                cout << "Dark Elves block your path!\n";
                Kingdom darkElves("Dark Elves", 15000, 15000, 17500);
                int oldMin = player->min_power1();
                int oldMax = player->max_power1();
                player->set_min_power(oldMin - 2500);
                player->set_max_power(oldMax - 2500);
                cout << "Winter weakens you (-2500 power this battle)\n";

                bool win = darkElves.battle(player, darkElves);
                player->set_min_power(oldMin);
                player->set_max_power(oldMax);
                if(win){
                    cout << "\nYou defeated the Dark Elves!\n";
                    cout << "You settle in a new forest.\n";
                }
                else{
                    cout << "\nYou retreat into the cold...\n";
                }
                running = false;
                break;
            }
            case 2: {
                cout << "\nYou stay in your dying forest...\n";
                cout << "Your people suffer.\n";
                const int PERMA = 2000;
                player->set_min_power(player->min_power1() - PERMA);
                player->set_max_power(player->max_power1() - PERMA);
                cout << "Permanent power -2000\n";
                running = false;
                break;
            }
            default:
                cout << "Enter number 1-4\n";
        }
    } while(running);
}
    void sacredTreeScene(Player* player){
    cout << "\n----Sacred Tree----\n";
    cout << "The ancient tree is dying...\n";
    cout << "Its magic sustains the longevity of all elves.\n\n";
    cout << "If it dies...\n";
    cout << "Your people will lose part of their life force.\n\n";
    bool running = true;

    do {
        cout << "What will you do?\n";
        cout << "1 Heal the tree\n";
        cout << "2 Ignore it\n";
        cout << "3 Show stats\n";
        cout << "4 Inventory\n";
        cout << "Choice: ";
        int choice = getValidation();
        switch(choice){
            case 3:
                player->showStats();
                break;
            case 4:
                player->inventoryMenu();
                break;
            case 1: {
                cout << "\nYou attempt to heal the sacred tree...\n";
                cout << "Ancient magic requires precision.\n\n";
                cout << "Solve this:\n";
                cout << "6 * 6 - 10 = ?\n";
                cout << "Your answer: ";
                int answer = getValidation();
                if(answer == 26){
                    cout << "\nThe tree is restored!\n";
                    cout << "Its magic flows once again.\n";
                    player->set_min_power(player->min_power1() + 1500);
                    player->set_max_power(player->max_power1() + 1500);
                    cout << "Power +1500\n";
                }
                else{
                    cout << "\nYour magic fails...\n";
                    cout << "The tree collapses into dust.\n";
                    player->LoseLive();
                }
                running = false;
                break;
            }
            case 2: {
                cout << "\nYou ignore the tree...\n";
                cout << "Days pass...\n";
                cout << "The sacred tree dies.\n\n";
                cout << "Elves feel their life force fading...\n";
                player->LoseLive();
                running = false;
                break;
            }
            default:
                cout << "Enter number 1-4\n";
        }
    } while(running);
}
    void hybridVisitorScene(Player* player){
    cout << "\n----Strange Visitor----\n";
    cout << "A traveler arrives at your gates...\n\n";
    cout << "He is... unusual.\n";
    cout << "Half-elf. Half-dwarf.\n\n";
    cout << "\"My mother was one of your elders,\" he says.\n";
    cout << "\"I seek a place in your kingdom.\"\n\n";
    cout << "Your advisors whisper:\n";
    cout << "\"He does not belong to any race...\"\n\n";
    bool running = true;
    do {
        cout << "What will you do?\n";
        cout << "1 Accept him\n";
        cout << "2 Refuse\n";
        cout << "3 Show stats\n";
        cout << "4 Inventory\n";
        cout << "Choice: ";

        int choice = getValidation();
        switch(choice){
            case 3:
                player->showStats();
                break;
            case 4:
                player->inventoryMenu();
                break;
            case 1: {
                cout << "\nYou accept the stranger.\n";
                cout << "That night, he approaches you.\n\n";
                cout << "\"If you are worthy... answer this.\"\n\n";
                cout << "I build but never rest.\n";
                cout << "I create but never live.\n";
                cout << "What am I?\n";
                cout << "1 Factory\n2 Warrior\n";
                int answer = getValidation();
                if(answer == 1){
                    cout << "\nHe smiles.\n";
                    cout << "\"Then you understand...\"\n\n";
                    cout << "He reveals the location of an abandoned factory.\n";
                    cout << "You claim it for your kingdom.\n\n";
                    Item* factory = new Weapon_Factory();
                    player->receiveItem(factory);
                }
                else{
                    cout << "\nHe looks disappointed.\n";
                    cout << "\"You are not ready...\"\n";
                }
                player->setAcceptedHybrid(true);
                running = false;
                break;
            }
            case 2: {
                cout << "\nYou refuse him.\n";
                cout << "He lowers his head\n\n";
                cout << "\"You have lost your chance to grow stronger.\"\n";
                cout << "Without another word, he disappears into the shadows.\n";
                player->setAcceptedHybrid(false);
                running = false;
                break;
            }

            default:
                cout << "Enter number 1-4\n";
        }

    } while(running);
}
    void hybridReturnScene(Player* player){
    cout << "\n----Unexpected Return----\n";
    if(player->getAcceptedHybrid()){


        cout << "The hybrid returns...\n";
        cout << "\"Enemies are coming. I warned you.\"\n\n";
        cout << "A small enemy force approaches.\n";
        Kingdom weakArmy("Raiders", 8000, 9000, 11000);
        cout << "Scouts report:\n";
        cout << "Warriors: " << weakArmy.warriors1() << endl;
        cout << "Power: " << weakArmy.min_power1() << "-" << weakArmy.max_power1() << endl;
        cout << "\nYour army easily overwhelms them.\n";
        cout << "Victory is inevitable.\n";
        cout << "Victory!\n";
        cout << "No significant gains.\n";
    }
    else{
        cout << "A familiar figure stands before your gates...\n";
        cout << "It is the one you rejected.\n\n";
        cout << "\"You chose weakness. Now face it.\"\n\n";
        cout << "He has taken control of an abandoned factory...\n";
        cout << "His army is stronger.\n";
        Kingdom boss("Hybrid Warlord", 22000, 20000, 24000);
        cout << "\nScouts report:\n";
        cout << "Warriors: " << boss.warriors1() << endl;
        cout << "Power: " << boss.min_power1() << "-" << boss.max_power1() << endl;
        bool running = true;
        while(running){
            int decision = chooseAction(player);
            switch(decision){
                case 1: {
                    cout << "\nYou engage the Hybrid Warlord!\n";
                    bool win = boss.battle(player, boss);
                    if(win){
                        cout << "\nYou defeated the hybrid!\n";
                        cout << "The factory is now yours.\n";
                        Item* factory = new Weapon_Factory();
                        player->receiveItem(factory);
                        running = false;
                    }
                    else{
                        cout << "He laughs as your army retreats...\n";
                    }
                    break;
                }
                case 2: {
                    cout << "\nYou attempt diplomacy...\n";
                    cout << "\"Too late for that.\"\n";
                    cout << "He attacks immediately!\n";
                    bool win = boss.battle(player, boss);
                    if(win){
                        cout << "\nYou barely survive and defeat him.\n";
                        Item* factory = new Weapon_Factory();
                        player->receiveItem(factory);
                        running = false;
                    }
                    break;
                }
                default:
                    cout << "Enter number 1-4\n";
            }
        }
    }
}
    void feastScene(Player* player){
    cout << "\n----Grand Feast----\n";
    cout << "A great feast is held in your honor.\n";
    cout << "Music fills the hall, nobles celebrate your victories.\n\n";
    cout << "Wine flows. Guards relax.\n";
    cout << "For a moment... there is peace.\n\n";
    bool running = true;
    do {
        cout << "What will you do?\n";
        cout << "1 Enjoy the feast\n";
        cout << "2 Stay alert\n";
        cout << "3 Show stats\n";
        cout << "4 Inventory\n";
        cout << "Choice: ";
        int choice = getValidation();
        switch(choice){
            case 3:
                player->showStats();
                break;
            case 4:
                player->inventoryMenu();
                break;
            case 1: {
                cout << "\nYou relax and enjoy the feast...\n";
                cout << "Laughter echoes across the hall.\n\n";
                cout << "Suddenly...\n";
                cout << "A sharp pain hits you.\n";
                cout << "The wine was poisoned!\n";
                player->LoseLive();
                running = false;
                break;
            }
            case 2: {
                cout << "\nYou stay alert, watching the crowd...\n";
                cout << "Something feels wrong.\n\n";
                cout << "You notice a servant acting strangely.\n";
                cout << "He carries a cup toward you.\n\n";
                cout << "Solve quickly:\n";
                cout << "8 * 3 - 10 = ?\n";
                cout << "Your answer: ";
                int answer = getValidation();
                if(answer == 14){
                    cout << "\nYou react instantly!\n";
                    cout << "You stop the servant.\n";
                    cout << "He confesses — an assassin.\n\n";
                    cout << "The threat is eliminated.\n";
                    player->set_min_power(player->min_power1() + 1000);
                    player->set_max_power(player->max_power1() + 1000);
                    cout << "Power +1000\n";
                }
                else{
                    cout << "\nToo slow...\n";
                    cout << "The poison reaches you.\n";
                    player->LoseLive();
                }
                running = false;
                break;
            }
            default:
                cout << "Enter number 1-4\n";
        }
    } while(running);
}
    void assassinTruthScene(Player* player) {
        cout << "\n----The Poisoner----\n";
        cout << "You find the one who tried to poison you...\n\n";
        cout << "\"Answer me... and I will tell you the truth.\"\n\n";
        cout << "I am always behind you, yet you cannot see me.\n";
        cout << "What am I?\n";
        cout << "1 Shadow\n2 Wind\n";
        int answer = getValidation();
        if(answer == 1){
            cout << "\"It was the dwarves. They prepare for war.\"\n";
        }
        else{
            cout << "\"It was the humans.\"\n";
        }
        bool running = true;
        do {
            int choose = chooseAction(player);
            if (choose == 1) {
                cout << "It was incorrect choice...\n";
                cout << "During your fight Dwarfs attack you\n";
                cout << "Now Dwarfs are the kings of this mainland\n";
                player->LoseLive();
                running = false;
            }
            else if (choose == 2) {
                    cout << "\nYou choose diplomacy...\n";
                    cout << "The humans agree immediately.\n";
                    cout << "An alliance is formed.\n";
                    player->set_min_power(player->min_power1() + 2500);
                    player->set_max_power(player->max_power1() + 2500);
                    cout << "Power +2500\n";
                    running = false;
            }
        }while (running);
    }
    void finalSceneElves(Player* player){
        cout << "\n----FINAL----\n\n";

        cout << "With the humans at your side...\n";
        cout << "Your armies march as one.\n\n";

        cout << "The dwarves stand against you...\n";
        cout << "But they are not ready for such force.\n\n";

        cout << "The battle is short.\n";
        cout << "Their lines break.\n";
        cout << "Their king falls.\n\n";

        cout << "Victory.\n\n";

        cout << "The continent is united.\n";
        cout << "Elves and humans rule together.\n";
        cout << "A new era begins.\n";
    }

    void Scene1(Player *player) override {
        elfPuzzleTree();
    }
    void Scene2(Player *player) override {
        beastfolks_spirits(player);
    }
    void Scene3(Player *player) override {
        retryScene(player, [this, player]() {
        elfWinterDilemma(player);
            });
    }
    void Scene4(Player *player) override {
        retryScene(player, [this, player]() {
        sacredTreeScene(player);
            });
    }
    void Scene5(Player *player) override {
        retryScene(player, [this, player]() {
        hybridVisitorScene(player);
            });
    }
    void Scene6(Player *player) override {
        retryScene(player, [this, player]() {
        hybridVisitorScene(player);
            });
    }
    void Scene7(Player *player) override {
        retryScene(player, [this, player]() {
        feastScene(player);
            });
    }
    void Scene8(Player *player) override {
        retryScene(player, [this, player]() {
        assassinTruthScene(player);
            });
    }
    void Scene9(Player *player) override {
        finalSceneElves(player);
    }
};
class AncientAlloy : public Item {
public:
    AncientAlloy() : Item("Ancient Alloy") {}

    void use(Player* player) override {
        cout << "You study the Ancient Alloy...\n";
        cout << "Your understanding of craft improves.\n";

        player->set_wisdom(player->wisdom1() + 1);

        cout << "Wisdom +1\n";
    }
};

class DwarfStory : public Scenes {
public:
    void dwarfForgeDuel(Player* player){
        cout << "\n----Forge Duel----\n";
        cout << "You enter the great forge of the dwarves.\n";
        cout << "Heat, steel, and fire surround you.\n\n";
        cout << "\"We judge rulers by their craft skills.\"\n";
        int correct = 2;
        cout << "Question 1:\n";
        cout << "What does 'Au' mean?\n";
        cout << "1 Silver\n2 Gold\n3 Iron\n4 Copper\n";
        cout << "Answer: ";
        int a1 = getValidation();
        if(a1 == 2){
            correct += 30;
        }
        cout << "\nQuestion 2:\n";
        cout << "At what temperature does water boil ?\n";
        cout << "1 50\n2 90\n3 100\n4 120\n";
        cout << "Answer: ";
        int a2 = getValidation();
        if(a2 == 3){
            correct += 30;
        }
        cout << "\nQuestion 3:\n";
        cout << "What is better sword or axe?\n";
        cout << "1 Depends on fighter skills\n2 Axe\n3 Sword\n4 Depends on weapon's quality\n";
        cout << "Answer: ";
        int a3 = getValidation();
        if(a3 == 1){
            correct += 30;
        }
        int chance = correct;

        cout << "Your chance of success: " << chance << "%\n";

        int roll = rand() % 100;

        cout << "Roll: " << roll << endl;

        if(roll <= chance){
            cout << "\nThe dwarves nod in respect.\n";
            cout << "\"You understand the forge.\"\n";
            player->set_min_power(player->min_power1() + 2000);
            player->set_max_power(player->max_power1() + 2000);
            cout << "Power +2000\n";
        }
        else{
            player ->LoseLive();
        }
    }
    void HobbitScene(Player *player) {
        cout << "\n----Hobbit Settlements----\n";
        cout << "You discover peaceful hobbit villages.\n";
        cout << "They are small... but clever.\n\n";
        Kingdom hobbits("Hobbits", 9000, 12000, 15000);
        cout << "\nScouts report:\n";
        cout << "Warriors: " << hobbits.warriors1() << endl;
        cout << "Power: " << hobbits.min_power1() << "-" << hobbits.max_power1() << endl;
        bool running = true;
        do {
            int choice = chooseAction(player);
            switch(choice){
                case 1: {
                    cout << "\nYou attack the hobbits...\n";
                    bool win = hobbits.battle(player, hobbits);
                    if(win){
                        cout << "\nYou crush their resistance.\n";
                        cout << "You capture their workshop!\n";
                        Item* factory = new Weapon_Factory();
                        player->receiveItem(factory);
                    }
                    else{
                        cout << "Even hobbits can surprise you...\n";
                    }
                    running = false;
                    break;
                }
                case 2: {
                    cout << "\nYou attempt diplomacy...\n";
                    cout << "The hobbits test your intelligence.\n\n";
                    cout << "Solve this:\n";
                    cout << "12 * 2 + 6 = ?\n";
                    cout << "Your answer: ";
                    int answer = getValidation();
                    if(answer == 30){
                        cout << "\nThe hobbits trust you.\n";
                        cout << "They offer support.\n";
                        Item* ticket = new MobilizationTicket();
                        player->receiveItem(ticket);
                    }
                    else{
                        cout << "\nWrong.\n";
                        cout << "The hobbits refuse to help.\n";
                    }
                    running = false;
                    break;
                }
                default:
                    cout << "Enter number 1-4\n";
            }
        } while(running);
    }
    void hobbitRebellion(Player* player){
    cout << "\n----Hobbit Trouble----\n";
    cout << "Some dwarves mistreat the hobbits.\n";
    cout << "Tension rises in the settlements.\n\n";
    bool running = true;
    do {
        cout << "What will you do?\n";
        cout << "1 Stop the dwarves\n";
        cout << "2 Ignore the situation\n";
        cout << "Choice: ";
        int choice = getValidation();
        switch(choice){
            case 1: {
                cout << "\nYou decide to restore order.\n";
                cout << "The hobbits test your fairness.\n\n";
                cout << "Solve this:\n";
                cout << "15 + 5 * 2 = ?\n";
                cout << "Your answer: ";
                int answer = getValidation();
                if(answer == 25){
                    cout << "\nThe hobbits respect your justice.\n";
                    cout << "They support your rule.\n";
                    player->set_min_power(player->min_power1() + 1000);
                    player->set_max_power(player->max_power1() + 1000);
                    cout << "Power +1000\n";
                }
                else{
                    cout << "\nYou fail to calm the situation...\n";
                    cout << "Rebellion begins!\n";
                    player->set_min_power(player->min_power1() - 4000);
                    player->set_max_power(player->max_power1() - 4000);
                    cout << "Power -4000\n";
                }
                running = false;
                break;
            }
            case 2: {
                cout << "\nYou ignore the problem...\n";
                cout << "The hobbits rise in rebellion!\n";
                player->set_min_power(player->min_power1() - 4000);
                player->set_max_power(player->max_power1() - 4000);
                cout << "Power -4000\n";
                running = false;
                break;
            }
            default:
                cout << "Enter number 1-2\n";
        }
    } while(running);
}
    void rareMetalScene(Player* player){
        cout << "\n----Deep Mine Discovery----\n";
        cout << "Deep in the mines...\n";
        cout << "Your workers discover a strange metal.\n\n";
        cout << "It glows faintly.\n";
        cout << "No one understands its purpose.\n\n";
        cout << "An inscription is carved nearby:\n\n";
        cout << "\"I am not alive, but I grow.\n";
        cout << "I dont have lungs, but I need air.\n";
        cout << "What am I?\"\n\n";
        cout << "1 Fire\n2 Stone\n3 Iron\n4 Shadow\n";
        cout << "Your answer: ";
        int answer = getValidation();
        if(answer == 1){
            cout << "\nYou understand...\n";
            cout << "This metal reacts to heat.\n";
            cout << "It can be forged into something powerful.\n\n";
            Item* alloy = new AncientAlloy();
            player->receiveItem(alloy);
        }
        else{
            cout << "\nYou fail to understand its nature...\n";
            cout << "The metal is discarded as useless.\n";
        }
    }
    void dwarfBetrayal(Player* player){
        cout << "\n----Clan Betrayal----\n";
        cout << "One of the dwarf clans plots against you.\n";
        cout << "They seek power.\n\n";
        bool running = true;
        while(running){
            cout << "What will you do?\n";
            cout << "1 Execute the traitors\n";
            cout << "2 Show mercy\n";
            cout << "3 Stats\n";
            cout << "4 Inventory\n";
            cout << "Choice: ";
            int choice = getValidation();
            switch(choice){
                case 3:
                    player->showStats();
                    continue;
                case 4:
                    player->inventoryMenu();
                    continue;
                case 1: {
                    cout << "\nYou execute the traitors.\n";
                    cout << "Order is restored through fear.\n";
                    player->set_min_power(player->min_power1() + 1500);
                    player->set_max_power(player->max_power1() + 1500);
                    cout << "Power +1500\n";
                    running = false;
                    break;
                }
                case 2: {
                    cout << "\nYou show mercy...\n";
                    cout << "The clan pretends loyalty...\n";
                    cout << "But betrayal comes later.\n";
                    player->set_min_power(player->min_power1() - 2000);
                    player->set_max_power(player->max_power1() - 2000);
                    cout << "Power -2000\n";
                    running = false;
                    break;
                }
                default:
                    cout << "Enter number 1-4\n";
            }
        }
    }
    void dwarfTombScene(Player* player){
    cout << "\n----Ancient Tomb----\n";
    cout << "Deep in the mountains...\n";
    cout << "You discover an ancient sealed tomb.\n\n";
    cout << "Runes are carved into the stone:\n\n";
    cout << "I guard treasures untold.\n";
    cout << "I sleep on gold.\n";
    cout << "Fire is my breath.\n";
    cout << "What am I?\n\n";
    cout << "1 Dragon\n2 King\n3 Fire\n";
    if(player->wisdom1() <= 2)
        cout << "4 Demon\n";
    cout << "Your answer: ";
    int answer = getValidation();


    if(answer == 1){
        cout << "\nYou understand the warning...\n";
        cout << "A dragon sleeps within.\n";
    }
    else{
        cout << "\nThe meaning escapes you...\n";
    }
    bool running = true;
    do {
        cout << "\nWhat will you do?\n";
        cout << "1 Enter the tomb\n";
        cout << "2 Leave it\n";
        cout << "3 Stats\n";
        cout << "4 Inventory\n";
        cout << "Choice: ";
        int choice = getValidation();
        switch(choice){
            case 3:
                player->showStats();
                break;
            case 4:
                player->inventoryMenu();
                break;
            case 1: {
                cout << "\nYou enter the tomb...\n";
                cout << "The ground trembles...\n";
                cout << "\nA DRAGON AWAKENS!\n";
                cout << "After a brutal battle...\n";
                cout << "You defeat it.\n";
                cout << "But all treasures burned during the fight :(\n";
                player->set_min_power(player->min_power1() - 5000);
                player->set_max_power(player->max_power1() - 5000);
                cout << "Power -5000\n";
                running = false;
                break;
            }
            case 2: {
                cout << "\nYou decide not to risk it.\n";
                cout << "Some secrets are better left buried.\n";
                running = false;
                break;
            }
            default:
                cout << "Enter number 1-4\n";
        }
    } while(running);
}
    void dwarfFeastScene(Player* player){
    cout << "\n----War Council Feast----\n";
    cout << "Before the great war...\n";
    cout << "Your generals gather in the great hall.\n\n";
    cout << "Some suggest a final feast to raise morale.\n";
    cout << "Others prefer strict preparation.\n\n";
    bool running = true;
    do {
        cout << "What will you do?\n";
        cout << "1 Hold a feast\n";
        cout << "2 Prepare for war\n";
        cout << "3 Stats\n";
        cout << "4 Inventory\n";
        cout << "Choice: ";
        int choice = getValidation();
        switch(choice){
            case 3:
                player->showStats();
                break;
            case 4:
                player->inventoryMenu();
                break;
            case 1: {
                cout << "\nYou hold a grand feast.\n";
                cout << "Ale flows. Warriors laugh.\n\n";
                cout << "But suddenly, two captains argue...\n";
                cout << "Solve quickly:\n";
                cout << "9 + 3 * 2 = ?\n";
                cout << "Your answer: ";
                int answer = getValidation();
                if(answer == 15){
                    cout << "\nYou calm them with wisdom.\n";
                    cout << "Morale rises across the army.\n";
                    player->set_min_power(player->min_power1() + 1500);
                    player->set_max_power(player->max_power1() + 1500);
                    cout << "Power +1500\n";
                }
                else{
                    cout << "\nThe conflict escalates...\n";
                    cout << "Tension spreads in your ranks.\n";
                    player->set_min_power(player->min_power1() - 1000);
                    player->set_max_power(player->max_power1() - 1000);
                    cout << "Power -1000\n";
                }
                running = false;
                break;
            }
            case 2: {
                cout << "\nYou choose discipline over celebration.\n";
                cout << "Your army prepares in silence.\n";
                running = false;
                break;
            }
            default:
                cout << "Enter number 1-4\n";
        }
    } while(running);
}
    void dwarfWarElfScene(Player* player){
    cout << "\n----War with Elves----\n";
    cout << "The war begins...\n";
    cout << "Elven armies stand before you.\n\n";
    Kingdom elves("Elves", 20000, 22000, 27000);
    cout << "Scouts report:\n";
    cout << "Warriors: " << elves.warriors1() << endl;
    cout << "Power: " << elves.min_power1() << "-" << elves.max_power1() << endl;
    bool running = true;
    while(running){
        cout << "\nWhat will you do?\n";
        cout << "1 Army vs Army\n";
        cout << "2 Duel (1 vs 1)\n";
        cout << "3 Stats\n";
        cout << "4 Inventory\n";
        cout << "Choice: ";
        int choice = getValidation();
        switch(choice){
            case 3:
                player->showStats();
                continue;
            case 4:
                player->inventoryMenu();
                continue;
            case 1: {
                cout << "\nYou command a full assault!\n";
                bool win = elves.battle(player, elves);
                if(win){
                    cout << "\nYou crush the elven army.\n";
                    player->set_min_power(player->min_power1() + 2000);
                    player->set_max_power(player->max_power1() + 2000);
                    cout << "Power +2000\n";
                    running = false;
                }
                else{
                    cout << "The elves push you back...\n";
                }
                break;
            }
            case 2: {
                cout << "\nYou challenge the Elf Champion.\n";
                cout << "A duel of mind and skill begins.\n\n";
                int correct = 0;
                cout << "Riddle 1:\n";
                cout << "20 / 5 + 6 = ?\n";
                cout<< "Answer: ";
                if(getValidation() == 10) correct++;
                cout << "\nRiddle 2:\n";
                cout << "2^4 = ?\n";
                cout<< "Answer: ";
                if(getValidation() == 16) correct++;
                cout << "\nRiddle 3:\n";
                cout << "log(2)32 = ?\n";
                cout<< "Answer: ";
                if(getValidation() == 5) correct++;
                cout << "\nCorrect: " << correct << endl;
                int chance = correct * 30;
                cout << "Chance: " << chance << "%\n";
                int roll = rand() % 100;
                cout << "Roll: " << roll << endl;
                if(roll < chance){
                    cout << "\nYou defeat the Elf Champion!\n";
                    cout << "The elven army retreats.\n";
                    player->set_min_power(player->min_power1() + 2500);
                    player->set_max_power(player->max_power1() + 2500);
                    cout << "Power +2500\n";
                    running = false;
                }
                else{
                    cout << "\nYou lose the duel...\n";
                    player->LoseLive();
                }
                break;
            }
            default:
                cout << "Enter number 1-4\n";
        }
    }
}
    void dwarfFinalScene(){
        cout << "\n----FINAL----\n\n";
        cout << "The war is over.\n";
        cout << "The elves have fallen.\n\n";
        cout << "The mountains stand stronger than ever.\n";
        cout << "The forges burn day and night.\n\n";
        cout << "Now only one question remains...\n";
        cout << "When will the humans fall?\n\n";
        cout << "It is only a matter of time.\n\n";
        cout << "You have brought glory to the dwarven kingdoms.\n";
        cout << "Strength. Steel. Power.\n\n";
        cout << "You are the ruler of this world.\n";
    }
    void Scene1(Player *player) override {
        retryScene(player, [this, player]() {
        dwarfForgeDuel(player);
            });
    }
    void Scene2(Player *player) override {
        retryScene(player, [this, player]() {
        HobbitScene(player);
            });
    }
    void Scene3(Player *player) override {
        retryScene(player, [this, player]() {
        hobbitRebellion(player);
            });
    }
    void Scene4(Player *player) override {
        retryScene(player, [this, player]() {
        rareMetalScene(player);
            });
    }
    void Scene5(Player *player) override {
        retryScene(player, [this, player]() {
        dwarfBetrayal(player);
            });
    }
    void Scene6(Player *player) override {
        retryScene(player, [this, player]() {
        dwarfTombScene(player);
            });
    }
    void Scene7(Player *player) override {
        retryScene(player, [this, player]() {
        dwarfFeastScene(player);
            });
    }
    void Scene8(Player *player) override {
        retryScene(player, [this, player]() {
        dwarfWarElfScene(player);
            });
    }
    void Scene9(Player *player) override {
        dwarfFinalScene();
    }
};

    

    int main() {
        srand(time(0));
        Player player("","",0,0,0,3,0);
        string inputName;
        cout<<"Enter your name: ";
        getline(cin,inputName);
        player.set_name(inputName);
        cout << "\nWelcome, ruler " << player.name() << "!\n\n";

        showLore();

        player.chooseRace();



        if(player.race() == "Humans"){
            peopleScenes scene;
            scene.introRiddle(&player);
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
            elfStory elfScene;
            elfScene.introRiddle(&player);
            elfScene.Scene1(&player);
            elfScene.Scene2(&player);
            elfScene.Scene3(&player);
            elfScene.Scene4(&player);
            elfScene.Scene5(&player);
            elfScene.Scene6(&player);
            elfScene.Scene7(&player);
            elfScene.Scene8(&player);
            elfScene.Scene9(&player);
        }
        else if(player.race() == "Dwarves"){
            DwarfStory dwarvesScene;
            dwarvesScene.Scene1(&player);
            dwarvesScene.Scene2(&player);
            dwarvesScene.Scene3(&player);
            dwarvesScene.Scene4(&player);
            dwarvesScene.Scene5(&player);
            dwarvesScene.Scene6(&player);
            dwarvesScene.Scene7(&player);
            dwarvesScene.Scene8(&player);
            dwarvesScene.Scene9(&player);
        }
        return 0;
    }
