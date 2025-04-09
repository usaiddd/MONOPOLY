#include <iostream>
#include<string.h>
#include<vector>
using namespace std;

class Player{};
class Rules{
public:
    virtual void apply_rule()=0;
};
class General_Rule:public Rules{
private:
    int sum;
public:
    void apply_rule(int sum,Player &player){
        player.change_balance(sum);
    }
};
class community1:public Rules{
public:
    void apply_rule(Player &player){
        cout<<" Advance to Go. (Collect $200) ";
        player.change_index(0);
        player.change_balance(200);
    }
};
class community2:public Rules{
public:
    void apply_rule(Player &player){
        cout<<" Bank error in your favor. (Collect $200) ";
        player.change_balance(200);
    }
};
class community3:public Rules{
public:
    void apply_rule(Player &player){
        cout<<" Doctor's fees. {fee} Pay $50 ";
        player.change_balance(-50);
    }
};
class community4:public Rules{
public:
     void apply_rule(Player &player){
        cout<<" From sale of stock you get $50. ";
        player.change_balance(50);
    }
};
class community5:public Rules{
public:
    void apply_rule(Player &player){
        cout<<" Life insurance matures , Collect $100  ";
        player.change_balance(100);
    }
};
class chance1:public Rules{
public:
    void apply_rule(Player &player){
        cout<<" Go to Jail. Go directly to Jail. Do not pass GO, do not collect $200. ";
        player.change_index(10);
        player.change_balance(0);
    }
};
class chance2:public Rules{
public:
    void apply_rule(Player &player){
        cout<<" Pay Poor Tax of $15 ";
        player.change_balance(-15);
    }
};
class chance3:public Rules{
public:
    void apply_rule(Player &player){
        cout<<" “Drunk in charge” fine $20 ";
        player.change_balance(-20);
    }
};
class chance4:public Rules{
public:
    void apply_rule(Player &player){
        cout<<" Pay school tax of $150 ";
        player.change_balance(-150);
    }
};
class chance5:public Rules{
public:
    void apply_rule(Player &player){
        cout<<" our Xmas fund matures. Collect $100 ";
        player.change_balance(100);
    }
};
class Player{
private:
    string name;
    int balance;
    vector<tile*>owned;
    int index;
public:
    Player(string name){
        this -> name=name;
        balance=1500;
        index=0;
    }
    void change_balance(int sum){
        balance+=sum;
    }
    void change_index(int i){
        index=i;
    }
};
class tile{
public:
    virtual void rules()=0;
};
class Assets : public tile{
};
class Events : public tile{
private:
    string name;
    int sum;
public:
    Events(string name,int sum){
        this ->name=name;
        this ->sum=sum;
    }
    void rules(){
        if (sum==1){

        }
        else if (sum==2){

        }
        else{

        }
    }
};
class Property : public Assets{
private:
    int price;
    int rent;
    string name;
    bool owned;
    string owner;
public:
    Property(string name,int price,int rent){
        this -> price=price;
        this -> rent=rent;
        this -> name=name;
        owned=false;
    }
    void rules(){
    }
    int tell_rent(){
        return rent;
    }
};
class Commodity : public Assets{
private:
    int price;
    string name;
    bool owned;
    string owner;
public:
    Commodity(string name,int price){
        this -> price=price;
        this -> name=name;
    }
    void rules(){
    }
    int tell_rent(){
    }
};

class controller{
private: 
    Player player1("red");
    Player player2("blue");
    Player player3("green");
    Player player4("yellow");

    vector <tile*> board = {
        new Events("GO",150),
        new Property("Mediterranean Avenue", 60, -2),
        new Events("Community Chest",1),
        new Property("Baltic Avenue", 60, -4),
        new Events("Income Tax", -200),
        new Commodity("Reading Railroad", 200),
        new Property("Oriental Avenue", 100, -6),
        new Events("Chance",1),
        new Property("Vermont Avenue", 100, -6),
        new Property("Connecticut Avenue", 120, -8),
        new Events("Jail (Just Visiting)",2),
        new Property("St. Charles Place", 140, -10),
        new Commodity("Electric Company", 150),
        new Property("States Avenue", 140, -10),
        new Property("Virginia Avenue", 160, -12),
        new Commodity("Pennsylvania Railroad", 200),
        new Property("St. James Place", 180, -14),
        new Events("Community Chest",1),
        new Property("Tennessee Avenue", 180, -14),
        new Property("New York Avenue", 200, -16),
        new Events("Free Parking",0),
        new Property("Kentucky Avenue",220, -18),
        new Events("Chance",1),
        new Property("Indiana Avenue", 220, -18),
        new Property("Illinois Avenue",240, -20),
        new Commodity("B&O Railroad", 200),
        new Property("Atlantic Avenue", 260, -22),
        new Property("Ventnor Avenue", 260, -22),
        new Commodity("Water Works", 150),
        new Property("Marvin Gardens", 280, -24),
        new Events("Go to Jail",2),
        new Property("Pacific Avenue", 300, -26),
        new Property("North Carolina Avenue", 300, -26),
        new Events("Community Chest",1),
        new Property("Pennsylvania Avenue", 320, -28),
        new Commodity("Short Line Railroad", 200),
        new Events("Chance",1),
        new Property("Park Place", 350, -35),
        new Events("Luxury Tax", -100),
        new Property("Boardwalk", 400, -50)
    };
};