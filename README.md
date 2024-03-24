# Introduction
Hello everyone, this is Tyler. This game was made for Dungeon Crawler Jam
2024. Where you would have to make a dungeon crawler in under about 9 
days. This is the second game jam I ever participated in. Not only that,
this is also the first project where I'm working with someone else, so
this is a momumental occasion that I would like to be remembered.

The game would be writen in C++ using the Raylib framework. My role in the
the project would be to program the game itself, and create the sound
effects and music. My teammate, which I will be refering to by her
username which is: the_saver1, would be responsible for the game's art.

The 4 themes for the gamejam are: Infinity/The Endless, Ancient Ruins, 
Solitude, and Cosmic Horror. The game has to incorporate at least one of
these themes. The ones we agreed to go with for now are: Ancient Ruins,
and Solitude.

9 days to create a dungeon crawler, we really gonna have to lock in for
this one. At least it would be a good learning experience as I never
worked with other people on a game before.

# Credits
**Tyler Dillard** - Programmer/Sound and Music Composer

**the_saver1** - Artist/Designer

Her Itch.io: https://the-saver1.itch.io/

Her Twitter: https://twitter.com/The_saver1

# File Structure
This is the general idea of the project's file structure. Please note that
the names given in the file tree are not accurate.

```
Root
├─── Graphics
│    ├─── Models
│    ├─── Sprites
│    └─── Textures
├─── Header Files
└─── Source Code
```

# Minimum Viable Product
The core of the game. Very important that we get this right. What's the
smallest thing we could possibly make that could still gives us useful
data.

I figured that the a minimum viable product for a dungeon crawler would be
this: 

* A small room with the player inside.
* The player would be able to move around with step-movement and the
player could only turn 90 degrees.
* An array would be used to track the player's location and to implement
collisions.

That's for the field gameplay, as for the battle system it would be a 
little more complicated.

* When a battle begins, I'm thinking that the area will slightly darken,
and the enemies will appear in the middle of the screen.
* The most often way a battle will begin would be though random 
encounters.
* There would be a battle manager that would be responsible for a number
of things like: Who's turn it is, who won the battle, and what to do
depending on who won.
* The only option the player would have would be "Attack".

So yeah, that's it. If we could get this right, we would be free to expand
upon it later.

# The Game's Scope
Since we literally had a little less than 9 days to finish the game, have
to define our scope. With something as complex as this, it would probably
be very narrow as this was the first time programming something like this.

The game would be about escaping the ancient ruins after obtaining it's 
magical artifact. The gameplay would be searching around for chests that
may contain a key, that allows you to unlock doors to progress. There may
be extra chests that may contain items, or familiars that may help you in
battle.

The only stats each party member would have is: HP, SP, ATK, AGI, and DEF.
There would be no equipment or experience, but there could be items that
temporary buff or debuff stats.

As for skills, each party member would have a set amount of skills for the
entire game. The skills could range from dealing damage, buffing stats, or
healing party members. The game ends once the player unlocks the final
door and escape.

As for battle system, it wouldn't be anything too complicated. Each turn,
you chose the action of each party member. The order of which participant
in the battle could act, depends on their Agility stat. Basically the
battle system would work like the old nes Final Fantasy games, and SMT.
