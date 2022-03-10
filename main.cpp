#include <iostream>

#include "ClearingControl.h"
#include "Event.h"


int main()
{
   auto ccfsm = ClearingControl{};
   std::cout << ccfsm.report_current_state() << "\n";

   ccfsm.process_event(event::Start {});
   std::cout << ccfsm.report_current_state() << "\n";

   ccfsm.process_event(event::Info { 1000 });
   std::cout << ccfsm.report_current_state() << "\n";

   ccfsm.process_event(event::Info { 500 });
   std::cout << ccfsm.report_current_state() << "\n";

   ccfsm.process_event(event::Cut {});
   std::cout << ccfsm.report_current_state() << "\n";

   ccfsm.process_event(event::Turn_Off {});
   std::cout << ccfsm.report_current_state() << "\n";
}
