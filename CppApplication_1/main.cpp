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


#include </home/mvondermey/NetBeansProjects/NodeRaspberryPi/CppApplication_1/client.h>
#include </home/mvondermey/NetBeansProjects/NodeRaspberryPi/CppApplication_1/BroadcastSender.h>
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
int main(int argc, char** argv) {

    pthread_t BroadcastSender;
    const char *BroadcastSenderMessage1 = "BroadcastSender";
    long tid;
    
    printf("Main\n");
    
    //client myClient ;
    pthread_create(&BroadcastSender, NULL, BroadcastSenderF, (void *) tid); 
    //
    int input;
    std::cin >> input ;
    //
    printf("After client\n");
    
    return 0;
}

