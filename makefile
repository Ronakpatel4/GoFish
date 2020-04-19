# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 


gofish: card_demo.o player.o deck.o card.o
	g++ -o gofish  card_demo.o player.o deck.o card.o
card_demo: card_demo.cpp player.h deck.h card.h
	g++ -c deck.cpp
player.o: player.cpp player.h card.h
	g++ -c player.cpp
deck: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp