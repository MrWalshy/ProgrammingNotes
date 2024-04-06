A **sprite** is a 2D image, they can be images depicting a single object or an entire scene. Several sprites can also be combined into a single object.

> When a project is in 2D mode, any imported images will automatically be assigned a **Sprite (2D and UI)** texture type.

Dragging a sprite image from the `Assets` folder to the **Scene** view adds a **2D Object-Sprite** to the scene, the object is automatically given a **Sprite Renderer** component which makes the sprite visible in the game.

- If a sprite has any transparency layers, import the sprite texture as a `png` formatted image.

When importing an image, it is imported as a single sprite by default, the **Sprite Editor** can be used to change this. It is recommended that sprite textures be a *perfect square* where their height and width are a power of two (`64x64`, `128x128`, `256x256`, etc...).

## Sprite Renderer
A **Sprite Renderer** is a component attached to a 2D object to be displayed as a sprite on the screen, this is what specifically renders it and makes it visible. There are multiple useful properties, including:

- **Sprite**: Allows selecting the image to be displayed, must be a **Sprite (2D and UI)** texture type.
- **Color**: Allows for the vertex colour and alpha channel (transparency) of the rendered image to be modified.
- **Flip**: Allows for a sprite to be flipped in the *X* or *Y* planes without using the **Scale** properties in the transform component.
- **Material**: This uses a default **shader** property of **Sprite/Default**, this shader does not interact with scene lights and thus lighting is not required to view sprites with the default settings.

## Sprite Editor
The **Sprite Editor** is used to manipulate sprites imported into Unity, it can only be used with images whose texture type is set to **Sprite (2D and UI)**. The editor allows for basic manipulations like:

- Changing the mipmap (sprite pixilation)
- Modifying the pivot position
- Splicing the texture to identify sprite regions (also used for sprite sheets)

## Sprite Sheets
A **Sprite Sheet** is a core part of a 2D animation system, it is a single texture containing multiple images which represent the individual frames of a 2D animation.

As sprite sheets combine multiple textures into one single, large texture, they improve performance when sending the sprites to the graphics card (it is faster to send one large sprite than multiple small sprites).

Traditionally, sprite sheets are formed by placing the multiple images of an animation into a single image. Each image in the sprite sheet will be placed into its own region, this could be in a row, a column, or in rows and columns. If the images are all the same size in the sprite sheet, Unity can automatically slice the texture into the appropriate regions otherwise you will have to manually set the regions appropriately.

## Texture atlases
A **texture atlas** is like a sprite sheet, it is a more efficient way of packing textures into a single texture. It can contain various parts of an object, sets of objects, etc...

The **Sprite Packer** utility provided by Unity can be used to combine all sprite textures into a single, tightly packed atlas to improve performance.