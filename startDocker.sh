#!/bin/bash 

docker run -it --rm \
	-p 8888:8888 \
	-v "$HOME/Documents/Projects/tictactapp/notebooks":/JuliaProjects \
	jj