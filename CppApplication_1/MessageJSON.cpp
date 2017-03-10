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
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include "MessageJSON.h"

using namespace rapidjson;

MessageJSON::MessageJSON() {
    std::string Message;
    std::string Command;
}

MessageJSON::MessageJSON(const MessageJSON& orig) {
}

MessageJSON::~MessageJSON() {
}

std::string MessageJSON::GetJSON(std::string Message, std::string Command){
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
    std::cout << machineid << "/1/" << std::endl;
    //
    rapidjson::Document json;
    json.SetObject();
    json.AddMember("UUID",Value(machineid.c_str(),json.GetAllocator()).Move(),json.GetAllocator());
    //
    std::cout << machineid << "/2/" << std::endl;
    //
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    json.Accept(writer);
    //
    std::cout << machineid << "/3/" << std::endl;
    //
    std::string jsonstring =  buffer.GetString();
    //
    std::cout << "String to send "<< jsonstring << std::endl;
    //
    std::cout << machineid << "/4/" << std::endl;
    //
    return jsonstring;
    //
}

