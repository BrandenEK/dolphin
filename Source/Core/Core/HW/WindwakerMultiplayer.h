#pragma once

#include "../Core.h"
#include "Memmap.h"

namespace Windwaker
{
class WindwakerMultiplayer
{
public:
  explicit WindwakerMultiplayer();
  ~WindwakerMultiplayer();
  void Update();

private:
  //Core::System& _system;
  //Memory::MemoryManager& _memory;
  u8 sword;
  u8 telescope;
  u8 sail;
};
}
