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
};
class Property : public Assets{
private:
    int price;
    int rent;
    string color;
    bool owned;
    string owner;
public:
    Property(int price,int rent,string color){
        this -> price=price;
        this -> rent=rent;
        this -> color=color;
        owned=false;
    }
    void rules(){
    }
};
class Commodity : public Assets{
private:
    int price;
    int mortgage;
public:
    Commodity(int price,int mortgage){
        this -> price=price;
        this -> mortgage=mortgage;
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
        new Property("Mediterranean Avenue", "Brown", 60, 2),
        new CommunityChest("Community Chest"),
        new Property("Baltic Avenue", "Brown", 60, 4),
        new Commodity("Income Tax", "Tax", 200, 0),
        new Commodity("Reading Railroad", "Railroad", 200, 25),
        new Property("Oriental Avenue", "Light Blue", 100, 6),
        new Chance("Chance"),
        new Property("Vermont Avenue", "Light Blue", 100, 6),
        new Property("Connecticut Avenue", "Light Blue", 120, 8),
        new Chance("Jail (Just Visiting)"),
        new Property("St. Charles Place", "Pink", 140, 10),
        new Commodity("Electric Company", "Utility", 150, 0),
        new Property("States Avenue", "Pink", 140, 10),
        new Property("Virginia Avenue", "Pink", 160, 12),
        new Commodity("Pennsylvania Railroad", "Railroad", 200, 25),
        new Property("St. James Place", "Orange", 180, 14),
        new CommunityChest("Community Chest"),
        new Property("Tennessee Avenue", "Orange", 180, 14),
        new Property("New York Avenue", "Orange", 200, 16),
        new Chance("Free Parking"),
        new Property("Kentucky Avenue", "Red", 220, 18),
        new Chance("Chance"),
        new Property("Indiana Avenue", "Red", 220, 18),
        new Property("Illinois Avenue", "Red", 240, 20),
        new Commodity("B&O Railroad", "Railroad", 200, 25),
        new Property("Atlantic Avenue", "Yellow", 260, 22),
        new Property("Ventnor Avenue", "Yellow", 260, 22),
        new Commodity("Water Works", "Utility", 150, 0),
        new Property("Marvin Gardens", "Yellow", 280, 24),
        new Chance("Go to Jail"),
        new Property("Pacific Avenue", "Green", 300, 26),
        new Property("North Carolina Avenue", "Green", 300, 26),
        new CommunityChest("Community Chest"),
        new Property("Pennsylvania Avenue", "Green", 320, 28),
        new Commodity("Short Line Railroad", "Railroad", 200, 25),
        new Chance("Chance"),
        new Property("Park Place", "Blue", 350, 35),
        new Commodity("Luxury Tax", "Tax", 100, 0),
        new Property("Boardwalk", "Blue", 400, 50)
    };
};