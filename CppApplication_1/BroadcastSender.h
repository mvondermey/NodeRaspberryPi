/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BroadcastSender.h
 * Author: mvondermey
 *
 * Created on March 2, 2017, 1:51 PM
 */

#ifndef BROADCASTSENDER_H
#define BROADCASTSENDER_H

#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket() and bind() */
#include <arpa/inet.h>  /* for sockaddr_in */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <fcntl.h>




class BroadcastSender {
public:
    BroadcastSender();
    BroadcastSender(const BroadcastSender& orig);
    virtual ~BroadcastSender();
private:

};

#endif /* BROADCASTSENDER_H */

