/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BroadcastSender.cpp
 * Author: mvondermey
 * 
 * Created on March 2, 2017, 1:51 PM
 */

#include "BroadcastSender.h"
#include "Singleton.h"
#include "MessageParser.h"

BroadcastSender::BroadcastSender() {
    int sock;                         /* Socket */
    struct sockaddr_in broadcastAddr; /* Broadcast address */
    struct sockaddr_in addr;
    char *broadcastIP;                /* IP broadcast address */
    unsigned short broadcastPort;     /* Server port */
    char *sendString;                 /* String to broadcast */
    int broadcastPermission;          /* Socket opt to set permission to broadcast */
    unsigned int sendStringLen;       /* Length of string to broadcast */
    socklen_t fromlen;
    char buf[512];
    int byte_count;

    broadcastIP = "255.255.255.255";            /* First arg:  broadcast IP address */ 
    broadcastPort = 8003;    /* Second arg:  broadcast port */
    sendString = "Hello World";             /* Third arg:  string to broadcast */

    /* Create socket for sending/receiving datagrams */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        printf("socket() failed\n");

    /* Set socket to allow broadcast */
    broadcastPermission = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (void *) &broadcastPermission, 
          sizeof(broadcastPermission)) < 0)
        printf("setsockopt() failed\n");

    int flags = fcntl(sock, F_GETFL);
    flags |= O_NONBLOCK;
    fcntl(sock,F_SETFL,flags);
    
    /* Construct local address structure */
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));   /* Zero out structure */
    broadcastAddr.sin_family = AF_INET;                 /* Internet address family */
    broadcastAddr.sin_addr.s_addr = inet_addr(broadcastIP);/* Broadcast IP address */
    broadcastAddr.sin_port = htons(broadcastPort);         /* Broadcast port */

    sendStringLen = strlen(sendString);  /* Find length of sendString */
    for (;;) /* Run forever */
    {
         /* Broadcast sendString in datagram to clients every 3 seconds*/
         if (sendto(sock, sendString, sendStringLen, 0, (struct sockaddr *) 
               &broadcastAddr, sizeof(broadcastAddr)) != sendStringLen)
             printf("sendto() sent a different number of bytes than expected\n");
         //
         printf("BroadcastSender.Sent %s \n",sendString);
         //
             byte_count = recvfrom(sock,buf, sizeof buf,0, (struct sockaddr *)&addr, &fromlen);
             //
             if (byte_count > 0 ) {
                 //
                 printf("Received %d bytes of data %s \n",byte_count,buf);
                 //
                 printf("From %s \n",inet_ntoa(addr.sin_addr));
                 //
                 MessageParser myMessageParser;
                 myMessageParser.ParseMessage(buf);
                 //
             }
             //
        sleep(3);   /* Avoids flooding the network */
    }
}

BroadcastSender::BroadcastSender(const BroadcastSender& orig) {
}

BroadcastSender::~BroadcastSender() {
}

