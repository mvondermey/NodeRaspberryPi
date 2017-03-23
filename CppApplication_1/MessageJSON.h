/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MessageJSON.h
 * Author: mvondermey
 *
 * Created on March 9, 2017, 1:43 PM
 */

#ifndef MESSAGEJSON_H
#define MESSAGEJSON_H

#include <string>     
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sys/time.h>
#include "Singleton.h"

class MessageJSON {
public:
    MessageJSON();
    MessageJSON(const MessageJSON& orig);
    virtual ~MessageJSON();
    std::string GetJSON(std::string, std::string);
private:

};

#endif /* MESSAGEJSON_H */

