/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** APizza.hpp
*/

#ifndef APIZZA_HPP_
    #define APIZZA_HPP_

#include <memory>
#include <vector>
#include "IPizza.hpp"
#include "IIngredient.hpp"

namespace plazza {
    namespace food {
        class APizza : public IPizza {
            public:
                APizza();
                ~APizza();
                PizzaType getType() const;
                PizzaSize getSize() const;
                int getBakingTime() const;
                int getIdCommand() const;
                void dump() const;
            protected:
                int _idCommand;
                PizzaType _type;
                PizzaSize _size;
                int _bakingTime;
                std::vector<std::unique_ptr<IIngredient>> _ingredients;
            private:
                void dumpPizza() const;
                void dumpSize() const;
                void dumpIngredients() const;
        };
    }
}

#endif /* !APIZZA_HPP_ */
