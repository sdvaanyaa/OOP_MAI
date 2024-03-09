#pragma once

#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "elf.h"

std::shared_ptr<NPC> factory(std::istream &is);
std::shared_ptr<NPC> factory(NpcType type, int x, int y);