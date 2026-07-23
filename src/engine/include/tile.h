//2048Squared (title pending) copyright (c) 2026 River Knuuttila, common alias: Annie Valentine or aval. All Rights Reserved.
//Do not redistribute or reuse code without accrediting and explicit permission from author.
//Contact:
//+1 (808) 223 4780
//riverknuuttila2@outlook.com

#pragma once

#include "passive.h"

struct Tile {
    int value = 0;
    PassiveType passive = PassiveType::NONE;
    // Consecutive-merge counter for the Combo passive. Reset to 0 whenever the
    // tile goes a turn without merging, or merges but the move direction
    // doesn't match combo_direction; only read for scoring on Combo tiles.
    int combo_streak = 0;
    // Stored direction (bitmask, see COMBO_DIR_* in passive.h) for the Combo
    // passive's direction gate. Re-rolled every turn for tiles carrying
    // Combo; only meaningful on those tiles.
    int combo_direction = 0;

    bool is_empty() const { return value == 0; }
    bool is_bomb() const { return value == -1; }
    bool is_snail() const { return value == -2; }
    bool is_wall() const { return value == -3; }
    bool is_numbered() const { return value > 0; }
    bool has_passive() const { return passive != PassiveType::NONE; }
};
