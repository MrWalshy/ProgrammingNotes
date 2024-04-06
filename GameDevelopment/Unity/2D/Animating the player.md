The player character currently isn't animated, this means only a single image is shown when moving about. The sprite sheet for the player has three angles which can be used to animate walking though.

Three things are needed:

- An **Animator Component** on the GameObject
- An **Animator Controller** to manage the animation bound to the animator
- At least one **Animation clip** to play in the controller

When a new animation clip is created for a game object, the other items will be automatically created.

The **Animation** and **Animator** windows can be opened using the `Window > Animation > Animation` and `Window > Animation > Animator` options from the menu bar.

## Adding the animation clip
