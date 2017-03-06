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

Singleton* Singleton::m_Instance = NULL;
std::vector< std::pair<std::string,int> > mListConnections;

Singleton::Singleton() {
    //

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

std::vector<std::pair<std::string,int> >* Singleton::getConnections(){
    //
    return &mListConnections;
    //
}