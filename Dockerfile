FROM julia:latest

# Basics 
LABEL maintainer="Alton Barbehenn"
WORKDIR /JuliaProjects
USER root

# copy board library `g++ -shared -fPIC Board.cpp -o libBoard.so`
COPY ./Board/libBoard.so .

# set Julia threads
ENV JULIA_NUM_THREADS 2

# install g++ as a dependency of Cxx.jl
RUN apt update && apt install -y build-essential python3 python3-pip

# install jupyter notebook
RUN pip3 install jupyter

# install packages
RUN julia -e 'using Pkg; Pkg.add.(["Cxx", "Flux", "IJulia", "POMDPs"])'

# precompile packages (slightly faster load)
RUN julia -e 'using Cxx; using Flux; using IJulia; using POMDPs'

RUN julia -e 'using POMDPs;\
	using Pkg;\
	POMDPs.add_registry();\
	Pkg.add.(["QuickPOMDPs", "POMDPSimulators", "QMDP", "POMDPSimulators", "POMDPModels"]);\
	Pkg.clone("DeepQLearning");\
	Pkg.build("DeepQLearning");'
RUN julia -e 'using DeepQLearning; using POMDPModels; using POMDPSimulators; using QuickPOMDPs; using QMDP'

# launch jupyter notebook
CMD ["/usr/local/bin/jupyter-notebook", "--ip=0.0.0.0", "--allow-root", "--no-browser", "--NotebookApp.token=''"]
