#pragma once

namespace state
{
   struct Off {};

   struct Running
   {
      int m_yarn_length{};
   };

   struct Cut {};
}

using State = std::variant<state::Off, state::Running, state::Cut>;
