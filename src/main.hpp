#pragma once
#include <Geode/Geode.hpp>
using namespace geode::prelude;

struct MyPlayLayer : geode::Modify<MyPlayLayer, PlayLayer> {
    int m_currentFrame;
    bool m_isAlive;
    bool m_hasWrittenDead;
};
