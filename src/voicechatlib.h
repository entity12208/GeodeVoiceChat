#ifndef VOICECHATLIB_H
#define VOICECHATLIB_H

#include <iostream>
#include <discord.h>

class VoiceChatLib {
private:
    static bool isDeafened;
    static DiscordClient* discordClient;
    static std::string voiceChannelId;

public:
    static void initialize();
    static void connectToVoiceChatServer();
    static void deafen();
    static void undeafen();
};

#endif // VOICECHATLIB_H
