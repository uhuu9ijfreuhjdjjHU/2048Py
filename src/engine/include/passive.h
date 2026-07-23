//2048Squared (title pending) copyright (c) 2026 River Knuuttila, common alias: Annie Valentine or aval. All Rights Reserved.
//Do not redistribute or reuse code without accrediting and explicit permission from author.
//Contact:
//+1 (808) 223 4780
//riverknuuttila2@outlook.com

#pragma once

#include <algorithm>
#include <string>

enum class PassiveType {
    NONE = 0,
    A_LITTLE_SLOW = 1,
    CONTRARIAN = 2,
    COMBO = 4,
};

// Bitmask check: returns true if 'stored' has the given flag bit set.
// Tiles can hold multiple passives simultaneously (e.g., A_LITTLE_SLOW | CONTRARIAN = 3).
inline bool has_passive(PassiveType stored, PassiveType flag) {
    return (static_cast<int>(stored) & static_cast<int>(flag)) != 0;
}

// Merge rule: a merged tile carries the OR of both source tiles' passives.
inline PassiveType combine_passives(PassiveType a, PassiveType b) {
    return static_cast<PassiveType>(static_cast<int>(a) | static_cast<int>(b));
}

// Merge rule: Combo streak carries forward as the longer of the two chains.
// The +1 for an actual streak-extending hit is applied centrally in
// GameEngine::process_move, gated on the per-tile direction check below —
// this just picks the surviving count. Tracked on every tile regardless of
// passive (cheap int, ignored unless the tile is Combo) so the merge code
// doesn't need passive checks sprinkled through it.
inline int combine_combo_streak(int a, int b) {
    return std::max(a, b);
}

// Combo direction, encoded as a bitmask so a merge between two Combo tiles can
// carry forward both candidate directions for this turn's hit check (see
// combine_combo_direction below). Outside of that single-turn window exactly
// one bit is set — assign_passive() and process_move's per-turn reroll always
// pick one of the four values below.
constexpr int COMBO_DIR_UP    = 1;
constexpr int COMBO_DIR_DOWN  = 2;
constexpr int COMBO_DIR_LEFT  = 4;
constexpr int COMBO_DIR_RIGHT = 8;

inline int direction_to_combo_bit(const std::string& direction) {
    if (direction == "up")    return COMBO_DIR_UP;
    if (direction == "down")  return COMBO_DIR_DOWN;
    if (direction == "left")  return COMBO_DIR_LEFT;
    return COMBO_DIR_RIGHT;
}

inline std::string combo_bit_to_direction(int bit) {
    switch (bit) {
        case COMBO_DIR_UP:   return "up";
        case COMBO_DIR_DOWN: return "down";
        case COMBO_DIR_LEFT: return "left";
        default:             return "right";
    }
}

// Merge rule: a merged tile's Combo direction is the OR of whichever source
// tiles actually carry the Combo passive (a plain tile merging into a Combo
// tile contributes nothing; two Combo tiles merging keeps both as hit
// candidates for this turn's move — see the two-Combo-tiles tie-break in
// GameEngine::process_move).
inline int combine_combo_direction(PassiveType a_passive, int a_dir, PassiveType b_passive, int b_dir) {
    int mask = 0;
    if (has_passive(a_passive, PassiveType::COMBO)) mask |= a_dir;
    if (has_passive(b_passive, PassiveType::COMBO)) mask |= b_dir;
    return mask;
}

std::string passive_name(PassiveType type);
std::string passive_description(PassiveType type);
