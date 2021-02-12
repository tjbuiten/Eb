# Eb - Line Renderer
This project contains a OpenGL and FreeGLUT based rendering program, developed as a personal side-project.
Currently only works on MacOS.

## Setup
* Install brew
* Install CMake
* Install FreeGLUT

## Explanation
### General
Main -> creates the necessary classes

### Input
InputManager -> receives input and sents it as an event to the eventbroker
InputEventHandlers -> subscribe on a eventbroker with a specific event that the handler handles
InputEventBus -> keep a map of registered handlers coupled to events
InputEvents -> Enum with the events
InputMapper -> std::map, mapping a std::string to the InputEvents enum.

### Drawing
ScreenManager -> creates a screen and keeps the main update loop going
Screen -> the actual screen on which is drawn
ScreenEventHandlers -> subscribe on a eventbroker with a specific event that hte handler handles
ScreenEventBus -> keeps a map of registered handlers coupled to events

Object is type of ScreenEventHandler -> handles the logic for drawing the correct pixels for a specific object on the screen
 * Circle
 * Line
 * Square

### Libraries
 * InputHandling -> Executable library which will handle user input with std::cin
 * Drawing -> Executable library which will connect drawing functions to an eventqueue, this mediates between input and screens
 * Screens -> Executable library which will connect screens to a eventqueue