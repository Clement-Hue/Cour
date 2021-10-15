FLAGS = -w a

LIBRARIES= unix.cma  camlimages/camlimages_core.cma camlimages/camlimages_graphics.cma camlimages/camlimages_all_formats.cma


a.out: Mandelbrot.cmo  Couleur.cmo Image.cmo ImageDump.cmo Sprite.cmo Lueur.cmo test.ml
	ocamlc $(FLAGS) -o $@ $(LIBRARIES) $^

# Utiliser cette cible si nous n'avez pas installé la bibliothèque Camlimages (pas de Sprites)
a.nosprite.out:  Couleur.cmo Image.cmo ImageDump.cmo Mandelbrot.cmo Lueur.cmo test.ml
	ocamlc $(FLAGS) -o $@ $^

Couleur.cmo : Couleur.ml Couleur.cmi
	ocamlc $(FLAGS) -c $<

Couleur.cmi : Couleur.mli
	ocamlc $(FLAGS) -c $<

Image.cmo : Image.ml Image.cmi Couleur.cmi 
	ocamlc $(FLAGS) -c $<
Image.cmi : Image.mli Couleur.cmi 
	ocamlc $(FLAGS) -c $<

Mandelbrot.cmi : Mandelbrot.mli
	ocamlc $(FLAGS) -c $<
Mandelbrot.cmo : Mandelbrot.ml Mandelbrot.cmi
	ocamlc $(FLAGS) -c $<

Lueur.cmo : Lueur.ml Couleur.cmi Image.cmi
	ocamlc $(FLAGS) -c $<



ImageDump.cmi: ImageDump.mli Image.cmi
	ocamlopt $(FLAGS) -c $<

ImageDump.cmo: ImageDump.ml ImageDump.cmi Image.cmi 
	ocamlc $(FLAGS) -c $<

Sprite.cmo: Sprite.ml Sprite.cmi Image.cmi
	ocamlc $(FLAGS) -c -I +camlimages $<
Sprite.cmi: Sprite.mli Image.cmi
	ocamlc $(FLAGS) -c $<

clean:
	rm -f *.cmo *.cmi
mrproper:
	rm -f *.cmo *.cmi a.out

.PHONY : test

test : a.out
	./$< | display

# Utiliser cette cible si nous n'avez pas installé la bibliothèque Camlimages (pas de Sprites)
test.nosprite : a.nosprite.out
	./$< | display

