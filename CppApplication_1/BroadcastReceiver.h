/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BroadcastSender.h
 * Author: mvondermey
 *
 * Created on March 2, 2017, 1:43 PM
 */

#ifndef BROADCASTRECEIVER_H
#define BROADCASTRECEIVER_H

#define MAXRECVSTRING 255  /* Longest string to receive */

#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), sendto(), and recvfrom() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

class BroadcastReceiver {
public:
    BroadcastReceiver();
    BroadcastReceiver(const BroadcastReceiver& orig);
    virtual ~BroadcastReceiver();
private:

};

#endif /* BROADCASTSENDER_H */

