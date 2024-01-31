# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore

[English](README.md) | [Spanish](README_ES.md)

## mod-account-mounts

The module's objective is to go through the list of characters on an account (which is activated when the player enters the server, with OnLogin), obtain the playerGuids and store the mount spells that all the characters know. Then, said list is run through, and the character who does not know the spell is taught said spell. By default, it shows mounts that are of the same race, however, it can be enabled to show all mounts, regardless of faction.

Currently, another module is in development, which is not finished, but has a similar idea, however, the difference is that it stores the spells in a database, allowing them to be classified into Alliance, horde and neutral, so If a player is an alliance, he learns those of the alliance plus the neutral ones. And if a player is Horde, learn those of that faction plus the neutral ones. As is the case, of the Lich King's mount.

https://github.com/pangolp/mod-mounts-on-account

- Latest build status with azerothcore:

[![Build Status](https://github.com/azerothcore/mod-account-mounts/workflows/core-build/badge.svg?branch=master&event=push)](https://github.com/azerothcore/mod-account-mounts)

Credits: ConanHun513
