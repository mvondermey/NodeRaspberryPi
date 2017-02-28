/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   client.cpp
 * Author: mvondermey
 * 
 * Created on February 21, 2017, 2:45 PM
 */

#include "client.h"

using namespace rapidjson;

client::client() {
    
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    portno = 8081;
    
    printf("Opening port\n");
    
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        perror("ERROR opening socket");
    server = gethostbyname("10.144.8.138");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    printf("Before connect \n");
    if ( connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0 ){ 
        printf("Error \n");
    }
    printf("After connect \n");
    //printf("Please enter the message: \n");
    //bzero(buffer,256);
    //fgets(buffer,255,stdin);
    //n = write(sockfd,buffer,strlen(buffer));
    //if (n < 0) 
      //   perror("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         perror("ERROR reading from socket");
    printf("%s\n",buffer);
    //
    std::string json(buffer);
    //
    //
    //json ="{\"TimeStamp\":\"148828132992\",\"Message\":\"Beep\",\"UUID\":\"XLM\",\"Command\":\"\"}";
    //json = "{\"a\":\"21\"}";
    json.erase(json.find("<BOF>"),5);
    json.erase(json.find("<EOF>"),5);
    
    //
    printf("After erase: \n %s \n",json.c_str());
    //
    Document document;
    document.Parse(json.c_str());
    //
    if ( document.HasParseError() ) {
        printf("ParseError \n");
        printf("Failed parsing json %s Offset: %d \n",GetParseError_En(document.GetParseError()),document.GetErrorOffset());
    }
        //
    raspidjson:Value & results = document["Message"];
    std::string message = results.GetString();
    printf(" Message: %s \n",message.c_str());
    //
    close(sockfd);
}

client::client(const client& orig) {
}

client::~client() {
}

