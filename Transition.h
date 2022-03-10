#pragma once
#include "State.h"
#include "Event.h"
#include "Spindle.h"

template <typename From_State>
State on_event(From_State, event::Start)
{
   return state::Running{};
}

inline State on_event(state::Running running, event::Cut cut)
{
   running.m_yarn_length += cut.m_yarn_length;
   spindle::communicate_cut(running.m_yarn_length);
   return state::Cut{};
}

inline State on_event(state::Running running, event::Info info)
{
   running.m_yarn_length += info.m_yarn_length;
   return running;
}

template <typename From_State>
State on_event(From_State, event::Turn_Off)
{
   return state::Off{};
}
