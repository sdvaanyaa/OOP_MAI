#pragma once

#include "npc.h"
#include "dragon.h"
#include "elf.h"
#include "knight.h"

std::string randname();

std::shared_ptr<NPC> Create(NpcType type, std::string name, int x, int y);

std::shared_ptr<NPC> Create(std::istream& stream);