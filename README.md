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


# Final Thoughts

## the_saver1
HI everyone this is saver. I worked on the art and textures for the game jam, it was bit hard trying to draw things outside my comfort zone, but was really fun. Made me draw monsters for the game jam that though that wouldn't come out looking good, but really happy with how they look and the textures were challenging and fun to draw/paint. Had lots of fun working it and this being my first game jam, I'm really proud of myself and Tyler, Wouldn't be able to do this without there help. They worked on the coding and framework for the game and tried new things as well. was really good time working with them on this.

## Tyler Dillard
Hey guys, this is Tyler again. At the time I'm typing this, it's 11:12 PM
EST, and I just finished the last feature needed before releasing the
game. In hindsight, having to program a dungeon crawler (Which is something 
that's debatably mechanically complex.) in under 9 DAYS is absolutely 
WILD!

Considering the fact that I used a framework to make the game, and never 
had much experience with programming battle systems or 3D, we had to 
narrow our scope and cut a lot of things in order get finish the game
before the deadline. Like I said in the beginning, we really had to lock
in. I had to put my main project at the time on hold to put my full focus
into the project.

I know I'm sort of parroting what she said but, we had a good time. Both
of us played very important roles in the making of the game. Thanks to her
taking on the responsibility of drawing the art, I was able to put my
full attention to programming. Which believe is a important factor that
allowed us to finished. If I was alone, I'd probably burn myself out.

The game itself is alright. It's certainly one of the dungeon crawlers of
all time, and honestly that's okay. I'm still proud of it nonetheless, and
it would be good project to add to our portfolios. If you ever took the
time to play this game, thank you. I would also appreciate it if you
check out the main project if you have the chance.

# Credits
**Programmer** - Tyler Dillard - My [Itch.io](https://lorenarc.itch.io/), [Gamejolt](https://gamejolt.com/@LorenArc), and [Twitter](https://twitter.com/Tyler37961642)

**Artist/Designer** - the_saver1 - Her [Itch.io](https://the-saver1.itch.io/), and [Twitter](https://twitter.com/The_saver1)

# File Structure
This is the general idea of the project's file structure. Please note that
the names given in the file tree are not accurate.

```
Root
├─── Data
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
magical artifact. The ruins are like a maze, and the encounter rate is high
make this taske more challenging.

The only stats each party member would have is: HP, SP, ATK, AGI, and DEF.
There would be no equipment or experience.

As for skills, each party member would have a set amount of skills for the
entire game. 

As for battle system, it wouldn't be anything too complicated. Each turn,
you chose the action of each party member. The order of which participant
in the battle could act, depends on their Agility stat. Basically the
battle system would work like the old NES Final Fantasy games, and SMT.
