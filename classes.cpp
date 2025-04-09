#include <iostream>
#include<string.h>
#include<vector>
using namespace std;
class Player{
    private:
        string name;
        int balance;
        vector<tile*>owned;
    public:
        Player(string name){
            this -> name=name;
            balance=1500;
        }
};
class tile{
public:
    virtual void rules()=0;
};
class Assets : public tile{
};
class Events : public tile{
public:
    Events()
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
};

class controller{
private: 
    Player player1("red");
    Player player2("blue");
    Player player3("green");
    Player player4("yellow");

    vector <tile*> board = {
        new Chance("GO"),
        new Property("Mediterranean Avenue", 60, 2),
        new CommunityChest("Community Chest"),
        new Property("Baltic Avenue", 60, 4),
        new Commodity("Income Tax", 200, 0),
        new Commodity("Reading Railroad", 200, 25),
        new Property("Oriental Avenue", 100, 6),
        new Chance("Chance"),
        new Property("Vermont Avenue", 100, 6),
        new Property("Connecticut Avenue", 120, 8),
        new Chance("Jail (Just Visiting)"),
        new Property("St. Charles Place", 140, 10),
        new Commodity("Electric Company", 150, 0),
        new Property("States Avenue", 140, 10),
        new Property("Virginia Avenue", 160, 12),
        new Commodity("Pennsylvania Railroad", 200, 25),
        new Property("St. James Place", 180, 14),
        new CommunityChest("Community Chest"),
        new Property("Tennessee Avenue", 180, 14),
        new Property("New York Avenue", 200, 16),
        new Chance("Free Parking"),
        new Property("Kentucky Avenue",220, 18),
        new Chance("Chance"),
        new Property("Indiana Avenue", 220, 18),
        new Property("Illinois Avenue",240, 20),
        new Commodity("B&O Railroad", 200, 25),
        new Property("Atlantic Avenue", 260, 22),
        new Property("Ventnor Avenue", 260, 22),
        new Commodity("Water Works", 150, 0),
        new Property("Marvin Gardens", 280, 24),
        new Chance("Go to Jail"),
        new Property("Pacific Avenue", 300, 26),
        new Property("North Carolina Avenue", 300, 26),
        new CommunityChest("Community Chest"),
        new Property("Pennsylvania Avenue", 320, 28),
        new Commodity("Short Line Railroad", 200, 25),
        new Chance("Chance"),
        new Property("Park Place", 350, 35),
        new Commodity("Luxury Tax", 100, 0),
        new Property("Boardwalk", 400, 50)
    };
};