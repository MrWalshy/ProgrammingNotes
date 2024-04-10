A world map offers a view of what is available in a game, the size of its scope is often revealed. Maps are not required in all games, but even then they can help the player understand the world they are navigating.

## Types of map
There are generally two main types of map:

- **Fixed**: These maps are usually drawn by artists, with extensive details of the surrounding world. They will sometimes appear blank initially to the player, with details revealed as the player traverses the world.
- **Generated**: Generated maps differ on each run of a game, with the places to go and/or events that take place also being randomised.

Another key element of maps are repeatability and replayability, allowing players to revisit existing locations and discover new things.

### Fixed maps
Many resources exist that can be used to create maps for a title where no dedicated artists exist, it is important to keep in mind the license and usage policy of any images acquired for the purpose of a map though.

- Free option: [Free Fantasy Maps - Free Maps of Fantasy Worlds](https://freefantasymaps.org/)
- Paid option: [Cartographers' Guild - a community for maps of fantasy, sci-fi and real world locations (cartographersguild.com)](https://www.cartographersguild.com/content.php?s=2ab7a52c862946d8427b86d9304fc5b4)

### Generated maps
Map generators can be used for these maps. Online systems exist, but these are usually low quality and aimed at tabletop games.

- High quality online generator: [donjon; Fantasy World Generator (bin.sh)](https://donjon.bin.sh/fantasy/world/)

#### In-game generated maps
Rather than using online-tools, the developers can also create maps using Unity's asset pipeline or in-game code.

- **Tiled**, free map editor: [Tiled | Flexible level editor (mapeditor.org)](https://www.mapeditor.org/)
- Plugins exist which can integrate maps from Tiled, like [Seanba/SuperTiled2Unity: Imports Tiled files to Unity. Better than regular Tiled2Unity. (github.com)](https://github.com/Seanba/SuperTiled2Unity)

Procedural generation techniques can also be used build a map while a game is running.

## Procedural generation
- [Procedural Content Generation Wiki - Procedural Content Generation Wiki (wikidot.com)](http://pcg.wikidot.com/)

Useful techniques for procedural generation include:

- **Iterated function systems**: Fractals to create land masses or structured areas
- **L-systems**: Used for road or path generation
- **Diamond-square and midpoint displacement algorithm**: Used to create random height terrain
- **Perlin and simplex noise systems**: Adds more randomness to generation

