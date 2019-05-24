##
## EPITECH PROJECT, 2019
## PSU - Concurrent Programming - Plazza
## File description:
## Makefile Plazza
##

SRC	=	./src/main.cpp	\
		./src/Commands/Command.cpp	\
		./src/Exceptions/Exceptions.cpp	\
		./src/Ingredients/AIngredient.cpp	\
		./src/Ingredients/ChiefLoveIngredient.cpp	\
		./src/Ingredients/DoeIngredient.cpp	\
		./src/Ingredients/EggplantIngredient.cpp	\
		./src/Ingredients/GoatCheeseIngredient.cpp	\
		./src/Ingredients/GruyereIngredient.cpp	\
		./src/Ingredients/HamIngredient.cpp	\
		./src/Ingredients/IngredientGenerator.cpp	\
		./src/Ingredients/MushroomsIngredient.cpp	\
		./src/Ingredients/SteakIngredient.cpp	\
		./src/Ingredients/TomatoIngredient.cpp	\
		./src/IPC/Messenger.cpp	\
		./src/Kitchens/Cook.cpp	\
		./src/Kitchens/Kitchen.cpp	\
		./src/Kitchens/IngredientStock.cpp	\
		./src/Logger/Logger.cpp	\
		./src/Mutex/Mutex.cpp	\
		./src/Parser/Parser.cpp	\
		./src/Pizzas/AmericanaPizza.cpp	\
		./src/Pizzas/APizza.cpp	\
		./src/Pizzas/FantasiaPizza.cpp	\
		./src/Pizzas/MargaritaPizza.cpp	\
		./src/Pizzas/PizzaGenerator.cpp	\
		./src/Pizzas/ReginaPizza.cpp	\
		./src/Reception/Reception.cpp	\
		./src/UserInterface/UserInterface.cpp	\

NAME	=	plazza

INCLUDES	+=	-I./include/Ingredients/
INCLUDES	+=	-I./include/Exceptions/
INCLUDES	+=	-I./include/Pizzas/
INCLUDES	+=	-I./include/Commands/
INCLUDES	+=	-I./include/IPC/
INCLUDES	+=	-I./include/Kitchens/
INCLUDES	+=	-I./include/Logger/
INCLUDES	+=	-I./include/Mutex/
INCLUDES	+=	-I./include/Parser/
INCLUDES	+=	-I./include/Reception/
INCLUDES	+=	-I./include/UserInterface/

all:	$(NAME)

$(NAME):
		g++ $(SRC) -o $(NAME) $(INCLUDES) -lrt -pthread

clean:
		rm -rf *.o

fclean:	clean
		rm -rf $(NAME)

re:		fclean all
