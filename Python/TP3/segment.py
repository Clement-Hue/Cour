from tkinter import *

def draw_point(canvas,x,y,color="black"):
	canvas.create_rectangle(x,y,x,y,fill=color , width=0)

def segment(w,x,y):
	if x == 0 or  y==0:
		return
	draw_point(w,x,y)
	return segment(w,x-1,y-1)

window = Tk()
w = Canvas(window, width=200, height = 100)
w.pack()
draw_point(w,10,10)
mainloop()


