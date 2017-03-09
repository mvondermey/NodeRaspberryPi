/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MessageJSON.cpp
 * Author: mvondermey
 * 
 * Created on March 9, 2017, 1:43 PM
 */

#include <ios>

#include "MessageJSON.h"

MessageJSON::MessageJSON() {
}

MessageJSON::MessageJSON(const MessageJSON& orig) {
}

MessageJSON::~MessageJSON() {
}

std::string MessageJSON::GetJSON(){
//
    std::ifstream ifs("/etc/machine-id");
    std::string machineid;
    getline(ifs,machineid, (char)ifs.eof());
    //
    machineid.erase(std::remove(machineid.begin(),machineid.end(),' '),machineid.end());  
    machineid.erase(std::remove(machineid.begin(),machineid.end(),'\n'),machineid.end());  
    machineid.erase(std::remove(machineid.begin(),machineid.end(),'\r'),machineid.end());  
    //
    //machineid.erase(machineid.length()-1);
    //
    std::string json = "{\"UUID\":\""+machineid+"\"}";
    //
    std::cout << json << std::endl;
    //
    return json;
    //
}
