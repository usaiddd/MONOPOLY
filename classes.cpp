#include <iostream>
using namespace std;

class controller{
private: 
    Property mediterranean_avenue(60, 2, "Brown");
    Property baltic_avenue(60, 4, "Brown");
    Property oriental_avenue(100, 6, "Light_Blue");
    Property vermont_avenue(100, 6, "Light_Blue");
    Property connecticut_avenue(120, 8, "Light_Blue");
    Property st_charles_place(140, 10, "Pink");
    Property states_avenue(140, 10, "Pink");
    Property virginia_avenue(160, 12, "Pink");
    Property st_james_place(180, 14, "Orange");
    Property tennessee_avenue(180, 14, "Orange");
    Property new_york_avenue(200, 16, "Orange");
    Property kentucky_avenue(220, 18, "Red");
    Property indiana_avenue(220, 18, "Red");
    Property illinois_avenue(240, 20, "Red");
    Property atlantic_avenue(260, 22, "Yellow");
    Property ventnor_avenue(260, 22, "Yellow");
    Property marvin_gardens(280, 24, "Yellow");
    Property pacific_avenue(300, 26, "Green");
    Property north_carolina_avenue(300, 26, "Green");
    Property pennsylvania_avenue(320, 28, "Green");
    Property park_place(350, 35, "Blue");
    Property boardwalk(400, 50, "Blue");

    Commodity income_tax(200, 0, "None");
    Commodity reading_railroad(200, 25, "Railroad");
    Commodity electric_company(150, 75, "Utility");
    Commodity pennsylvania_railroad(200, 25, "Railroad");
    Commodity b_and_o_railroad(200, 25, "Railroad");
    Commodity water_works(150, 75, "Utility");
    Commodity short_line_railroad(200, 25, "Railroad");
    Commodity luxury_tax(100, 0, "None");

    Chance go;
    CommunityChest community_chest_1;
    Chance chance_1;
    Chance jail;
    CommunityChest community_chest_2;
    Chance free_parking;
    Chance chance_2;
    Chance go_to_jail;
    CommunityChest community_chest_3;
    Chance chance_3;

    vector<Tile*> board = {
        &go, &mediterranean_avenue, &community_chest_1, &baltic_avenue, &income_tax,
        &reading_railroad, &oriental_avenue, &chance_1, &vermont_avenue, &connecticut_avenue,
        &jail, &st_charles_place, &electric_company, &states_avenue, &virginia_avenue,
        &pennsylvania_railroad, &st_james_place, &community_chest_2, &tennessee_avenue, &new_york_avenue,
        &free_parking, &kentucky_avenue, &chance_2, &indiana_avenue, &illinois_avenue,
        &b_and_o_railroad, &atlantic_avenue, &ventnor_avenue, &water_works, &marvin_gardens,
        &go_to_jail, &pacific_avenue, &north_carolina_avenue, &community_chest_3, &pennsylvania_avenue,
        &short_line_railroad, &chance_3, &park_place, &luxury_tax, &boardwalk
    };
};