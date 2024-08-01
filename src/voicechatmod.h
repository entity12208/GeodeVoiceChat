#pragma once

#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/ui/Slider.hpp>

class VoiceChatMod : public geode::Mod {
public:
    void onLoad() override;
    void onDeafenPercentageChange(int value);
    void onPercentageReached(int percentage);
    void onPlayerDeath();
    void onLevelComplete();

private:
    geode::ui::Slider* deafenPercentageSlider;
    int deafenPercentage = 50;
};
