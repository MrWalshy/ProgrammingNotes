The `Monobehaviour` class in C# Unity is for creating scripts which can be attached to game objects, a variety of methods are inherited from this class which are called as part of the rendering pipeline.

## `Start()`

The `Start()` method is called on the first frame when a script is enabled for the first time. This is when the game object is loaded into a scene.

This method is primarily used for:

- setting up variables
- performing logic that happens before the first run of `Update()`

## `Update()`
A games scene is displayed multiple times per second, known as its **frame rate** in frames per second (FPS). After each frame is displayed, the `Update()` method is called by the Unity engine.


