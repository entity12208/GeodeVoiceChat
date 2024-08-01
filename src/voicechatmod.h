#pragma once

class VoiceChatMod {
public:
    VoiceChatMod();
    void initialize();

private:
    int deafenPercentage;
    bool isDeafened = false;

    void setupDeafenSlider();
    void subscribeToGameEvents();

    void onLevelStart(bool practice);
    void onPlayerDeath(PlayerObject* player);
    void onLevelComplete(PlayerObject* player);
    void onPercentage(float percentage);
};
