#pragma once
#include <cstdint>

class GameMessage
{
public:

    virtual char* Serialize() = 0;
    


    static void Deserialize(char* data)
    {
        size_t cursor = 0;
        uint8_t recievedMessageByte;

        std::memcpy(&recievedMessageByte, data+cursor,1);
        cursor+=1;

        if(recievedMessageByte = 0)
        {

        }
        else if(recievedMessageByte = 1)
        {
                
            std::string recievedMessagePlayerID;
            int stringLength;
            std::memcpy(&stringLength, data+cursor,sizeof(int));
            cursor+=sizeof(int);
            std::memcpy(recievedMessagePlayerID.data(), data+cursor,stringLength);
            cursor+=stringLength;
            std::string recievedMessageText;
            std::memcpy(&stringLength, data+cursor, sizeof(int));
            cursor+=sizeof(int);
            std::memcpy(recievedMessageText.data(),data+cursor,stringLength);
            cursor+=stringLength;

            std::cout<< recievedMessageText << std::endl;

            

        }
        else if(recievedMessageByte = 2)
        {

        }
    }
        
};


