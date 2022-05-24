# Dynamic Allocation Decomp
Decompiling objects from SM64DS so we can allocate them dynamically using DLs.

## General

The source code in this repo uses a custom version of the SM64DS patch template headers.

The headers in other repos will be updated with documentation from this repo as soon as pants64 merges his headers with the ones in the ASM Reference repo (because these headers use his headers as a base).

The following abbreviations are used to categorize object folder names:
* B: Boss
* E: Enemy
* L: Level Specifics (bank 7)
* N: NPC
* O: Other
* P: Platform

Objects like Koopa the Quick and the Koopa Flag should be together in a folder because both objects depend on eachother, and should be compiled into a single DL.