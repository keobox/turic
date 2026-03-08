# Topics

- Will use claude code to continue.
- The program evolve the video memory of ZX spectrum so that an image resembles the image passed.
- The program uses simulated annealing to do so.
- Reference:
  - [Code ZXfy](https://github.com/antirez/zxfy)
- Recap about video memory
  - function mutata, first part only the bitmap (1,0 is pixel is enabled)
  - There is a byte that has the attribute of every 8x8 bit group (pixel).
  - Minute 8:10 has a table of the video memory
  - 192 x 256 pixels 24 rows x 32 cols, pixel data 6114 (binary bitmap)
  - 768 bytes of attributes for every block of 8x8 pixels.
    - 3 bit III ink colour of the enabled pixels, 3 bit PPP color of "paper", so background,
    1 bit R if the colour is brighter or no, 1 bit F flashing.
  - Digression about a ZX80 emulator written with AI, there's an article on blog
- Comments on mutate gen> 200000 to avoid black blocks.  
  - There are other phases
  - iThis is called: Curriculum learning
- Use "sample" program MacOS for profiling
  - computeDiff is the CPU hog function.
- Write with claude cade a program to see the percentages
- Prompt: Take the file /tmp/zxfy.txt that was geneerated by the MacOS sapmple program and turn it into a
percentage of time used function. Turn this work into a python script that I can reuse.
Put the script somewhere into /tmp.
- Results 94.2% computeDiff is clear that this program is not optimized.
- This is because when we change few pixels we recalculate the diff for 192x256 pixels
- Digress about dithering: computeDiff make the "image difference" using a pixel kernel of 2x2 pixels
  - This is a trick to minimize a local area (dithering like)
  - Tried to remove the kernezxl and the result is bad.
- One change can be having a parametrized kernel size
- Minute 24:48 ask an optimization for 16x16 pixel area to claude code.
- Prompt
  - zxfy.c is a C program that evolves the Spectrum memory to reach a target image. The difference is computed using a function that considers each obtained and target RGB value as point in a 3D space, and the distance function is computed. However right now we do changes at random in the image space, and recompute the difference of the whole image. Please change the program in order to work on 1 8x8 block each time, without aligning this 8x8 block to the actual specturm blocks (grouped by the color attributes) so that we don't have local minima due to blocks being optimized locally (JPEG alike near-blocks artifacts). Consider that when we modify a 8x8 block, the actual color attributes related to it map to potentially up to 4 bytes of color attributes (the 4 8x8 blocks a random 8x8 block may be within). So each time we do changes, we change pixels or colors within such a block, using the same curriculum learning we are using right now. The cost of computing the difference of 8x8 is much cheaper and the program should be much faster. Do the changes with clean code using minimal complexity. 
- NOTE: the prompt stress the fact that the pixel and color should be changed accordingly.
- New generated code: computeBlockDiff and mutateBlock, minute 32:20.
- Minute 34:27 the implementation is not working stuck on 25% of difference. A second prompt
- Prompt:
  - There is some problem with the implementation. Add an headless option so that SDL is not used, like --no-sdl and check the loss in the output to see if the image converges since I see it stuck at 25% of difference.
  Also print the loss and status line after much more iterations, since now an iteration is too fast and would just spam the terminal.
- Another malfuction, new prompt:
  - Does the difference still uses a 2x2 kernel? This is a key feature of the program for it to evolve dithering.
  Another thing to change: insted of computing the differnce of the 8x8 block, compute the difference of the 16x16 pixels the unaligned 8x8 block falls within. This way you also fix the attribute clashing issue.
- A best practice: ask to write in CLAUDE.md the session recap with this prompt:
  - Do this: all you learned about this project that will be useful for the next sessions (only what is really relevant), should be written in CLAUDE.md, so in the next sessions you will know the fundamental ideas immeditaly.
- Adding a "zoom" feature prompt:
  - Please add --zoom option that will display zoomed SDL preview. The parameters dictates the zoom level, like, --zoom 2 
- Appendix, new features
  - Remove curriculum learning, that was a way to change mutation "rate" to avoid local minima.
  - "color-bonus" a value to avoid dischromia
  - "saturation boost"
  - "only bright or no bright"
- Unfortunately all the code was not delivered in Github.
