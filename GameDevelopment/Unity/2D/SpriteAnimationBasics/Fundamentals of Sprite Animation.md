There are three main features in Unity to create animations from sprite sheets, these are:

- Animation clips
- Animation controllers
- Animator components

## Animation clips
Animation clips are the core of the Unity animation system, all created animation clips are saved with the `.anim` file extension. The animation **Dope Sheet** system is used for animations, it tracks almost every change in the inspector for sprites which allows almost everything to be animated; each sprite from a sprite sheet can even be used for each frame of the animation.

> Sprites don't have to come from a sprite sheet for animation, they can come individual textures or other sprite sheets that have been imported.

### Animation Dope Sheet
The animation **Dope Sheet** is used to make simple or complex animations, it provides an **Animation** editor in which animations can be modified. It has a variety of sections available for modifying the animation.

### Time/recording controls
The time controls allow for recorded animations to be played or stepped through, useful when combined with the active play in the **Scene** and **Game** views.

The record button determines whether changes in the **Scene** or **Inspector** windows affect the **Animation** properties, automatically adding new properties if they have not yet been modified.

Buttons also exist for adding new **KeyFrames** (specific points on the timeline at the currently selected time) or **Animation Events** (script launching points based on time).

### Animation drop-down selection
Below the time controls is a drop-down containing a simple list of all the clips in the current animation set/controller. More clips can be added directly from this drop-down menu.

### Sample rate (frames per second)
The sample rate sets the number of frames per second available in the timeline, controlling the possible number of key frame points between time intervals. By default, this is set to `60fps`.

> It is important to know what frame rate sprite sheets were made in, many 2D animation systems run at `24fps`.

### Animation properties
Animation properties lists out all the properties from the **Inspector** which are actively being controlled by the animation clip. If a property is touched in the editor while record mode is active, it will be added here or altered if it exists. Any changes will also be captured from child game object properties that are changed.

### Timeline
The timeline window shows all key frames being animated over the animations lifetime. The sample rate will set how many key points/frames will be available between time units.

Some keyboard shortcuts can be used to navigate between the frames on the timeline:
- `,`: Go to previous frame
- `.`: Go to next frame
- `ALT+,`: Go to previous key frame
- `ALT+.`: Go to next key frame

### Curve view
The timeline view has an alternate view mode which adds finer control and curves between key frame animations. Editing the curves can provide a smoother looking animation transition then the default on/off effect.

## Animation controllers
Animation controllers are state machines, they store states and the transitions between them, that control when an animation should be played and what conditions control the transition between each state.

Animation controllers are saved with the file extension `.controller`, animations cannot play without an associated and controller. Each controller may contain many animations to play.

In the animator for controllers:
- Grey rectangles represent animation states
- Orange rectangles represent the default animation state
- Arrows represent transitions between animation states
- **Entry** and **Exit** nodes are added to the **State Machine Transitions**, they tell the state machine what it should do when it starts and when it should exit

## Animator component
The **Animator** component is used to apply animations prepared in a controller to a game object. In 2D projects, the **Controller** property is the only one that matters; it is used to specify which controller to attach to a game object.