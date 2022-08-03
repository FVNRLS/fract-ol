# fract-ol

<br>**About The Project**

Project based on library MiniLibX, to discover or use the mathematical notion of complex numbers, to take a peek at the concept of optimization out computer graphics and practice event handling.


<br>**Getting Started**

_to compile the program on Mac:_
<br>`make all`
<br><br>_to compile the program on Linux:_
<br> 
* download and install minilibx for Linux
* extract the minilibx folder from /libs and delete all references to it in  Makefile and headers

<br>**Prerequisites**

* Installed C compiler like gcc, cc or clang.
* installed or compiled minilibx

<br>**Usage**

	                                 ░▒▓▆▅▃▂▁USAGE▁▂▃▅▆▓▒░

		MANDELBROT:     MANDELBROT INSIDE_COLOR OUTSIDE_COLOR OUTLINE_COLOR
		JULIA:          JULIA INSIDE_COLOR OUTSIDE_COLOR OUTLINE_COLOR REAL_CONSTANT IMAGINARY_CONSTANT
		BURNING_SHIP:   BURNING_SHIP INSIDE_COLOR OUTSIDE_COLOR OUTLINE_COLOR
		PRESETS:        MANDELBROT PRESET PRESET_NAME"


	░▒▓▆▅▃▂▁COLORS AND PRESETS▁▂▃▅▆▓▒░   			░▒▓▆▅▃▂▁JULIA CONSTANTS▁▂▃▅▆▓▒░

		
		COLORS:         PRESETS					REAL:    |   IMAGINARY:
		WHITE           MATRIX				             	 |
		BLACK           STD_BLUE				−0.4     |   	 0.6 
		RED             STD_RED					 0.285   |   	 0
		LIME            STD_TEAL				 0.285   |   	 0.01
		BLUE            STD_GREEN				 0.285   |   	 0.01
		YELLOW          ACID     				 0.285   |   	 0.45
		CYAN            CMYK      			 	-0.70176 |     	-0.3842
		MAGENTA         DEPRESSIVE				-0.835   |  	-0.2321
		SILVER          BLOODY    				-0.8     |   	 0.156
		GRAY            UGLY      				−0.7269  |   	 0.1889
		MAROON                    				−0.7269  |   	 0.1889 
		OLIVE                     				-0.8     |   	 0
		GREEN                     
		PURPLE                    
		TEAL                      
		NAVY          


<br>**Roadmap**

1) Resolve slow 🐢 zooming (in and out) and moving of the fractal:
* pre-calculate the rendering before initial rendering
* define sufficient but not too high number of iterations for each fractal separately

2) Add more features:

* change Julia shape depending on the mouse coordinate by clicking and moving the mouse pointer around the window 
* support changing fractal sharpness with hotkeys
* support more (maybe all?) colors from the library https://htmlcolorcodes.com/colors/
* add persistent fluent fractal animation

<br>**Contributing**

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement". Don't forget to give the project a star! Thanks again!


<br>**Acknowledgments**

Many thanks for support and patience to:

💟 Heleen [https://github.com/heleenoomen]

<br>Good color library:
https://htmlcolorcodes.com/colors/
