/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BroadcastSender.cpp
 * Author: mvondermey
 * 
 * Created on March 2, 2017, 1:43 PM
 */

#include "BroadcastReceiver.h"
#include "MessageJSON.h"
#include "MessageParser.h"

BroadcastReceiver::BroadcastReceiver() {
    //
   int sock;                         /* Socket */
    struct sockaddr_in broadcastAddr; /* Broadcast Address */
    unsigned short broadcastPort;     /* Port */
    char recvString[MAXRECVSTRING+1]; /* Buffer for received string */
    int recvStringLen;                /* Length of received string */

    broadcastPort = 8003;   /* First arg: broadcast port */

    /* Create a best-effort datagram socket using UDP */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        printf("socket() failed\n");

    /* Construct bind structure */
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));   /* Zero out structure */
    broadcastAddr.sin_family = AF_INET;                 /* Internet address family */
    broadcastAddr.sin_addr.s_addr = htonl(INADDR_ANY);  /* Any incoming interface */
    broadcastAddr.sin_port = htons(broadcastPort);      /* Broadcast port */

    /* Bind to the broadcast port */
    if (bind(sock, (struct sockaddr *) &broadcastAddr, sizeof(broadcastAddr)) < 0)
        printf("bind() failed\n");

    while (true){
  //  
    /* Receive a single datagram from the server */
    if ((recvStringLen = recvfrom(sock, recvString, MAXRECVSTRING, 0, NULL, 0)) < 0)
        printf("recvfrom() failed\n");
//
    recvString[recvStringLen] = '\0';
    printf("BroadcastReceiver.Received: %s\n", recvString);    /* Print the received string */
    //
    MessageParser mMessageParser;
    mMessageParser.ParseMessage(recvString);
    //
    }
 
    
    close(sock);
    //
}

BroadcastReceiver::BroadcastReceiver(const BroadcastReceiver& orig) {
}

BroadcastReceiver::~BroadcastReceiver() {
}

