Circles, a learning project with C and SDL2

What you can do with it:
 - Click to change the position of the larger circle
 - Control the position of the smaller circle by moving your cursor
 - Have the larger circle change color if it's colliding with the smaller circle

How to build and run (on Debian 10):
 1. Have these packages: libsdl2-dev libsdl2-gfx-dev clang
 2. Run this command to build: clang -lSDL2 -lm -lSDL2_gfx -g main.c circle.c maths.c -o circles
 3. Run the program with this command: ./circles

Resources I've used:
 - https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index2.php (I remember this page being useful, but I forget what for.)
 - https://wiki.libsdl.org/
 - https://suckless.org/coding_style/ (I could suck less at following this)
 - https://www.ferzkopp.net/Software/SDL2_gfx/Docs/html/_s_d_l2__gfx_primitives_8h.html
 - https://yal.cc/rectangle-circle-intersection-test/

Development environment:
 - Debian 10 container on ChromeOS
 - VSCodium with these packages:
  - llvm-vs-code-extensions.vscode-clangd
  - vadimcn.vscode-lldb
 - Clang & LLDB 7.0.1



Who needs Markdown?
