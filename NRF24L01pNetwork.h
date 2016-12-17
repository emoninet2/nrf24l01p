/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NRF24L01pNetwork.h
 * Author: emon1
 *
 * Created on December 13, 2016, 1:18 AM
 */

#ifndef NRF24L01PNETWORK_H
#define NRF24L01PNETWORK_H

#include "NRF24L01p.h"

#include <inttypes.h>
#include <stdint.h>
#include <limits>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

class NRF24L01pNetwork : public NRF24L01p{
public:
    typedef struct network_payload{
        uint16_t fromNodeId;
        uint16_t toNodeId;
        uint8_t pid;
        uint8_t packet_info;
        uint8_t payload[26];
    }network_payload_t;

    typedef struct adjacent_nodes{
        uint16_t NodeId;
        pipe_t RxPipe;
    }Node_t;
    
    
    typedef struct fwrd_addr{
        uint16_t SrcNodeId;
        Node_t AdjNode;
    }fwrd_addr_t;
    
    Node_t AdjacentNodes[5];
    fwrd_addr_t RoutingTable[NRF24L01P_NETWORK_ROUTING_TABLE_SIZE];
    unsigned int RoutingTablePtrLvl;
    
    uint16_t ownNetworkId;
    uint16_t ownNodeId;
    
    
    NRF24L01pNetwork();
    NRF24L01pNetwork(const NRF24L01pNetwork& orig);
    virtual ~NRF24L01pNetwork();
    
    void init_network(uint16_t networkID, uint16_t nodeID);
    void processPacket(Payload_t *payload);
    void processRoutingTable(Payload_t *payload);
    void sendToNode(Payload_t *payload, uint16_t Node);
    
    
    void sendPacketViaAdjacent(Payload_t *payload, uint16_t AdjNode);
    void forwardPacket(Payload_t *payload);
    
    
private:

};

#endif /* NRF24L01PNETWORK_H */

