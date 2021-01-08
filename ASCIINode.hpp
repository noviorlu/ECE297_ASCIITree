//
// Created by ychen on 2021/1/7.
//

#ifndef NEWTEST_ASCIINODE_HPP
#define NEWTEST_ASCIINODE_HPP

#include <iostream>
#include <vector>

using namespace std;
struct ACSIINode {
    //save all possible id in current treeNode
    vector<int> id_pool;

    //correspond to 256 char in ASCII table
    ACSIINode* next_char[256];

    //insert streetName into tree by char, save streetId into vector in Node
    void insertStreetName(const string& street_name, const int& street_id);

    //return all street_id saved in vector
    vector<int> getPrefixId(const string& prefix);

    // free the current node's children and itself
    void clear();

};


#endif //NEWTEST_ASCIINODE_HPP
