#include "voicechatmod.h"
#include "voicechatlib.h"
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/ui/Slider.hpp>

using namespace geode::prelude;

void VoiceChatMod::onLoad() {
    VoiceChatLib::initialize();

    deafenPercentageSlider = geode::ui::Slider::create(
        "Deafen Percentage",
        0, 100, 50,
        [this](int value) { this->onDeafenPercentageChange(value); }
    );

    geode::ui::addElement(deafenPercentageSlider);

    geode::event::subscribe<geode::level::PercentageReached>([this](int percentage) { this->onPercentageReached(percentage); });
    geode::event::subscribe<geode::player::Death>([this]() { this->onPlayerDeath(); });
    geode::event::subscribe<geode::level::Complete>([this]() { this->onLevelComplete(); });
}

void VoiceChatMod::onDeafenPercentageChange(int value) {
    deafenPercentage = value;
}

void VoiceChatMod::onPercentageReached(int percentage) {
    if (percentage >= deafenPercentage) {
        VoiceChatLib::deafen();
    }
}

void VoiceChatMod::onPlayerDeath() {
    VoiceChatLib::undeafen();
}

void VoiceChatMod::onLevelComplete() {
    VoiceChatLib::undeafen();
}
