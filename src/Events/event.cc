#include "Events/event.h"

namespace events {
EventType Event::GetType() {
    return EventType::DEFAULT;
}
}