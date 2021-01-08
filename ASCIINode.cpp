//
// Created by ychen on 2021/1/7.
//

#include "ASCIINode.hpp"


void ACSIINode::insertStreetName(const string& streetName, const int& street_id) {
    //special case when streetName is empty,insertNothing
    if (0 == streetName.length()) {
        return;
    }

    ACSIINode* cptr = this; //define a current layer ASCIINode pointer
    for (char c : streetName) {
        //for loop through each letter in streetName
        auto idx = (unsigned)(c & 0xff);

        //determine whether current ASCIINode is nullptr, if yes dynmaic allocate
        if (cptr->next_char[idx] == nullptr) {
            cptr->next_char[idx] = new ACSIINode();
        }

        //save streetId into current layer id_pool
        cptr->next_char[idx]->id_pool.emplace_back(street_id);

        //set pointer point to nextChar ASCIINode
        cptr = cptr->next_char[idx];
    }
}

vector<int> ACSIINode::getPrefixId(const string& prefix) {
    //special case where prefix is ""
    if (0 == prefix.length()) {
        return vector<int>();
    }

    ACSIINode* cptr = this; //temporary ASCIINode pointer
    for (char c : prefix) {
        //loop through every char in prefix
        auto idx = (unsigned)(c & 0xff);

        //if nextChar NULL, prefix no found
        if (cptr->next_char[idx] == nullptr) {
            return vector<int>();
        }

        cptr = cptr->next_char[idx];
        //set cptr towards nextChar
    }
    return cptr->id_pool;
}

void ACSIINode::clear() {
    for (int i = 0; i < 128; i++) {
        if (this->next_char[i] != nullptr) {
            this->next_char[i]->clear();
            delete this->next_char[i];
        }
    }
}