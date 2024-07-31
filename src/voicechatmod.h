#ifndef VOICECHATMOD_H
#define VOICECHATMOD_H

#include "geode-sdk/sdk.h"
#include "geode-sdk/ui.h"
#include "geode-sdk/event.h"
#include "geode-sdk/level.h"
#include "geode-sdk/player.h"
#include "voicechatlib.h"

class VoiceChatMod : public geode::Mod {
private:
    geode::ui::Slider* deafenPercentageSlider;
    int deafenPercentage = 50;

public:
    void onLoad() override;

    void onDeafenPercentageChange(int value);

    void onPercentageReached(int percentage);

    void onPlayerDeath();

    void onLevelComplete();
};

extern "C" geode::Mod* createMod();

#endif // VOICECHATMOD_H
