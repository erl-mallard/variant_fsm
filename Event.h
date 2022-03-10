#pragma once

namespace event
{
   struct Start
   {
   };

   struct Info
   {
      int m_yarn_length{};
   };

   struct Cut
   {
      int m_yarn_length{};
   };

   struct Turn_Off
   {
   };
}
