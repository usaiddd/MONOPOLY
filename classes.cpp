#include <iostream>
#include<string.h>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<conio.h>

using namespace std;

class Player;
class Property;
class Tile;
class Asset;
class Rule;
class GameController{
public:
    static vector<Rule*> currentRules;
    static int playerIndx;
    static Player *currentPlayer;
    static vector <Rule*> rules;
    static vector<Player*> players;
    static vector <Tile*> board;
    static vector<string> get_rule_txt();
    static int show_diceroll();
    static void next_turn();
    static void Apply_rule(int ruleIndex);
    static void show_rules(vector<string> ruleTxts);
    static bool end_game();
    static void showBoard();
    ~GameController(){}
};

class Rule{
public:
    virtual void apply_rule(){}
    virtual string getTitle()=0;
    ~Rule(){}
};
class Skip:public Rule{
public:
    void apply_rule(){}
    string getTitle();
    ~Skip(){};
};
class Buy:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~Buy(){}
};
class Rent:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~Rent(){}
};

class GeneralRule:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~GeneralRule(){}
};

class community1:public Rule{
    public:
        void apply_rule();
        string getTitle();
        ~community1(){}
    };

class community2:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~community2(){}
};


class community3:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~community3(){}
};

class community4:public Rule{
public:
     void apply_rule();
    string getTitle();
    ~community4(){}
};

class community5:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~community5(){}
};

class chance1:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~chance1(){}
};

class chance2:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~chance2(){}
};

class chance3:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~chance3(){}
};

class chance4:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~chance4(){}
};

class chance5:public Rule{
public:
    void apply_rule();
    string getTitle();
    ~chance5(){}
};

class JailRule:public Rule{
private:
    static int turns;
    static int no_of_players;
    vector<Player*>players ;
public:
    void apply_rule();
    bool check_jail();
    string getTitle();
    ~JailRule(){}
};

class Player{
private:
    string name;
    int balance;
    vector<Asset*>owned;
    int index;
    int in_jail_chances=0;
    
public:
    Player(string name){
        this -> name=name;
        balance=1500;
        index=0;
    }
    vector<Asset*> Owned();
    int getBalance();
    void pushProperty(Asset * owns);
    bool checkbankcorrupcy ();
    void jail_update();
    bool jail_status();
    void change_balance(int sum);
    void edit_index(int i);
    int change_index(int i);
    string get_name();
    int get_index();
    ~Player(){}
};

class Tile{
public:
    virtual vector<Rule*> get_rules()=0;
    ~Tile(){}
};
class Asset : public Tile{
public:
    virtual void has_baught()=0;
    virtual int get_price()=0;
    virtual int get_rent()=0;
    ~Asset(){}
};
class Event : public Tile{
};
class CommunityChest:public Event{
private:
    string name;
    int price;
public:
    CommunityChest(string name){
        this->name=name;
    }
    vector<Rule*> get_rules();
    ~CommunityChest(){}
};

class Chance:public Event{
private:
    string name;
    int price;
public:
    Chance(string name){
        this->name=name;
    }
    vector<Rule*> get_rules();
    ~Chance(){}
};

class JailEvent: public Event {
    private:
        string name;
    public:
    JailEvent(string name){
        this->name=name;
    }
    vector<Rule*> get_rules();
    ~JailEvent(){}
};

class TaxEvent: public Event {
private:
    string name;
    int tax;
public:
    TaxEvent(string name,int tax){
        this->tax=tax;
        this->name=name;
    }
    int get_tax();
    vector<Rule*> get_rules();
    ~TaxEvent(){}
};

class Property : public Asset{
private:
    int price;
    int rent;
    string name;
    bool owned;
    Buy buy;
    Player *owner=GameController::players[4];
public:
    Property(string name,int price,int rent){
        this -> price=price;
        this -> rent=rent;
        this -> name=name;
        owned=false;
    }
    void has_baught();
    vector<Rule*> get_rules();
    int get_rent();
    void assignOwner(Player *player);
    int get_price();
    ~Property(){}
};

class Commodity : public Asset{
private:
    int price;
    string name;
    bool owned=false;
    Player *owner = GameController::players[4];
    int rent;
public:
    Commodity(string name,int price){
        this -> price=price;
        this -> name=name;
    }
    void has_baught();
    vector<Rule*> get_rules();
    int get_price();
    void assignOwner(Player *player);
    int get_rent();
    ~Commodity(){}
};

int main()
{
    srand(time(0));
    GameController::showBoard();
}

string Skip::getTitle(){
    return "skip";
}

void Buy::apply_rule(){
    Player *player= GameController::currentPlayer;
    Asset *currentAsset = dynamic_cast<Asset*>(GameController::board[GameController::currentPlayer->get_index()]);
    currentAsset->has_baught();
    player->pushProperty(currentAsset);
    int price = currentAsset->get_price();
    player->change_balance(-price);
}
string Buy::getTitle(){
    return "buy property";
}

void Rent::apply_rule(){
    Player* player = GameController::currentPlayer;
    Tile* tile = GameController::board[player->get_index()];
    Asset* currentAsset = dynamic_cast<Asset*>(tile);
        int rent = currentAsset->get_rent();
        player->change_balance(-rent); // Deduct rent
        // Pay rent to owner if applicable
}
string Rent::getTitle(){
    return "";
}

void GeneralRule::apply_rule(){
    Player* player = GameController::currentPlayer;
    Tile* tile = GameController::board[player->get_index()];
    TaxEvent* currentAsset = dynamic_cast<TaxEvent*>(tile);
    int tax = currentAsset->get_tax();
    player->change_balance(tax);
}
string GeneralRule::getTitle(){
    return "";
}
void community1::apply_rule(){
    Player*player=GameController::currentPlayer;
    player->edit_index(0);
    player->change_balance(200);
}
string community1::getTitle(){
    return " Advance to Go. (Collect $200) ";
}
void community2::apply_rule(){
    Player*player=GameController::currentPlayer;
    player->change_balance(200);
}
string community2::getTitle(){
    return " Bank error in your favor. (Collect $200) ";
}
void community3::apply_rule(){
    Player*player=GameController::currentPlayer;
    player->change_balance(-50);
}
string community3::getTitle(){
    return " Doctor's fees. {fee} Pay $50 ";
}
void community4::apply_rule(){
    Player* player=GameController::currentPlayer;
    player->change_balance(50);
}
string community4::getTitle(){
    return " From sale of stock you get $50. ";
}

void community5::apply_rule(){
    Player* player=GameController::currentPlayer;
    player->change_balance(100);
}
string community5::getTitle(){
    return " Life insurance matures , Collect $100  ";
}
void chance1::apply_rule(){
    Player* player=GameController::currentPlayer;
    player->edit_index(10);
    player->change_balance(0);
}
string chance1::getTitle(){
    return" Go to Jail. Go directly to Jail. Do not pass GO, do not collect $200. ";
}
void chance2::apply_rule(){
    Player* player=GameController::currentPlayer;
    player->change_balance(-15);
}
string chance2::getTitle(){
    return " Pay Poor Tax of $15 ";
}
void chance3::apply_rule(){
    Player* player=GameController::currentPlayer;
    player->change_balance(-20);
}
string chance3::getTitle(){
    return " “Drunk in charge” fine $20 ";
}
void chance4::apply_rule(){
    Player* player=GameController::currentPlayer;
    player->change_balance(-150);
}
string chance4::getTitle(){
    return " Pay school tax of $150 ";
}
void chance5::apply_rule(){
    Player* player=GameController::currentPlayer;
    player->change_balance(100);
}
string chance5::getTitle(){
    return " our Xmas fund matures. Collect $100 ";
}
void JailRule::apply_rule(){
}
string JailRule::getTitle(){
    return "YOU HAVE BEEN ARRESTED!!!(you can't move for next 2 turns TTwTT)";
}
bool JailRule::check_jail(){
    GameController::currentPlayer->jail_update();
    if(GameController::currentPlayer->jail_status()==0){
        return false;
    }
    return true;
}
int JailRule::turns=0;
int Player::getBalance(){
    return balance;
}
vector<Asset*> Player::Owned(){
    return owned;
}
void Player::pushProperty(Asset*owns){
    owned.push_back(owns);
}
bool Player::checkbankcorrupcy (){
    if(balance<=0){
        return true;
    }
    return false;
}
void Player::jail_update(){
    in_jail_chances+=1;
    if(in_jail_chances==3){
        in_jail_chances=0;
    } 
}
bool Player::jail_status(){
    if(in_jail_chances>0){
        jail_update();
        return true;
    }
    return false;
}
void Player::change_balance(int sum){
    balance+=(sum/2);
}
void Player::edit_index(int i){
    index=i;
}
int Player::change_index(int i){
    index+=i;
    return index;
}
string Player::get_name(){
    return name;
}
int Player::get_index(){
    return index;
}
vector<Rule*> CommunityChest::get_rules(){
    
    int random=3+rand()%5;
    vector<Rule*> rules={GameController::rules[random]};
    return rules;
}

vector<Rule*> Chance::get_rules(){
    
    int random=8+rand()%5;
    vector<Rule*> rules={GameController::rules[random]};
    return rules;
}
vector<Rule*>JailEvent::get_rules(){
    vector<Rule*> rules={GameController::rules[13]};
    return rules;
}
int TaxEvent::get_tax(){
    return tax;
}
vector<Rule*>  TaxEvent::get_rules(){
    vector<Rule*> rules={GameController::rules[14]};
    return rules;
}
void Property::has_baught(){
    owned=true;
}
vector<Rule*> Property::get_rules(){
    Player *player = GameController::currentPlayer;
    if(owned){
        if(player->get_name()==owner->get_name()){
            vector<Rule*> rules={GameController::rules[0]};
            return rules;
        }
        else{
            player->change_balance(rent);
            for(Player*plyr:GameController::players){
                if(plyr->get_name()==owner->get_name()){
                    plyr->change_balance(rent);
                }
            }
            vector<Rule*> rules={GameController::rules[2]};
            return rules;
        }
    }
    else{
        vector<Rule*>Rules={GameController::rules[0],GameController::rules[1]} ;
        owned=true;
        return Rules;
    }
}
int Property::get_rent(){
    return rent;
}
void Property::assignOwner(Player *player){
    owner = player;
    owned=true;
}
int Property::get_price(){
    return price;
}
vector<Rule*> Commodity::get_rules(){
    Player *player = GameController::currentPlayer;
    if(owned){
        if(player->get_name()== owner->get_name()){
            vector<Rule*>Rules={GameController::rules[0]};
            return Rules;
        }
        else{
            int roll1=1+rand()%6;
            int roll2=1+rand()%6;
            rent=roll1+roll2;
            player->change_balance(-rent);
            for(Player*plyr:GameController::players){
                if(plyr->get_name()==owner->get_name()){
                    plyr->change_balance(rent);
                }
            }
            vector<Rule*>rules={GameController::rules[2]};
            return rules;
        }
    }
    else{
        vector<Rule*>rules;
        rules.push_back(GameController::rules[0]);
        rules.push_back(GameController::rules[1]);
        owned=true;
        return rules;
    }
}
void Commodity::has_baught(){
    owned=true;
}
int Commodity::get_price(){
    return price;
}
void Commodity::assignOwner(Player *player){
    owner = player;
    owned=true;
}
int Commodity::get_rent(){
    return rent;
}
int GameController::playerIndx=0;
Player* GameController::currentPlayer=new Player("green");
vector<Rule*> GameController::currentRules = {};
vector<Rule*> GameController::rules={
    new Skip,
    new Buy,
    new Rent,
    new chance1,
    new chance2,
    new chance3,
    new chance4,
    new chance5,
    new community1,
    new community2,
    new community3,
    new community4,
    new community5,
    new JailRule,
    new GeneralRule
};
vector<Player*> GameController::players ={
    new Player("red"),
    new Player("green"),
    new Player("blue"),
    new Player("yellow"),
    new Player("grey")
};

vector <Tile*> GameController::board={
    new TaxEvent("GO",150),
    new Property("Mediterranean Avenue", 60, -2),
    new CommunityChest("Community Chest"),
    new Property("Baltic Avenue", 60, -4),
    new TaxEvent("Income Tax", -100),
    new Commodity("Reading Railroad", 200),
    new Property("Oriental Avenue", 100, -6),
    new Chance("Chance"),
    new Property("Vermont Avenue", 100, -6),
    new Property("Connecticut Avenue", 120, -8),
    new JailEvent("Jail (Just Visiting)"),
    new Property("St. Charles Place", 140, -10),
    new Commodity("Electric Company", 150),
    new Property("States Avenue", 140, -10),
    new Property("Virginia Avenue", 160, -12),
    new Commodity("Pennsylvania Railroad", 200),
    new Property("St. James Place", 180, -14),
    new CommunityChest("Community Chest"),
    new Property("Tennessee Avenue", 180, -14),
    new Property("New York Avenue", 200, -16),
    new TaxEvent("Free Parking",0),
    new Property("Kentucky Avenue",220, -18),
    new Chance("Chance"),
    new Property("Indiana Avenue", 220, -18),
    new Property("Illinois Avenue",240, -20),
    new Commodity("B&O Railroad", 200),
    new Property("Atlantic Avenue", 260, -22),
    new Property("Ventnor Avenue", 260, -22),
    new Commodity("Water Works", 150),
    new Property("Marvin Gardens", 280, -24),
    new JailEvent("Go to Jail"),
    new Property("Pacific Avenue", 300, -26),
    new Property("North Carolina Avenue", 300, -26),
    new CommunityChest("Community Chest"),
    new Property("Pennsylvania Avenue", 320, -28),
    new Commodity("Short Line Railroad", 200),
    new Chance("Chance"),
    new Property("Park Place", 350, -35),
    new TaxEvent("Luxury Tax", -100),
    new Property("Boardwalk", 400, -50)
};

vector<string> GameController::get_rule_txt(){
    vector<string> ruleTxts;
    Tile *tile = GameController::board[GameController::currentPlayer->get_index()];
    vector<Rule*>rules=tile->get_rules();
    currentRules=rules;
    for(Rule *rule : rules){
        ruleTxts.push_back(rule->getTitle());
    }
    return ruleTxts;
}


int GameController::show_diceroll(){
    int roll1=1+rand()%6;
    int roll2=1+rand()%6;
    cout<<roll1+roll2<<endl;
    return roll1+roll2;
}

void GameController::next_turn(){
    currentPlayer = players.at(playerIndx);
    while(currentPlayer->checkbankcorrupcy() || currentPlayer->jail_status()){
        playerIndx+=1;
        currentPlayer=players.at(playerIndx);
    }
    int playerBoardIdx = show_diceroll();
    int newIndex = (currentPlayer->get_index() + playerBoardIdx) % GameController::board.size();
    currentPlayer->edit_index(newIndex);
    vector<string> strArr = get_rule_txt();
    show_rules(strArr);
}

void GameController::Apply_rule(int ruleIndex){
    currentRules[ruleIndex]->apply_rule();
}
void GameController::show_rules(vector<string> ruleTxts){
    for (string rule : ruleTxts) {
        cout << "rule : " << rule<<endl;
    }
    Apply_rule(0);
}
bool GameController::end_game(){
    if((players[0]->checkbankcorrupcy() && players[1]->checkbankcorrupcy() && players[2]->checkbankcorrupcy())||(players[0]->checkbankcorrupcy() && players[1]->checkbankcorrupcy() && players[3]->checkbankcorrupcy())||(players[0]->checkbankcorrupcy() && players[2]->checkbankcorrupcy() && players[3]->checkbankcorrupcy())||(players[1]->checkbankcorrupcy() && players[2]->checkbankcorrupcy() && players[3]->checkbankcorrupcy())){
        return true;
    }
    return false;
}
void GameController::showBoard() {
    cout<<"board has been initialised"<<endl;
    for(int i=0;i<6;i++){
        
        GameController::next_turn();
        if(currentRules.size()==1){
            Apply_rule(0);
        }
        else{
            Apply_rule(1);
        }
        currentRules.clear();
        GameController::playerIndx = (GameController::playerIndx + 1) % ((GameController::players.size())-1);
        cout<<"balance :"<<currentPlayer->getBalance()<<endl;
        cout<<currentPlayer->get_name()<<endl;
    }
    while(currentPlayer->checkbankcorrupcy()){
        playerIndx+=1;
        currentPlayer=players.at(playerIndx);
    }
    int total=0;
    for(Asset *tile : currentPlayer->Owned()){
        total+=tile->get_price();
    }
    total+=currentPlayer->getBalance();
    cout<<"jeet gaya "<<currentPlayer->get_name()<<" bkc yayayayayayay "<<"with the assets of : "<<total;
}

