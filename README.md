# Dynamic Allocation Decomp
Decompiling objects from SM64DS so we can allocate them dynamically using DLs (Dynamic Libraries).

Feel free to use the source code here for your own projects, giving credit would be appreciated :).

If you ever notice any inconsistencies with the original objects, feel free to create an issue or message me on Discord so I can investigate.

## General

The source code in this repo uses a custom, more up-to-date, version of the SM64DS patch template headers.

The following abbreviations are used to categorize object folder names:
* E: Enemy / Boss
* N: NPC
* O: Other
* P: Platform

Objects like Koopa the Quick and the Koopa Flag should be together in a folder because both objects depend on eachother, and should be compiled into a single DL.

Objects like Goomba and Goomboss that can function independently from eachother should be split, and compiled into separate DLs, but keep in mind that Goomboss needs the Goomba code to be loaded in order to spawn Goombas.

# Credits
* Splatterboy: mod manager, decompiled objects, game documentation
* Gota7: decompiled objects, game documentation
* pants64: shared object resource system (GloballySharedFilePtr), game documentation
* Josh65536: DL format, game documentation
