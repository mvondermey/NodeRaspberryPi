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
#include <dirent.h>


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
    std::string temperature;
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
    struct timeval tp;
    gettimeofday(&tp,NULL);
    //printf("Sec %fn\n",(double)tp.tv_sec);
    //printf("Usec %f \n",(double)tp.tv_usec);
    long int ms = tp.tv_sec*1000000 + tp.tv_usec;
    char TimeStamp[256];
    sprintf(TimeStamp,"%ld",ms);
    //
    //std::cout << machineid << "/1/" << std::endl;
    //
    std::string DeviceName = Singleton::Instance()->DeviceName;
    //
    DIR *pdir = NULL;
    struct dirent *pent = NULL;
    pdir = opendir("/sys/bus/w1/devices/");
    if ( pdir == NULL)
    {
        printf ("ERROR pdir not found\n");
    } else {
        //
        printf("Readdir \n");
        //
        while (pent = readdir(pdir) ){
            //
            std::string DirectoryName = pent->d_name;
            //
            if ( DirectoryName.find("28-") != std::string::npos ) {
                std::string myFile = "/sys/bus/w1/devices/"+DirectoryName+"/w1_slave";
                std::cout << "Reading File " << myFile << std::endl;
                std::ifstream infile(myFile.c_str());
                if (! infile) {
                    std::cout << "Cannot open" << std::endl;
                }else {
                    std::string a;
                    while (infile >> a ){
                        if ( a.find("t=") != std::string::npos ) {temperature = a.substr(2);
                            std::cout << "Temperature " << temperature << std::endl;
                        }
                    }                
                }
            //
            }
           }
    }
    //
    rapidjson::Document json;
    json.SetObject();
    json.AddMember("TimeStamp",Value(TimeStamp,json.GetAllocator()).Move(),json.GetAllocator());
    json.AddMember("Message",Value(Message.c_str(),json.GetAllocator()).Move(),json.GetAllocator());
    json.AddMember("UUID",Value(machineid.c_str(),json.GetAllocator()).Move(),json.GetAllocator());
    json.AddMember("Command",Value(Command.c_str(),json.GetAllocator()).Move(),json.GetAllocator());
    json.AddMember("DeviceName",Value(DeviceName.c_str(),json.GetAllocator()).Move(),json.GetAllocator());

    //
    //std::cout << machineid << "/2/" << std::endl;
    //
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    json.Accept(writer);
    //
    //std::cout << machineid << "/3/" << std::endl;
    //
    std::string jsonstring =  buffer.GetString();
    //
    //std::cout << "String to send "<< jsonstring << std::endl;
    //
    //std::cout << machineid << "/4/" << std::endl;
    //
    return jsonstring;
    //
}

