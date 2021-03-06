/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   server.cpp
 * Author: mvondermey
 * 
 * Created on February 21, 2017, 2:37 PM
 */

#include "server.h"

server::server() {
    //
    int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
//
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        perror("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = 3009;
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              perror("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          perror("ERROR on accept");
     bzero(buffer,256);
     n = read(newsockfd,buffer,255);
     if (n < 0) perror("ERROR reading from socket");
     printf("Here is the message: %s\n",buffer);
     n = write(newsockfd,"I got your message",18);
     if (n < 0) perror("ERROR writing to socket");
     close(newsockfd);
     close(sockfd);
   
    //
}

server::server(const server& orig) {
}

server::~server() {
}

