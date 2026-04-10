#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <fstream>
#include <filesystem>

using namespace geode::prelude;

class $modify(PlayLayer) {
    bool init(GJGameLevel* level) {
        if (!PlayLayer::init(level)) return false;
        m_fields->m_currentFrame = 0;
        m_fields->m_isAlive = true;
        m_fields->m_hasWrittenDead = false;
        return true;
    }

    void update(float dt) {
        PlayLayer::update(dt);

        if (m_fields->m_isAlive && !m_isPaused && !m_player1->m_isDead) {
            m_fields->m_currentFrame++;
            std::ofstream out("/sdcard/Android/media/com.geode.launcher/frame.txt");
            out << m_fields->m_currentFrame;
            out.close();
        }

        if (m_player1->m_isDead && !m_fields->m_hasWrittenDead) {
            m_fields->m_isAlive = false;
            m_fields->m_hasWrittenDead = true;
            std::ofstream out("/sdcard/Android/media/com.geode.launcher/frame.txt");
            out << -1;
            out.close();
        }
    }

    void onQuit() {
        PlayLayer::onQuit();
        std::ofstream out("/sdcard/Android/media/com.geode.launcher/frame.txt");
        out << 0;
        out.close();
    }

    void resetLevel() {
        PlayLayer::resetLevel();
        m_fields->m_currentFrame = 0;
        m_fields->m_isAlive = true;
        m_fields->m_hasWrittenDead = false;
        std::ofstream out("/sdcard/Android/media/com.geode.launcher/frame.txt");
        out << 0;
        out.close();
    }

private:
    int m_currentFrame;
    bool m_isAlive;
    bool m_hasWrittenDead;
};
