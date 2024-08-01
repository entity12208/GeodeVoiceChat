#include "voicechatmod.h"
#include "voicechatlib.h"
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/ui/Slider.hpp>

using namespace geode::prelude;

VoiceChatMod::VoiceChatMod() : deafenPercentage(50) {
}

void VoiceChatMod::initialize() {
    VoiceChatLib::initializeVoiceChat();
    setupDeafenSlider();
    subscribeToGameEvents();
}

void VoiceChatMod::setupDeafenSlider() {
    Slider* slider = Slider::create("Deafen Percentage", 0, 100, deafenPercentage, [this](float value) {
        this->deafenPercentage = static_cast<int>(value);
    });
    GameManager::sharedState()->addChild(slider);
}

void VoiceChatMod::subscribeToGameEvents() {
    GameManager::sharedState()->onLevelStart([this](bool practice) {
        this->onLevelStart(practice);
    });

    GameManager::sharedState()->onPlayerDeath([this](PlayerObject* player) {
        this->onPlayerDeath(player);
    });

    GameManager::sharedState()->onLevelComplete([this](PlayerObject* player) {
        this->onLevelComplete(player);
    });

    PlayerObject::sharedInstance()->onPercentage([this](float percentage) {
        this->onPercentage(percentage);
    });
}

void VoiceChatMod::onLevelStart(bool practice) {
    isDeafened = false;
    VoiceChatLib::undeafen();
}

void VoiceChatMod::onPlayerDeath(PlayerObject* player) {
    VoiceChatLib::undeafen();
}

void VoiceChatMod::onLevelComplete(PlayerObject* player) {
    VoiceChatLib::undeafen();
}

void VoiceChatMod::onPercentage(float percentage) {
    if (percentage >= deafenPercentage && !isDeafened) {
        VoiceChatLib::deafen();
        isDeafened = true;
    } else if (percentage < deafenPercentage && isDeafened) {
        VoiceChatLib::undeafen();
        isDeafened = false;
    }
}
