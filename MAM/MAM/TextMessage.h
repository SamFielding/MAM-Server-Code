#pragma once
#include "GameMessage.h"
class TextMessage : public GameMessage{
public:
TextMessage(std::string playerID, std::string text):playerID(playerID), text(text) {}
    std::string text;
    std::string playerID;
    

    char data[1024];

    char* Serialize() override
    {
        GameMessageType type = GameMessageType::text;

        std::memset(data, 0, 1014);
        
        std::memcpy(data, &type, 1);
        
        const uint32_t playerIdLen = static_cast<uint32_t>(playerID.size());
        
        std::cout << "Player Id Len: " << playerIdLen << std::endl;

        std::memcpy(data+1,playerID.data(), playerIdLen);

        std::memcpy(data+5+playerIdLen,&text,static_cast<uint32_t>(text.size()));
        return data;

    }

};