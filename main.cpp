#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <vector>

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
class item; //declaration
class Player {
    string Name;
    string Race;
    int warriors;
    int min_power;
    int max_power;
    int lives;
    int wisdom;

    vector <item*> inventory;
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
    void addItem(item *item) {
           inventory.push_back(item);
           cout<<"Item received: "<< item->item_name()<<endl;
        }
    void showInventory() {
            cout<<"----Inventory----\n";
            if (inventory.empty()) {
                cout<<"Inventory empty\n";
            }
            else {
                for (int i= 0; i < inventory.size(); i++) {
                    cout<<i++<<")"<<inventory[i]->item_name<<endl;
                }
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
class item {
protected:
    string itemName;
public:
    item (string cItemName) {
        itemName = cItemName;
    }

    string item_name(){
        return itemName;
    }

    void set_item_name(string item_name) {
        itemName = item_name;
    }
    void useName(Player *player) {
        cout<<"You used "<< itemName<<endl;
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
    int chooseAction(Player* player){
        int decision;
        bool run = true;
        while(run){
            cout << "\nWhat will you do?\n";
            cout << "1 Attack\n";
            cout << "2 Try diplomacy\n";
            cout << "3 See stats\n";
            cout << "Enter your choice: ";
            decision = getValidation();
            if(decision == 3){
                player->showStats();
                continue;
            }
            if(decision == 1 || decision == 2){
                run = false;
            }
            else{
                cout << "Enter number 1-3\n";
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

        if(answer == 1){
            cout << "The crowd erupts in cheers.\n";
            player->set_min_power(player->min_power1() + 400);
            player->set_max_power(player->max_power1() + 400);
            cout << "Power +400\n";
        }
        else{
            cout << "The crowd looks uncertain.\n";
            player->set_min_power(player->min_power1() - 400);
            player->set_max_power(player->max_power1() - 400);
            cout << "Power -400\n";
        }
        return true;
    }
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
            if (x >=1 && x<=3) {
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

        player->set_min_power(player->min_power1() - 700);
        player->set_max_power(player->max_power1() - 700);

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

        player->set_min_power(player->min_power1() - 500);
        player->set_max_power(player->max_power1() - 500);

        cout << "Your army loses confidence.\n";
        cout << "Power decreased by 500.\n";
    }
    void Scene4(Player *player, int choice) {

        Kingdom goblins("Goblins", 25000, 14000, 17000);
        Kingdom trolls("Trolls", 10000, 15000, 18500);

        if (choice == 1) {
            cout<<"Scouts reported about Goblins:\n";
            cout<<"Warriors: " <<goblins.warriors1()<<endl;
            cout<<"Power: "<<goblins.min_power1()<<"-"<<goblins.max_power1()<<endl;
            bool running = true;
            while (running) {
                int decision = chooseAction(player);
                if (decision == 1){
                    bool win = goblins.battle(player, goblins);
                    if(win){
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
                    cout<<"Your people discover a weapon factory\n";
                    running = false;
                }
                else{
                    cout<<"Enter number 1-3\n";
                }
            }
        }
        else if (choice == 2){
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
                        cout<<"You receive a mobilisation ticket.\n";
                        running = false;
                    }
                }
                else{
                    cout<<"Enter number 1-3\n";
                }
            }

        }
    }

    void humanStory(Player *player){
        int choice = Humanchoose1(player);
        Scene4(player,choice);
    }

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
        int answer;
        while(answer < 1 || answer > 2){
            cout << "Enter number between 1 and 2\n";
            answer = getValidation();

            if(answer == 1){
                cout << "Correct answer.\n";
                return true;
            }
            cout << "Wrong answer.\n";
            return false;
        }
    }
    int ElfChoose1(Player *player){
        int x;
        bool run = true;
        cout << "\nTwo groups live near your forests.\n";
        cout << "Beastfolk tribes roam the wild lands.\n";
        cout << "Forest spirits guard ancient places.\n\n";
        while(run){
            cout<<"Who will you approach?\n";
            cout<<"1 Beastfolk\n";
            cout<<"2 Spirits\n";
            cout<<"3 Kingdom Stats\n";
            cout<<"Enter your choice: ";
            x = getValidation();
            if(x == 3){
                player->showStats();
                continue;
            }
            if(x == 1 || x == 2){
                run = false;
            }
            else{
                cout<<"Enter number between 1 and 3\n";
            }
        }
        return x;
    }
    void SceneElf4(Player *player, int choice, bool tree){


        Kingdom beastfolk("Beastfolk",19000,17000,20000);
        Kingdom spirits("Spirits",5000,10000,15000);

        if(choice == 1){
            cout<<"Scouts reported about Beastfolk:\n";
            cout<<"Warriors: "<<beastfolk.warriors1()<<endl;
            cout<<"Power: "<<beastfolk.min_power1()<<"-"<<beastfolk.max_power1()<<endl;
            bool running = true;
            while(running){
                int decision = chooseAction(player);
                if(decision == 1){
                    bool win = beastfolk.battle(player, beastfolk);
                    if(win){

                        running = false;
                    }
                    else{
                        cout<<"Your army retreats and regroups...\n";
                    }
                }
                else if(decision == 2){
                    bool solved = puzzleBeastfolkRiddle();
                    if(solved){
                        cout<<"The Beastfolk agree to join your cause.\n";
                        running = false;
                    }
                    else{
                        cout<<"Negotiations fail.\n";
                        bool win = beastfolk.battle(player, beastfolk);
                        if(win){
                            running = false;
                        }
                        else{
                            cout<<"Your army retreats and regroups...\n";
                        }
                    }
                }
            }
        }
        else if(choice == 2){
            cout<<"You approach the forest spirits.\n";
            bool running = true;
            while(running){
                int decision = chooseAction(player);
                if(decision == 1){
                    cout<<"The spirits are weak and quickly defeated.\n";
                    cout<<"Their defeat brings no benefit.\n";
                    running = false;
                }
                else if(decision == 2){
                    if(tree){
                        cout<<"The spirits recognise your wisdom and immediately join you.\n";
                    }
                    else{
                        cout<<"The spirits cautiously agree to cooperate.\n";
                    }
                    running = false;
                }
            }
        }
    }
    void elfStory(Player *player) {
        bool tree = elfPuzzleTree();
        int choice = ElfChoose1(player);
        SceneElf4(player, choice, tree);
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
        Player player("","",0,0,0,3,0);
        string inputName;
        cout<<"Enter your name: ";
        getline(cin,inputName);
        player.set_name(inputName);
        cout << "\nWelcome, ruler " << player.name() << "!\n\n";

        showLore();

        player.chooseRace();

        balance(&player,humans, elves, dwarves);
        Scenes scene;
        scene.introRiddle(&player);
        if(player.race() == "Humans"){
            scene.humanStory(&player);
        }
        else if(player.race() == "Elves"){
            scene.elfStory(&player);
        }
        return 0;
    }
