# Tic-Tac-Toe Game 

## Goal / Background

This project is to serve as a fun little entry way to reinforcement learning and to build my background to help with the (sjlist/pokemon-sim project)[https://github.com/sjlist/pokemon-sim]. 

The project has multiple stages and will be changing form as I learn more. Initially, I'm focusing on building a tic-tac-toe game in C++ using the command line and standard libraries. This game is chosen because it's a simple two player, turn-based game that I can code up in an afternoon (thus refreshing my C++, which is admittedly rusty at this point). 

The end goal of this project is to train an algorithm to play tic-tac-toe better than randomly guessing. I have a low bar here because I really only care about learning the tools. 


## Run

Cmake is set up for this project and I've added a `Makefile` for even more laziness! Build it with `make`, this will produce a library using Boost.Python to allow the Board class to be used from Python 3.7. Additionally, the command line game is built for fun. 

## Tools

The game will be built with C++ and standard libraries and the algorithm will be built and trained in Julia 1.1.1. This is because I like the language and am eager to learn it better. Additionally, it seems to have very good C++ integration and speed. 

These tools are subject to change as I continue the project. 

### August 8, 2018

Because of the libraries available and for development speed, I'm changing gears to training in Python. I am using the Boost.Python library to allow the game to be accessed from Python. I plan to start training with Tensorflow 2.0 and Keras. The binary being built of just the Board class files should still be usable in Julia 1.1, should I switch back.  

## Resources

A large part of the python code for performing Q learning was implemented using https://github.com/giladariel/TicTacToe_RL as a guide. 

Additionally, here are a few other resources: 

- Good text on Reinforcement Learning http://incompleteideas.net/book/RLbook2018.pdf
- Promising tutorial https://towardsdatascience.com/cartpole-introduction-to-reinforcement-learning-ed0eb5b58288
