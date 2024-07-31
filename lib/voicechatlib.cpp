#include "voicechatlib.h"

// Initialize static members
bool VoiceChatLib::isDeafened = false;
DiscordClient* VoiceChatLib::discordClient = nullptr;
std::string VoiceChatLib::voiceChannelId = "";

void VoiceChatLib::initialize() {
    connectToVoiceChatServer();
}

void VoiceChatLib::connectToVoiceChatServer() {
    discordClient = new DiscordClient("YOUR_DISCORD_BOT_TOKEN");
    voiceChannelId = "YOUR_VOICE_CHANNEL_ID";
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
