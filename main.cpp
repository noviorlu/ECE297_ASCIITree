#include <iostream>


#include "ASCIINode.hpp"

using namespace std;

int main() {
    ACSIINode search_street_name_db = {};
    search_street_name_db.insertStreetName("Bay St", 0);
    search_street_name_db.insertStreetName("Bloor St W", 1);
    search_street_name_db.insertStreetName("Bloor St E", 2);
    search_street_name_db.insertStreetName("Yonge St", 3);

    std::cout<<search_street_name_db.getPrefixId("B").size()<<std::endl;

    return 0;
}
