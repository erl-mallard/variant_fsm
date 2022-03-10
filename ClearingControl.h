#pragma once
#include <string>
#include <variant>

#include "State.h"
#include "Transition.h"

template <class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...)->overload<Ts...>;

class ClearingControl
{
public:
   template <typename Event>
   void process_event(Event&& event)
   {
      m_state = std::visit(
         overload{
            [&] (const auto& state) requires std::is_same_v<decltype(on_event(state, std::forward<Event>(event))), State>
            {
               return on_event(state, std::forward<Event>(event));
            },
            [](const auto&) -> State
            {
               throw std::logic_error{ "Unsupported state transition" };
            }
         },
         m_state);
   }

   std::string report_current_state()
   {
      return std::visit(
         overload{
            [](const state::Running& state) -> std::string {return "State: Running - yarn length = " + std::to_string(state.m_yarn_length); },
            [](const state::Cut&) -> std::string {return "State: Cut"; },
            [](const state::Off&) -> std::string {return "State: Off"; }
         },
         m_state);
   }

private:
   State m_state;
};
