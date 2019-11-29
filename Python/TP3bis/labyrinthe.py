def getOut_of_here(labyrinthe,personnage):
	labyrinthe[0][0], personnage =  personnage, labyrinthe[0][0]
	print(labyrinthe)
	


labyrinthe =[  [  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1] ,[  1 ,  3 ,  1 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  1] ,[  1 ,  0 ,  1 ,  1 ,  1 ,  1 ,  0 ,  1 ,  0 ,  1] ,[  1 ,  0 ,  0 ,  0 ,  1 ,  1 ,  0 ,  1 ,  0 ,  1] ,[  1 ,  0 ,  1 ,  1 ,  1 ,  1 ,  0 ,  1 ,  0 ,  1] ,[  1 ,  0 ,  1 ,  0 ,  1 ,  1 ,  0 ,  1 ,  0 ,  2] ,[  1 ,  0 ,  1 ,  0 ,  0 ,  0 ,  0 ,  1 ,  1 ,  1] ,[  1 ,  0 ,  1 ,  0 ,  1 ,  1 ,  0 ,  0 ,  0 ,  1] ,[  1 ,  0 ,  0 ,  0 ,  1 ,  1 ,  0 ,  1 ,  0 ,  1] ,[  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ] ]
getOut_of_here(labyrinthe,labyrinthe[1][1])
