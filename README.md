Overview

This project involves the creation of a boat movement system using Unreal Engine, leveraging both C++ and Blueprints to achieve realistic and functional gameplay mechanics.
The following sections outline the key components and features implemented.

Obstacle Ships Movement

    C++ Movement Logic: The obstacle ships' movement logic was created using C++. These ships follow a spline path for smooth and predictable movement.
    Custom Editor Functions:
        A function to spawn a path class used by the obstacle ships.
        Another function to automatically generate a circular spline path, making path creation easier.

Player Boat

    C++ Base Class: The player's boat was built using a C++ base class.
    Turning Logic: C++ logic was implemented to handle turning inputs, with a lerping turn speed for realistic movement.
    Blueprint Scripting: After testing, it was found that using Blueprint scripting to add force to the actor provided better performance and realism compared to using add movement.
    Collision Handling: Several capsule collisions were added to the boat for realistic interactions with both water and other boats.
    Particle System: Blueprints were used to activate and deactivate a simple water particle system.
    Game Mechanics: Blueprints were also used to script the final goal overlap, widget trigger, and level restart.

Blueprint Function Library

    To demonstrate the use of a Blueprint function library, a simple example was included in the project.
    
Known Issues

    The boat may capsize due to collisions. In such an event, the level will restart.

Controls

    W: Move forward
    A/D: Turn left/right
