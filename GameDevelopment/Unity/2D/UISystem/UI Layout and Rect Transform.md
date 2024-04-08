All UI objects are automatically given a **Rect Transform** component, these work in a similar way to the **Transform** component. It allows the UI object to be positioned. Unlike transforms though, properties for Width, Height, Pivot, and Anchors are also provided.

When positioning UI objects, it is important to remember that the coordinates are relative to the canvas and not the world space unless the canvas render mode is set to **World Space**.

## Rect Tool
The Rect Tool, like with non-UI elements in a scene, can be used to change the size, position, or rotation of UI objects. When modifying a UI object with the **Rect Tool**, its **Width** and **Height** will change on the **Rect Transform** component but not the scale value.

## Pivot
The **Pivot** of a UI object determines the UI elements registered location, the point about which it will rotate and scale from. Adjusting the `X` values of the pivot moves it left and right from the position selected using the anchor preset, adjusting the `Y` values moves it up and down. If an **Anchor Preset** has not been chosen, the pivot point defaults to the centre of the UI element.

## Anchors
The **Anchors** property determines where objects are attached or anchored to its parent, this allows the element to resize relative to its parent object. Each **Rect Transform** has an **Anchor Preset** button in the top-left corner, clicking it reveals the presets which can be chosen.

- Holding `Shift` while clicking a preset sets the pivot
- Holding `Alt` while clicking sets the anchor position
- Holding `Shift+Alt` sets both the pivot and anchor position

