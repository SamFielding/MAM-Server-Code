#pragma once
class TextMessage : public GameMessage{
public:
TextMessage(std::string playerID, std::string text):playerID(playerID), text(text) {}
    std::string text;
    std::string playerID;

    char* Serialize() override
    {
        char data[1024];
        std::memcpy(data,&playerID,playerID.size());
        std::memcpy(data,&text,text.size());
        return data;

    }

};