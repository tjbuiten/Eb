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
            std::cout << "event doesnt have value!\n";
            event = workstation->OnSubscribedEvent(eventType);
        } else {
            std::cout << "event does have value\n";
            event = workstation->OnSubscribedEvent(event.value());
        }
    };

    if (event.has_value()) {
        std::cout << event.value()->GetType() << "\n";
        _eventBus.SentEvent(event.value());
    }
}
}