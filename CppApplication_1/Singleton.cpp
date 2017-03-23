/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Singleton.cpp
 * Author: mvondermey
 * 
 * Created on March 6, 2017, 12:36 PM
 */

#include "Singleton.h"
#include "MessageParser.h"

Singleton* Singleton::m_Instance = NULL;
std::vector<std::string> mListConnections;

Singleton::Singleton() {
    //

}

Singleton::Singleton(const Singleton& orig) {
}

Singleton::~Singleton() {
}

Singleton* Singleton::Instance(){
    //
    if ( ! m_Instance ) m_Instance = new Singleton;
    //
    return m_Instance; 
    //
}

std::vector<std::string>* Singleton::getConnections(){
    //
    return &mListConnections;
    //
}

//
bool Singleton::CheckUUIDExists(std::string message){
    //
    bool result = false;
    //
    for (std::vector<std::string>::iterator it = mListConnections.begin() ; it != mListConnections.end(); ++it){
    //
        printf("Singleton::CheckUUIDExists %s \n",(*it).c_str());
        //
        MessageParser mMessageParser;
        //
        if ( mMessageParser.ExtractUUID(*it) == mMessageParser.ExtractUUID(message) ) {
            printf("Already exists \n");
            result = true;
        }
        //

    //
    }
         return result;
    //
}
//

void Singleton::addConnections(std::string message){
    //
    if ( ! CheckUUIDExists(message) ){
        mListConnections.push_back(message);
        printf("MessageParser.addConnections Element added\n");
    }
    //
}