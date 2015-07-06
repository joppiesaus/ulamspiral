### Cloning
`git clone https://github.com/joppiesaus/ulamspiral.git`

### Dependencies
* [SDL2](https://www.libsdl.org/) (deb: `libsdl2-2.0-0 libsdl2-dev`)
* [GLEW](http://glew.sourceforge.net/) (deb: `libglew1.10 libglew-dev`)

Windows(VS): Dependencies included in the `windows` branch.

Right now developing for windows(TODO: fix this, sln file won't be updated!):
```
git checkout windows
git checkout master
# some change made
git add foo.bar
git commit -m "blah blah"
git checkout windows
git merge master
git checkout master
```

Linux(Debian): Install dependencies by typing `sudo apt-get install <deps>`. Code::Blocks project included.

### Installing/Compiling
Linux(debug):
`g++ <all files here> -o ulamspiral -lSDL2 -lGL -lGLEW -lm -std=c++11 -I/usr/include -L/usr/lib/x86_64-linux-gnu`
Directories may be different on your system.
Add -O3 for a release build.
Can someone teach me to not do `<all files here>`? Makefiles? Help?!

### Running
(Should be pretty obvious)
Windows: `ulamspiral.exe`
Linux: `./ulamspiral`

### History
I wanted to make a graph so you could see if there was any pattern in the prime numbers.

I created [this](https://www.khanacademy.org/computer-programming/prime-visualizer/4555808299941888) on khanacademy, but I wasn't satisfied. I wanted to see _real_ patterns.

So I made a [spiral version](https://www.khanacademy.org/computer-programming/prime-visualizer-spiral-editionulam-spiral/5760394155130880) of it, which turns out to be an Ulam Spiral.

Then I cloned it into C++ SDL OpenGL application on Windows, but I wanted it to run on Linux too so I could run it on my crappy netbook which is perfect for Lubuntu.

I spent half a day trying to figure out how it worked, I couldn't get it working. So I tried to learn a little bit more of Linux and this is it now.

### Contributing
Just fork & pull request!

### TODO
* Fix git repo: make windows files independent from master
* Cleanup
* Everything todo with the draw code sucks.
* Make the window resizable.

### Bugs
* Above 200, the graph starts to clip into itself.
