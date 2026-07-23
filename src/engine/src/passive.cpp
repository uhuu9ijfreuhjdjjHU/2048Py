//2048Squared (title pending) copyright (c) 2026 River Knuuttila, common alias: Annie Valentine or aval. All Rights Reserved.
//Do not redistribute or reuse code without accrediting and explicit permission from author.
//Contact:
//+1 (808) 223 4780
//riverknuuttila2@outlook.com

#include "passive.h"

std::string passive_name(PassiveType type) {
    int bits = static_cast<int>(type);
    bool is_slow = bits & static_cast<int>(PassiveType::A_LITTLE_SLOW);
    bool is_contrarian = bits & static_cast<int>(PassiveType::CONTRARIAN);
    bool is_combo = bits & static_cast<int>(PassiveType::COMBO);
    if (is_slow && is_contrarian && is_combo) return "Slow Contrarian Combo";
    if (is_slow && is_combo) return "Slow Combo";
    if (is_contrarian && is_combo) return "Contrarian Combo";
    if (is_slow && is_contrarian) return "Slow Contrarian";
    if (is_slow) return "A Little Slow";
    if (is_contrarian) return "Contrarian";
    if (is_combo) return "Combo";
    return "None";
}

std::string passive_description(PassiveType type) {
    int bits = static_cast<int>(type);
    bool is_slow = bits & static_cast<int>(PassiveType::A_LITTLE_SLOW);
    bool is_contrarian = bits & static_cast<int>(PassiveType::CONTRARIAN);
    bool is_combo = bits & static_cast<int>(PassiveType::COMBO);
    if (is_slow && is_contrarian && is_combo) return "slowly moves opposite to your input, and merging it back-to-back scores a growing bonus";
    if (is_slow && is_combo) return "it's okay, take your time — merging it back-to-back scores a growing bonus";
    if (is_contrarian && is_combo) return "moves opposite to your input, and merging it back-to-back scores a growing bonus";
    if (is_slow && is_contrarian) return "slowly moves opposite to your input";
    if (is_slow) return "it's okay, take your time";
    if (is_contrarian) return "moves opposite to your input";
    if (is_combo) return "merging it in consecutive turns scores a growing bonus";
    return "";
}
