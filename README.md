# Maze-Rider
Maze crawler where you hunt for parts of a unicycle.

This is a simple maze wandering game where you seek the 5 pieces of a unicycle.  It's relatively simple as I ran short on time for some things I wanted( pause screen displaying what pieces you've found etc.)  But the core mechanics I wanted are present.  

The important info:

    Character: SnailGuy
    
    Buttons:
    --------
    DPad: move in that direction
    A: select/ pause menu ingame
    B: exit pause menu
    A + B: return to level select while in game
    
    Move between floor tiles:
    -------------------------
    Upstairs: U
    Downstairs: D
    
    Move through in one direction tiles:
    ------------------------------------
    Left Gate: <
    Right Gate: >
    Upwards Gate: ^
    Downwards Gate: v
    
    Special Tiles: 
    --------------
    Closed Gate: * (Can't move through)
    Open Gate: # (Can move through)
    Gate Button: @ (Toggles gate state)

    Part tiles:
    -----------
    Parts:
    Seat: ~
    Stem: l
    Crank: z
    wheel: o
    Pedals: =








To Do:
---------

* add saving level.
* add tutorial page.
* write tutorial to add levels(ez pz);
* better document code (never ending)
* add levels (at least one with the gate)
* implement EEPROM saving of unlocked levels and scores
* fix the faq to show the tiles not the character encodings




Maybes:
-----------
* add a background music theme.
* write a cheeseball story page.
* add pushable tile.
* add RLE to the levels to save extra memory 



Done:
--------
* add one way movement tiles ' v, ^, <, >, '.
* add inbetween screen for stages
* add level select screen.
* add level with gate tiles
* add a button and gate tile (would need an aditional class prob). (It didn't)
* make inbetween screen for stages pleasent.
* make level select not awful to look at.
* implement art.
* make pause screen not horrible.
* Change scoring to level based.
