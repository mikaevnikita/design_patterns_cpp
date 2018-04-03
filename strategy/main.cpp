#include "ducks.h"
#include "flyes.h"
#include "quacks.h"

/*
+Можно отлично видеть поддержку изменения поведения в рантайме
+Делегирование поведения
+Гибкость в изменении работы алгоритмов поведения
+Один объект алгоритма может использоваться несколькими объектами Duck, для этого
необходимо реализовать поддержку через умные указатели, например shared_ptr.
Это даст экономию памяти.

Здесь используется отношение СОДЕРЖИТ.

Паттерн стратегия:
определяет семейство алгоритмов, инкапсулирует каждый из них,
обеспечивает их взаимозаменяемость, позволяет модифицировать алгоритмы независимо от их
использования на стороне клиента.
*/

int main()
{
    FlyBehaviour* fly_behaviour = new RocketFly;
    QuackBehaviour* quack_behaviour = new Quack;

    RedheadDuck duck;
    duck.setFlyBehaviour(fly_behaviour);
    duck.setQuackBehaviour(quack_behaviour);

    duck.performFly();
    duck.performQuack();

    duck.setFlyBehaviour(new FlyNoWay);
    duck.setQuackBehaviour(new MuteQuack);

    duck.performFly();
    duck.performQuack();

    return 0;
}
