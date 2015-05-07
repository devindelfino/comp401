Project 05: Julia Sets
======================
*Devin Delfino*

Description
-----------
Using python and Matplotlib, I visualized plots representing various [Julia Sets](http://en.wikipedia.org/wiki/Julia_set). Saving these plots as svg files, I was able to etch the fractal on wood using a laser cutter.

Taking a small region of the complex plane centered around the origin, we break it up into a series of points. For each complex point z, we apply the equation z = z^2 + c, where c is another complex number x + yi, for a certain number of iterations. While we are applying this function, z will either remain small or diverge towards infinity. If we iterate this function over each complex point in our region, and plot only the points that remain stable during the iteration, we get a nice fractal image.

Contents
--------

In the *project05/* directory:
* *julia.py* - python script that plots julia sets. This is the most effective working version.
* *JuliaSetSVGs/* - Directory containing some saved SVG images of Julia Sets
* *mathematica_version/* - Directory containing a mathematica implementation of the code.
* *matlab_version* - Directory containing a matlab implementation of the code (currently does not work).

References
----------
1. [Vizualizing Julia Sets](http://sites.williams.edu/fws1/files/2011/10/VisualizingJuliaSets.pdf) - I based my code off of this source, picking it apart in order to understand the algorithm, which turned out to be relatively straightforward. Mostly, I used this code to deal with some Mathematica idiosynchrosies, and built my own code off of this, improving it where I saw fit.
2. [Julia Set](http://en.wikipedia.org/wiki/Julia_set)
3. [Understanding Julia Sets](http://www.karlsims.com/julia.html)
