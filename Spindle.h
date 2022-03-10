#pragma once
#include <iostream>

namespace spindle
{
   inline void communicate_cut([[maybe_unused]] int yarn_length)
   {
      std::cout << "Spindle removing " + std::to_string(yarn_length) << "\n";
   }
}
