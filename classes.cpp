#include <iostream>
#include<string.h>
#include<vector>
using namespace std;
class player{
    private:
        string name;
        int balance;
        vector<tile*>owned;
    public:
        player(string name){
            this -> name=name;
            balance=1500;
        }
};
class tile{
public:
    virtual void rules()=0;
};
class assets : public tile{
};
class executables : public tile{
};
class property : public assets{
private:
    int price;
    int rent;
    string color;
    bool owned;
    string owner;
public:
    property(int price,int rent,string color){
        this -> price=price;
        this -> rent=rent;
        this -> color=color;
        owned=false;
    }
    void rules(){
    }
};
class commodity : public assets{
private:
    int price;
    int mortgage;
public:
    commodity(int price,int mortgage){
        this -> price=price;
        this -> mortgage=mortgage;
    }
    void rules(){
    }
};
class go : public executables{
    public:
        void rules(player const &player1){
        }
};
class rent : public executables{
    public:
        void rules(player const &player1,player const &player2){
        }
};
class chance_1 : public executables{
    public:
        void rules(player const &player1){
        }
};
class chance_2 : public executables{
    public:
        void rules(player const &player1){
        }
};
class chance_3 : public executables{
    public:
        void rules(player const &player1){
        }
};
class chance_4 : public executables{
    public:
        void rules(player const &player1){
        }
};
class chance_5 : public executables{
    public:
        void rules(player const &player1){
        }
};
class community_1 : public executables{
    public:
        void rules(player const &player1){
        }
};
class community_2 : public executables{
    public:
        void rules(player const &player1){
        }
};
class community_3 : public executables{
    public:
        void rules(player const &player1){
        }
};
class community_4 : public executables{
    public:
        void rules(player const &player1){
        }
};
class community_5 : public executables{
    public:
        void rules(player const &player1){
        }
};
class income_tax : public executables{
    public:
        void rules(player const &player1){
        }
};
class luxury_tax : public executables{
    public:
        void rules(player const &player1){
        }
};
class free_parking : public executables{
    public:
        void rules(player const &player1){
        }
};
class jail : public executables{
    public:
        void rules(player const &player1){
        }
};
class go_to_jail : public executables{
    public:
        void rules(player const &player1){
        }
};
class controller{
private: 
    property mediterranean_avenue(60, 2, "Brown");
    property baltic_avenue(60, 4, "Brown");
    property oriental_avenue(100, 6, "Light_Blue");
    property vermont_avenue(100, 6, "Light_Blue");
    property connecticut_avenue(120, 8, "Light_Blue");
    property st_charles_place(140, 10, "Pink");
    property states_avenue(140, 10, "Pink");
    property virginia_avenue(160, 12, "Pink");
    property st_james_place(180, 14, "Orange");
    property tennessee_avenue(180, 14, "Orange");
    property new_york_avenue(200, 16, "Orange");
    property kentucky_avenue(220, 18, "Red");
    property indiana_avenue(220, 18, "Red");
    property illinois_avenue(240, 20, "Red");
    property atlantic_avenue(260, 22, "Yellow");
    property ventnor_avenue(260, 22, "Yellow");
    property marvin_gardens(280, 24, "Yellow");
    property pacific_avenue(300, 26, "Green");
    property north_carolina_avenue(300, 26, "Green");
    property pennsylvania_avenue(320, 28, "Green");
    property park_place(350, 35, "Blue");
    property boardwalk(400, 50, "Blue");

    income_tax incometax;
    commodity reading_railroad(200, 25);
    commodity electric_company(150, 75);
    commodity pennsylvania_railroad(200, 25);
    commodity b_and_o_railroad(200, 25);
    commodity water_works(150, 75);
    commodity short_line_railroad(200, 25);
    luxury_tax luxurytax;

    go go;
    community_1 community_chest_1;
    community_2 community_chest_2;
    community_3 community_chest_3;
    community_4 community_chest_4;
    community_5 community_chest_5;
    jail jail;
    free_parking free_parking;
    chance_1 chance1;
    chance_2 chance2;
    chance_3 chance3;
    chance_4 chance4;
    chance_5 chance5;
    go_to_jail go_to_jail;

    player player1("red");
    player player2("blue");
    player player3("green");
    player player4("yellow");

    vector <tile*> board = {
        &go, &mediterranean_avenue, &community_chest_1, &baltic_avenue, &incometax,
        &reading_railroad, &oriental_avenue, &chance1, &vermont_avenue, &connecticut_avenue,
        &jail, &st_charles_place, &electric_company, &states_avenue, &virginia_avenue,
        &pennsylvania_railroad, &st_james_place, &community_chest_2, &tennessee_avenue, &new_york_avenue,
        &free_parking, &kentucky_avenue, &chance2, &indiana_avenue, &illinois_avenue,
        &b_and_o_railroad, &atlantic_avenue, &ventnor_avenue, &water_works, &marvin_gardens,
        &go_to_jail, &pacific_avenue, &north_carolina_avenue, &community_chest_3, &pennsylvania_avenue,
        &short_line_railroad, &chance3, &park_place, &luxurytax, &boardwalk
    };
};