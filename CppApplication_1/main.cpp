/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mvondermey
 *
 * Created on February 21, 2017, 2:31 PM
 */


#include "client.h"
#include "BroadcastSender.h"
#include "BroadcastReceiver.h"
#include <stdlib.h>
#include <iostream>    

using namespace std;

/*
 * 
 */

void *BroadcastSenderF(void *tid){
    //
    BroadcastSender myBroadcastSender;
    //
}
//
void *BroadcastReceiverF(void *tid){
    //
    BroadcastReceiver myBroadcastReceiver;
    //
}
//
int main(int argc, char** argv) {

    pthread_t BroadcastSender;
    long tidS;
  
    pthread_t BroadcastReceiver;
    long tidR;
    
    printf("Main\n");
   
    //
    pthread_create(&BroadcastSender, NULL, BroadcastSenderF, (void *) tidS); 
    //pthread_create(&BroadcastReceiver, NULL, BroadcastReceiverF, (void *) tidR); 
    //
    int input;
    std::cin >> input ;
    //
    printf("After client\n");
    
    return 0;
}

