#include "WindwakerMultiplayer.h"
#include "Memmap.h"
#include "../Core.h"
#include "../System.h"

namespace Windwaker
{

//WindwakerMultiplayer::WindwakerMultiplayer(Memory::MemoryManager memory) : _memory(memory)
//{
//
//}
WindwakerMultiplayer::WindwakerMultiplayer()
{
  //_memory = Core::System::GetInstance().GetMemory();
  sword = 0;
  telescope = 0;
  sail = 0;
}

WindwakerMultiplayer::~WindwakerMultiplayer() = default;

void WindwakerMultiplayer::Update()
{
  /*if (Core::System::GetInstance().GetMemory().Read_U8(0x803C53A4) == 0x05)
    Core::DisplayMessage("In TOTG", 50);*/

  u8 currentSword = Core::System::GetInstance().GetMemory().Read_U8(0x803C4C16);
  if (currentSword == 0x3E && sword < 4)
  {
    sword = 4;
    Core::DisplayMessage("You have obtained the Master Sword (Full power)", 3000);
  }
  else if (currentSword == 0x3A && sword < 3)
  {
    sword = 3;
    Core::DisplayMessage("You have obtained the Master Sword (Half power)", 3000);
  }
  else if (currentSword == 0x39 && sword < 2)
  {
    sword = 2;
    Core::DisplayMessage("You have obtained the Master Sword (Powerless)", 3000);
  }
  else if (currentSword == 0x38 && sword < 1)
  {
    sword = 1;
    Core::DisplayMessage("You have obtained the Hero's Sword", 3000);
  }

  if (Core::System::GetInstance().GetMemory().Read_U8(0x803C4C44) == 0x20 && telescope < 1)
  {
    telescope = 1;
    Core::DisplayMessage("You have obtained the Telescope", 3000);
  }
}

}
