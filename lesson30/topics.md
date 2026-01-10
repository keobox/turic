# Topics

- Toy Forth set aside today.
- Why doing this lesson?
  - To show an example where C language shines.
- The starting code is in this repo https://github.com/antirez/zxfy
starting from the b50cb97a1248a400f71e669536892dce98dde280 commit
"Minor refactoring + accept worse solutions initially."
- ZX spectrum games intros have some spectucalar initial splash screens.
- The colour can be set on 8x8 bit grid. Is a limitation.
- What is the purpose of this program?
  - Given a PNG file, with the girl with earring as input and can transformed to an image that can be loaded in the ZX Spectrum.
- The algorithm to generate the image that take into account the Spectrum limitation is not dithering, but is an evolutive algorithm.
- The image resolution starts in black and white, then is coloured later.
- Another buzzword: the action of starting black and white and then color in the nueral network lingo is "Curriculum Learning". Is doing things step by step. This is true also in other algorithms.
- Search "Evolutionary algorithm" in wikipedia. Important: Italian wikipedia is wrong.
- We will use the Simulated Annealing, that seems not part of the page but should be
classified in this algoritthm category, since it simulates a biological system but with only
mutations, not reproduction.
- All these problems are optimizations problems, on pixels.
