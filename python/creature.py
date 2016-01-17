# Assignment: <Assignment 2, Creature>, File name: <creature.py> 
# Author: <Tanya Lindermeier>
# Collaboration: <Independent>
# Resources: <CSCI 1300 class slides, Python Programming by Zelle>
#
# Comments: Why a caterpillar? <Creating a caterpillar was fun! I was able to use 
# various sizes and colors of shapes such as, circles, ovals, and 
# rectangles. The caterpillar was drawn with balloons, a metaphor
# for expected flight to come as the caterpillar metamorphoses 
# into a butterfly. Additionally, a platform was made where hexagons and 
# triangles were fitted tightly together.>
#
# Bonus: <Additional shape: golden filled stars with yellow outline>

from graphics import *

def creature():
	win = GraphWin("Creature", 700, 700) # "title", and dimensions
	
	body4 = Circle(Point(448, 420), 42) # (center, radius) of body segment 4
	body4.setFill("green") # fills the body with green color
	body4.setOutline("red") # outlines the body with red
	body4.draw(win) # draws the body
	
	body3 = Circle(Point(406, 462), 42) # (center, radius) of body segment 3
	body3.setFill("blue") # fills the body with blue color
	body3.setOutline("green") # outlines the body with green
	body3.draw(win) # draws the body
	
	body2 = Circle(Point(364, 420), 42) # (center, radius) of body segment 2
	body2.setFill("red") # fills the body with red color
	body2.setOutline("blue") # outlines the body with blue
	body2.draw(win) # draws the body
	
	body1 = Circle(Point(322, 462), 42) # (center, radius) of body segment 1
	body1.setFill("green") # fills the body with green color
	body1.setOutline("red") # outlines the body with red
	body1.draw(win) # draws the body
	
	head = Circle(Point(280, 420), 42) # (center, radius) of head
	head.setFill("yellow") # fills the head with yellow color
	head.setOutline("blue") # outlines the head with blue
	head.draw(win) # draws the head
	
	eye1 = Circle(Point(265, 412), 11) # (center, radius) of eye1
	eye1.setFill("yellow") # fills eye1 with yellow color
	eye1.setOutline("purple") # outlines eye1 with purple
	eye1.draw(win) # draws eye1
	
	inner_eye1 = Circle(Point(265, 412), 8) # (center, radius) of inner_eye1
	inner_eye1.setFill("black") # fills the inner_eye1 with black color
	inner_eye1.draw(win) # draws inner_eye1
	
	eye2 = Circle(Point(293, 412), 11) # (center, radius) of eye2
	eye2.setFill("yellow") # fills eye2 with yellow color
	eye2.setOutline("purple") # outlines eye2 with purple color
	eye2.draw(win) # draws eye2
	
	inner_eye2 = Circle(Point(293, 412), 8) # (center, radius) of inner_eye2
	inner_eye2.setFill("black") # fills inner_eye2 with black color
	inner_eye2.draw(win) # draws inner_eye2
	
	lower_antenna1 = Rectangle(Point(266, 380), Point(268, 360)) # dimensions of the 1st lower antenna
	lower_antenna1.setFill("purple") # fill with purple color
	lower_antenna1.draw(win) # draw antenna 1
	
	upper_antenna1 = Circle(Point(267, 356), 6) # dimensions of the 1st upper antenna
	upper_antenna1.setFill("red") # fill with red color
	upper_antenna1.draw(win) # draw antenna 1
	
	lower_antenna2 = Rectangle(Point(294, 380), Point(296, 360)) # dimensions of the 2nd lower antenna
	lower_antenna2.setFill("purple") # fill with purple color
	lower_antenna2.draw(win) # draw antenna 2
	
	upper_antenna2 = Circle(Point(295, 356), 6) # dimensions of the 2nd upper antenna
	upper_antenna2.setFill("red") # fill with red color
	upper_antenna2.draw(win) # draw antenna 2
	
	leg1 = Rectangle(Point(315, 504), Point(317, 520)) # dimensions of the 1st leg
	leg1.setFill("black") # fill with black color
	leg1.draw(win) # draw leg 1
	
	foot1 = Rectangle(Point(312, 520), Point(317, 522)) # dimensions of the 1st foot
	foot1.setFill("black") # fill with black color
	foot1.draw(win) # draw foot 1
	
	leg2 = Rectangle(Point(320, 504), Point(322, 519)) # dimensions of the 2nd leg
	leg2.setFill("black") # fill with black color
	leg2.draw(win) # draw leg 2
	
	foot2 = Rectangle(Point(317, 519), Point(322, 521)) # dimensions of the 2nd foot
	foot2.setFill("black") # fill with black color
	foot2.draw(win) # draw foot 2
	
	leg3 = Rectangle(Point(401, 504), Point(403, 520)) # dimensions of the 3rd leg
	leg3.setFill("black") # fill with black color
	leg3.draw(win) # draw leg 3
	
	foot3 = Rectangle(Point(398, 520), Point(403, 522)) # dimensions of the 3rd foot
	foot3.setFill("black") # fill with black color
	foot3.draw(win) # draw foot 3
	
	leg4 = Rectangle(Point(406, 504), Point(408, 519)) # dimensions of the 4th leg
	leg4.setFill("black") # fill with black color
	leg4.draw(win) # draw leg 4
	
	foot4 = Rectangle(Point(403, 519), Point(408, 521)) # dimensions of the 4th foot
	foot4.setFill("black") # fill with black color
	foot4.draw(win) # draw foot 4
	
	mouth = Oval(Point(274,434), Point(286,446)) # dimensions of the mouth
	mouth.setFill("black") # fills the oval with black
	mouth.draw(win) # draws the mouth
	
	balloonstring3 = Rectangle(Point(405, 250), Point(405, 412)) # dimensions of the balloonstring3
	balloonstring3.setOutline("yellow") # outlines with yellow color
	balloonstring3.draw(win) # draw balloonstring3
	
	balloon3 = Oval(Point(355,145), Point(455,255)) # draws a balloon
	balloon3.setFill("red") # fills balloon with red
	balloon3.draw(win) # draws balloon
	
	balloonstring2 = Rectangle(Point(360, 150), Point(360, 378)) # dimensions of balloonstring2
	balloonstring2.setOutline("blue") # outlines with blue color
	balloonstring2.draw(win) # draw balloonstring2
	
	balloon2 = Oval(Point(315,150), Point(405,20)) # dimensions of balloon2
	balloon2.setFill("yellow") # fills balloon2 with yellow
	balloon2.draw(win) # draws balloon2
	
	balloonstring1 = Rectangle(Point(321, 200), Point(321, 418)) # dimensions of balloonstring1
	balloonstring1.setOutline("red") # outlines with red color
	balloonstring1.draw(win) # draws balloonstring1
	
	balloon1 = Oval(Point(276,200), Point(366,90)) # dimensions of balloon1
	balloon1.setFill("blue") # fills balloon1 with blue color
	balloon1.draw(win) # draws balloon1
	
	hexagon1 = Polygon(Point(308, 550), Point(350,550), Point(371, 592), Point(350, 634), Point(308, 634), Point(287, 592)) # draws hexagon1
	hexagon1.setFill("yellow") # fills hexagon with yellow
	hexagon1.setOutline("green") # outlines hexagon with green
	hexagon1.draw(win) # draws hexagon1
	
	hexagon2 = Polygon(Point(392, 550), Point(434,550), Point(455, 592), Point(434, 634), Point(392, 634), Point(371, 592)) # draws hexagon2
	hexagon2.setFill("green") # fills hexagon2 with green
	hexagon2.setOutline("yellow") # oulines hexagon2 yellow
	hexagon2.draw(win) # draws hexagon2
	
	upper_triangle1 = Polygon(Point(350,550), Point(371, 592), Point(392, 550)) # dimensions of upper_triangle1
	upper_triangle1.setFill("blue") # fills upper_triangle1 blue
	upper_triangle1.setOutline("red") # outlines upper_triangle1 red
	upper_triangle1.draw(win) # draws upper_triangle1
	
	lower_triangle1 = Polygon(Point(371,592), Point(350, 634), Point(392, 634)) # dimensions of lower_triangle1
	lower_triangle1.setFill("red") # fills lower_triangle1 red
	lower_triangle1.setOutline("blue") # outlines lower_triangle1 blue
	lower_triangle1.draw(win) # draws lower_triangle1
	
	star1 = Polygon(Point(130,120), Point(138, 134), Point(158, 134), Point(144,148), Point(150, 162), Point(130, 150), Point(110, 162), Point(116, 148), Point(102, 134), Point(122, 134)) # dimensions of star
	star1.setFill("gold") # fills star1 gold
	star1.setOutline("yellow") # outlines star1 yellow
	star1.draw(win) # draws star1
	
	star2 = Polygon(Point(50,50), Point(58, 64), Point(78, 64), Point(64,78), Point(70, 92), Point(50, 80), Point(30, 92), Point(36, 78), Point(22, 64), Point(42, 64)) # dimensions of star
	star2.setFill("gold") # fills star2 gold
	star2.setOutline("yellow") # outlines star2 yellow
	star2.draw(win) # draws star2
	
	
	star3 = Polygon(Point(530,120), Point(538, 134), Point(558, 134), Point(544,148), Point(550, 162), Point(530, 150), Point(510, 162), Point(516, 148), Point(502, 134), Point(522, 134)) # dimensions of star
	star3.setFill("gold") # fills star3 gold
	star3.setOutline("yellow") # outlines star3 yellow
	star3.draw(win) # draws star3

	star4 = Polygon(Point(650,50), Point(658, 64), Point(678, 64), Point(664,78), Point(670, 92), Point(650, 80), Point(630, 92), Point(636, 78), Point(622, 64), Point(642, 64)) # dimensions of star
	star4.setFill("gold") # fills star4 gold
	star4.setOutline("yellow") # outlines star4 yellow
	star4.draw(win) # draws star4
	
	star5 = Polygon(Point(230,20), Point(238, 34), Point(258, 34), Point(244,48), Point(250, 62), Point(230, 50), Point(210, 62), Point(216, 48), Point(202, 34), Point(222, 34)) # dimensions of star
	star5.setFill("gold") # fills star5 gold
	star5.setOutline("yellow") # outlines star5 yellow
	star5.draw(win) # draws star5
	
	title1 = Text(Point(150, 250), "Practicing.") # placement of title "Practicing"
	title1.setSize(36) # sets font size to 36 points
	title1.setTextColor("red") # sets the color of the text to red
	title1.draw(win) # draws the text
	
	subtitle1 = Text(Point(150, 300), "Pre-butterfly afloat.") # placement of subtitle "A pre-butterfly afloat."
	subtitle1.setSize(20) # sets font size to 20 points
	subtitle1.setTextColor("blue") # sets the color of the text to blue
	subtitle1.draw(win) # draws the text
	
	win.getMouse() # pauses for user to click mouse in window
	win.close()
	
creature()