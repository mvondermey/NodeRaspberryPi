/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MessageParser.h
 * Author: mvondermey
 *
 * Created on March 6, 2017, 2:13 PM
 */

#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include <stdio.h>
#include <algorithm>
#include "rapidjson/document.h"
#include "rapidjson/error/en.h"



class MessageParser {
public:
    MessageParser();
    MessageParser(const MessageParser& orig);
    virtual ~MessageParser();
    void ParseMessage(std::string);
    std::string ExtractUUID(std::string);
private:

};

#endif /* MESSAGEPARSER_H */

