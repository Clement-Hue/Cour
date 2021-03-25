#! /bin/python3
# vim: set fileencoding=utf-8
#
# (c) March 1, 2021, José Martinez, Polytech Nantes, University of Nantes
#
# Licence:  proprietary
# The use of this library is not authorised outside the Polytechnic School of the University of Nantes.
#

from typing import *
import sys

X_CENTER    =    0.0
Y_CENTER    =    0.0
X_DELTA     =    3.0 # > 0
Y_DELTA     =    2.0 # > 0
IMAGE_WIDTH = 1920   # > 0
N_MAX       = 5000   # > 0

#
# MEMBERSHIP COMPUTATION
#

def PointMandelbrot (x0:     float,
                     y0:     float,
                     n_max:  int) -> float:
    assert n_max > 0
##    x = y = 0.0
##    for n in range(n_max):
##       x_prec = x
##       y_prec = y
##       x = x0 + x_prec * x_prec - y_prec * y_prec # The square function has been replaced by the available power operator to avoid its very costly interpretation (from 5'14'' down to 2'39'' on the default image with an iCore 5).  Notice that using the power operator, i.e., **2, is as costly as the square function!
##       y = y0 + 2 * x_prec * y_prec
##       if x * x + y * y > 4.0:
##          return n / n_max
##    return 0.0
    
    c0 = complex(x0, y0) # The complex version is much faster than the real-based one (from 2'39'' down to 1'39'').
    z = complex(0, 0)
    for n in range(n_max):
        z = z * z + c0
        if abs(z) > 2.0:
            return n / n_max
    return 0.0

#
# PIXEL COLOURS
#

def CouleurMandelbrot (p:  float) -> Tuple[int, int, int]:
    assert 0.0 <= p <= 1.0
    if p == 0.0:
       return (0, 0, 0);
    else:
       value = int((1.0 - p) * 256 * 256 * 256);
       v1 = value % 256;
       v2 = value // 256 % 256;
       v3 = value // 256 // 256 % 256;
       if   value % 3 == 0:  return (v1, v2, v3)
       elif value % 3 == 1:  return (v3, v1, v2)
       else:                 return (v2, v3, v1)

#
# ASCII PPM IMAGE
#

def ImageMandelbrot (largeur:  int,
                     hauteur:  int,
                     x0:       float,
                     y0:       float,
                     x1:       float,
                     y1:       float,
                     n_max:    int):
    assert largeur > 0
    assert hauteur > 0
    assert x0 < x1
    assert y0 < y1
    assert n_max > 0
    dx = (x1 - x0) / largeur;
    dy = (y1 - y0) / hauteur;
    assert( dx > 0 );
    assert( dy > 0 );
    print("P3\n#Mandelbrot set\n", largeur, hauteur, 255)
    y = y0;
    for i in range(hauteur):
       x = x0;
       for j in range(largeur):
          (r, v, b) = CouleurMandelbrot(PointMandelbrot(x, y, n_max))
          print(r, v, b, "   ", end="");
          x += dx
       print()
       y += dy

#
# COMMAND-LINE INTERFACE
#

def LigneCommande () -> Tuple[float, float, float, int, int]:
    assert X_DELTA     > 0
    assert Y_DELTA     > 0
    assert IMAGE_WIDTH > 0
    assert N_MAX       > 0
    if len(sys.argv) == 1:
        return (X_CENTER, Y_CENTER, X_DELTA, Y_DELTA, IMAGE_WIDTH, N_MAX)
    elif len(sys.argv) != 7:
        print("Usage:  Mandelbrot x y dx dy width n_max")
        print("where (x, y) is the coordinate of the center of the region of interest in the plane,")
        print("      (dx, dy) is the width and height of the region of interest,")
        print("      'width' is the width, in pixels, of the image to generate.")
        print("      and 'n_max' is the maximum number of iterations before a point is declared outside the Mandelbrot set.")
        print("Default values are:  0 0 3 2 500 200")
        print("The result is sent on the standard output.")
        quit()
    else:
        x     = float(sys.argv[1]);
        y     = float(sys.argv[2]);
        dx    = float(sys.argv[3]);
        dy    = float(sys.argv[4]);
        width = int(sys.argv[5]);
        n_max = int(sys.argv[6]);
        if dx <= 0.0 or dy <= 0.0 or width <= 0 or n_max <= 0:
            print("Error:  'dx,' 'dy,' 'width,' and 'n_max' must be strictly greater than zero.")
            quit()
        else:
            return (x, y, dx, dy, width, n_max)

if __name__ == "__main__":
    (xc, yc, dx, dy, largeur, n_max) = LigneCommande()
    hauteur = int((dy / dx) * largeur);
    x0 = xc - dx;
    x1 = xc + dx;
    y0 = yc - dy;
    y1 = yc + dy;
    ImageMandelbrot(largeur, hauteur, x0, y0, x1, y1, n_max);
