#include "voicechatmod.h"
#include "voicechatlib.h"

class VoiceChatMod : public geode::Mod {
private:
    geode::ui::Slider* deafenPercentageSlider;
    int deafenPercentage = 50;

public:
    void onLoad() override {
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

    void onDeafenPercentageChange(int value) {
        deafenPercentage = value;
    }

    void onPercentageReached(int percentage) {
        if (percentage >= deafenPercentage) {
            VoiceChatLib::deafen();
        }
    }

    void onPlayerDeath() {
        VoiceChatLib::undeafen();
    }

    void onLevelComplete() {
        VoiceChatLib::undeafen();
    }
};

extern "C" geode::Mod* createMod() {
    return new VoiceChatMod();
}
