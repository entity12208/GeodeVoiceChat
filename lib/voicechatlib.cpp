#include <iostream>
#include <discord.h>

class VoiceChatLib {
private:
    static bool isDeafened;
    static DiscordClient* discordClient;
    static std::string voiceChannelId;

public:
    static void initialize() {
        connectToVoiceChatServer();
    }

    static void connectToVoiceChatServer() {
        discordClient = new DiscordClient(MTI2Nzg4MDA0NDc0Mzg4NDg2MQ.GBCtfg.2OaCatoXPoWbEITPw5lZvJ-gK2P_sinzVxQs7Y
);
        voiceChannelId = 1267881280624922647;
        discordClient->connect();
        std::cout << "Connected to voice chat server" << std::endl;
    }

    static void deafen() {
        if (!isDeafened) {
            discordClient->muteSelf();
            std::cout << "User deafened" << std::endl;
            isDeafened = true;
        }
    }

    static void undeafen() {
        if (isDeafened) {
            discordClient->unmuteSelf();
            std::cout << "User undeafened" << std::endl;
            isDeafened = false;
        }
    }
};

// Initialize static members
bool VoiceChatLib::isDeafened = false;
DiscordClient* VoiceChatLib::discordClient = nullptr;
std::string VoiceChatLib::voiceChannelId = "";
