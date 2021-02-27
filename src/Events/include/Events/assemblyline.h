#pragma once

#include <map>
#include <list>
#include "Events/workstation.h"
#include "Events/eventbus.h"

namespace events {
class AssemblyLine {
    public:
        AssemblyLine(EventBus& eventBus): _eventBus(eventBus) { }

        void AddWorkstation(EventType eventType, Workstation* workstation);
        void ConstructEvent(EventType eventType);
    protected:
    private:
        EventBus& _eventBus;
        std::map<EventType, std::list<Workstation*>> workstations;
};
}