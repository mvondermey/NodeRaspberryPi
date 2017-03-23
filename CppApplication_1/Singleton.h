/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Singleton.h
 * Author: mvondermey
 *
 * Created on March 6, 2017, 12:35 PM
 */

#ifndef SINGLETON_H
#define SINGLETON_H

#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <string.h>   

class Singleton {
    //
    //
public:
    std::string DeviceName = "RedRat";

    static Singleton* Instance();
    static std::vector<std::string>* getConnections();
    static void addConnections(std::string);
    static bool CheckUUIDExists(std::string message);
private:
    Singleton();
    Singleton(const Singleton& orig);
    virtual ~Singleton();
    static Singleton* m_Instance ;
};

#endif /* SINGLETON_H */

