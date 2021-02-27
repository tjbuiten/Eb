#include "Events/assemblyline.h"
#include <iostream>
#include <utility>
#include <vector>
#include <string>

namespace events {
void AssemblyLine::AddWorkstation(EventType eventType, Workstation* workstation) {
    workstations[eventType].push_back(workstation);
}

void AssemblyLine::ConstructEvent(EventType eventType) {

    std::optional<Event*> event;

    for (Workstation* workstation : workstations[eventType]) {
        if (workstation == nullptr) {
            workstations[eventType].remove(workstation);
        }

        if (!event.has_value()) {
            event = workstation->OnSubscribedEvent(eventType);
        } else {
            event = workstation->OnSubscribedEvent(event.value());
        }
    };

    if (event.has_value()) {
        _eventBus.SentEvent(event.value());
        return;
    }

    std::cout << "This event has not been implemented yet\n";
}
}