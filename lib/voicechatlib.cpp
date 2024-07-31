#include "voicechatlib.h"

// Initialize static members
bool VoiceChatLib::isDeafened = false;
DiscordClient* VoiceChatLib::discordClient = nullptr;
std::string VoiceChatLib::voiceChannelId = "";

void VoiceChatLib::initialize() {
    connectToVoiceChatServer();
}

void VoiceChatLib::connectToVoiceChatServer() {
    discordClient = new DiscordClient("MTI2Nzg4MDA0NDc0Mzg4NDg2MQ.GBCtfg.2OaCatoXPoWbEITPw5lZvJ-gK2P_sinzVxQs7Y");
    voiceChannelId = "1267881280624922647";
    discordClient->connect();
    discordClient->joinVoiceChannel(voiceChannelId);
    std::cout << "Connected to voice chat server" << std::endl;
}

void VoiceChatLib::deafen() {
    if (!isDeafened) {
        discordClient->muteSelf();
        std::cout << "User deafened" << std::endl;
        isDeafened = true;
    }
}

void VoiceChatLib::undeafen() {
    if (isDeafened) {
        discordClient->unmuteSelf();
        std::cout << "User undeafened" << std::endl;
        isDeafened = false;
    }
}
