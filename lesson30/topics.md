# Topics

- Toy Forth set aside today.
- Why doing this lesson?
  - To show an example where C language shines.
- The starting code is in this repo https://github.com/antirez/zxfy
starting from the b50cb97a1248a400f71e669536892dce98dde280 commit
"Minor refactoring + accept worse solutions initially."
- ZX spectrum games intros have some spectacular initial splash screens.
- The colour can be set on 8x8 bit pixel grid. Is a limitation.
- What is the purpose of this program?
  - Given a PNG file, with the girl with earring as input and can transformed to an image that can be loaded in the ZX Spectrum.
- The algorithm to generate the image that take into account the Spectrum limitation is not dithering, but is an evolutive algorithm.
- The image resolution starts in black and white, then is coloured later.
- Another buzzword: the action of starting black and white and then color in the nueral network lingo is "Curriculum Learning". Is doing things step by step. This is true also in other algorithms.
- Search "Evolutionary algorithm" in wikipedia. Important: Italian wikipedia is wrong.
- We will use the Simulated Annealing, that seems not part of the page but is something near a genetic algo
, since it simulates a system but with only mutations, not reproduction.
- All these problems that simuated annealing solves are optimizations problems, on pixels in this case.
- Code walktrought after minute 12.
- It use SDL and png library.
- `computeDiff` calculate, as distance, how much the wanted image is different from the generated image.
- `zx2rgb` is the algorithm used by the ZX Spectrum, in his ULA (Uncommitted Logic Array) a chip, to
transform the RGB image in RAM into a visualization on screen.
- Explanation of the 768 bytes of screen video, 32 rows and 24 cols of grids of 8 pixels.
- `mutate` is the function that mutate a bit the image.
- The main algorithm starts at the comment "Initialize SDL... ".
- There's a hint to check a previous video on "Simulated Annealing" but after the explanation of this video.
- This algorithm is very basic, it accepts a new image if the distance from previous generation is better.
- The real algorithm has tricks to avoid local minima, one is "curriculum learning", the other trick
is temperature, if temperature is high we mutate more and is possible to accept a image worst than
before when temperature goes down this acceptance happens less or not happen and mutation is low.
- The main loop is in the `while(1)` under `float temperature = 0.1`.
- In the end is stated that a sort of dithering is performed.
- References:
  - [Code ZXfy](https://github.com/antirez/zxfy)
  - [Dithering](https://en.wikipedia.org/wiki/Dither)
  - [Evolutianry algorithm](https://en.wikipedia.org/wiki/Evolutionary_algorithm)
  - [Sinclair ULA](https://sinclair.wiki.zxnet.co.uk/wiki/ZX_Spectrum_ULA)
  - [Simulated annealing video](https://www.youtube.com/watch?v=aii__13k52M)
- After watching the Simulated annealing video above, here is other use cases of Simulated Annealing:
  - Salesman problem: or finding the longest path in this case by perturbating a random path in a graph
  this is a notable NP complete problem, in this case Simulated Annealing is an approximation.
  - Evolving a neural networks in case we cannot use gradient descent to train a network because we don't have a training set.
    - My NOTE: this is something I know and a nice example of this is Flappy Bird neural network player using a genetic algorithm
    for training the net.
      - [Machine Learning for Flappy Bird using Neural Network and Genetic Algorithm](https://github.com/ssusnic/Machine-Learning-Flappy-Bird)
      - In this case the difference of Genetic algo and SA is super clear since above there is a real population of birds generated.
